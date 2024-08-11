#include<iostream>
using namespace std;
struct time
{
	int year,month,day,hour,minute,second;
};
int main()
{
	struct time a;
	cin>>a.year>>a.month>>a.day>>a.hour>>a.minute>>a.second;
	cout<<a.year<<" "<<a.month<<" "<<a.day<<" "<<a.hour<<" "<<a.minute<<" "<<a.second;
	return 0;
}