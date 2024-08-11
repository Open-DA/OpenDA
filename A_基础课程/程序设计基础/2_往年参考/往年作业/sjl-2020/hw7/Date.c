#include <stdio.h>
struct date
{
int year;
int month;
int day; 
};
int numofleapyear(int x,int y)
{int i,j,k;
if(x>y)
{
	i=x;
for(k=0;i<y;i++)
	if((i%4==0&&i%100!=0)||i%400==0)
		k++;
return k;
}
	if(x<y)
{
	i=y;
	for(k=0;i<x;i++)
	if((i%4==0&&i%100!=0)||i%400==0)
		k++;
	return k;

}
    if(x==y)
      return 0;
}
int minus(struct date x,struct date y)
{
	int numofleapyear(int x,int y);
	int i,j,k,m,n,result,temp;
	int normal[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int leap[]={31,29,31,30,31,30,31,31,30,31,30,31};
	i=numofleapyear(x.year,y.year);
	if(x.year<y.year)
		temp=x.year,
		x.year=y.year,
		y.year=temp,
		temp=x.month,
		x.month=y.month,
		y.month=temp,
		temp=x.day,
		x.day=y.day,
		y.day=temp;
  if(x.year==y.year&&x.month<y.month)
	  temp=x.month,
		x.month=y.month,
		y.month=temp,
		temp=x.day,
		x.day=y.day,
		y.day=temp;
   if(x.year==y.year&&x.month==y.month&&x.day<y.day)
	   temp=x.day,
		x.day=y.day,
		y.day=temp;
	j=(x.year-y.year)*365+i;
	if((y.year%4==0&&y.year%100!=0)||y.year%400==0)
	{for(k=0,m=0;k<y.month-1;k++)
	m+=leap[k];
	m+=y.day;}
	else
	{for(k=0,m=0;k<y.month-1;k++)
	m+=normal[k];
	m+=y.day;}
	if((x.year%4==0&&x.year%100!=0)||x.year%400==0)
	{for(k=0,n=0;k<x.month-1;k++)
	n+=leap[k];
	n+=x.day;}
	else
	{for(k=0,n=0;k<x.month-1;k++)
	n+=normal[k];
	n+=x.day;}

result=j+n-m;
return result;

}
int main (void)
{
int minus(struct date x,struct date y);
struct date a,b;
int r;
scanf("%d%d%d",&a.year,&a.month,&a.day);
scanf("%d%d%d",&b.year,&b.month,&b.day);
r=minus(a,b);
printf("%d",r);
return 0;
}