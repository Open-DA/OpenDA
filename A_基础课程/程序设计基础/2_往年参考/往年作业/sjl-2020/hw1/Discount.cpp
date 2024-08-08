// ConsoleApplication7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{float price,discount,pay;
int a,number;
scanf_s("%d %f",&number,&price);
a=number*price/100;
pay=number*price-a*20;
discount=20*a;
printf("%.2f %.2f",discount,pay);

	return 0;
}

