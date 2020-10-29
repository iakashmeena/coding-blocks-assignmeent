#include <stdio.h>
 
int main()
{
    int num1,num2;
    float result;
    char ch;    //to store operator choice
     
    printf("Enter first number: ");
    scanf("%d",&num1);
    printf("Enter second number: ");
    scanf("%d",&num2);
     
    printf("Choose operation to perform (+,-,*,/,%): ");
    scanf(" %c",&ch);
     
    result=0;
    switch(ch)    
    {
        case '+':
            result=num1+num2;
            break;
             
        case '-':
            result=num1-num2;
            break;
         
        case '*':
            result=num1*num2;
            break;
             
        case '/':
            result=(float)num1/(float)num2;
            break;
             
        case '%':
            result=num1%num2;
            break;
        default:
            printf("Invalid operation.\n");
    }
 
    printf("Result: %d %c %d = %f\n",num1,ch,num2,result);
    return 0;
}
/*
%{
%}
%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int lineno = 1; // initialized number of line with 1
    int words = 0;  //number of lexemes
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
 
"//".*                  { printf("Eat up comment at line %d\n",lineno); } 
 
"/*"                    { printf("Eat up comment from line %d ", lineno); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/"        { printf("to line %d\n", lineno); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+     
<ML_COMMENT>"*"         
<ML_COMMENT>"\n"        { lineno += 1; }
 
 
"char"|"CHAR"           { ret_print("CHAR"); }
"int"|"INT"             { ret_print("INT"); }
"float"|"FLOAT"         { ret_print("FLOAT"); }
"double"|"DOUBLE"       { ret_print("DOUBLE"); }
"if"|"IF"               { ret_print("IF"); }
"else"|"ELSE"           { ret_print("ELSE"); }
"while"|"WHILE"         { ret_print("WHILE"); }
"for"|"FOR"             { ret_print("FOR"); }
"continue"|"CONTINUE"   { ret_print("CONTINUE"); }
"break"|"BREAK"         { ret_print("BREAK"); }
"void"|"VOID"           { ret_print("VOID"); }
"return"|"RETURN"       { ret_print("RETURN"); }
 
 
"+"                     { ret_print("ADD"); }
"-"                     { ret_print("SUB"); }
"*"                     { ret_print("MUL"); }
"/"                     { ret_print("DIV"); }
"%"                     { ret_print("PERCENT"); }
"++"|"--"               { ret_print("INCR"); }
"||"                    { ret_print("OR"); }
"&&"                    { ret_print("AND"); }
"!"                     { ret_print("NOT"); }
"=="|"!="               { ret_print("EQU"); }
">"|"<"|">="|"<="       { ret_print("REL"); }
 
 
"("             { ret_print("LPAREN"); }
")"             { ret_print("RPAREN"); }
"["             { ret_print("LBRACK"); }
"]"             { ret_print("RBRACK"); }
"{"             { ret_print("LBRACE"); }
"}"             { ret_print("RBRACE"); }
";"             { ret_print("SEMI"); }
"."             { ret_print("DOT"); }
","             { ret_print("COMMA"); }
"="             { ret_print("ASSIGN"); }
"&"             { ret_print("REFER"); }
":"             { ret_print("COLON"); }

{preprocessor_directives} { ret_print("PREPROCESSOR DIRECTIVES"); }
{POINTER}       { ret_print("POINTER"); }
{ARRAY}         { ret_print("ARRAY"); }
{ID}            { ret_print("ID"); }
{ICONST}        { ret_print("ICONST"); }
{FCONST}        { ret_print("FCONST"); }
{CCONST}        { ret_print("CCONST"); }
{STRING}        { ret_print("STRING"); }
 

"\n"*           { lineno += 1; }
[ \t\r\f]+          /* eat up whitespace */
 
.               { yyerror("Unrecognized character"); }
 
%%
 
void ret_print(char *token_type){
    words++;
    printf("text: %s \t token: %s\tlineno: %d\n", yytext, token_type, lineno);
}
 
void yyerror(char *message){
    printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
    exit(1);
}
 
int main(int argc, char *argv[]){
    yyin = fopen(argv[1], "r");
    yylex();
    fclose(yyin);
    printf("Number of Lexemes = %d\n", words);
    return 0;
}
*/


/*%{
int c=0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%
#.* { printf("\n\t%s is a preprocessor directive",yytext);}

\\comment_problem_resolved
"/*" {c = 1;}
"*/" {c = 0;} 

void |
int |
float |
char |
double |
long {if(!c) printf("\n\t%s DATA TYPE",yytext);}
while |
for |
do |
if |
else |
break |
continue |
switch |
case |
struct |
const |
typedef |
return |
goto {if(!c)printf("\n\t%s  keyword",yytext);}

{identifier}\(\) {if(!c)printf("\n\t%s function name",yytext);}
{identifier} {if(!c)printf("\n\t%s Identifier",yytext);}

\\Block

\{ {if(!c) printf("\n BLOCK BEGINS");}
\} {if(!c) printf("\n BLOCK ENDS");}


\".*\" {if(!c) printf("\n\t%s string",yytext);}
[0-9]+ {if(!c) printf("\n\t%s constant",yytext);}
\) {if(!c) printf("\n\t");ECHO;printf(" Lbracket");}
\( {if(!c) printf("\n\t");ECHO;printf(" Rbracket");}

= {if(!c)printf("\n\t%s assignment operator",yytext);}

== |
\<= |
\>= |
\< |
\> {if(!c) printf("\n\t%s relational operator",yytext);}
\-- {if(!c) printf("\n\t%s decrement",yytext);}
\+\+ {if(!c) printf("\n\t%s increment",yytext);}
\+ {if(!c) printf("\n\t%s arithmetic operator",yytext);}
\; {if(!c) printf("\n\t%s terminate symbol",yytext);} 


%%

int main()
{

    FILE *file;
    file = fopen("./input.c","r");
    if(!file)
    {
        printf("could not open file \n");
        exit(0);
    }
    yyin = file;
    yylex();
    printf("\n\n");
    return 0;
    } 
    int yywrap()
    {
    return 0;
}*/
