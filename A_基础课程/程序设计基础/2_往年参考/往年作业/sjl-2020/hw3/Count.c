#include<stdio.h>
#include <string.h>
int main (void)
{int j,i,k,N,n,S,K[100],M[100],num[100],temp,temp2;
	
scanf("%d %d",&N,&S);

	for(i=0;i<S;i++)
	scanf("%d %d",&K[i],&M[i]);
for(i=0;i<S;i++)
	{for(k=0;k<N;k++)
	num[k]=k+1;
		{for(n=N;n>1;n--)
		{temp2=M[i];
			for(;temp2>n;temp2-=n);
     {if(temp2>(n-K[i]+1))
		{ temp=temp2-(n-K[i]+1);
		 for(j=temp-1;j<n-1;j++)
			 num[j]=num[j+1];
	                 K[i]=temp;}
	 else {for(j=K[i]-1+temp2-1;j<n-1;j++)
		 num[j]=num[j+1];
	 K[i]=K[i]+temp2-1;}}
                     }
         }
printf("%d\n",num[0]);}
return 0;
}


    


