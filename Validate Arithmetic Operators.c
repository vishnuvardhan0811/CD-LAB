/* Exp4: Lexical Analyzer - validate arithmetic operators +,-,*,/ */
#include<stdio.h>

int main(){
    char expr[100];
    int i=0;
    printf("Enter an arithmetic expression: ");
    fgets(expr,100,stdin);
    printf("Operators found:\n");
    while(expr[i]&&expr[i]!='\n'){
        if(expr[i]=='+'||expr[i]=='-'||expr[i]=='*'||expr[i]=='/'){
            char *name;
            switch(expr[i]){
                case '+': name="Addition";break;
                case '-': name="Subtraction";break;
                case '*': name="Multiplication";break;
                case '/': name="Division";break;
                default: name="Unknown";
            }
            printf("  '%c' -> %s operator\n",expr[i],name);
        }
        i++;
    }
    return 0;
}
