#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"

#define SIZE 100

symbole *table[SIZE];

int hash(char *nom)
{
    int i, h = 0;
    for(i = 0; i < strlen(nom); i++)
        h += nom[i];
    return h % SIZE;
}

symbole* rechercher(char *nom)
{
    int h = hash(nom);
    symbole *s = table[h];

    while(s)
    {
        if(strcmp(s->nom, nom) == 0)
            return s;
        s = s->suivant;
    }
    return NULL;
}

void inserer(char *nom, char *type)
{
    if(rechercher(nom) != NULL)
    {
        printf("Erreur semantique : double declaration %s\n", nom);
        return;
    }

    int h = hash(nom);
    symbole *new = malloc(sizeof(symbole));

    strcpy(new->nom, nom);
    strcpy(new->type, type);
    new->valeur = 0;
    new->taille = 0;
    new->tabValeurs = NULL;

    new->suivant = table[h];
    table[h] = new;
}

void afficher_ts()
{
    int i;
    symbole *s;

    printf("\n===== Table des symboles =====\n");

    for(i = 0; i < SIZE; i++)
    {
        s = table[i];
        while(s)
        {
            if(s->taille > 0)
            {
                printf("Nom: %s | Type: Tableau de %s | Taille: %d\n",
                       s->nom, s->type, s->taille);
            }
            else
            {
                printf("Nom: %s | Type: %s | Valeur: %.2f\n",
                       s->nom, s->type, s->valeur);
            }
            s = s->suivant;
        }
    }
}