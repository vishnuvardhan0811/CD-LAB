/* Exp5: Count whitespaces and newline characters */
#include<stdio.h>

int main(){
    char ch;
    int ws=0,nl=0,tab=0;
    printf("Enter text (Ctrl+D to end):\n");
    while((ch=getchar())!=EOF){
        if(ch==' ') ws++;
        else if(ch=='\n') nl++;
        else if(ch=='\t') tab++;
    }
    printf("Spaces   : %d\n",ws);
    printf("Tabs     : %d\n",tab);
    printf("Newlines : %d\n",nl);
    printf("Total WS : %d\n",ws+nl+tab);
    return 0;
}
