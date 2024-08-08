#include<iostream>
#include <stdio.h>
#include<string>
using namespace std;
int main ()
{
	string sentence;
	char ch[100],temchar;
	int times[100],i,j,k=-1,temint;
	getline(cin,sentence);
	for(i=0;sentence[i]!='\0';i++)
	{
		if(sentence[i]!=' ')
			{
				k++;
				ch[k]=sentence[i];
				times[k]=1;
		if(sentence[i+1]!='\0')	
		for(j=i+1;sentence[j]!='\0';j++)
		{
			if(sentence[j]==ch[k])
			{
				times[k]++;
				sentence[j]=' ';
			}
		}
    }
	}
	ch[k+1]='\0';
	for(i=0;ch[i]!='\0';i++)
		for(j=0;ch[j+1]!='\0';j++)
		{
			if(ch[j]>ch[j+1])
				temchar=ch[j],
				ch[j]=ch[j+1],
				ch[j+1]=temchar,
				temint=times[j],
				times[j]=times[j+1],
				times[j+1]=temint;
		}
	for(i=0;ch[i]!='\0';i++)
		cout<<ch[i]<<' '<<times[i]<<endl;
	return 0;
}

