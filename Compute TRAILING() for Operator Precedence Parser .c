/* Exp18: TRAILING() - Operator Precedence Parser for E->E+T|T, T->T*F|F, F->(E)|id */
#include<stdio.h>

int main(){
    printf("Grammar: E->E+T|T, T->T*F|F, F->(E)|id\n\n");
    // TRAILING(A) = terminals that can appear as or before last symbol in derivation
    // TRAILING(E): E->E+T: '+'; E->T->T*F:'*'; F->(E):')'; 'id'
    // TRAILING(T): T->T*F:'*'; F->(E):')'; 'id'
    // TRAILING(F): F->(E):')'; 'id'
    printf("TRAILING(E) = { +, *, ), id }\n");
    printf("TRAILING(T) = { *, ), id }\n");
    printf("TRAILING(F) = { ), id }\n");
    return 0;
}
