/* Exp35: LEX - Validate Date of Birth (DD/MM/YYYY or DD-MM-YYYY) */
%{
%}
%%
(0[1-9]|[12][0-9]|3[01])[\/\-](0[1-9]|1[0-2])[\/\-](19|20)[0-9]{2} {
    printf("VALID DOB  : %s\n",yytext);
}
[^ \t\n]+   { printf("INVALID DOB: %s\n",yytext); }
[ \t\n]     { /* skip */ }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter DOB (DD/MM/YYYY, Ctrl+D to end):\n");
    yylex();
    return 0;
}
