/* Exp13: Bottom-Up Parsing (Shift-Reduce) for simple expression grammar */
#include<stdio.h>
#include<string.h>

char stack[100][10];
int top=-1;
char input[100];
int iptr=0;

void push(char *s){ strcpy(stack[++top],s); }
char* pop(){ return stack[top--]; }

// Simple shift-reduce for E->E+E | E*E | (E) | id
// Using precedence: reduce id->E, then handle operators
int reduce(){
    // E+E -> E
    if(top>=2 && !strcmp(stack[top-1],"+") && !strcmp(stack[top],"E") && !strcmp(stack[top-2],"E")){
        pop();pop();pop();push("E");return 1;
    }
    // E*E -> E
    if(top>=2 && !strcmp(stack[top-1],"*") && !strcmp(stack[top],"E") && !strcmp(stack[top-2],"E")){
        pop();pop();pop();push("E");return 1;
    }
    // (E) -> E
    if(top>=2 && !strcmp(stack[top-1],"E") && !strcmp(stack[top],")") && !strcmp(stack[top-2],"(")){
        pop();pop();pop();push("E");return 1;
    }
    // id -> E
    if(top>=0){
        char *t=stack[top];
        if(t[0]>='a'&&t[0]<='z'&&t[1]=='\0'){pop();push("E");return 1;}
    }
    return 0;
}

int main(){
    printf("Enter expression (end with $): ");
    scanf("%s",input);
    int n=strlen(input)-1; // exclude $
    printf("%-20s %-20s %s\n","Stack","Input","Action");
    printf("----------------------------------------------------\n");
    
    while(1){
        // Print stack
        char stk[100]=""; for(int i=0;i<=top;i++){strcat(stk,stack[i]);strcat(stk," ");}
        printf("%-20s %-20s ",stk[0]?stk:"empty",&input[iptr]);
        
        if(!reduce()){
            if(input[iptr]=='$'){
                if(top==0&&!strcmp(stack[0],"E")) printf("ACCEPT\n");
                else printf("REJECT\n");
                break;
            }
            // Shift
            char tmp[2]={input[iptr++],'\0'};
            push(tmp);
            printf("Shift '%s'\n",tmp);
        } else {
            printf("Reduce -> E\n");
        }
    }
    return 0;
}
