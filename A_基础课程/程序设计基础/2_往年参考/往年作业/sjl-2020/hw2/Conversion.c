#include<stdio.h>
int main (void)
{
	long int n,a,i,t;
	scanf("%d%d",&n,&a);
	for(t=1,i=0;(n/a)>0;i=i+t*(n%a),n=n/a,t=t*10);
    i=i+t*(n%a);
	printf("%d",i);
	return 0;
}