#include <stdio.h>
#include <string.h>
#include "quad.h"
#include <stdlib.h>
#include "ts.h"

quad Q[1000];
int qc = 0;

void maj_quad(int index, char *val)
{
    strcpy(Q[index].res, val);
}
void ajouter_quad(char *op, char *arg1, char *arg2, char *res)
{
    strcpy(Q[qc].op, op);
    strcpy(Q[qc].arg1, arg1);
    strcpy(Q[qc].arg2, arg2);
    strcpy(Q[qc].res, res);
    qc++;
}

void afficher_quad()
{
    int i;
    printf("\n===== Quadruplets =====\n");
    for(i = 0; i < qc; i++)
    {
        printf("%d : ( %s , %s , %s , %s )\n",
               i,
               Q[i].op,
               Q[i].arg1,
               Q[i].arg2,
               Q[i].res);
    }
}
float get_val(char *x)
{
    symbole *s = rechercher(x);
    if(s) return s->valeur;
    return atof(x);
}
void executer_quads()
{
    int pc = 0;

    while(pc < qc)
    {
        /* ============ OPERATIONS ARITHMETIQUES ============ */
        if(strcmp(Q[pc].op, "+") == 0)
        {
            float v = get_val(Q[pc].arg1) + get_val(Q[pc].arg2);

            symbole *s = rechercher(Q[pc].res);
            if(s) s->valeur = v; // uniquement si res est une vraie variable
        }
        else if(strcmp(Q[pc].op, "-") == 0)
        {
            float v = get_val(Q[pc].arg1) - get_val(Q[pc].arg2);
            symbole *s = rechercher(Q[pc].res);
            if(s) s->valeur = v;
        }
        else if(strcmp(Q[pc].op, "*") == 0)
        {
            float v = get_val(Q[pc].arg1) * get_val(Q[pc].arg2);
            symbole *s = rechercher(Q[pc].res);
            if(s) s->valeur = v;
        }
        else if(strcmp(Q[pc].op, "/") == 0)
        {
            float d = get_val(Q[pc].arg2);
            if(d == 0)
            {
                printf("Erreur execution : division par zero\n");
                pc++;
                continue;
            }
            float v = get_val(Q[pc].arg1) / d;
            symbole *s = rechercher(Q[pc].res);
            if(s) s->valeur = v;
        }

        /* ============ AFFECTATION ============ */
        else if(strcmp(Q[pc].op, "=") == 0)
        {
            symbole *s = rechercher(Q[pc].res);
            if(s) s->valeur = get_val(Q[pc].arg1);
        }

        /* ============ COMPARAISONS ============ */
        else if(strcmp(Q[pc].op, ">") == 0 ||
                strcmp(Q[pc].op, "<") == 0 ||
                strcmp(Q[pc].op, ">=") == 0 ||
                strcmp(Q[pc].op, "<=") == 0 ||
                strcmp(Q[pc].op, "==") == 0 ||
                strcmp(Q[pc].op, "!=") == 0)
        {
            float v = 0;
            if(strcmp(Q[pc].op, ">") == 0) v = (get_val(Q[pc].arg1) > get_val(Q[pc].arg2)) ? 1 : 0;
            else if(strcmp(Q[pc].op, "<") == 0) v = (get_val(Q[pc].arg1) < get_val(Q[pc].arg2)) ? 1 : 0;
            else if(strcmp(Q[pc].op, ">=") == 0) v = (get_val(Q[pc].arg1) >= get_val(Q[pc].arg2)) ? 1 : 0;
            else if(strcmp(Q[pc].op, "<=") == 0) v = (get_val(Q[pc].arg1) <= get_val(Q[pc].arg2)) ? 1 : 0;
            else if(strcmp(Q[pc].op, "==") == 0) v = (get_val(Q[pc].arg1) == get_val(Q[pc].arg2)) ? 1 : 0;
            else if(strcmp(Q[pc].op, "!=") == 0) v = (get_val(Q[pc].arg1) != get_val(Q[pc].arg2)) ? 1 : 0;

            // NE PAS insérer les temporaires dans la table des symboles
            // stocker temporaire dans res si nécessaire, sinon ignorer
        }

        /* ============ BRANCHES ============ */
        else if(strcmp(Q[pc].op, "BZ") == 0)
        {
            if(get_val(Q[pc].arg1) == 0)
            {
                pc = atoi(Q[pc].res);
                continue;
            }
        }
        else if(strcmp(Q[pc].op, "BR") == 0)
        {
            pc = atoi(Q[pc].res);
            continue;
        }

        /* ============ ECRITURE ============ */
        else if(strcmp(Q[pc].op, "WRITE") == 0)
        {
            printf("%s = %f\n", Q[pc].arg1, get_val(Q[pc].arg1));
        }

        pc++;
    }
}