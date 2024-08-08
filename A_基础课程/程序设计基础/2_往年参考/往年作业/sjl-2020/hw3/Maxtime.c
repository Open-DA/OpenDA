#include<stdio.h>
#include <string.h>
int main (void)
{int i,j,k=1,c[1000],d[1000],temp;
char a[1001],b[1000][1000],T[1000];
for(i=0;i<1000;i++)d[i]=1;
gets (a);
c[0]=-1;
for(i=0;a[i]!='e'||a[i+1]!='n'||a[i+2]!='d';i++)
	if(a[i]==' ')c[k]=i,k+=1;
for(i=0;i<k;i++)
b[i][0]='\0';       
for(i=0;i<=k;i++)
	for(j=0;j<=(c[i+1]-c[i]-1);j++)
		{if(j<(c[i+1]-c[i]-1))b[i][j]=a[c[i]+j+1];
		else b[i][j]='\0';}
 

for(i=0;b[i][0]!='\0';i++)
	for(j=i+1;b[j][0]!='\0';j++)
if(strcmp(b[i],b[j])==0)
	d[i]+=1;

for(i=0;i<k;i++)
{	for(j=0;j<999;j++)
         if (d[j]<d[j+1])
             temp=d[j],
			 d[j]=d[j+1],
			 d[j+1]=temp,
			 strcpy(T,b[j]),
			 strcpy(b[j],b[j+1]),
				 strcpy(b[j+1],T);}

for(i=0;b[0][i]!='\0';i++)         
printf("%c",b[0][i]);
printf(" %d",d[0]);
if(d[0]==d[1])
	printf("\n");
for(i=0;d[i]==d[i+1];i++)
{
	{for(j=0;b[i+1][j]!='\0';j++) 
printf("%c",b[i+1][j]);
printf(" %d",d[i]);}
if(d[i+1]==d[i+2])
	printf("\n");}
return 0;
}

		
	


