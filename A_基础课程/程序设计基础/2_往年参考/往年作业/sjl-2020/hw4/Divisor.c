#include <stdio.h>
#include <math.h>
int maxdivisor(int x,int y,int z)
{int i=1,divisor;
while(i<=x&&i<=y&&i<=z)
     {
	if(x%i==0&&y%i==0&&z%i==0)
		divisor=i;
	i++;
      }
return(divisor);
}

int main(void)
{
int maxdivisor(int a,int b,int c);
int a=1,b=1,c=1;
int temp,k,j,i=0,divisor[20];
while(a!=0&&b!=0&&c!=0)
{scanf("%d %d %d",&a,&b,&c);
	if(a>0&&b>0&&c>0)
	{
	divisor[i]= maxdivisor(a,b,c);
	i++;}
	else if(a<0||b<0||c<0) printf("error\n");
}
for(k=0;k<i-1;k++)
	for(j=0;j<i-1;j++)
		if(divisor[j]<divisor[j+1])
			temp=divisor[j],
		divisor[j]=divisor[j+1],
		divisor[j+1]=temp;
printf("%d",divisor[0]);
for(i=0,k=1;divisor[i]==divisor[i+1];i++)
	k++;
printf(" %d",k);
return 0;
}




