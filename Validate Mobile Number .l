/* Exp29: LEX - Validate mobile number (10 digits starting with 6-9) */
%{
%}
%%
[6-9][0-9]{9}       { printf("VALID   mobile: %s\n",yytext); }
[0-9]+              { printf("INVALID mobile: %s\n",yytext); }
[ \t\n]             { /* skip */ }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter mobile numbers (Ctrl+D to end):\n");
    yylex();
    return 0;
}
