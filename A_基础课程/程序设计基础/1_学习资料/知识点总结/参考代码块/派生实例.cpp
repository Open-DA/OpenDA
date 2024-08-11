#include<iostream>
#include<cmath>
using namespace std;
class Point
{
protected:
	int x1,y1;
public:
	Point(int a,int b){x1=a,y1=b;};

};
class Line:public Point
{
protected:
	int x2,y2;
public:
	Line(int a,int b,int c,int d);
};
Line::Line (int a,int b,int c,int d)
	:Point(a,b)
{
	x2=c,y2=d;
}
class Triangle:public Line
{
private:
	int x3,y3;
	double area;
public:
	Triangle(int a,int b,int c,int d,int e,int f);
	void f();
	void print();

};
Triangle::Triangle(int a,int b,int c,int d,int e,int f)
	:Line(a,b,c,d)
{
	x3=e,y3=f;
	cout<<"Triangle constructed"<<endl;
}
void Triangle::f()
{
	double x,y,z,s;
	x=sqrt((double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
	y=sqrt((double)((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)));
	z=sqrt((double)((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)));
	s=(x+y+z)/2;
	area=sqrt(s*(s-x)*(s-y)*(s-z));
}
void Triangle::print()
{
	cout<<"("<<x1<<","<<y1<<")"<<endl;
	cout<<"("<<x2<<","<<y2<<")"<<endl;
	cout<<"("<<x3<<","<<y3<<")"<<endl;
	cout<<"area="<<area<<endl;
}
int main()
{
	Triangle tri(1,1,4,1,4,5);
	tri.f();
	tri.print();
}