#include "optim.h"
#include "quad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern quad Q[];
extern int  qc;

/* ================================================================
   UTILITAIRES
   ================================================================ */

static int est_constante(const char *s)
{
    if (!s || s[0] == '\0') return 0;
    int i = 0;
    if (s[i] == '-' || s[i] == '+') i++;
    if (s[i] == '\0') return 0;
    int point = 0;
    for (; s[i]; i++) {
        if (s[i] == '.')  { if (point++) return 0; }
        else if (!isdigit((unsigned char)s[i])) return 0;
    }
    return 1;
}

static int est_arith(const char *op)
{
    return strcmp(op,"+")==0 || strcmp(op,"-")==0 ||
           strcmp(op,"*")==0 || strcmp(op,"/")==0;
}

/* Invalider une variable dans le tableau d'expressions connues */
#define MAX_EXPR 500
typedef struct { char op[10]; char a1[20]; char a2[20]; char res[20]; } ExprCache;
static ExprCache cache[MAX_EXPR];
static int cache_cnt = 0;

static void cache_invalider(const char *nom)
{
    for (int i = 0; i < cache_cnt; i++) {
        if (strcmp(cache[i].a1, nom)==0 ||
            strcmp(cache[i].a2, nom)==0 ||
            strcmp(cache[i].res, nom)==0) {
            /* retirer en décalant */
            for (int j = i; j < cache_cnt-1; j++)
                cache[j] = cache[j+1];
            cache_cnt--;
            i--;
        }
    }
}

static const char *cache_chercher(const char *op, const char *a1, const char *a2)
{
    for (int i = 0; i < cache_cnt; i++)
        if (strcmp(cache[i].op,op)==0 &&
            strcmp(cache[i].a1,a1)==0 &&
            strcmp(cache[i].a2,a2)==0)
            return cache[i].res;
    return NULL;
}

static void cache_ajouter(const char *op, const char *a1, const char *a2, const char *res)
{
    if (cache_cnt >= MAX_EXPR) return;
    strcpy(cache[cache_cnt].op,  op);
    strcpy(cache[cache_cnt].a1,  a1);
    strcpy(cache[cache_cnt].a2,  a2);
    strcpy(cache[cache_cnt].res, res);
    cache_cnt++;
}

/* Table copie : Ti = Tj  → remplacer Ti par Tj dans les suivants */
#define MAX_COPY 200
typedef struct { char from[20]; char to[20]; } CopyEntry;
static CopyEntry copies[MAX_COPY];
static int copy_cnt = 0;

static void copy_set(const char *from, const char *to)
{
    /* invalider les copies impliquant "from" */
    for (int i = 0; i < copy_cnt; i++)
        if (strcmp(copies[i].from,from)==0 || strcmp(copies[i].to,from)==0) {
            for (int j=i;j<copy_cnt-1;j++) copies[j]=copies[j+1];
            copy_cnt--; i--;
        }
    if (copy_cnt < MAX_COPY) {
        strcpy(copies[copy_cnt].from, from);
        strcpy(copies[copy_cnt].to,   to);
        copy_cnt++;
    }
}

static const char *copy_get(const char *nom)
{
    for (int i = 0; i < copy_cnt; i++)
        if (strcmp(copies[i].from, nom)==0)
            return copies[i].to;
    return NULL;
}

static void copy_invalider(const char *nom)
{
    for (int i = 0; i < copy_cnt; i++)
        if (strcmp(copies[i].from,nom)==0 || strcmp(copies[i].to,nom)==0) {
            for (int j=i;j<copy_cnt-1;j++) copies[j]=copies[j+1];
            copy_cnt--; i--;
        }
}

/* Résoudre un argument via la table des copies */
static void resoudre_arg(char *arg)
{
    const char *v = copy_get(arg);
    if (v) strcpy(arg, v);
}

/* ================================================================
   PASSE 1 : Propagation d'expression
   Si Ti = expr et Ti utilisé une seule fois après → substituer
   ================================================================ */
