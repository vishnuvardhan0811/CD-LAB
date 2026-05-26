/* Exp6: Check whether identifier is valid */
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){
    char id[50];
    printf("Enter identifier: ");
    scanf("%s",id);
    int n=strlen(id),valid=1;
    if(!isalpha(id[0])&&id[0]!='_') valid=0;
    for(int i=1;i<n&&valid;i++)
        if(!isalnum(id[i])&&id[i]!='_') valid=0;
    printf("%s is %s identifier.\n",id,valid?"a VALID":"an INVALID");
    return 0;
}
