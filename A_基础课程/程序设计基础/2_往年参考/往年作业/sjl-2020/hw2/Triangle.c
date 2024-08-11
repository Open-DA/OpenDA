#include<stdio.h>
#include<math.h>
int main (void)
{float a,b,c,s,C;
scanf("%f%f%f",&a,&b,&c);
if((a>0)&&(b>0)&&(c>0)&&(a+b>c)&&(a+c>b)&&(b+c>a))
      {s= sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a)/16);
       C=a+b+c;
	   printf("%.2f %.2f",C,s);}
else 
	printf("Error");
}

