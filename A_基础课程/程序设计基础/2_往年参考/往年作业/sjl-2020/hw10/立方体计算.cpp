#include<iostream>
using namespace std;
class box
{
private:
	int side;
public:
	box(int side);
	void volume();
	void area();

};
box::box(int side)
{
	this->side=side;
}
void box::volume()
{
	cout<<side*side*side<<' ';
}
void box::area()
{
	cout<<6*side*side<<endl;
}
int main()
{
	int s;
	cin>>s;
	box b(s);
	b.volume();
	b.area();
	return 0;
}