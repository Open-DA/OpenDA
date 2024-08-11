#include<stdio.h>
#include <string.h>
int main (void)
{

int a[20][20],m,n,i,j,k,temp,row[20],sum[20]={0,0,0,0,0};
for(i=0;i<20;i++)
row[i]=i,sum[i]=0;
scanf("%d",&m);
scanf("%d",&n);
if(m>0&&m<=20&&n>0&&n<=20)
{
	{for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);}
for (i=0;i<=m-1;i++)
{ for (k=0;k<n-1;k++)
	for (j=0;j<n-1;j++)

{ if (a[i][j]> a[i][j+1]) 
    { temp = a[i][j];
a[i][j]= a[i][j+1];
a[i][j+1] = temp; } 
}
}
for(i=0;i<m;i++)
{	for(j=0;j<n;j++)
sum[i]+=a[i][j];}
for(i=0;i<m;i++)
{	for(j=0;j<m-1;j++)
         if (sum[j]>sum[j+1])
             temp=sum[j],
			 sum[j]=sum[j+1],
			 sum[j+1]=temp,


	         temp=row[j],
			 row[j]=row[j+1],
			 row[j+1]=temp;}
	

for(i=0;i<m;i++)
	for(j=0;j<n;j++)
		
	{if(j<n-1) printf("%d ",a[row[i]][j]);
	else printf("%d\n",a[row[i]][j]);}

}
else printf("error");
return 0;
}