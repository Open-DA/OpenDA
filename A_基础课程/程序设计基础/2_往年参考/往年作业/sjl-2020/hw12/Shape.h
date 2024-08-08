#ifndef _SHAPE_H
#define _SHAPE_H
#include<iostream>
using namespace std;

class Shape
{
public:
	virtual float getArea();
	virtual float getPerim();
};
class Rectangle:public Shape
{
public:
	Rectangle(const float& width,const float& height)
	{
		x=width;
		y=height;
	};
	float getArea()
	{return x*y;};
	float getPerim()
	{return 2*(x+y);};
private:
	float x;
	float y;
};
class Circle:public Shape
{
public:
	Circle(const float& radius)
	{
		r=radius;
	};
	float getArea()
	{return r*r*3.141592;};
	float getPerim()
	{return 2*r*3.141592;};
private:
	float r;
};

#endif