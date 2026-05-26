/* Exp26: LEX - Identify capital words */
%{
%}
%%
[A-Z][A-Z0-9_]*     { printf("Capital word: %s\n",yytext); }
.|\n                { /* ignore */ }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter input text (Ctrl+D to end):\n");
    yylex();
    return 0;
}
