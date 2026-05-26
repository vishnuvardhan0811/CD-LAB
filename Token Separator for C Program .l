/* Exp30: FLEX - Lexical Analyzer - separate tokens in C program */
%{
int keywords=0,identifiers=0,operators=0,constants=0,punctuation=0;
%}
%%
"int"|"float"|"char"|"double"|"if"|"else"|"while"|"for"|"return"|"void"|"main"|"printf"|"scanf"|"include"|"define" {
    printf("Keyword    : %s\n",yytext); keywords++;
}
[a-zA-Z_][a-zA-Z0-9_]*  { printf("Identifier : %s\n",yytext); identifiers++; }
[0-9]+(\.[0-9]+)?        { printf("Constant   : %s\n",yytext); constants++; }
"<="|">="|"=="|"!="|"&&"|"||"|"++"|"--"|"+="|"-="|"->"|[+\-*/=<>!%&|^~] {
    printf("Operator   : %s\n",yytext); operators++;
}
[(){}[\];,.]        { printf("Punctuation: %s\n",yytext); punctuation++; }
\"[^\"]*\"          { printf("String     : %s\n",yytext); }
\/\/[^\n]*          { printf("Comment    : %s\n",yytext); }
\/\*[^*]*\*\/       { printf("Comment    : %s\n",yytext); }
[ \t\n#<>]          { /* skip */ }
%%
int yywrap(){ return 1; }
int main(int argc,char *argv[]){
    if(argc>1) yyin=fopen(argv[1],"r");
    yylex();
    printf("\n--- Summary ---\n");
    printf("Keywords   : %d\nIdentifiers: %d\nConstants  : %d\nOperators  : %d\nPunctuation: %d\n",
        keywords,identifiers,constants,operators,punctuation);
    return 0;
}
