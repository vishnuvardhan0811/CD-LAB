/* Exp33: LEX - Identify and count positive and negative numbers */
%{
int pos=0,neg=0;
%}
%%
"-"[0-9]+(\.[0-9]+)?    { printf("Negative: %s\n",yytext); neg++; }
[0-9]+(\.[0-9]+)?       { printf("Positive: %s\n",yytext); pos++; }
[ \t\n,]                { /* skip */ }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter numbers (Ctrl+D to end):\n");
    yylex();
    printf("\nPositive: %d  Negative: %d\n",pos,neg);
    return 0;
}
