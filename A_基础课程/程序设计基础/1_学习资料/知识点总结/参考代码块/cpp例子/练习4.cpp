#include<iostream>
#include"point.h"
#include"rect.h"
#include"cuboid.h"
#include<cmath>
using namespace std;
float point::dist(const point&p)const
{
	float di,L1,L2;
	L1=(x-p.x)>0?(x-p.x):(p.x-x);
	L2=(y-p.y)>0?(y-p.y):(p.y-y);
	di=sqrt(L1*L1+L2*L2);
	return di;
}
int main()
{
	int x1,x2,y1,y2;
	float dist;
	int w,d,h,cx,ch;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	point a(x1,y1),b(x2,y2);
	dist=a.dist(b);
	w=(x1-x2)>0?(x1-x2):(x2-x1);
	d=(y1-y2)>0?(y1-y2):(y2-y1);
	rect R(x1,x2,d,w);
	cin>>h;
	cuboid C(x1,x2,d,w,h);
	cin>>cx>>ch;
	C.changex(cx);
	C.changeh(ch);

	printf("%.2f\n",dist);
	printf("%d\n",R.getarea());
	printf("%d\n",C.getvol());
	printf("%d\n",C.getcuarea());
	return 0;

}
