/* Exp31: LEX - Count consonants in a sentence */
%{
int consonants=0;
%}
%%
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]   { consonants++; }
.|\n    { /* ignore */ }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter sentence (Ctrl+D to end):\n");
    yylex();
    printf("Total Consonants: %d\n",consonants);
    return 0;
}
