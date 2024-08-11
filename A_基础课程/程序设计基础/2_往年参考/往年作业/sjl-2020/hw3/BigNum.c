#include<stdio.h>
#include <string.h>
int main (void)
{int i=0,lengtha,lengthb,a[100],b[100],sum[101];
char chara[101],charb[101];
gets(chara),gets(charb);
lengtha=strlen(chara),lengthb=strlen(charb);
for(;i<=100&&chara[i]!='\0';i++)
	a[i]=chara[i]-'0';
	
for(i=0;i<=100&&charb[i]!='\0';i++)
b[i]=charb[i]-'0';
 for(i=lengtha;i<100&&i>=lengtha;i++)
	 a[i]=0;
 for(i=lengthb;i<100&&i>=lengthb;i++)
	 b[i]=0;
if(lengtha>lengthb)
   {for(i=lengthb-1;i>=0;i--)
	   b[i+lengtha-lengthb]=b[i];
     for(i=0;i<lengtha-lengthb;i++)
		 b[i]=0;}
if(lengtha<lengthb)
   {for(i=lengtha-1;i>=0;i--)
	   a[i+lengthb-lengtha]=a[i];
     for(i=0;i<lengthb-lengtha;i++)
		 a[i]=0;}
for(i=0;i<=100;i++)
sum[i]=0;
for(i=0;i<=100;i++)
{sum[i]=a[i]+b[i];
if(i!=0&&sum[i]>=10)sum[i-1]+=1,sum[i]-=10;}
if(lengtha>=lengthb)
	for(i=0;i<lengtha;i++)
		printf("%d",sum[i]);
else for(i=0;i<lengthb;i++)
		printf("%d",sum[i]);

return 0;
}