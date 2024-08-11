#include<stdio.h>
int main(void)
{long int a,i;
i=0,a=1;
scanf("%d",&a);
while (a>0)
{i=i+(a%2);
a=a/2;
}
printf("%d",i);
return 0;
}