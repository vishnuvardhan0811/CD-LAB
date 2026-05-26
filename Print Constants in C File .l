/* Exp20: LEX - Print all constants in C source file */
%{
%}
%%
[0-9]+(\.[0-9]+)?   { printf("Constant: %s\n",yytext); }
.|\n                { /* ignore */ }
%%
int yywrap(){ return 1; }
int main(int argc,char *argv[]){
    if(argc>1) yyin=fopen(argv[1],"r");
    yylex();
    return 0;
}
