// ConsoleApplication14.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char b;int a; 
	scanf_s("%d",&a);
	scanf_s(" %c",&b);
	b=b+a;
	
	printf("%c",b);

	return 0;
}

