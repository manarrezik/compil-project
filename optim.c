#include "optim.h"
#include "quad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern quad Q[];
extern int  qc;

#define MAX_Q 1000

int est_nombre(char *s)
{
    int i = 0;
    if (s[0] == '\0') return 0;
    if (s[0] == '-' || s[0] == '+') i = 1;
    for (; s[i] != '\0'; i++)
        if (!isdigit(s[i]) && s[i] != '.') return 0;
    return 1;
}

/* ecrire et comparer  */
void ecrire_quads(char *fichier)
{
    FILE *f = fopen(fichier, "w");
    fprintf(f, "%d\n", qc);
    for (int i = 0; i < qc; i++)
        fprintf(f, "%s|%s|%s|%s\n",
                Q[i].op, Q[i].arg1, Q[i].arg2, Q[i].res);
    fclose(f);
}

int fichiers_identiques(char *f1, char *f2)
{
    FILE *a = fopen(f1, "r");
    FILE *b = fopen(f2, "r");
    int ca, cb;
    do {
        ca = fgetc(a);
        cb = fgetc(b);
        if (ca != cb) { fclose(a); fclose(b); return 0; }
    } while (ca != EOF);
    fclose(a); fclose(b);
    return 1;
}

/* sauvgarder pour afficher la differance */
quad Q_avant[MAX_Q];
int  qc_avant;

void sauvegarder()
{
    qc_avant = qc;
    for (int i = 0; i < qc; i++)
        Q_avant[i] = Q[i];
}

void afficher_changements(char *nom_passe)
{
    int nb = 0;
    for (int i = 0; i < qc && i < qc_avant; i++) {
        if (strcmp(Q[i].op,   Q_avant[i].op)   != 0 ||
            strcmp(Q[i].arg1, Q_avant[i].arg1)  != 0 ||
            strcmp(Q[i].arg2, Q_avant[i].arg2)  != 0 ||
            strcmp(Q[i].res,  Q_avant[i].res)   != 0) {
            if (nb == 0)
                printf("  [%s] Modifications :\n", nom_passe);
            printf("    %d: (%s,%s,%s,%s) => (%s,%s,%s,%s)\n", i,
                   Q_avant[i].op, Q_avant[i].arg1,
                   Q_avant[i].arg2, Q_avant[i].res,
                   Q[i].op, Q[i].arg1,
                   Q[i].arg2, Q[i].res);
            nb++;
        }
    }
    int suppr = qc_avant - qc;
    if (suppr > 0)
        printf("  [%s] %d quadruplet(s) elimine(s)\n", nom_passe, suppr);
    if (nb == 0 && suppr == 0)
        printf("  [%s] Aucun changement\n", nom_passe);
}

