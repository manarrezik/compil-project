#ifndef TS_H
#define TS_H

typedef struct symbole
{
    char nom[20];
    char type[10];
    float valeur;
    int taille;
    float *tabValeurs;   
    struct symbole *suivant;
} symbole;

void inserer(char *nom, char *type);
symbole* rechercher(char *nom);
void afficher_ts();

#endif