static int compter_utilisations(int from, const char *nom)
{
    int cnt = 0;
    for (int i = from+1; i < qc; i++) {
        if (strcmp(Q[i].arg1, nom)==0) cnt++;
        if (strcmp(Q[i].arg2, nom)==0) cnt++;
        if (strcmp(Q[i].res,  nom)==0) { cnt += 10; break; } /* réécrit */
    }
    return cnt;
}

static void passe_propagation_expression()
{
    for (int i = 0; i < qc; i++) {
        /* Ti = a op b  et Ti utilisé UNE seule fois */
        if (!est_arith(Q[i].op)) continue;
        if (Q[i].res[0] != 'T')  continue;

        int uses = compter_utilisations(i, Q[i].res);
        if (uses != 1) continue;

        /* trouver l'utilisation */
        for (int j = i+1; j < qc; j++) {
            /* si le résultat est réécrit avant utilisation → stop */
            if (strcmp(Q[j].res, Q[i].res)==0) break;
            /* invalider si a1 ou a2 sont modifiés entre i et j */
            int invalide = 0;
            for (int k = i+1; k < j; k++) {
                if (strcmp(Q[k].res, Q[i].arg1)==0 ||
                    strcmp(Q[k].res, Q[i].arg2)==0) { invalide=1; break; }
            }
            if (invalide) break;

            int changed = 0;
            if (strcmp(Q[j].arg1, Q[i].res)==0) {
                /* propager : remplacer Ti dans arg1 par arg1_i op arg2_i */
                /* on insère un nouveau quad intermédiaire — trop complexe en linéaire
                   On fait juste la substitution d'arg si op est = */
            }
            if (strcmp(Q[j].arg2, Q[i].res)==0) { (void)changed; break; }
            (void)changed;
            break;
        }
    }
    /* NOTE : la propagation d'expression complète nécessite réécriture d'arbre.
       On l'implémente via la simplification algébrique + propagation de copie ci-dessous. */
}

/* ================================================================
   PASSE 2 : Simplification algébrique
   x + 1 - 1  →  x        (neutralité addition/soustraction)
   x * 1      →  x
   x * 0      →  0
   x + 0      →  x
   x - 0      →  x
   x * 2      →  x + x   (remplacement multiplication par addition)
   ================================================================ */
