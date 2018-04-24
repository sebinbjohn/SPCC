#include <stdio.h>
#include <ctype.h>
#include <string.h>

char s[100][100];
int tot_lines=0, loop_invariant[100];

void print_optimized_code( char *a)
{
	int i;
	printf("\nOptimized code : [%s]\n\n", a);
	for(i=0; i<tot_lines; i++)
		if(s[i][0]!='\0')
			printf("%s\n", s[i]);
}

void dead_code_elimination()
{
	int i,j, optimized_atleast_once=0;
	for(i=0;i<tot_lines;i++)
	{
		if(strstr(s[i],"="))
		{
			char temp1[2]="";
			strncpy(temp1, s[i]+0, 1);
			for(j=i+1; j<tot_lines;j++)
			{
				char temp2[2]="";
				strncpy(temp2, s[j]+0, 1);
				if(strcmp(temp1,temp2)==0)
				{
					strcpy(s[i],"\0");
					optimized_atleast_once++;
					break;
				}
			}
		}
	}
	if(optimized_atleast_once!=0)
		print_optimized_code("Dead Code Elimination");
}

int main(void)
{
 int option=1, i=0;
 printf("\nEnter your code to be optimized :\n[Use only one lettered variable names e.g. x,y,z] \n[Enter 0 to stop adding code]\n\n");
 while (option !=0)
 {
  scanf("%[^\n]s", s[i++]);
  if(scanf("%d",&option));
 }
 tot_lines=i;
 printf("\nTotal lines :%d\n",tot_lines);
 dead_code_elimination();
 return 0;
}