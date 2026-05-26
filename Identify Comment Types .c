/* Exp2: Lexical Analyzer - identify comments (// and /* ... *\/) */
#include<stdio.h>
#include<string.h>

int main(){
    char line[300];
    int commentFound=0;
    printf("Enter a line of C code:\n");
    fgets(line,300,stdin);
    int n=strlen(line);
    for(int i=0;i<n-1;i++){
        if(line[i]=='/'&&line[i+1]=='/'){
            printf("Single-line comment found: %s",&line[i]);
            commentFound=1; break;
        }
        if(line[i]=='/'&&line[i+1]=='*'){
            printf("Multi-line comment start found: /*\n");
            for(int j=i+2;j<n-1;j++){
                if(line[j]=='*'&&line[j+1]=='/'){
                    printf("Multi-line comment end found: */\n");
                    commentFound=1; break;
                }
            }
            commentFound=1; break;
        }
    }
    if(!commentFound) printf("No comment found in the given line.\n");
    return 0;
}
