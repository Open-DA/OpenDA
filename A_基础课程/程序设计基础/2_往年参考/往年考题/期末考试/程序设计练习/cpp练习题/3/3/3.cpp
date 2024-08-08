#include<iostream>
#include<string.h>

using namespace std;

class String
{
private:
	char *str1,*str2;
	char *str;
public:
	String(char *s1,char *s2);
	void dele();
	void sort();
	void show();
	~String();
};
String ::String(char *s1,char *s2)
{
	str1=new char[strlen(s1)+1];
	strcpy(str1,s1);
	str2=new char[strlen(s2)+1];
	strcpy(str2,s2);
	str=new char[strlen(s1)+strlen(s2)+1];
	strcpy(str,str1);
	strcat(str,str2);

}
void String ::dele()
{
	int i,j,k=0;
	for(k=0;k<strlen(str);k++)
	{
		if(str[k]==' ')
		{
			for(i=k;i<strlen(str);i++)
				str[i]=str[i+1];
			k--;
		}
	}
}
void String ::sort()
{
	int i,j,k;
	char temp;
	for(i=0;i<strlen(str);i++)
		for(j=0;j<strlen(str)-1;j++)
		{
			if(str[j]>str[j+1])
			{
				temp=str[j];
				str[j]=str[j+1];
				str[j+1]=temp;
		    }
          }
}
void String ::show()
{
	puts(str1);
	puts(str2);
	puts(str);
}
String::~String()
{
	delete[] str1;
	delete[] str2;
	delete[] str;

}
int main()
{
	char s1[10],s2[10];
	gets(s1);
	gets(s2);
	String a(s1,s2);
	a.show();
	a.dele();
	a.sort();
	a.show();
	return 0;
}