#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
 char opcode[10],operand[10],label[10],a[10],ad[10],ch;
 char mnemonic[10][10]={"START","LOAD","STORE","JUMP","GOTO","END"};
 int locctr,start,length,i=0,j=0,k,l=0;

 FILE *fp1;
 fp1=fopen("INPUT.txt","r");
 fscanf(fp1,"%s%s%s",label,opcode,operand);

 if(strcmp(opcode,"START")==0)
  {
   start=atoi(operand);
   locctr=start;
   fscanf(fp1,"%s%s%s",label,opcode,operand);
  }
 else
  locctr=0;

printf("\nSymbol Table contents:\n");

 while(strcmp(opcode,"END")!=0)
  {
   if(strcmp(label,"**")!=0)
     printf("%s\t%d\n",label,locctr);
   while(strcmp(mnemonic[j],"END")!=0)
    { if(strcmp(opcode,mnemonic[j])==0)
     { locctr+=3;
        break; }
     j++;
    }
   if(strcmp(opcode,"BYTE")==0)   
    locctr+=1;   //Byte =1 byte
   else if(strcmp(opcode,"WORD")==0)
    locctr+=2;  //Word = 2 byte
   else if(strcmp(opcode,"DWORD")==0)
    locctr+=4;  //Dword = double word = 4 byte
   fscanf(fp1,"%s%s%s",label,opcode,operand);
  }
  fclose(fp1);
return 0;
}

