%{
#include "syntax.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"

int ligne   = 1;
int colonne = 1;

void erreur_lexicale()
{
    printf("Erreur Lexicale : ligne %d , colonne %d , element %s\n",
           ligne, colonne, yytext);
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

"PROGRAM"  { inserer_kw(yytext,"PROGRAM");  colonne+=yyleng; return PROGRAM;  }
"DECL"     { inserer_kw(yytext,"DECL");     colonne+=yyleng; return DECL;     }
"ENDDECL"  { inserer_kw(yytext,"ENDDECL"); colonne+=yyleng; return ENDDECL;  }
"BEGIN"    { inserer_kw(yytext,"BEGIN");    colonne+=yyleng; return BEGIN_;   }
"END"      { inserer_kw(yytext,"END");      colonne+=yyleng; return END_;     }
"INTEGER"  { inserer_kw(yytext,"INTEGER"); colonne+=yyleng; return INTEGER;  }
"FLOAT"    { inserer_kw(yytext,"FLOAT");   colonne+=yyleng; return FLOAT;    }
"CONST"    { inserer_kw(yytext,"CONST");   colonne+=yyleng; return CONST;    }
"IF"       { inserer_kw(yytext,"IF");       colonne+=yyleng; return IF;       }
"ELSE"     { inserer_kw(yytext,"ELSE");     colonne+=yyleng; return ELSE;     }
"FOR"      { inserer_kw(yytext,"FOR");      colonne+=yyleng; return FOR;      }
"WHILE"    { inserer_kw(yytext,"WHILE");    colonne+=yyleng; return WHILE;    }
"WRITE"    { inserer_kw(yytext,"WRITE");    colonne+=yyleng; return WRITE;    }


"=="  { inserer_sep(yytext,"EQ");    colonne+=yyleng; return EQ;    }
"!="  { inserer_sep(yytext,"NE");    colonne+=yyleng; return NE;    }
">="  { inserer_sep(yytext,"GE");    colonne+=yyleng; return GE;    }
"<="  { inserer_sep(yytext,"LE");    colonne+=yyleng; return LE;    }
">"   { inserer_sep(yytext,"GT");    colonne+=yyleng; return GT;    }
"<"   { inserer_sep(yytext,"LT");    colonne+=yyleng; return LT;    }
"&&"  { inserer_sep(yytext,"AND");   colonne+=yyleng; return AND;   }
"||"  { inserer_sep(yytext,"OR");    colonne+=yyleng; return OR;    }
"!"   { inserer_sep(yytext,"NOT");   colonne+=yyleng; return NOT;   }
"+"   { inserer_sep(yytext,"PLUS");  colonne+=yyleng; return PLUS;  }
"-"   { inserer_sep(yytext,"MOINS"); colonne+=yyleng; return MOINS; }
"*"   { inserer_sep(yytext,"MUL");   colonne+=yyleng; return MUL;   }
"/"   { inserer_sep(yytext,"DIV");   colonne+=yyleng; return DIV;   }
"="   { inserer_sep(yytext,"AFF");   colonne+=yyleng; return AFF;   }
";"   { inserer_sep(yytext,"PV");    colonne+=yyleng; return PV;    }
","   { inserer_sep(yytext,"VIRG");  colonne+=yyleng; return VIRG;  }
":"   { inserer_sep(yytext,"DP");    colonne+=yyleng; return DP;    }
"("   { inserer_sep(yytext,"PO");    colonne+=yyleng; return PO;    }
")"   { inserer_sep(yytext,"PF");    colonne+=yyleng; return PF;    }
"{"   { inserer_sep(yytext,"AO");    colonne+=yyleng; return AO;    }
"}"   { inserer_sep(yytext,"AF");    colonne+=yyleng; return AF;    }
"["   { inserer_sep(yytext,"CO");    colonne+=yyleng; return CO;    }
"]"   { inserer_sep(yytext,"CF");    colonne+=yyleng; return CF;    }


{signeReel} {
    char temp[20];
    strncpy(temp, yytext+1, yyleng-2);
    temp[yyleng-2] = '\0';
    yylval.reel = atof(temp);
    colonne += yyleng;
    return REEL;
}
{signeEnt} {
    char temp[20];
    strncpy(temp, yytext+1, yyleng-2);
    temp[yyleng-2] = '\0';
    yylval.entier = atoi(temp);
    colonne += yyleng;
    return ENTIER;
}

[+-]{chiffre}+ {
    printf("Erreur Lexicale : ligne %d , colonne %d , nombre signe sans parentheses %s\n",
           ligne, colonne, yytext);
    colonne += yyleng;
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
    printf("Erreur Lexicale : ligne %d , colonne %d , identificateur trop long %s\n",
           ligne, colonne, yytext);
    colonne += yyleng;
}
{idf} {
    yylval.str = strdup(yytext);
    inserer_idf(yytext, "IDF");  
    colonne += yyleng;
    return IDF;
}

[ \t]                          { colonne += yyleng; }
\n                             { ligne++; colonne = 1; }
"//".*                         ;
"/*"([^*]|[*][^/])*"*/"       ;

. { erreur_lexicale(); colonne += yyleng; }

%%
int yywrap() { return 1; }