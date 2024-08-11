#include<stdio.h>

int main (void)
{int a,b,i,t,m;
double k,A;
m=0;
scanf("[%d,%d]",&a,&b);
i=a,t=2;
if (b==0) b=-1;
else if (a<=2&&b!=1)a=3,m=1;
else if(b=1)m=0,b=-1;
else if (a%2==0) a=a+1;
i=a;
while (i<=b)
{
for(;i<=b;i+=2)
     {  
	   for(t=3;t*t<i;t+=1)
	     {if (i%t==0)  break;}
       if (t*t>i)m=m+1;
      }
}
printf("%d",m);
return 0;
}