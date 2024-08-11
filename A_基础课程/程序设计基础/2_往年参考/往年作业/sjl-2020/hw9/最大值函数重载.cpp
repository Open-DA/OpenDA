#include<iostream>
int MaxPro(int a,int b)
{
	return(a>b?a:b);
}
double MaxPro(double a,double b)
{
	return(a>b?a:b);
}
int main()
{
	int MaxPro(int a,int b);
	double MaxPro(double a,double b);
	int n;
	scanf("%d",&n);
	if(n==1)
	{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",MaxPro(a,b));
	}
	if(n==2)
	{
		double a,b;
		scanf("%lf%lf",&a,&b);
		printf("%.1lf",MaxPro(a,b));
	}
	return 0;
}