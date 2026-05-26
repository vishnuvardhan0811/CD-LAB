/* Exp16: Back end of compiler - simple code generation (register allocation) */
#include<stdio.h>
#include<string.h>

typedef struct{ char op[5],arg1[10],arg2[10],res[10]; } TAC;
TAC code[20]; int n=0;

void genCode(TAC t){
    if(!strcmp(t.op,"+")){
        printf("MOV R0, %s\n",t.arg1);
        printf("ADD R0, %s\n",t.arg2);
        printf("MOV %s, R0\n",t.res);
    }else if(!strcmp(t.op,"-")){
        printf("MOV R0, %s\n",t.arg1);
        printf("SUB R0, %s\n",t.arg2);
        printf("MOV %s, R0\n",t.res);
    }else if(!strcmp(t.op,"*")){
        printf("MOV R0, %s\n",t.arg1);
        printf("MUL R0, %s\n",t.arg2);
        printf("MOV %s, R0\n",t.res);
    }else if(!strcmp(t.op,"/")){
        printf("MOV R0, %s\n",t.arg1);
        printf("DIV R0, %s\n",t.arg2);
        printf("MOV %s, R0\n",t.res);
    }
}

int main(){
    printf("Enter number of 3-address instructions: ");
    scanf("%d",&n);
    printf("Format: op arg1 arg2 result (e.g.: + a b t1)\n");
    for(int i=0;i<n;i++){
        scanf("%s%s%s%s",code[i].op,code[i].arg1,code[i].arg2,code[i].res);
    }
    printf("\nGenerated Assembly:\n");
    for(int i=0;i<n;i++) genCode(code[i]);
    return 0;
}
