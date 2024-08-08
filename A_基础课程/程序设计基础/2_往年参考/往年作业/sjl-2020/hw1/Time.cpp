// ConsoleApplication10.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{int a1,a2,b1,b2,c1,c2,a,b,c;
long int x;
scanf_s("%d%*c%d%*c%d\n",&a1,&b1,&c1);
scanf_s("%d%*c%d%*c%d",&a2,&b2,&c2);
a=a1-a2;
b=b1-b2;
c=c1-c2;
x=a*3600+b*60+c;
	if(x>0)a=x/3600 ,b=(x-a*3600)/60,c=x%60,printf("%02d:%02d:%02d",a,b,c);
	else if(x<0)x=-x,a=x/3600 ,b=(x-a*3600)/60,c=x%60,printf("%02d:%02d:%02d",a,b,c);
	else printf("00:00:00");





	return 0;
}

