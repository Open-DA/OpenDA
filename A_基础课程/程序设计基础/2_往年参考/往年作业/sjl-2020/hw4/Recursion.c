#include<stdio.h>
float f(int x,int n)
{float fx;
	if (n==0) return(1);
	else if(n==1) return(x);
	else 
		fx=(float)(((2*n-1)*x*f(x,n-1)-(n-1)*f(x,n-2))/n);
	     return(fx);

}
int main (void)
{
float f(int x,int n);
int x1,n1;
char c;
float result;
scanf("%d,%d",&x1,&n1);
result=f(x1,n1);
printf("%.2f",result);

}