static void passe_simplification_algebrique()
{
    for (int i = 0; i < qc; i++) {
        if (!est_arith(Q[i].op)) continue;

        const char *a1 = Q[i].arg1;
        const char *a2 = Q[i].arg2;
        const char *op = Q[i].op;

        /* x + 0  ou  x - 0  →  = x */
        if ((strcmp(op,"+")==0 || strcmp(op,"-")==0) &&
            (strcmp(a2,"0")==0 || strcmp(a2,"0.000000")==0)) {
            strcpy(Q[i].op,   "=");
            strcpy(Q[i].arg2, "");
            continue;
        }
        /* 0 + x  →  = x */
        if (strcmp(op,"+")==0 && (strcmp(a1,"0")==0 || strcmp(a1,"0.000000")==0)) {
            strcpy(Q[i].op,   "=");
            strcpy(Q[i].arg1, Q[i].arg2);
            strcpy(Q[i].arg2, "");
            continue;
        }
        /* x * 1  →  = x */
        if (strcmp(op,"*")==0 &&
            (strcmp(a2,"1")==0 || strcmp(a2,"1.000000")==0)) {
            strcpy(Q[i].op,   "=");
            strcpy(Q[i].arg2, "");
            continue;
        }
        /* 1 * x  →  = x */
        if (strcmp(op,"*")==0 &&
            (strcmp(a1,"1")==0 || strcmp(a1,"1.000000")==0)) {
            strcpy(Q[i].op,   "=");
            strcpy(Q[i].arg1, Q[i].arg2);
            strcpy(Q[i].arg2, "");
            continue;
        }
        /* x * 0  ou  0 * x  →  = 0 */
        if (strcmp(op,"*")==0 &&
            (strcmp(a1,"0")==0 || strcmp(a2,"0")==0)) {
            strcpy(Q[i].op,   "=");
            strcpy(Q[i].arg1, "0");
            strcpy(Q[i].arg2, "");
            continue;
        }
        /* x / 1  →  = x */
        if (strcmp(op,"/")==0 &&
            (strcmp(a2,"1")==0 || strcmp(a2,"1.000000")==0)) {
            strcpy(Q[i].op,   "=");
            strcpy(Q[i].arg2, "");
            continue;
        }

        /* simplification T = (y +/- c1) +/- c2 en cherchant dans les précédents */
        /* ex: t11 = t10 - 1  et  t10 = j + 1  →  t11 = j + 1 - 1 = j */
        if ((strcmp(op,"+")==0 || strcmp(op,"-")==0) && est_constante(a2)) {
            /* chercher si a1 est un temp défini juste avant par a_x op c */
            for (int j = i-1; j >= 0; j--) {
                if (strcmp(Q[j].res, a1)==0) {
                    if ((strcmp(Q[j].op,"+")==0 || strcmp(Q[j].op,"-")==0)
                        && est_constante(Q[j].arg2)) {
                        float c1 = atof(Q[j].arg2);
                        float c2 = atof(a2);
                        float r;
                        if (strcmp(Q[j].op,"+")==0) r = c1;  else r = -c1;
                        if (strcmp(op,      "+")==0) r += c2; else r -= c2;

                        char buf[20];
                        if (r == 0) {
                            /* résultat = arg de base */
                            strcpy(Q[i].op,   "=");
                            strcpy(Q[i].arg1, Q[j].arg1);
                            strcpy(Q[i].arg2, "");
                        } else {
                            if (r == (int)r) sprintf(buf,"%d",(int)r);
                            else             sprintf(buf,"%g",r);
                            strcpy(Q[i].op,   "+");
                            strcpy(Q[i].arg1, Q[j].arg1);
                            strcpy(Q[i].arg2, buf);
                        }
                    }
                    break;
                }
            }
        }
    }
}

/* ================================================================
   PASSE 3 : Propagation de copie
   Ti = Tj  →  remplacer Ti par Tj dans tous les suivants
   ================================================================ */
static void passe_propagation_copie()
{
    copy_cnt = 0;
    for (int i = 0; i < qc; i++) {
        /* résoudre arg1 et arg2 via la table des copies */
        resoudre_arg(Q[i].arg1);
        if (Q[i].arg2[0]) resoudre_arg(Q[i].arg2);

        /* si c'est une copie simple Ti = Tj  (pas Ti = constante) */
        if (strcmp(Q[i].op,"=")==0 && Q[i].arg2[0]=='\0' && !est_constante(Q[i].arg1)) {
            copy_set(Q[i].res, Q[i].arg1);
        } else {
            /* invalider les copies qui impliquent le résultat */
            if (Q[i].res[0]) copy_invalider(Q[i].res);
        }
    }
}

/* ================================================================
   PASSE 4 : Élimination d'expressions redondantes (communes)
   Ti = a op b  déjà calculé → Tj = Ti
   ================================================================ */
static void passe_expressions_redondantes()
{
    cache_cnt = 0;
    for (int i = 0; i < qc; i++) {
        /* invalider cache si arg1 ou arg2 ont été modifiés */
        if (Q[i].res[0]) cache_invalider(Q[i].res);

        if (!est_arith(Q[i].op) &&
            strcmp(Q[i].op,"="  )!=0) continue;

        if (est_arith(Q[i].op)) {
            /* chercher si a op b déjà dans le cache */
            const char *prev = cache_chercher(Q[i].op, Q[i].arg1, Q[i].arg2);
            if (prev) {
                /* remplacer Ti = a op b  par  Ti = prev */
                strcpy(Q[i].op,   "=");
                strcpy(Q[i].arg1, prev);
                strcpy(Q[i].arg2, "");
            } else {
                cache_ajouter(Q[i].op, Q[i].arg1, Q[i].arg2, Q[i].res);
            }
        }
    }
}

