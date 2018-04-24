%token ID NUM IF THEN ELSE WHILE
%right '='
%left '+' '-'
%left '*' '/'
%left UMINUS
%%

S : IF '(' E ')' THEN S ELSE S
  | WHILE '(' E ')' '{' S '}'
  | ID '=' E ';' 
  ;
E : V '=' E
  | E '+' E
  | E '-' E
  | E '*' E
  | E '/' E
  | '(' E ')'
  | '-' E %prec UMINUS
  | V
  | NUM
  ;
V : ID
  ;
%%

#include "lex.yy.c"
#include<ctype.h>
int error=0;
void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    error++;
}

int main()
 {
 printf("Enter the expression : ");
 yyparse();
 if(error==0)
 printf("\nNo Syntax Error\n");
 return 0;
 }