/*SIMPLIFICATION ALGEBRIQUE */
void simplification_algebrique()
{
    int i, j;
    for (i = 0; i < qc; i++) {

        /* ignorer si ce n est pas une operation arithmetique */
        if (strcmp(Q[i].op, "+") != 0 &&
            strcmp(Q[i].op, "-") != 0 &&
            strcmp(Q[i].op, "*") != 0 &&
            strcmp(Q[i].op, "/") != 0) continue;

        /* x + 0 = x  ou  x - 0 = x */
        if (strcmp(Q[i].arg2, "0") == 0 &&
            (strcmp(Q[i].op, "+") == 0 || strcmp(Q[i].op, "-") == 0)) {
            strcpy(Q[i].op, "=");
            strcpy(Q[i].arg2, "");
            continue;
        }

        /* 0 + x = x */
        if (strcmp(Q[i].arg1, "0") == 0 && strcmp(Q[i].op, "+") == 0) {
            strcpy(Q[i].op, "=");
            strcpy(Q[i].arg1, Q[i].arg2);
            strcpy(Q[i].arg2, "");
            continue;
        }

        /* x * 1 = x */
        if (strcmp(Q[i].arg2, "1") == 0 && strcmp(Q[i].op, "*") == 0) {
            strcpy(Q[i].op, "=");
            strcpy(Q[i].arg2, "");
            continue;
        }

        /* 1 * x = x */
        if (strcmp(Q[i].arg1, "1") == 0 && strcmp(Q[i].op, "*") == 0) {
            strcpy(Q[i].op, "=");
            strcpy(Q[i].arg1, Q[i].arg2);
            strcpy(Q[i].arg2, "");
            continue;
        }

        /* x * 0 = 0  ou  0 * x = 0 */
        if (strcmp(Q[i].op, "*") == 0 &&
            (strcmp(Q[i].arg1, "0") == 0 || strcmp(Q[i].arg2, "0") == 0)) {
            strcpy(Q[i].op, "=");
            strcpy(Q[i].arg1, "0");
            strcpy(Q[i].arg2, "");
            continue;
        }

        /* x / 1 = x */
        if (strcmp(Q[i].arg2, "1") == 0 && strcmp(Q[i].op, "/") == 0) {
            strcpy(Q[i].op, "=");
            strcpy(Q[i].arg2, "");
            continue;
        }

        /* (x + c1) - c2 = x  si c1 et c2 s annulent
           exemple : T8 = a + 1  puis T12 = T8 - 1  → T12 = a  */
        if ((strcmp(Q[i].op, "+") == 0 || strcmp(Q[i].op, "-") == 0)
            && est_nombre(Q[i].arg2)) {

            /* chercher en arriere le quad qui calcule Q[i].arg1 */
            for (j = i - 1; j >= 0; j--) {
                if (strcmp(Q[j].res, Q[i].arg1) == 0) {
                    /* verifier que ce quad est aussi + ou - avec constante */
                    if ((strcmp(Q[j].op, "+") == 0 || strcmp(Q[j].op, "-") == 0)
                        && est_nombre(Q[j].arg2)) {

                        float c1 = atof(Q[j].arg2);
                        float c2 = atof(Q[i].arg2);
                        float r;

                        /* signe de c1 selon l operation du quad j */
                        if (strcmp(Q[j].op, "+") == 0) r =  c1;
                        else                           r = -c1;

                        /* signe de c2 selon l operation du quad i */
                        if (strcmp(Q[i].op, "+") == 0) r += c2;
                        else                           r -= c2;

                        /* si le resultat est 0 : Ti = base */
                        if (r == 0) {
                            strcpy(Q[i].op,   "=");
                            strcpy(Q[i].arg1, Q[j].arg1);
                            strcpy(Q[i].arg2, "");
                        } else {
                            /* sinon : Ti = base + r */
                            char buf[20];
                            sprintf(buf, "%d", (int)r);
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

/* ============================================================
   PASSE 2 : PROPAGATION DE COPIE
   Si on a  Ti = Tj  alors on remplace Ti par Tj partout apres.
   Exemple : b = T8  → la prochaine fois qu on lit b, on met T8.

   On utilise deux tableaux simples :
     copie_de[k]  = nom de la variable copiee
     copie_vers[k] = valeur qu elle copie
   ============================================================ */
char copie_de  [100][20];
char copie_vers[100][20];
int  nb_copies;

/* chercher si on connait la valeur copiee de ce nom */
char *trouver_copie(char *nom)
{
    int i;
    for (i = 0; i < nb_copies; i++)
        if (strcmp(copie_de[i], nom) == 0)
            return copie_vers[i];
    return NULL;  /* pas trouve */
}

/* supprimer les copies qui parlent de ce nom */
void supprimer_copies(char *nom)
{
    int i, j;
    for (i = 0; i < nb_copies; i++) {
        if (strcmp(copie_de[i],   nom) == 0 ||
            strcmp(copie_vers[i], nom) == 0) {
            /* decaler le reste du tableau */
            for (j = i; j < nb_copies - 1; j++) {
                strcpy(copie_de[j],   copie_de[j+1]);
                strcpy(copie_vers[j], copie_vers[j+1]);
            }
            nb_copies--;
            i--;
        }
    }
}

void propagation_copie()
{
    int i;
    char *v;
    nb_copies = 0;

    for (i = 0; i < qc; i++) {

        /* remplacer arg1 si on connait sa copie */
        v = trouver_copie(Q[i].arg1);
        if (v != NULL) strcpy(Q[i].arg1, v);

        /* remplacer arg2 si on connait sa copie */
        if (Q[i].arg2[0] != '\0') {
            v = trouver_copie(Q[i].arg2);
            if (v != NULL) strcpy(Q[i].arg2, v);
        }

        /* si ce quad est une copie simple  Ti = Tj  → memoriser */
        if (strcmp(Q[i].op, "=") == 0 &&
            Q[i].arg2[0] == '\0'      &&
            !est_nombre(Q[i].arg1)) {

            supprimer_copies(Q[i].res);
            strcpy(copie_de  [nb_copies], Q[i].res);
            strcpy(copie_vers [nb_copies], Q[i].arg1);
            nb_copies++;

        } else {
            /* le resultat est recalcule → invalider les copies le concernant */
            if (Q[i].res[0] != '\0')
                supprimer_copies(Q[i].res);
        }
    }
}

/* ============================================================
   PASSE 3 : ELIMINATION DES EXPRESSIONS REDONDANTES
   Si  a op b  a deja ete calcule dans Ti,
   et que a et b n ont pas change depuis,
   on remplace le nouveau calcul par  Tj = Ti.

   On utilise des tableaux simples :
     expr_op[k], expr_a1[k], expr_a2[k] = l expression
     expr_res[k]                         = le temporaire qui la contient
   ============================================================ */
char expr_op [100][10];
char expr_a1 [100][20];
char expr_a2 [100][20];
char expr_res[100][20];
int  nb_exprs;

/* chercher si cette expression a deja ete calculee */
char *trouver_expression(char *op, char *a1, char *a2)
{
    int i;
    for (i = 0; i < nb_exprs; i++)
        if (strcmp(expr_op[i], op) == 0 &&
            strcmp(expr_a1[i], a1) == 0 &&
            strcmp(expr_a2[i], a2) == 0)
            return expr_res[i];
    return NULL;  /* pas trouvee */
}

/* supprimer les expressions qui utilisent ce nom */
void supprimer_expressions(char *nom)
{
    int i, j;
    for (i = 0; i < nb_exprs; i++) {
        if (strcmp(expr_a1[i],  nom) == 0 ||
            strcmp(expr_a2[i],  nom) == 0 ||
            strcmp(expr_res[i], nom) == 0) {
            for (j = i; j < nb_exprs - 1; j++) {
                strcpy(expr_op [j], expr_op [j+1]);
                strcpy(expr_a1 [j], expr_a1 [j+1]);
                strcpy(expr_a2 [j], expr_a2 [j+1]);
                strcpy(expr_res[j], expr_res[j+1]);
            }
            nb_exprs--;
            i--;
        }
    }
}

void elimination_expressions_redondantes()
{
    int i;
    char *deja;
    nb_exprs = 0;

    for (i = 0; i < qc; i++) {

        /* si ce quad modifie une variable → invalider les expressions */
        if (Q[i].res[0] != '\0')
            supprimer_expressions(Q[i].res);

        /* si c est une operation arithmetique */
        if (strcmp(Q[i].op, "+") == 0 || strcmp(Q[i].op, "-") == 0 ||
            strcmp(Q[i].op, "*") == 0 || strcmp(Q[i].op, "/") == 0) {

            deja = trouver_expression(Q[i].op, Q[i].arg1, Q[i].arg2);

            if (deja != NULL) {
                /* expression deja calculee → remplacer par copie */
                strcpy(Q[i].op,   "=");
                strcpy(Q[i].arg1, deja);
                strcpy(Q[i].arg2, "");
            } else {
                /* nouvelle expression → la memoriser */
                strcpy(expr_op [nb_exprs], Q[i].op);
                strcpy(expr_a1 [nb_exprs], Q[i].arg1);
                strcpy(expr_a2 [nb_exprs], Q[i].arg2);
                strcpy(expr_res[nb_exprs], Q[i].res);
                nb_exprs++;
            }
        }
    }
}

/* ============================================================
   PASSE 4 : ELIMINATION DU CODE MORT
   Un quad est mort si son resultat n est jamais relu apres lui.
   On le supprime car il ne sert a rien.
   ============================================================ */

/* retourne 1 si nom est utilise dans un quad apres la position from */
int est_utilise_apres(int from, char *nom)
{
    int i;
    for (i = from + 1; i < qc; i++) {
        if (strcmp(Q[i].arg1, nom) == 0) return 1;  /* utilise en arg1 */
        if (strcmp(Q[i].arg2, nom) == 0) return 1;  /* utilise en arg2 */
        if (strcmp(Q[i].res,  nom) == 0) return 0;  /* recrit avant relu */
    }
    return 0;  /* jamais lu */
}

void elimination_code_mort()
{
    int mort[MAX_Q] = {0};
    int i, j, cible;
    int nouvel_index[MAX_Q];
    int nb_vivants;
    quad tmp[MAX_Q];

    /* etape 1 : marquer les quads morts */
    for (i = 0; i < qc; i++) {
        /* ne jamais supprimer ces instructions */
        if (strcmp(Q[i].op, "WRITE") == 0) continue;
        if (strcmp(Q[i].op, "BR")    == 0) continue;
        if (strcmp(Q[i].op, "BZ")    == 0) continue;
        if (strcmp(Q[i].op, "=[]")   == 0) continue;

        /* si le resultat n est jamais relu → quad mort */
        if (Q[i].res[0] != '\0' && !est_utilise_apres(i, Q[i].res))
            mort[i] = 1;
    }

    /* etape 2 : calculer les nouveaux indices apres suppression */
    nb_vivants = 0;
    for (i = 0; i < qc; i++) {
        if (mort[i] == 0)
            nouvel_index[i] = nb_vivants++;
        else
            nouvel_index[i] = -1;
    }

    /* etape 3 : corriger les cibles de BZ et BR */
    for (i = 0; i < qc; i++) {
        if (mort[i] == 0 &&
            (strcmp(Q[i].op, "BZ") == 0 || strcmp(Q[i].op, "BR") == 0)) {

            cible = atoi(Q[i].res);
            /* avancer jusqu au premier quad vivant */
            while (cible < qc && mort[cible] == 1) cible++;

            char buf[20];
            if (cible < qc)
                sprintf(buf, "%d", nouvel_index[cible]);
            else
                sprintf(buf, "%d", nb_vivants);
            strcpy(Q[i].res, buf);
        }
    }

    /* etape 4 : copier seulement les quads vivants */
    nb_vivants = 0;
    for (i = 0; i < qc; i++)
        if (mort[i] == 0)
            tmp[nb_vivants++] = Q[i];

    for (i = 0; i < nb_vivants; i++)
        Q[i] = tmp[i];
    qc = nb_vivants;
}

/* ============================================================
   POINT D ENTREE : OPTIMISER
   On applique les 4 passes en boucle.
   On s arrete quand rien ne change
   (quads_avant.txt == quads_apres.txt).
   ============================================================ */
void optimiser()
{
    int total_avant = qc;
    int iteration   = 0;

    printf("\n======== Optimisation du code ========\n");
    printf("Quadruplets initiaux : %d\n", qc);

    do {
        iteration++;
        printf("\n  >> Iteration %d :\n", iteration);

        /* ecrire l etat AVANT la passe */
        ecrire_quads("quads_avant.txt");

        /* PASSE 1 */
        sauvegarder();
        simplification_algebrique();
        afficher_changements("Simplification algebrique");

        /* PASSE 2 */
        sauvegarder();
        propagation_copie();
        afficher_changements("Propagation de copie");

        /* PASSE 3 */
        sauvegarder();
        elimination_expressions_redondantes();
        afficher_changements("Elimination expressions redondantes");

        /* PASSE 4 */
        sauvegarder();
        elimination_code_mort();
        afficher_changements("Elimination code mort");

        printf("  => Total : %d quadruplets\n", qc);

        /* ecrire l etat APRES la passe */
        ecrire_quads("quads_apres.txt");

    /* continuer tant que quelque chose a change */
    } while (!fichiers_identiques("quads_avant.txt", "quads_apres.txt")
             && iteration < 20);

    printf("\n======== Resultat final ========\n");
    printf("Convergence en %d iteration(s)\n", iteration);
    printf("Quadruplets avant : %d\n", total_avant);
    printf("Quadruplets apres : %d\n", qc);
    printf("Quadruplets elimines : %d\n", total_avant - qc);

    printf("\n======== Quadruplets Optimises ========\n");
    for (int i = 0; i < qc; i++)
        printf("%d : ( %s , %s , %s , %s )\n",
               i, Q[i].op, Q[i].arg1, Q[i].arg2, Q[i].res);
}