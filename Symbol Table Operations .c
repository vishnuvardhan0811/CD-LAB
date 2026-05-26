/* Exp11: Symbol Table Operations - Insert, Search, Display, Delete */
#include<stdio.h>
#include<string.h>

#define MAX 20

struct Symbol{
    char name[30];
    char type[15];
    int size;
} table[MAX];

int count=0;

void insert(){
    if(count>=MAX){printf("Table full!\n");return;}
    printf("Name: "); scanf("%s",table[count].name);
    printf("Type: "); scanf("%s",table[count].type);
    printf("Size: "); scanf("%d",&table[count].size);
    printf("'%s' inserted.\n",table[count++].name);
}

void search(){
    char name[30]; int found=0;
    printf("Name to search: "); scanf("%s",name);
    for(int i=0;i<count;i++)
        if(!strcmp(table[i].name,name)){
            printf("Found -> Name:%s Type:%s Size:%d\n",table[i].name,table[i].type,table[i].size);
            found=1; break;
        }
    if(!found) printf("Symbol '%s' not found.\n",name);
}

void display(){
    if(!count){printf("Table empty.\n");return;}
    printf("%-15s %-10s %-5s\n","Name","Type","Size");
    printf("------------------------------\n");
    for(int i=0;i<count;i++)
        printf("%-15s %-10s %-5d\n",table[i].name,table[i].type,table[i].size);
}

void deleteSymbol(){
    char name[30]; int found=-1;
    printf("Name to delete: "); scanf("%s",name);
    for(int i=0;i<count;i++) if(!strcmp(table[i].name,name)){found=i;break;}
    if(found==-1){printf("Not found.\n");return;}
    for(int i=found;i<count-1;i++) table[i]=table[i+1];
    count--;
    printf("'%s' deleted.\n",name);
}

int main(){
    int ch;
    do{
        printf("\n1.Insert 2.Search 3.Display 4.Delete 5.Exit\nChoice: ");
        scanf("%d",&ch);
        if(ch==1) insert();
        else if(ch==2) search();
        else if(ch==3) display();
        else if(ch==4) deleteSymbol();
    }while(ch!=5);
    return 0;
}
