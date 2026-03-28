%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"
#include "quad.h"
extern int ligne;
extern int colonne;
extern char* yytext; 

int temp = 1;
char tmp[20];
char currentType[10];
char* newTemp()
{
    sprintf(tmp, "T%d", temp++);
    return strdup(tmp);
}
void yyerror(char *s);
int yylex();
%}

%union {
    int entier;
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
%token <reel> REEL
%token <str> IDF
%type <expr> expression
%type <str> type
%type <str> liste_idf
%type <reel> valeur

%left OR
%left AND
%left EQ NE
%left GT LT GE LE
%left PLUS MOINS
%left MUL DIV
%right NOT
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
    inserer($2, "CONST");

    symbole *s = rechercher($2);
    if(s != NULL)
    {
        s->valeur = $4; // ✔ correction finale
    }
}
;

type:
      INTEGER { $$ = "INTEGER"; }
    | FLOAT   { $$ = "FLOAT"; }
;

liste_idf:
      IDF
      {
          symbole *s = rechercher($1);
          if(s != NULL)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (double declaration)\n", ligne, colonne, $1);
          else
              inserer($1, currentType);
      }

    | IDF CO ENTIER CF
      {
          symbole *s = rechercher($1);
          if(s != NULL)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (double declaration)\n", ligne, colonne, $1);
          else {
              inserer($1, currentType);
              s = rechercher($1);

              if($3 <= 0)
                  printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (taille tableau invalide)\n", ligne, colonne, $1);
              else
                  s->taille = $3;
                  s->tabValeurs = malloc(sizeof(float) * $3);
          }
      }

    | liste_idf VIRG IDF
      {
          symbole *s = rechercher($3);
          if(s != NULL)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (double declaration)\n", ligne, colonne, $3);
          else
              inserer($3, currentType);
      }

    | liste_idf VIRG IDF CO ENTIER CF
      {
          symbole *s = rechercher($3);
          if(s != NULL)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (double declaration)\n", ligne, colonne, $3);
          else {
              inserer($3, currentType);
              s = rechercher($3);

              if($5 <= 0)
                  printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (taille tableau invalide)\n", ligne, colonne, $3);
              else
                  s->taille = $5;
                  s->tabValeurs = malloc(sizeof(float) * $5);
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

          if(s == NULL)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (variable non declaree)\n", ligne, colonne, $1);

          else if(strcmp(s->type, "CONST") == 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , modification d'une constante %s\n", ligne, colonne, $1);

          else if(strcmp(s->type, $3.type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (incompatibilite de type)\n", ligne, colonne, $1);

          else
          {
              ajouter_quad("=", $3.nom, "", $1);
              if(strcmp($3.type, "INTEGER") == 0)
                  s->valeur = atoi($3.nom);
              else
                  s->valeur = atof($3.nom);
          }
      }

    | IDF CO ENTIER CF AFF expression PV
      {
          symbole *s = rechercher($1);

          if(s == NULL)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (tableau non declare)\n", ligne, colonne, $1);

          else if(s->taille == 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (n'est pas un tableau)\n", ligne, colonne, $1);

          else if($3 < 0 || $3 >= s->taille)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (depassement tableau)\n", ligne, colonne, $1);

          else if(strcmp(s->type, "CONST") == 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , modification d'une constante %s\n", ligne, colonne, $1);

          else if(strcmp(s->type, $6.type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (type tableau invalide)\n", ligne, colonne, $1);

          else
          {
              ajouter_quad("=[]", $1, $6.nom, "TAB");

              if(strcmp($6.type, "INTEGER") == 0)
                  s->tabValeurs[$3] = atoi($6.nom);
              else
                  s->tabValeurs[$3] = atof($6.nom);
          }
      }
;
condition:
    IF PO condition_logique PF AO instructions AF
    ELSE AO instructions AF
;

boucle_for:
    FOR PO IDF DP ENTIER DP ENTIER DP ENTIER PF AO instructions AF
;

boucle_while:
    WHILE PO condition_logique PF AO instructions AF
;

ecriture:
    WRITE PO IDF PF PV
    {
        if(rechercher($3) == NULL)
            printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (variable non declaree)\n", ligne, colonne, $3);
    }
;

expression:
      expression PLUS expression
      {
          if(strcmp($1.type, $3.type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , incompatibilite de type\n", ligne, colonne);

          char *t = newTemp();
          ajouter_quad("+", $1.nom, $3.nom, t);

          strcpy($$.nom, t);
          strcpy($$.type, $1.type);
      }
    | expression MOINS expression
      {
          if(strcmp($1.type, $3.type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , incompatibilite de type\n", ligne, colonne);

          char *t = newTemp();
          ajouter_quad("-", $1.nom, $3.nom, t);

          strcpy($$.nom, t);
          strcpy($$.type, $1.type);
      }
    | expression MUL expression
      {
          if(strcmp($1.type, $3.type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , incompatibilite de type\n", ligne, colonne);

          char *t = newTemp();
          ajouter_quad("*", $1.nom, $3.nom, t);

          strcpy($$.nom, t);
          strcpy($$.type, $1.type);
      }
    | expression DIV expression
{
    if(strcmp($3.nom, "0") == 0)
        printf("Erreur Sémantique : ligne %d , colonne %d , division par zero\n", ligne, colonne);
    else if(strcmp($1.type, $3.type) != 0)
        printf("Erreur Sémantique : ligne %d , colonne %d , incompatibilite de type\n", ligne, colonne);
    else {
        char *t = newTemp();
        ajouter_quad("/", $1.nom, $3.nom, t);
        strcpy($$.nom, t);
        strcpy($$.type, $1.type);
    }
}
| PO expression PF
{
    strcpy($$.nom, $2.nom);
    strcpy($$.type, $2.type);
}
    | IDF
{
    symbole *s = rechercher($1);
    if(s == NULL)
        printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (variable non declaree)\n", ligne, colonne, $1);
    else {
        strcpy($$.nom, $1);
        strcpy($$.type, s->type);
    }
}
    | ENTIER
{
    if($1 < -32768 || $1 > 32767)
        printf("Erreur Sémantique : ligne %d , colonne %d , entier hors intervalle\n", ligne, colonne);

    char buffer[20];
    sprintf(buffer, "%d", $1);
    strcpy($$.nom, buffer);
    strcpy($$.type, "INTEGER");
}
    | REEL
      {
          char buffer[20];
          sprintf(buffer, "%f", $1);

          strcpy($$.nom, buffer);
          strcpy($$.type, "FLOAT");
      }
;

condition_logique:
      expression GT expression
      {
          if(strcmp($1.type, $3.type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , comparaison entre types differents\n", ligne, colonne);
      }
    | expression LT expression
      {
          if(strcmp($1.type, $3.type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , comparaison entre types differents\n", ligne, colonne);
      }
    | expression GE expression
      {
          if(strcmp($1.type, $3.type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , comparaison entre types differents\n", ligne, colonne);
      }
    | expression LE expression
      {
          if(strcmp($1.type, $3.type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , comparaison entre types differents\n", ligne, colonne);
      }
    | expression EQ expression
      {
          if(strcmp($1.type, $3.type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , comparaison entre types differents\n", ligne, colonne);
      }
    | expression NE expression
      {
          if(strcmp($1.type, $3.type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , comparaison entre types differents\n", ligne, colonne);
      }
;

%%

void yyerror(char *s)
{
    if(strcmp(yytext, ")") == 0)
        printf("Erreur Syntaxique : parenthese fermante sans ouvrante ligne %d colonne %d\n", ligne, colonne);
    else if(strcmp(yytext, "(") == 0)
        printf("Erreur Syntaxique : parenthese ouvrante sans fermante ligne %d colonne %d\n", ligne, colonne);
    else
        printf("Erreur Syntaxique : ligne %d , colonne %d , élément %s\n", ligne, colonne, yytext);
}

int main()
{
    yyparse();
    afficher_ts();
    afficher_quad();
    return 0;
}