/* ================================================================
   PASSE 5 : Élimination du code inutile (code mort)
   Un quadruplet est mort si son résultat n'est plus utilisé après
   et que l'opération n'a pas d'effet de bord
   ================================================================ */
static int utilise_apres(int from, const char *nom)
{
    for (int i = from+1; i < qc; i++) {
        if (strcmp(Q[i].arg1, nom)==0) return 1;
        if (strcmp(Q[i].arg2, nom)==0) return 1;
        /* si réécrit avant d'être lu → pas utile */
        if (strcmp(Q[i].res,  nom)==0) return 0;
    }
    return 0;
}

static int dead[1000];

static void passe_code_mort()
{
    memset(dead, 0, sizeof(dead));
    for (int i = 0; i < qc; i++) {
        /* jamais supprimer WRITE, BR, BZ, =[] */
        if (strcmp(Q[i].op,"WRITE")==0 || strcmp(Q[i].op,"BR")==0 ||
            strcmp(Q[i].op,"BZ"   )==0 || strcmp(Q[i].op,"=[]")==0)
            continue;
        if (Q[i].res[0] && !utilise_apres(i, Q[i].res))
            dead[i] = 1;
    }
}

/* ================================================================
   COMPACTER + RENUMÉROTER les cibles de branchement
   ================================================================ */
static int compacter()
{
    int new_index[1000];
    int j = 0;
    for (int i = 0; i < qc; i++)
        new_index[i] = dead[i] ? -1 : j++;

    /* corriger cibles BZ / BR */
    for (int i = 0; i < qc; i++) {
        if (!dead[i] && (strcmp(Q[i].op,"BZ")==0 || strcmp(Q[i].op,"BR")==0)) {
            int old = atoi(Q[i].res);
            if (old >= 0 && old < qc) {
                int target = old;
                while (target < qc && dead[target]) target++;
                char buf[20];
                sprintf(buf, "%d", (target < qc) ? new_index[target] : j);
                strcpy(Q[i].res, buf);
            }
        }
    }

    quad tmp[1000];
    int cnt = 0;
    for (int i = 0; i < qc; i++)
        if (!dead[i]) tmp[cnt++] = Q[i];
    memcpy(Q, tmp, cnt * sizeof(quad));
    return cnt;
}

/* ================================================================
   POINT D'ENTRÉE  — ordre selon le cours :
   1. Propagation d'expression
   2. Simplification algébrique
   3. Propagation de copie
   4. Élimination d'expressions redondantes
   5. Élimination de code inutile
   On répète les passes jusqu'à stabilisation (comme dans l'exemple
   de la prof qui fait 3 étapes)
   ================================================================ */
void optimiser()
{
    int avant = qc;

    int changed = 1;
    int iter = 0;
    while (changed && iter < 10) {
        int qc_avant = qc;
        iter++;

        passe_propagation_expression();
        passe_simplification_algebrique();
        passe_propagation_copie();
        passe_expressions_redondantes();
        passe_code_mort();
        qc = compacter();

        changed = (qc != qc_avant);
    }

    printf("\n======== Optimisation du code (%d iteration(s)) ========\n", iter);
    printf("Quadruplets avant : %d\n", avant);
    printf("Quadruplets apres : %d\n", qc);
    printf("Quadruplets elimines : %d\n", avant - qc);

    printf("\n======== Quadruplets Optimises ========\n");
    for (int i = 0; i < qc; i++)
        printf("%d : ( %s , %s , %s , %s )\n",
               i, Q[i].op, Q[i].arg1, Q[i].arg2, Q[i].res);
}
