#include<stdio.h>
int main (void)
{int i=0,n=0;
	char a[257];
	gets(a);
	for(;i<=257;i++)
	{if (a[i]=='a'&&a[i+1]=='b'&&a[i+2]=='a')
	n++;}
	printf("%d",n);
	return 0;
}