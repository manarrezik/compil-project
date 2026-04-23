%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"
#include "quad.h"
#include "optim.h"

extern int ligne;
extern int colonne;
extern char* yytext;
extern int qc;

int temp = 1;
char currentType[10];

char* newTemp()
{
    static char tmp[20];
    sprintf(tmp, "T%d", temp++);
    return strdup(tmp);
}
void yyerror(char *s);
int yylex();
%}

%union {
    int   entier;
    float reel;
    char* str;
    struct {
        char nom[20];
        char type[10];
    } expr;
}

%token PROGRAM DECL ENDDECL BEGIN_ END_
%token INTEGER FLOAT CONST
%token IF ELSE FOR WHILE WRITE
%token PLUS MOINS MUL DIV
%token AND OR NOT
%token GT LT GE LE EQ NE
%token AFF
%token PV VIRG DP
%token PO PF AO AF CO CF
%token <entier> ENTIER
%token <reel>   REEL
%token <str>    IDF

%type <expr> expression
%type <str>  type
%type <str>  liste_idf
%type <reel> valeur
%type <expr> condition_logique
%type <entier> condition
%type <entier> boucle_for
%type <entier> boucle_while

%nonassoc  NOT
%left  OR
%left  AND
%left  EQ NE
%left  GT LT GE LE
%left  PLUS MOINS
%left  MUL DIV


%%

programme:
    PROGRAM IDF DECL declarations ENDDECL BEGIN_ instructions END_
;

declarations:
    declarations declaration
  |
;

declaration:
    type DP
    {
        strcpy(currentType, $1);
    }
    liste_idf PV

  | CONST IDF AFF valeur PV
    {
        symbole *s = rechercher($2);
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, $2);
        else {
            if (s == NULL) inserer_idf($2, "CONST");
            s = rechercher($2);
            strcpy(s->code, "CONST");
            strcpy(s->type, "CONST");
            s->valeur   = $4;
            s->init     = 1;
            s->declared = 1;
        }
    }
;

type:
    INTEGER { $$ = "INTEGER"; }
  | FLOAT   { $$ = "FLOAT";   }
;

liste_idf:
    IDF
    {
        symbole *s = rechercher($1);
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, $1);
        else {
            if (s == NULL) inserer_idf($1, "IDF");
            s = rechercher($1);
            strcpy(s->type, currentType);
            s->declared = 1;
        }
    }

  | IDF AFF valeur
    {
        symbole *s = rechercher($1);
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, $1);
        else {
            if (s == NULL) inserer_idf($1, "IDF");
            s = rechercher($1);
            strcpy(s->type, currentType);
            s->valeur   = $3;
            s->init     = 1;
            s->declared = 1;
            char buf[20];
            if (strcmp(currentType, "FLOAT") == 0)
                sprintf(buf, "%f", $3);
            else
                sprintf(buf, "%d", (int)$3);
            ajouter_quad("=", buf, "", $1);
        }
    }

  | IDF CO ENTIER CF
    {
        symbole *s = rechercher($1);
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, $1);
        else {
            if (s == NULL) inserer_idf($1, "IDF");
            s = rechercher($1);
            strcpy(s->type, currentType);
            s->declared = 1;
            if ($3 <= 0)
                printf("Erreur Semantique : ligne %d , colonne %d , element %s (taille tableau invalide)\n",
                       ligne, colonne, $1);
            else {
                s->taille     = $3;
                s->tabValeurs = malloc(sizeof(float) * $3);
            }
        }
    }

  | liste_idf VIRG IDF
    {
        symbole *s = rechercher($3);
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, $3);
        else {
            if (s == NULL) inserer_idf($3, "IDF");
            s = rechercher($3);
            strcpy(s->type, currentType);
            s->declared = 1;
        }
    }

  | liste_idf VIRG IDF AFF valeur
    {
        symbole *s = rechercher($3);
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, $3);
        else {
            if (s == NULL) inserer_idf($3, "IDF");
            s = rechercher($3);
            strcpy(s->type, currentType);
            s->valeur   = $5;
            s->init     = 1;
            s->declared = 1;
            char buf[20];
            if (strcmp(currentType, "FLOAT") == 0)
                sprintf(buf, "%f", $5);
            else
                sprintf(buf, "%d", (int)$5);
            ajouter_quad("=", buf, "", $3);
        }
    }

  | liste_idf VIRG IDF CO ENTIER CF
    {
        symbole *s = rechercher($3);
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, $3);
        else {
            if (s == NULL) inserer_idf($3, "IDF");
            s = rechercher($3);
            strcpy(s->type, currentType);
            s->declared = 1;
            if ($5 <= 0)
                printf("Erreur Semantique : ligne %d , colonne %d , element %s (taille tableau invalide)\n",
                       ligne, colonne, $3);
            else {
                s->taille     = $5;
                s->tabValeurs = malloc(sizeof(float) * $5);
            }
        }
    }
