/* Exp40: FLEX - Replace a word with another word in a file */
%{
#include<string.h>
char oldword[50],newword[50];
%}
%%
[a-zA-Z_][a-zA-Z0-9_]*  {
    if(!strcmp(yytext,oldword)) printf("%s",newword);
    else printf("%s",yytext);
}
.|\n    { printf("%s",yytext); }
%%
int yywrap(){ return 1; }
int main(){
    printf("Word to replace: "); scanf("%s",oldword);
    printf("New word       : "); scanf("%s",newword);
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    return 0;
}
