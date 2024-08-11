#include<iostream>
using namespace std;
int main()
{
	double exam(double n,double x);
	double n,x;	
	cin>>n>>x;	
    printf("%.1lf",exam(n,x));
	return 0;
}
double exam(double n,double x)
{
	double P;
	if(n==0) return 1;
	else if(n==1) return x;
	else return ((2*n-1)*x*exam(n-1,x)-(n-1)*exam(n-2,x))/n;
	
}