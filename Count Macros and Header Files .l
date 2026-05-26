/* Exp21: LEX - Count macros and header files */
%{
int macros=0,headers=0;
%}
%%
^"#define"[^\n]*\n  { macros++; printf("Macro    : %s",yytext); }
^"#include"[^\n]*\n { headers++; printf("Header   : %s",yytext); }
.|\n                { /* ignore */ }
%%
int yywrap(){ return 1; }
int main(int argc,char *argv[]){
    if(argc>1) yyin=fopen(argv[1],"r");
    yylex();
    printf("\nTotal Macros : %d\nTotal Headers: %d\n",macros,headers);
    return 0;
}
