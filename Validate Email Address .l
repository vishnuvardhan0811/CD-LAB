/* Exp27: LEX - Validate email address */
%{
%}
%%
[a-zA-Z0-9._%+-]+"@"[a-zA-Z0-9.-]+"."[a-zA-Z]{2,}   { printf("VALID email  : %s\n",yytext); }
[^ \t\n]+                                               { printf("INVALID email: %s\n",yytext); }
[ \t\n]                                                 { /* skip */ }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter email addresses (Ctrl+D to end):\n");
    yylex();
    return 0;
}
