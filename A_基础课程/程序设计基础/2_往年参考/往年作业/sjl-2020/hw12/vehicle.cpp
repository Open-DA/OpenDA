#include<iostream>
using namespace std;
class vehicle
{
public:
	vehicle(){cout<<"vehicle Construct"<<endl;};
	~vehicle(){cout<<"vehicle Destroy"<<endl;};
};
class bicycle:virtual public vehicle
{
public:
	bicycle(){cout<<"bicycle Construct"<<endl;};
	~bicycle(){cout<<"bicycle Destroy"<<endl;};
};
class motorcar:virtual public vehicle
{
public:
	motorcar(){cout<<"motorcar Construct"<<endl;};
	~motorcar(){cout<<"motorcar Destroy"<<endl;};
};
class motorcycle:public bicycle,public motorcar
{
	public:
	motorcycle(){cout<<"motorcycle Construct"<<endl;};
	~motorcycle(){cout<<"motorcycle Destroy"<<endl;};
};
int main()
{
	motorcycle a;
	return 0;
}