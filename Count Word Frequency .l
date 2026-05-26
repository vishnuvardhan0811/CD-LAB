/* Exp38: LEX - Count frequency of a given word in a sentence */
%{
#include<string.h>
int freq=0;
char target[50];
%}
%%
[a-zA-Z]+   { if(!strcasecmp(yytext,target)) freq++; }
.|\n        { /* ignore */ }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter the word to search: ");
    scanf("%s",target);
    printf("Enter the sentence (Ctrl+D to end):\n");
    yylex();
    printf("\nFrequency of '%s': %d\n",target,freq);
    return 0;
}
