%{
#include "syntax.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"

int ligne = 1;
int colonne = 1;

void erreur_lexicale()
{
    printf("Erreur Lexicale : ligne %d , colonne %d , élément %s\n", ligne, colonne, yytext);
}
%}

lettre      [a-zA-Z]
chiffre     [0-9]
idf         {lettre}({lettre}|{chiffre}|_){0,7}
entier      {chiffre}+
reel        {chiffre}+"."{chiffre}+
signeEnt    \([+-]{chiffre}+\)
signeReel   \([+-]{chiffre}+"."{chiffre}+\)
%%

"PROGRAM"      { colonne += yyleng; return PROGRAM; }
"DECL"         { colonne += yyleng; return DECL; }
"ENDDECL"      { colonne += yyleng; return ENDDECL; }
"BEGIN"        { colonne += yyleng; return BEGIN_; }
"END"          { colonne += yyleng; return END_; }
"INTEGER"      { colonne += yyleng; return INTEGER; }
"FLOAT"        { colonne += yyleng; return FLOAT; }
"CONST"        { colonne += yyleng; return CONST; }
"IF"           { colonne += yyleng; return IF; }
"ELSE"         { colonne += yyleng; return ELSE; }
"FOR"          { colonne += yyleng; return FOR; }
"WHILE"        { colonne += yyleng; return WHILE; }
"WRITE"        { colonne += yyleng; return WRITE; }

"=="           { colonne += yyleng; return EQ; }
"!="           { colonne += yyleng; return NE; }
">="           { colonne += yyleng; return GE; }
"<="           { colonne += yyleng; return LE; }
">"            { colonne += yyleng; return GT; }
"<"            { colonne += yyleng; return LT; }

"&&"           { colonne += yyleng; return AND; }
"||"           { colonne += yyleng; return OR; }
"!"            { colonne += yyleng; return NOT; }

"+"            { colonne += yyleng; return PLUS; }
"-"            { colonne += yyleng; return MOINS; }
"*"            { colonne += yyleng; return MUL; }
"/"            { colonne += yyleng; return DIV; }

"="            { colonne += yyleng; return AFF; }

";"            { colonne += yyleng; return PV; }
","            { colonne += yyleng; return VIRG; }
":"            { colonne += yyleng; return DP; }
"("            { colonne += yyleng; return PO; }
")"            { colonne += yyleng; return PF; }
"{"            { colonne += yyleng; return AO; }
"}"            { colonne += yyleng; return AF; }
"["            { colonne += yyleng; return CO; }
"]"            { colonne += yyleng; return CF; }

{signeReel} {
    char temp[20];
    strncpy(temp, yytext + 1, yyleng - 2);
    temp[yyleng - 2] = '\0';

    yylval.reel = atof(temp);
    colonne += yyleng;
    return REEL;
}

{signeEnt} {
    char temp[20];
    strncpy(temp, yytext + 1, yyleng - 2); // enlever '(' et ')'
    temp[yyleng - 2] = '\0';

    yylval.entier = atoi(temp);
    colonne += yyleng;
    return ENTIER;
}

[+-]{chiffre}+ {
    printf("Erreur Lexicale : ligne %d , colonne %d , nombre signe doit etre entre parentheses %s\n", ligne, colonne, yytext);
}
{reel} {
    yylval.reel = atof(yytext);
    colonne += yyleng;
    return REEL;
}

{entier} {
    yylval.entier = atoi(yytext);
    colonne += yyleng;
    return ENTIER;
}
{lettre}({lettre}|{chiffre}|_){8,} {
    printf("Erreur Lexicale : ligne %d , colonne %d , identificateur trop long %s\n", ligne, colonne, yytext);
}
{idf} {
    yylval.str = strdup(yytext);
    colonne += yyleng;
    return IDF;
}

[ \t]      { colonne += yyleng; }
\n         { ligne++; colonne = 1; }

"//".*     ;
"/*"([^*]|[*][^/])*"*/"   ;

. { erreur_lexicale(); colonne += yyleng; }

%%

int yywrap() { return 1; }