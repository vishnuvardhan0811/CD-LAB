/* Exp32: LEX - Separate keywords and identifiers */
%{
int kc=0,ic=0;
%}
%%
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while" {
    printf("Keyword    : %s\n",yytext); kc++;
}
[a-zA-Z_][a-zA-Z0-9_]*  { printf("Identifier : %s\n",yytext); ic++; }
.|\n    { /* ignore */ }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter C code (Ctrl+D to end):\n");
    yylex();
    printf("\nKeywords: %d  Identifiers: %d\n",kc,ic);
    return 0;
}
