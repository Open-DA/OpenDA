#include <stdio.h>
#include <math.h>
float a,b,c,d,e;
float f(float x)
{float fx;
fx=x*x*x*x*x + a*x*x*x*x + b*x*x*x + c*x*x  + d*x + e ;
return(fx);
}

float xpoint(float x1, float x2)
{
float xpoint;

xpoint=(x2*f(x1)-x1*f(x2))/(f(x1)-f(x2));
return(xpoint);
}
float root(float x1, float x2)
{
int i;
float x[2000];
x[0]=xpoint(x1,x2);
if((f(x[0])>0&&f(x2)>0)||(f(x[0])<0&&f(x2)<0))
		x2=x[0];
     if((f(x[0])>0&&f(x1)>0)||(f(x[0])<0&&f(x1)<0))
		 x1=x[0];
 
 x[1]=xpoint(x1,x2);
if((f(x[1])>0&&f(x2)>0)||(f(x[1])<0&&f(x2)<0))
		x2=x[1];
 if((f(x[1])>0&&f(x1)>0)||(f(x[1])<0&&f(x1)<0))
		 x1=x[1];
i=2;
while(x[i-1]-x[i-2]>1e-6||x[i-1]-x[i-2]<-1e-6)
	   {x[i]=xpoint(x1,x2);
		if((f(x[i])>0&&f(x2)>0)||(f(x[i])<0&&f(x2)<0))
		x2=x[i];
        if((f(x[i])>0&&f(x1)>0)||(f(x[i])<0&&f(x1)<0))
		 x1=x[i];
		i++;
        }
 return(x[i-1]);
}
int main(void)
{
float f(float x);
float xpoint(float x1, float x2);
float root(float x1, float x2);
float x1,x2,result;
scanf("%f,%f,%f,%f,%f",&a,&b,&c,&d,&e);
scanf("%f,%f",&x1,&x2);
result=root(x1,x2);
printf("%.3f",result);
return 0;
}
