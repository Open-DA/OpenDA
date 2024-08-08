// ConsoleApplication8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{float i1,r1,i2,r2;
float a,b;
scanf_s("%f%f%*c %f%f%*c",&r1,&i1,&r2,&i2);
a=r1*r2-i1*i2;
b=r1*i2+r2*i1;
if (b>0) printf("%.3f+%.3fi",a,b);
else if(b<0) printf("%.3f%.3fi",a,b);
else printf("%.3f",a);
	return 0;
}

