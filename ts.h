#ifndef TS_H
#define TS_H

#define SIZE 100

typedef struct symbole {
    char nom[20];
    char code[20];    
    char type[20];    
    float valeur;    
    int   init;      
    int   taille;
    float *tabValeurs;
    int   declared;   
    struct symbole *suivant;
} symbole;

typedef struct {
    char nom[20];
    char code[20];
} simple;

extern symbole* table_idf[SIZE];
extern simple   table_sep[100];
extern simple   table_kw[100];
extern int count_sep, count_kw;

void inserer_idf(char *nom, char *code);
void inserer_sep(char *nom, char *code);
void inserer_kw (char *nom, char *code);

symbole* rechercher(char *nom);
void set_type  (char *nom, char *type);
void set_valeur(char *nom, float val);

void afficher_ts(int mode);

#endif