;

valeur:
    ENTIER { $$ = $1; }
  | REEL   { $$ = $1; }
;

instructions:
    instructions instruction
  |
;

instruction:
    affectation
  | condition
  | boucle_for
  | boucle_while
  | ecriture
;

affectation:
    IDF AFF expression PV
    {
        symbole *s = rechercher($1);
        if (s == NULL || s->declared == 0)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (variable non declaree)\n",
                   ligne, colonne, $1);
        else if (strcmp(s->type, "CONST") == 0)
            printf("Erreur Semantique : ligne %d , colonne %d , modification d'une constante %s\n",
                   ligne, colonne, $1);
        else if (strcmp(s->type, $3.type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (incompatibilite de type)\n",
                   ligne, colonne, $1);
        else
            ajouter_quad("=", $3.nom, "", $1);
    }

  | IDF CO ENTIER CF AFF expression PV
    {
        symbole *s = rechercher($1);
        if (s == NULL || s->declared == 0)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (tableau non declare)\n",
                   ligne, colonne, $1);
        else if (s->taille == 0)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (n'est pas un tableau)\n",
                   ligne, colonne, $1);
        else if ($3 < 0 || $3 >= s->taille)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (depassement tableau)\n",
                   ligne, colonne, $1);
        else if (strcmp(s->type, "CONST") == 0)
            printf("Erreur Semantique : ligne %d , colonne %d , modification d'une constante %s\n",
                   ligne, colonne, $1);
        else if (strcmp(s->type, $6.type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (type tableau invalide)\n",
                   ligne, colonne, $1);
        else {
            char index[20];
            sprintf(index, "%d", $3);
            ajouter_quad("=[]", $1, index, $6.nom);
        }
    }
;

condition:
    IF PO condition_logique PF
    {
        char t[20];
        sprintf(t, "%d", -1);
        ajouter_quad("BZ", $3.nom, "", t);
        $<entier>$ = qc - 1;
    }
    AO instructions AF
    {
        char t[20];
        sprintf(t, "%d", -1);
        ajouter_quad("BR", "", "", t);
        int saut = qc - 1;
        char finif[20];
        sprintf(finif, "%d", qc);
        maj_quad($<entier>5, finif);
        $<entier>$ = saut;
    }
    ELSE AO instructions AF
    {
        char fin[20];
        sprintf(fin, "%d", qc);
        maj_quad($<entier>9, fin);
    }
;

boucle_for:
    FOR PO IDF DP ENTIER DP ENTIER DP ENTIER PF
    {
        int debut = qc;
        char finv[20];
        sprintf(finv, "%d", $7);
        char *t = newTemp();
        ajouter_quad("<=", $3, finv, t);
        char tmp2[20];
        sprintf(tmp2, "%d", -1);
        ajouter_quad("BZ", t, "", tmp2);
        $<entier>$  = qc - 1;
        $<entier>2  = debut;
    }
    AO instructions AF
    {
        char step[20];
        sprintf(step, "%d", $9);
        char *t = newTemp();
        ajouter_quad("+", $3, step, t);
        ajouter_quad("=", t, "", $3);
        char retour[20];
        sprintf(retour, "%d", $<entier>2);
        ajouter_quad("BR", "", "", retour);
        char fin[20];
        sprintf(fin, "%d", qc);
        maj_quad($<entier>11, fin);
    }
;

boucle_while:
    WHILE PO
    {
        $<entier>$ = qc;
    }
    condition_logique PF
    {
        char t[20];
        sprintf(t, "%d", -1);
        ajouter_quad("BZ", $4.nom, "", t);
        $<entier>$ = qc - 1;
    }
    AO instructions AF
    {
        char retour[20];
        sprintf(retour, "%d", $<entier>3);
        ajouter_quad("BR", "", "", retour);
        char fin[20];
        sprintf(fin, "%d", qc);
        maj_quad($<entier>6, fin);
    }
;

ecriture:
    WRITE PO IDF PF PV
    {
        symbole *s = rechercher($3);
        if (s == NULL || s->declared == 0)
            printf("Erreur Semantique : ligne %d , colonne %d , variable non declaree\n",
                   ligne, colonne);
        else
            ajouter_quad("WRITE", $3, "", "");
    }
;

