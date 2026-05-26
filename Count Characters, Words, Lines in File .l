/* Exp19: LEX - Count characters, words, lines in a file */
%{
int chars=0,words=0,lines=0;
%}
%%
\n          { lines++; chars++; }
[^ \t\n]+   { words++; chars+=yyleng; }
.           { chars++; }
%%
int yywrap(){ return 1; }
int main(int argc, char *argv[]){
    if(argc>1) yyin=fopen(argv[1],"r");
    yylex();
    printf("Characters: %d\nWords     : %d\nLines     : %d\n",chars,words,lines);
    return 0;
}
