/* Exp22: LEX - Count vowels and consonants */
%{
int vowels=0,consonants=0;
%}
%%
[aeiouAEIOU]        { vowels++; }
[a-zA-Z]            { consonants++; }
.|\n                { /* ignore */ }
%%
int yywrap(){ return 1; }
int main(){
    printf("Enter a sentence:\n");
    yylex();
    printf("\nVowels    : %d\nConsonants: %d\n",vowels,consonants);
    return 0;
}
