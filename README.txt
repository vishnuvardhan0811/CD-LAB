COMPILATION INSTRUCTIONS:
--------------------------
For LEX/FLEX programs (exp19.l to exp40.l):
    flex exp22.l
    gcc lex.yy.c -o output22
    output22

EXPERIMENT LIST:
----------------
exp1.c   - Lexical Analyzer: identifiers, constants, operators
exp2.c   - Identify comment types (// and /* */)
exp3.c   - Lexical Analyzer ignoring spaces/tabs/newlines/comments
exp4.c   - Validate arithmetic operators (+,-,*,/)
exp5.c   - Count whitespaces and newline characters
exp6.c   - Validate identifier
exp7.c   - Compute FIRST() for predictive parser
exp8.c   - Compute FOLLOW() for predictive parser
exp9.c   - Eliminate left recursion from CFG
exp10.c  - Eliminate left factoring from CFG
exp11.c  - Symbol table operations
exp12.c  - Recursive descent parsing
exp13.c  - Bottom-up (Shift-Reduce) parsing
exp14.c  - Three address code generation
exp15.c  - Count characters, words, lines in file
exp16.c  - Back end: assembly code generation
exp17.c  - Compute LEADING() for operator precedence parser
exp18.c  - Compute TRAILING() for operator precedence parser
exp19.l  - LEX: count chars/words/lines (pass .c file as arg)
exp20.l  - LEX: print constants in C file
exp21.l  - LEX: count macros and headers
exp22.l  - LEX: count vowels and consonants
exp23.l  - LEX: print HTML tags
exp24.l  - LEX: add line numbers to file
exp25.l  - LEX: remove comments, count comment lines
exp26.l  - LEX: identify capital words
exp27.l  - LEX: validate email address
exp28.l  - LEX: convert 'abc' to 'ABC'
exp29.l  - LEX: validate mobile number
exp30.l  - FLEX: token separator for C program
exp31.l  - LEX: count consonants
exp32.l  - LEX: separate keywords and identifiers
exp33.l  - LEX: identify positive and negative numbers
exp34.l  - LEX: validate URL
exp35.l  - LEX: validate Date of Birth (DD/MM/YYYY)
exp36.l  - LEX: check if input is digit
exp37.l  - LEX: basic mathematical operations
exp38.l  - LEX: count word frequency
exp39.l  - LEX: find longest word
exp40.l  - FLEX: replace a word with another word

SAMPLE FILES:
-------------
sample.c      - sample C program for testing
input.c       - C program with comments for exp25
sample.html   - HTML file for exp23