expression:
    expression PLUS expression
    {
        if (strcmp($1.type, $3.type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , incompatibilite de type\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("+", $1.nom, $3.nom, t);
        strcpy($$.nom, t);
        strcpy($$.type, $1.type);
    }
  | expression MOINS expression
    {
        if (strcmp($1.type, $3.type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , incompatibilite de type\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("-", $1.nom, $3.nom, t);
        strcpy($$.nom, t);
        strcpy($$.type, $1.type);
    }
  | expression MUL expression
    {
        if (strcmp($1.type, $3.type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , incompatibilite de type\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("*", $1.nom, $3.nom, t);
        strcpy($$.nom, t);
        strcpy($$.type, $1.type);
    }
  | expression DIV expression
    {
        if (strcmp($3.nom, "0") == 0 || strcmp($3.nom, "0.0") == 0) {
            printf("Erreur Semantique : ligne %d , colonne %d , division par zero\n",
                   ligne, colonne);
            strcpy($$.nom, "0");
            strcpy($$.type, $1.type);
        } else if (strcmp($1.type, $3.type) != 0) {
            printf("Erreur Semantique : incompatibilite de type\n");
            strcpy($$.nom, "0");
            strcpy($$.type, $1.type);
        } else {
            char *t = newTemp();
            ajouter_quad("/", $1.nom, $3.nom, t);
            strcpy($$.nom, t);
            strcpy($$.type, $1.type);
        }
    }
  | PO expression PF
    {
        strcpy($$.nom,  $2.nom);
        strcpy($$.type, $2.type);
    }
  | IDF
    {
        symbole *s = rechercher($1);
        if (s == NULL || s->declared == 0) {
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (variable non declaree)\n",
                   ligne, colonne, $1);
            strcpy($$.nom,  $1);
            strcpy($$.type, "INTEGER");
        } else {
            strcpy($$.nom,  $1);
            strcpy($$.type, s->type);
        }
    }
  | ENTIER
    {
        if ($1 < -32768 || $1 > 32767)
            printf("Erreur Semantique : ligne %d , colonne %d , entier hors intervalle\n",
                   ligne, colonne);
        char buffer[20];
        sprintf(buffer, "%d", $1);
        strcpy($$.nom,  buffer);
        strcpy($$.type, "INTEGER");
    }
  | REEL
    {
        char buffer[20];
        sprintf(buffer, "%f", $1);
        strcpy($$.nom,  buffer);
        strcpy($$.type, "FLOAT");
    }
;

condition_logique:
    expression GT expression
    {
        if (strcmp($1.type, $3.type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , comparaison entre types differents\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad(">", $1.nom, $3.nom, t);
        strcpy($$.nom, t); strcpy($$.type, "INTEGER");
    }
  | expression LT expression
    {
        if (strcmp($1.type, $3.type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , comparaison entre types differents\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("<", $1.nom, $3.nom, t);
        strcpy($$.nom, t); strcpy($$.type, "INTEGER");
    }
  | expression GE expression
    {
        if (strcmp($1.type, $3.type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , comparaison entre types differents\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad(">=", $1.nom, $3.nom, t);
        strcpy($$.nom, t); strcpy($$.type, "INTEGER");
    }
  | expression LE expression
    {
        if (strcmp($1.type, $3.type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , comparaison entre types differents\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("<=", $1.nom, $3.nom, t);
        strcpy($$.nom, t); strcpy($$.type, "INTEGER");
    }
  | expression EQ expression
    {
        if (strcmp($1.type, $3.type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , comparaison entre types differents\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("==", $1.nom, $3.nom, t);
        strcpy($$.nom, t); strcpy($$.type, "INTEGER");
    }
  | expression NE expression
    {
        if (strcmp($1.type, $3.type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , comparaison entre types differents\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("!=", $1.nom, $3.nom, t);
        strcpy($$.nom, t); strcpy($$.type, "INTEGER");
    }
;

%%

void yyerror(char *s)
{
    if (strcmp(yytext, ")") == 0)
        printf("Erreur Syntaxique : parenthese fermante sans ouvrante ligne %d colonne %d\n",
               ligne, colonne);
    else if (strcmp(yytext, "(") == 0)
        printf("Erreur Syntaxique : parenthese ouvrante sans fermante ligne %d colonne %d\n",
               ligne, colonne);
    else
        printf("Erreur Syntaxique : ligne %d , colonne %d , element %s\n",
               ligne, colonne, yytext);
}

int main()
{
    yyparse();
    afficher_ts(1);
    afficher_quad();
    optimiser();
    return 0;
}
