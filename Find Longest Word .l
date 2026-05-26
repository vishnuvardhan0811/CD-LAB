/* Exp39: LEX - Find length of longest word */
%{
#include<string.h>
int maxLen=0;
char longest[100]="";
%}
%%
[a-zA-Z]+   {
    if((int)strlen(yytext)>maxLen){
        maxLen=strlen(yytext);
        strcpy(longest,yytext);
    }
}
.|\n    { /* ignore */ }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    printf("\nLongest word: '%s' (length: %d)\n",longest,maxLen);
    return 0;
}
