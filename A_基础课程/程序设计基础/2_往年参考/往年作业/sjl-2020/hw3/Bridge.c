#include<stdio.h>
#include <math.h>
int main (void)
{int N,i=0;
double a[101],c[101],d[101];
int b[101],m,n,Q,P;
int j=0,k=1;
double sum=0;
scanf("%d\n",&N);
while(i<(N-1))
{
scanf("%lf %2d%*c%2d\n",&a[i],&m,&n);
b[i]=m*60+n;
i++;
}
scanf("%lf",&a[i]);
scanf(" %2d%*c%2d",&m,&n);
b[i]=m*60+n;
i=0;
while(i<N)
{if (a[i]<=10)
c[i]=b[i]+19.8* pow(10, 1.0 / 3);
else if (a[i]>10&&a[i]<=20)
c[i]=b[i]+19.8* pow(20, 1.0 / 3);
else if (a[i]>20&&a[i]<=30)
c[i]=b[i]+19.8* pow(30, 1.0 / 3);
else if (a[i]>30&&a[i]<=40)
c[i]=b[i]+19.8* pow(40, 1.0 / 3);
else 
c[i]=b[i]+19.8* pow(50, 1.0 / 3);
i++;
}
i=0;
while(i<N)
{if (a[i]<=10)
d[i]=b[i]+15* pow(10, 1.0 / 3);
else if (a[i]>10&&a[i]<=20)
d[i]=b[i]+15* pow(20, 1.0 / 3);
else if (a[i]>20&&a[i]<=30)
d[i]=b[i]+15* pow(30, 1.0 / 3);
else if (a[i]>30&&a[i]<=40)
d[i]=b[i]+15* pow(40, 1.0 / 3);
else 
d[i]=b[i]+15* pow(50, 1.0 / 3);
i++;
}

for(;j<=N-2;j++)
	{sum=a[j];
	while((c[j]>=d[k])&&(k<N-1))
	       {sum=sum+a[k];
	       
            if( sum>=70)
               {  Q=((int)(d[k]+0.5))%60;
			      P=(int)(d[k]);
			      printf("%02d:%02d",P/60,Q);
				  break;}
			 k=k+1;
	       }
	if( sum>=70) break;

    }
if (j>N-2)
printf("%02d:%02d",b[0]/60,b[0]%60);



}

