#ifndef RECT_H_INCLUDE
#define RECT_H_INCLUDE
class rect:public point
{
public:
	rect(const int&x,const int&y,const int&d,const int&w)
		:point(x,y){this->d=d,this->w=w;};
	int getd(){return d;};
	int getw(){return w;};
	int getarea()const{return d*w;};
	void changed(int d){this->d=d;};
	void changew(int h){this->w=w;};
private:
	int d,w;
};

#endif