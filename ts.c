#include "ts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

symbole* table_idf[SIZE] = {NULL};
simple   table_sep[100];
simple   table_kw[100];
int count_sep = 0;
int count_kw  = 0;

static unsigned int hash(char *nom)
{
    unsigned int h = 0;
    while (*nom) h += (unsigned char)(*nom++);
    return h % SIZE;
}

symbole* rechercher(char *nom)
{
    unsigned int h = hash(nom);
    symbole *s = table_idf[h];
    while (s) {
        if (strcmp(s->nom, nom) == 0) return s;
        s = s->suivant;
    }
    return NULL;
}

void inserer_idf(char *nom, char *code)
{
    if (rechercher(nom) != NULL) return;
    unsigned int h = hash(nom);
    symbole *new = malloc(sizeof(symbole));
    strcpy(new->nom,  nom);
    strcpy(new->code, code);
    strcpy(new->type, "");
    new->valeur     = 0;
    new->init       = 0;
    new->taille     = 0;
    new->tabValeurs = NULL;
    new->declared   = 0;
    new->suivant    = table_idf[h];
    table_idf[h]    = new;
}

void inserer_sep(char *nom, char *code)
{
    for (int i = 0; i < count_sep; i++)
        if (strcmp(table_sep[i].nom, nom) == 0) return;
    strcpy(table_sep[count_sep].nom,  nom);
    strcpy(table_sep[count_sep].code, code);
    count_sep++;
}

void inserer_kw(char *nom, char *code)
{
    for (int i = 0; i < count_kw; i++)
        if (strcmp(table_kw[i].nom, nom) == 0) return;
    strcpy(table_kw[count_kw].nom,  nom);
    strcpy(table_kw[count_kw].code, code);
    count_kw++;
}

void set_type(char *nom, char *type)
{
    symbole *s = rechercher(nom);
    if (s) strcpy(s->type, type);
}

void set_valeur(char *nom, float val)
{
    symbole *s = rechercher(nom);
    if (s) {
        s->valeur = val;
        s->init   = 1;
    }
}

void afficher_ts(int mode)
{
    int i;
    symbole *s;

    printf("\n================ TABLE DES IDENTIFICATEURS ================\n");

    if (mode == 0) {
        printf("%-15s %-10s\n", "Nom", "Code");
        printf("---------------------------\n");
        for (i = 0; i < SIZE; i++) {
            s = table_idf[i];
            while (s) {
                printf("%-15s %-10s\n", s->nom, s->code);
                s = s->suivant;
            }
        }
    } else {
        printf("%-15s %-10s %-12s %-12s %-6s\n",
               "Nom", "Code", "Type", "Valeur", "Taille");
        printf("-------------------------------------------------------\n");
        for (i = 0; i < SIZE; i++) {
            s = table_idf[i];
            while (s) {
                if (s->declared == 1) {
                    char val_buf[20];
                    if (s->init == 1)
                        sprintf(val_buf, "%.2f", s->valeur);
                    else
                        strcpy(val_buf, "-");

                    char taille_buf[10];
                    if (s->taille > 0)
                        sprintf(taille_buf, "%d", s->taille);
                    else
                        strcpy(taille_buf, "-");

                    printf("%-15s %-10s %-12s %-12s %-6s\n",
                           s->nom, s->code, s->type, val_buf, taille_buf);
                }
                s = s->suivant;
            }
        }
    }

    printf("\n================ TABLE DES SEPARATEURS ================\n");
    printf("%-15s %-10s\n", "Nom", "Code");
    printf("--------------------------------\n");
    for (i = 0; i < count_sep; i++)
        printf("%-15s %-10s\n", table_sep[i].nom, table_sep[i].code);

    printf("\n================ TABLE DES MOTS-CLES ================\n");
    printf("%-15s %-10s\n", "Nom", "Code");
    printf("--------------------------------\n");
    for (i = 0; i < count_kw; i++)
        printf("%-15s %-10s\n", table_kw[i].nom, table_kw[i].code);
}