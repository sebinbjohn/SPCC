%{
%}

identifier ([A-Za-z])+
dig ([0-9])+ 
op [<>=]

%%
getch|main 		{printf("\n%s a function", yytext);}
if|else|void 	{printf("\n%s a keyword",yytext);}
{identifier} 	{printf("\n%s an identifier",yytext);}
{dig} 			{printf("\n%s a digit",yytext);}
{op} 			{printf("\n%s an operator",yytext);}
%%

int main(void){
   yyin=fopen("myfile.c","r");
   yylex();
   fclose(yyin);
   return 0;
}

int yywrap(void){
   return 1;
}
