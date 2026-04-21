#include <stdio.h>
#include <string.h>
#include "quad.h"

quad Q[1000];
int qc = 0;

void maj_quad(int index, char *val)
{
    strcpy(Q[index].res, val);
}

void ajouter_quad(char *op, char *arg1, char *arg2, char *res)
{
    strcpy(Q[qc].op,   op);
    strcpy(Q[qc].arg1, arg1);
    strcpy(Q[qc].arg2, arg2);
    strcpy(Q[qc].res,  res);
    qc++;
}

void afficher_quad()
{
    int i;
    printf("\n======== Quadruplets ========\n");
    for (i = 0; i < qc; i++)
        printf("%d : ( %s , %s , %s , %s )\n",
               i, Q[i].op, Q[i].arg1, Q[i].arg2, Q[i].res);
}
