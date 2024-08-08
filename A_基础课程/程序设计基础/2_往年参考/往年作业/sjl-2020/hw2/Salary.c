#include<stdio.h>
int main (void)
{
	float a,b;
	scanf("%f",&a);
	if(a<=8) b=62.5*a;
	else b=8*62.5+(a-8)*62.5*1.5;
	printf("%.2f",b);
	return 0;
}