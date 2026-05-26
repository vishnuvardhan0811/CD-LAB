/* Exp7: FIRST() for S->AaAb|BbBa, A->e, B->e */
#include<stdio.h>
#include<string.h>

int main(){
    printf("Grammar:\n");
    printf("  S -> AaAb | BbBa\n");
    printf("  A -> epsilon\n");
    printf("  B -> epsilon\n\n");
    // A -> epsilon, so FIRST(A)={epsilon}
    // S->AaAb: FIRST(A)=eps, so include a; FIRST(S) includes 'a'
    // S->BbBa: FIRST(B)=eps, so include b; FIRST(S) includes 'b'
    printf("FIRST(A) = { epsilon }\n");
    printf("FIRST(B) = { epsilon }\n");
    printf("FIRST(S) = { a, b }\n");
    return 0;
}
