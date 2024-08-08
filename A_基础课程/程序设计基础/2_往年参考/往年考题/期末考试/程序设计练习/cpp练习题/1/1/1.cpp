#include<iostream>
using namespace std;
class Fract
{
private:
	int num,den;
public:
	Fract( int a=0,int b=1){num=a;den=b;};
	int ged ( int m,int n);
	Fract add( Fract f);
    void show();
};
Fract Fract::add(Fract f)
{
	Fract a;
	int k;
	a.den=ged(den,f.den);
	a.num=num*ged(den,f.den)/den+f.num*ged(den,f.den)/f.den;
	k=a.den<a.num?a.den:a.num;
	for(;k>1;k--)
	{
		if(a.den%k==0&&a.num%k==0)
			break;
	}
	a.num/=k;
	a.den/=k;
	return a;
}
int Fract::ged ( int m,int n)
{
	int k;
	k=m<n?m:n;
	for(;k>1;k--)
	{
		if(m%k==0&&n%k==0)
			break;
	}
	return (m*n/k);
}
void Fract ::show()
{
	cout<<num<<"/"<<den<<endl;
}
int main()
{
	Fract f1(1,5),f2(7,20),f3=f1.add(f2);
	f3.show();
    return 0;
}