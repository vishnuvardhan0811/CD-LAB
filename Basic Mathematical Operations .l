/* Exp37: LEX - Basic mathematical operations */
%{
#include<stdlib.h>
double a,b;
char op;
%}
%%
[0-9]+(\.[0-9]+)?[ \t]*([\+\-\*\/])[ \t]*[0-9]+(\.[0-9]+)? {
    if(sscanf(yytext,"%lf %c %lf",&a,&op,&b)==3){
        printf("Expression: %s\n",yytext);
        if(op=='+') printf("Result    : %.2f\n",a+b);
        else if(op=='-') printf("Result    : %.2f\n",a-b);
        else if(op=='*') printf("Result    : %.2f\n",a*b);
        else if(op=='/'){
            if(b==0) printf("Error: Division by zero\n");
            else printf("Result    : %.2f\n",a/b);
        }
    }
}
.|\n    { /* ignore */ }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter expressions like '3 + 5' (Ctrl+D to end):\n");
    yylex();
    return 0;
}
