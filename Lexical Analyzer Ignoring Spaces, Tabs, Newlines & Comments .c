/* Exp3: Lexical Analyzer - ignore spaces, tabs, newlines and comments */
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int isKeyword(char *s){
    char *kw[]={"int","float","char","if","else","while","for","return","void","double","main",NULL};
    for(int i=0;kw[i];i++) if(!strcmp(s,kw[i])) return 1;
    return 0;
}

int main(){
    char line[500],token[50];
    int i=0,j;
    printf("Enter C code (one line): ");
    fgets(line,500,stdin);
    printf("\nAfter ignoring spaces/tabs/newlines/comments:\n");
    while(line[i]&&line[i]!='\n'){
        if(isspace(line[i])){i++;continue;}
        if(line[i]=='/'&&line[i+1]=='/'){while(line[i]&&line[i]!='\n')i++;continue;}
        if(line[i]=='/'&&line[i+1]=='*'){
            i+=2;
            while(line[i]&&!(line[i]=='*'&&line[i+1]=='/'))i++;
            i+=2;continue;
        }
        if(isalpha(line[i])||line[i]=='_'){
            j=0;
            while(isalnum(line[i])||line[i]=='_') token[j++]=line[i++];
            token[j]='\0';
            printf("[%s:%s] ",isKeyword(token)?"KW":"ID",token);
            continue;
        }
        if(isdigit(line[i])){
            j=0;
            while(isdigit(line[i])||line[i]=='.') token[j++]=line[i++];
            token[j]='\0';
            printf("[CONST:%s] ",token);
            continue;
        }
        printf("[SYM:%c] ",line[i++]);
    }
    printf("\n");
    return 0;
}
