#include<iostream>
#include<string.h>
using namespace std;

class ID
{
private:
        char s[19];
		char x[12];
		int w[17];
public:
	ID(char *str);
	void fun();
	void print();
};
ID::ID(char *str)
{
	int i,m[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	for(i=0;i<17;i++)
		w[i]=m[i];
	strcpy(x,"10X98765432");
	x[11]=0;
	strcpy(s,str);
}
void ID::fun()
{
	int i,j,k,S=0;
	for(i=17;i>7;i--)
		s[i]=s[i-2];
	s[6]='1';s[7]='9';
	s[18]=0;
	for(i=0;i<17;i++)
	S+=(s[i]-'0')*w[i];
	S=(S%11);
	s[17]=x[S];
}
void ID::print()
{
	puts(s);
}
int main()
{
	char str[16];
	gets(str);
	ID pc(str);
	pc.fun();
	pc.print();
}