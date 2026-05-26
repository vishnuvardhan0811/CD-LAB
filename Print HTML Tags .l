/* Exp23: LEX - Print all HTML tags */
%{
%}
%%
"<"[^>]*">"     { printf("Tag: %s\n",yytext); }
.|\n            { /* ignore */ }
%%
int yywrap(){ return 1; }
int main(int argc,char *argv[]){
    if(argc>1) yyin=fopen(argv[1],"r");
    yylex();
    return 0;
}
