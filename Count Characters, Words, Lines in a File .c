/* Exp15: Count characters, words, and lines in a file */
#include<stdio.h>
#include<ctype.h>

int main(){
    char fname[100];
    printf("Enter filename: ");
    scanf("%s",fname);
    FILE *f=fopen(fname,"r");
    if(!f){printf("Cannot open file.\n");return 1;}
    int chars=0,words=0,lines=0,inWord=0;
    char c;
    while((c=fgetc(f))!=EOF){
        chars++;
        if(c=='\n') lines++;
        if(isspace(c)) inWord=0;
        else if(!inWord){inWord=1;words++;}
    }
    fclose(f);
    printf("Characters: %d\nWords     : %d\nLines     : %d\n",chars,words,lines);
    return 0;
}
