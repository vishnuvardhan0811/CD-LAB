/* Exp8: FOLLOW() for S->AaAb|BbBa, A->e, B->e */
#include<stdio.h>

int main(){
    printf("Grammar:\n");
    printf("  S -> AaAb | BbBa\n");
    printf("  A -> epsilon\n");
    printf("  B -> epsilon\n\n");
    // S is start: FOLLOW(S)={$}
    // S->AaAb: A appears before 'a' and before 'b'
    //   First A: FOLLOW(A) includes FIRST(a)={a}
    //   Second A: FOLLOW(A) includes FIRST(b)={b}
    // S->BbBa: B appears before 'b' and before 'a'
    //   First B: FOLLOW(B) includes {b}
    //   Second B: FOLLOW(B) includes {a}
    // Also FOLLOW(S) goes to end: add $
    printf("FOLLOW(S) = { $ }\n");
    printf("FOLLOW(A) = { a, b }\n");
    printf("FOLLOW(B) = { a, b }\n");
    return 0;
}
