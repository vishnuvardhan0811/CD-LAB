/* Exp1: Lexical Analyzer - identify identifiers, constants, operators */
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isKeyword(char *s){
    char *kw[]={"int","float","char","double","if","else","while","for","return","void","main","include","printf","scanf",NULL};
    for(int i=0;kw[i];i++) if(!strcmp(s,kw[i])) return 1;
    return 0;
}

int main(){
    char line[200],token[50];
    int i,j;
    printf("Enter a C expression: ");
    fgets(line,200,stdin);
    printf("\nTokens identified:\n");
    i=0;
    while(line[i]!='\0'&&line[i]!='\n'){
        // Skip spaces/tabs/newlines
        if(isspace(line[i])){ i++; continue; }
        // Skip single-line comment
        if(line[i]=='/'&&line[i+1]=='/'){
            while(line[i]!='\n'&&line[i]!='\0') i++;
            continue;
        }
        // Identifier or keyword
        if(isalpha(line[i])||line[i]=='_'){
            j=0;
            while(isalnum(line[i])||line[i]=='_') token[j++]=line[i++];
            token[j]='\0';
            if(isKeyword(token)) printf("Keyword     : %s\n",token);
            else printf("Identifier  : %s\n",token);
            continue;
        }
        // Number constant
        if(isdigit(line[i])){
            j=0;
            while(isdigit(line[i])||line[i]=='.') token[j++]=line[i++];
            token[j]='\0';
            printf("Constant    : %s\n",token);
            continue;
        }
        // Operators
        char ops[]="+-*/=<>!&|%";
        int found=0;
        for(int k=0;ops[k];k++){
            if(line[i]==ops[k]){
                printf("Operator    : %c\n",line[i++]);
                found=1; break;
            }
        }
        if(!found){
            printf("Symbol      : %c\n",line[i++]);
        }
    }
    return 0;
}
