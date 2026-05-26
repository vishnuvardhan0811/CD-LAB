/* Exp14: Three Address Code generation */
#include<stdio.h>
#include<string.h>
#include<ctype.h>

char input[100];
int pos=0, tmp=1;
char result[20];

char newTemp(){ char t[10]; sprintf(t,"t%d",tmp++); return t[0]; /* simplified */ }

// Returns temp var name holding result
char* expr();
char* term();
char* factor();

char buf[50][20];
int bi=0;

char* mktemp(){ sprintf(buf[bi],"t%d",tmp++); return buf[bi++]; }

char* factor(){
    char *r=mktemp();
    if(input[pos]=='('){
        pos++; char *e=expr(); pos++; // skip )
        sprintf(r,"%s",e);
    } else {
        sprintf(r,"%c",input[pos++]);
    }
    return r;
}
char* term(){
    char *left=factor();
    while(input[pos]=='*'||input[pos]=='/'){
        char op=input[pos++];
        char *right=factor();
        char *r=mktemp();
        printf("%s = %s %c %s\n",r,left,op,right);
        left=r;
    }
    return left;
}
char* expr(){
    char *left=term();
    while(input[pos]=='+'||input[pos]=='-'){
        char op=input[pos++];
        char *right=term();
        char *r=mktemp();
        printf("%s = %s %c %s\n",r,left,op,right);
        left=r;
    }
    return left;
}

int main(){
    printf("Enter expression (e.g. a+b*c): ");
    scanf("%s",input);
    printf("\nThree Address Code:\n");
    char *r=expr();
    printf("Result in: %s\n",r);
    return 0;
}
