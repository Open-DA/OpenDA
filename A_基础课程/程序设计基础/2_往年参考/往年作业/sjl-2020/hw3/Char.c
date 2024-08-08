#include<stdio.h>
int main (void)
{char a[201];
int A=0,B=0,C=0,D=0,i;

gets(a);
for(i=0;i<=201&&a[i]!='\0';i++)
{if ((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')) A++;
else if(a[i]>='1'&&a[i]<='9')B++;
else if(a[i]!=' ')C++;
else D++;
}
for(i=0;i<=201;i++)
	{if (a[i]>='A'&&a[i]<='Z') a[i]=a[i]+('a'-'A');
	else if (a[i]>='a'&&a[i]<='z') a[i]=a[i]+('A'-'a');}
puts(a);
printf("%d",A);
printf("\n%d",D);
printf("\n%d",B);
printf("\n%d",C);
return 0;

}