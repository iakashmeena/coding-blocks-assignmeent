%{
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
file = fopen("C:/Users/PRASHANT KUMAR/Desktop/lex/code.txt","r");
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
}