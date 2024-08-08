// ConsoleApplication11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{float a,s,d,f,g,h,j,k,l,q,w,e;
scanf_s("%f %f %f %f %f %f %f %f %f %f %f %f",&a,&s,&d,&f,&g,&h,&j,&k,&l,&q,&w,&e);
a=(float)((int)(a*1000))/1000;
s=(float)((int)(s*1000))/1000;
d=(float)((int)(d*1000))/1000;
f=(float)((int)(f*1000))/1000;
g=(float)((int)(g*1000))/1000;
h=(float)((int)(h*1000))/1000;

printf("%-6.3f %-6.3f\n",a,s);
printf("%-6.3f %-6.3f\n",d,f);
printf("%-6.3f %-6.3f\n",g,h);
printf("%6.2f %6.2f %6.2f\n",j,k,l);
printf("%6.2f %6.2f %6.2f",q,w,e);
	return 0;
}

