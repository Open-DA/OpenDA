#ifndef POINT_H_INCLUDE
#define POINT_H_INCLUDE
class point
{
public:
	point(const int&x,const int&y){this->x=x,this->y=y;};
	int getx(){return x;};
	int gety(){return y;};
	void changex(int x){this->x=x;};
	void changey(int y){this->y=y;};
	float dist(const point&p)const;
private:
	int x,y;
};
#endif