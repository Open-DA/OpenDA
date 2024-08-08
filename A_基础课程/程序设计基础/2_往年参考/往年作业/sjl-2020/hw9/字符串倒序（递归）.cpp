#include<iostream>
#include<string>
using namespace std;
void reverse(string &s)
{
	static string a;
	int len2=a.size(),len1=s.size();
	if(len1==len2)
	{
		s=a;
	}
	else
	{
		a+=s[len1-len2-1];
		reverse(s);
	}
	
}
int main()
{
	void reverse(string &s);
	string sen;
	cin>>sen;
	reverse(sen);
	cout<<sen<<endl;
	return 0;
}