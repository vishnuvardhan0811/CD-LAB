/* Exp25: LEX - Count comment lines and remove them, write to output file */
%{
#include<stdio.h>
int comments=0;
FILE *out;
%}
%%
"/*"[^*]*"*/"           { comments++; fprintf(stdout,"[COMMENT REMOVED]\n"); }
"//"[^\n]*\n            { comments++; fprintf(stdout,"[COMMENT REMOVED]\n"); }
.                       { fprintf(out,"%s",yytext); }
\n                      { fprintf(out,"\n"); }
%%
int yywrap(){ return 1; }
int main(int argc,char *argv[]){
    if(argc>1) yyin=fopen(argv[1],"r");
    out=fopen("output_no_comments.c","w");
    yylex();
    fclose(out);
    printf("\nTotal comment lines removed: %d\n",comments);
    printf("Output written to output_no_comments.c\n");
    return 0;
}
