/* Exp36: LEX - Check whether given input is a digit or not */
%{
%}
%%
[0-9]       { printf("'%s' is a DIGIT\n",yytext); }
[^ \t\n]    { printf("'%s' is NOT a digit\n",yytext); }
[ \t\n]     { /* skip */ }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter characters (Ctrl+D to end):\n");
    yylex();
    return 0;
}
