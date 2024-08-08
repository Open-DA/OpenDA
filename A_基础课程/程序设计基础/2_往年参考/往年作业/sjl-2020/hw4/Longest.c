#include <stdio.h>
#include<string.h>
#include <math.h>

void findlong(char a[100],char result[20])
{int i,p,j=0,k=0,length[20],temp;
char longest[50][50],TEM[20];
for(i=0;i<50;i++)
longest[i][0]='\0';  
for(i=0;a[i]!='\0';i++)
{	if(a[i]!=','&&a[i]!='.'&&a[i]!=' ')
		length[j]++,
		longest[j][k]=a[i],
		k++;
else longest[j][k]='\0',j++,k=0;}

p=j;
for(i=0;i<p;i++)
{	for(j=0;longest[j+1][0]!='\0';j++)
         if (length[j]<length[j+1])
             temp=length[j],
			 length[j]=length[j+1],
			 length[j+1]=temp,
			 strcpy(TEM,longest[j]),
			 strcpy(longest[j],longest[j+1]),
				 strcpy(longest[j+1],TEM);}

strcpy(result,longest[0]);

}
int main (void)
{void findlong(char a[100],char result[20]);
int i;
char sentence[100],results[20];
for(i=0;i<20;i++)
results[i]='\0'; 
gets(sentence);
findlong(sentence,results);
puts(results);
return 0;
}