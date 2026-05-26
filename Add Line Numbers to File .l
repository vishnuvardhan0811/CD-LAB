/* Exp24: LEX - Add line numbers to C program */
%{
int line=1;
%}
%%
\n      { printf("%d\t\n",line); line++; }
[^\n]+  { printf("%d\t%s",line,yytext); }
%%
int yywrap(){ return 1; }
int main(int argc,char *argv[]){
    if(argc>1) yyin=fopen(argv[1],"r");
    printf("1\t");
    yylex();
    return 0;
}
