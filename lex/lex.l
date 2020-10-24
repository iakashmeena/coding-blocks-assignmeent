%{
%}

%option noyywrap
 
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int line_no = 1; // initializing number of line with 1
    int words = 0;  // this show number of lexemes
    void ret_print(char *token_type);
    void yyerror();
%}
 
%x ML_COMMENT
alpha       [a-zA-Z]
digit       [0-9]
alnum       {alpha}|{digit}
print       [ -~]

preprocessor_directives #.*
ARRAY       ({alpha}+{alnum}*"[".+"]")|({alpha}+{alnum}*"["+"]")
POINTER     "*"+{alpha}+{alnum}*
ID          {alpha}+{alnum}*
ICONST      "0"|[0-9]{digit}*
FCONST      "0"|{digit}*"."{digit}+
CCONST      (\'{print}\')|(\'\\[nftrbv]\')
STRING      \"{print}*\"
 
%%
 
"//".*                  { printf("Eat up comment at line %d\n", line_no); } 
 
"/*"                    { printf("Eat up comment from line %d ", line_no); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/"        { printf("to line %d\n", line_no); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+     
<ML_COMMENT>"*"         
<ML_COMMENT>"\n"        { line_no += 1; }
 
 
"char"|"CHAR"           { ret_print("KEYWORD_CHAR"); }
"int"|"INT"             { ret_print("KEYWORD_INT"); }
"float"|"FLOAT"         { ret_print("KEYWORD_FLOAT"); }
"double"|"DOUBLE"       { ret_print("KEYWORD_DOUBLE"); }
"if"|"IF"               { ret_print("KEYWORD_IF"); }
"else"|"ELSE"           { ret_print("KEYWORD_ELSE"); }
"while"|"WHILE"         { ret_print("KEYWORD_WHILE"); }
"for"|"FOR"             { ret_print("KEYWORD_FOR"); }
"continue"|"CONTINUE"   { ret_print("KEYWORD_CONTINUE"); }
"break"|"BREAK"         { ret_print("KEYWORD_BREAK"); }
"void"|"VOID"           { ret_print("KEYWORD_VOID"); }
"return"|"RETURN"       { ret_print("KEYWORD_RETURN"); }
 
 
"+"                     { ret_print("ADD"); }
"-"                     { ret_print("subtract"); }
"*"                     { ret_print("MUL"); }
"%"                     { ret_print("remainder"); }
"/"                     { ret_print("DIVIDE"); }
"++"|"--"               { ret_print("INCRIMENT"); }
"||"                    { ret_print("OR"); }
"&&"                    { ret_print("ANDOP"); }
"!"                     { ret_print("NOTOP"); }
"=="|"!="               { ret_print("EQUOP"); }
">"|"<"|">="|"<="       { ret_print("RELOP"); }
 
 
"("             { ret_print("LPAREN"); }
")"             { ret_print("RPAREN"); }
"["             { ret_print("LBRACK"); }
"]"             { ret_print("RBRACK"); }
"{"             { ret_print("L_BRACE"); }
"}"             { ret_print("R_BRACE"); }
";"             { ret_print("SEMI"); }
"."             { ret_print("DOT"); }
","             { ret_print("COMMA"); }
"="             { ret_print("ASSIGN"); }
":"             { ret_print("colon"); }
"&"             { ret_print("REFER"); }

{preprocessor_directives} { ret_print("PREPROCESSOR DIRECTIVES"); }
{POINTER}       { ret_print("POINTER"); }
{ARRAY}         { ret_print("ARRAY"); }
{ID}            { ret_print("ID"); }
{ICONST}        { ret_print("ICONST"); }
{FCONST}        { ret_print("FCONST"); }
{CCONST}        { ret_print("CCONST"); }
{STRING}        { ret_print("STRING"); }
 

"\n"*           { line_no += 1; }
[ \t\r\f]+          /* eat up whitespace */
 
.               { yyerror("Unrecognized character"); }
 
%%
 
void ret_print(char *token_type){
    words++;
    printf(" %s\ttoken: %s\tline_no: %d\n", yytext, token_type, line_no);
}
 
void yyerror(char *message){
    printf("Error: \"%s\" in line %d. Token = %s\n", message, line_no, yytext);
    exit(1);
}
 
int main(int argc, char *argv[]){
    yyin = fopen(argv[1], "r");
    yylex();
    fclose(yyin);
    printf("Number of Lexemes = %d\n", words);
    return 0;
}