#include<stdio.h>

int max(int n)
{int a,b,c,d,temp;
a=n/1000;
b=(n-1000*a)/100;
c =(n-1000*a-100*b)/10;
d=n%10;
if(a<b)
	temp=a,
	a=b,
	b=temp;
if(a<c)
	temp=a,
	a=c,
	c=temp;
if(a<d)
	temp=a,
	a=d,
	d=temp;
if(b<c)
	temp=b,
	b=c,
	c=temp;
if(b<d)
	temp=b,
	b=d,
	d=temp;
if(c<d)
	temp=c,
	c=d,
	d=temp;
return(1000*a+100*b+10*c+d);
}
int min(int m)
{
int a,b,c,d,temp;
a=m/1000;
b=(m-1000*a)/100;
c =(m-1000*a-100*b)/10;
d=m%10;
if(a<b)
	temp=a,
	a=b,
	b=temp;
if(a<c)
	temp=a,
	a=c,
	c=temp;
if(a<d)
	temp=a,
	a=d,
	d=temp;
if(b<c)
	temp=b,
	b=c,
	c=temp;
if(b<d)
	temp=b,
	b=d,
	d=temp;
if(c<d)
	temp=c,
	c=d,
	d=temp;
return(1000*d+100*c+10*b+a);
}
int main (void)
{
	int max(int n);
    int min(int m);
	int num,MAX,MIN,result[100],i;
	scanf("%d",&num);
	if(num/100==num%100&&num%10==num/1000)
		printf("ERROR");
	else 

	{MAX=max(num);
	MIN=min(num);
	result[0]=MAX-MIN;
	printf("(%d,%d,%d)\n",MAX,MIN,result[0]);
	num=result[0];
	MAX=max(num);
	MIN=min(num);
	result[1]=MAX-MIN;
	printf("(%d,%d,%d)\n",MAX,MIN,result[1]);
	num=result[1];
	for(i=2;result[i-1]!=result[i-2];i++)
	{
	MAX=max(num);
	MIN=min(num);
	result[i]=MAX-MIN;
	if(result[i]!=result[i-1])
	printf("(%d,%d,%d)\n",MAX,MIN,result[i]);
	num=result[i];
	}
	}
	return 0;
}
