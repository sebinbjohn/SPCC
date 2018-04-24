%token ID NUM IF THEN ELSE WHILE
%right '='
%left '+' '-'
%left '*' '/'
%left UMINUS
%%

S : ID{push();} '='{push();} E{codegen_assign();} ';' 
  ;
E : V '='{push();} E{codegen_assign();}
  | E '+'{push();} E{codegen();}
  | E '-'{push();} E{codegen();}
  | E '*'{push();} E{codegen();}
  | E '/'{push();} E{codegen();}
  | '(' E ')'
  | '-'{push();} E{codegen_umin();} %prec UMINUS
  | V
  | NUM{push();}
  ;
V : ID {push();}
  ;
%%

#include "lex.yy.c"
#include<ctype.h>
char st[100][10];
int top=0;
char i_[2]="0";
char temp[2]="t";

int start=1;

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main()
 {
 printf("Enter the expression : ");
 yyparse();
 return 0;
 }

void push()
 {
  strcpy(st[++top],yytext);
 }

void codegen()
 {
 strcpy(temp,"t");
 strcat(temp,i_);
  printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
  top-=2;
 strcpy(st[top],temp);
 i_[0]++;
 }

void codegen_umin()
 {
 strcpy(temp,"t");
 strcat(temp,i_);
 printf("%s = -%s\n",temp,st[top]);
 top--;
 strcpy(st[top],temp);
 i_[0]++;
 }

void codegen_assign()
 {
 printf("%s = %s\n",st[top-2],st[top]);
 top-=2;
 }
