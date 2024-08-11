#include<stdio.h>
int main (void)
{
double a,P;
int b,i;
i=1;
scanf("%lf%d",&a,&b);

switch(b)
{
case 1:P= a * (1 + 5*0.055);break;
case 2:P= a * (1 + 2*0.044),P= P* (1 + 3*0.05);break;
case 3:P= a * (1 + 3*0.05),P= P* (1 + 2*0.044);break;
case 4:for(P=a;i<=5;P= P* (1 + 1*0.035),i=i+1);break;
case 5:for(P=a;i<=20;P= P* (1 + 0.005/4),i=i+1);break;
default:P=a;
}
printf("%.2lf",P);
	return 0;
}


