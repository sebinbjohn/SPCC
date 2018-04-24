#include <stdio.h>
#include<ctype.h>
#include<string.h>

char s[100][100], first[100][100],ch;
int n,nt[100]={0},CI, nnt=0, n;

int FRST(char c, int b)
{
  int a,pr[100]={0},j,k=0,l,m;
  for(j=b-1;j>=0;j--)
  {
    if(s[j][0]==c&&s[j][2]!=c)
    {
      pr[j]=1;
      a = j;
      CI=j;
    }
  }
  for(j=0;j<b;j++)
  {
    if(pr[j]==1)
    {
      char check = s[j][2];
      jump:
      if(!(check>='A' && check<='Z'))
      {
        first[a][k]=check;
        k++;
      }
      else
      {
        l=FRST(check,b);
        for(m=0;m<l;m++)
        {
          if(first[CI][m]=='#'&&s[j][3]!='\0')
          {
            check=s[j][3];
            goto jump;
            break;
          }
          first[a][k]=first[CI][m];
          k++;
        }
      }
    }
  }
  first[a][k]=c;
  return k;
}

int find_in_list(char *ls, char ch, int y)
{
  int i, z=-1;
	for(i=0; i<y; i++)
	if(ls[i]==ch)
	{
		z=i;
		break;
	}
  return z;
}

void init_nt(int x)
{
  int i,j=0,k;char list[100];
  for(i=0;i<x;i++)
  {
    k=find_in_list(list,s[i][0],j+1);
	  if(k!=-1)
	  {
		  list[j++]=list[k];
		  nt[i]=-1;
	  }
  	else
  	{
    	list[j++]=s[i][0];
    	nnt++;
	  }
  }
}

int main()
{
  int h,i,count;
  printf("Enter the no. of s rules: ");
  scanf("%d", &n);
  printf("Enter the s rules:\n (in the format A>xB)\n (use # for epsilon)\n");
  for(i=0; i<n; i++)
  {
    printf("Rule no %d  ",i);
    scanf("%s",s[i]);	
  }

  init_nt(n);

  for(i=0;i<n;i++)
  {
    FRST(s[i][0],n);	
  }
  printf("\n\tFIRST");
  
  for(i=0; i<n; i++)
  {
    if(nt[i]==0)
    {
      printf("\n%c\t{", s[i][0]);
      for(h=0;first[i][h]!=s[i][0];h++)
        printf("%c ", first[i][h]);
      printf("}");
    }
  }
return 0;
}
