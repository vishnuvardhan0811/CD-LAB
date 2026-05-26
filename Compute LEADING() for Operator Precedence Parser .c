/* Exp17: LEADING() - Operator Precedence Parser for E->E+T|T, T->T*F|F, F->(E)|id */
#include<stdio.h>
#include<string.h>

char *nonterms[]={"E","T","F"};
// Productions: E->E+T, E->T, T->T*F, T->F, F->(E), F->id
// LEADING(A) = terminals that can appear as or after first symbol
// LEADING(E): from E->E+T: '+' ; from E->T->T*F: '*'; from T->F->(E): '('; id
// LEADING(T): from T->T*F:'*'; from T->F->(E):'('; 'id'
// LEADING(F): from F->(E):'('; from F->id:'id'

int main(){
    printf("Grammar: E->E+T|T, T->T*F|F, F->(E)|id\n\n");
    printf("LEADING(E) = { +, *, (, id }\n");
    printf("LEADING(T) = { *, (, id }\n");
    printf("LEADING(F) = { (, id }\n");
    return 0;
}
