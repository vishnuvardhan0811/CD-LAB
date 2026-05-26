/* Exp10: Eliminate Left Factoring from S->iEtS|iEtSeS|a, E->b */
#include<stdio.h>

int main(){
    printf("Original Grammar:\n");
    printf("  S -> iEtS | iEtSeS | a\n");
    printf("  E -> b\n\n");
    // S -> iEtS | iEtSeS | a
    // Common prefix: iEt
    // S -> iEtS' | a
    // S'-> S | SeS -> S S''  wait, S'->eS|epsilon
    // Actually: S->iEtSS'|a, S'->eS|epsilon
    printf("After Left Factoring:\n");
    printf("  S  -> iEtSS' | a\n");
    printf("  S' -> eS | epsilon\n");
    printf("  E  -> b\n");
    return 0;
}
