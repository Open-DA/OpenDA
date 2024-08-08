#include<iostream>
#include<string>
using namespace std;
int main()
{
	int m,n,i;
	scanf("%d%d\n",&m,&n);
	char *str1,*str2;
	str1=new char[m+n+1];
	str2=new char[n+1];
	cin>>str1;
    cin>>str2;
	for(i=m;i<m+n;i++)
		str1[i]=str2[i-m];
	str1[i]=0;
	cout<<str1;
	delete str1,str2;
	return 0;
}
