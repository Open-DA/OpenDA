#include<stdio.h>
#include <string.h>
int main (void)
{int i,n,k=0,j=0,A[200],temp;
char tmp;
scanf("%d%c",&n,&tmp);
for(i=0;i<n;i++)
{scanf("%d%c",&A[j],&tmp);
     k+=1;
      for(;A[j]!=0;j++)
		{scanf("%d%c",&A[j+1],&tmp);
	  if(A[j+1]!=0)k++;}
			  }


for(i=0;i<k;i++)
{	
   for(j=0;j<k-1;j++)
         if (A[j]>A[j+1])
             temp=A[j],
			 A[j]=A[j+1],
			 A[j+1]=temp;}
for(i=0;i<k-1;i++)
printf("%d,",A[i]);
printf("%d",A[i]);
return 0;
}






