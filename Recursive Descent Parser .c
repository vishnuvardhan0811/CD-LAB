/* Exp12: Recursive Descent Parser for E->TE', E'->+TE'|e, T->FT', T'->*FT'|e, F->(E)|id */
#include<stdio.h>
#include<string.h>

char input[100];
int pos=0;

void E(); void EP(); void T(); void TP(); void F();

void match(char c){
    if(input[pos]==c) pos++;
    else{ printf("Error: expected '%c' got '%c'\n",c,input[pos]); pos++; }
}

void F(){
    if(input[pos]=='('){match('(');E();match(')');}
    else if(input[pos]>='a'&&input[pos]<='z') pos++; // id
    else printf("Error in F\n");
}
void TP(){if(input[pos]=='*'){match('*');F();TP();}}
void T(){F();TP();}
void EP(){if(input[pos]=='+'){match('+');T();EP();}}
void E(){T();EP();}

int main(){
    printf("Enter expression (use single letters as id, end with $): ");
    scanf("%s",input);
    E();
    if(input[pos]=='$') printf("String ACCEPTED by grammar.\n");
    else printf("String REJECTED.\n");
    return 0;
}
