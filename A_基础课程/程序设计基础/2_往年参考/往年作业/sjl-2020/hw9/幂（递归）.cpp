#include<iostream>
using namespace std;
int getPower(int x, int y)
{
	if(y<0)return 0;
	if(y==0)return 1;
	else return (x*getPower(x,y-1));
}
double getPower(double x, int y)
{
	if(y<0)return (getPower(x,y+1)/x);
	if(y==0)return 1;
	else return (x*getPower(x,y-1));
}
int main()
{
	int getPower(int x, int y);
	double getPower(double x, int y);
	int a,m;
	double b;
	scanf("%d%lf\n",&a,&b);
	scanf("%d",&m);
	printf("%d %.4lf",getPower(a,m),(getPower(b,m)-0.00005));
	return 0;
}