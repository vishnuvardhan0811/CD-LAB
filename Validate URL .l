/* Exp34: LEX - Validate URL */
%{
%}
%%
(https?|ftp)"://"[a-zA-Z0-9._~:/?#[\]@!$&'()*+,;=%\-]+ {
    printf("VALID URL  : %s\n",yytext);
}
[^ \t\n]+   { printf("INVALID URL: %s\n",yytext); }
[ \t\n]     { /* skip */ }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter URLs (Ctrl+D to end):\n");
    yylex();
    return 0;
}
