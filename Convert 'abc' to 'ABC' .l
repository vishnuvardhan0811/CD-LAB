/* Exp28: LEX - Convert substring 'abc' to 'ABC' */
%{
%}
%%
"abc"       { printf("ABC"); }
.|\n        { printf("%s",yytext); }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter string (Ctrl+D to end):\n");
    yylex();
    return 0;
}
