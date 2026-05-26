/* Exp9: Eliminate Left Recursion from L->L,S|S ; S->(L)|a */
#include<stdio.h>

int main(){
    printf("Original Grammar:\n");
    printf("  S -> (L) | a\n");
    printf("  L -> L , S | S\n\n");
    // L -> L,S | S  has left recursion
    // After elimination: L -> S L'  ; L' -> ,S L' | epsilon
    printf("After Eliminating Left Recursion:\n");
    printf("  S  -> (L) | a\n");
    printf("  L  -> S L'\n");
    printf("  L' -> , S L' | epsilon\n");
    return 0;
}
