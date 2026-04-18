#ifndef QUAD_H
#define QUAD_H

typedef struct
{
    char op[10];
    char arg1[20];
    char arg2[20];
    char res[20];
} quad;

extern int qc;

void ajouter_quad(char *op, char *arg1, char *arg2, char *res);
void afficher_quad();
void maj_quad(int index, char *val);

#endif
