#ifndef CUBOID_H_INCLUDE
#define CUBOID_H_INCLUDE
class cuboid: public rect
{
public:
	cuboid(const int&x,const int&y,const int&w,const int&d,const int&h)
		:rect(x,y,d,w){this->h=h;};
	int geth(){return h;};
	void changeh(int h){this->h=h;};
	int getvol()const{return getarea()*h;};
	int getcuarea(){return 2*(getarea()+getw()*h+getd()*h);};
private:
	int h;
};
#endif