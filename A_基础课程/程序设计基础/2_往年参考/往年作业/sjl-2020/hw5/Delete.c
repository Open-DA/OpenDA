#include<stdio.h>
int strdelete(char *s1, char *s2)
{
	char*p,*q,*t,*a;
	int len1,len2=0,k=0,i;
	for(q=s2;*q!='\0';q++)
		len2++;
	for(p=s1;*p!='\0';p++)
	  { for(a=p,q=s2,k=0;*a==*q&&*a!='\0';a++,q++)
		k++;
	    if (k==len2)
		 { for(i=0;i<len2;i++)
			 { for(t=a-i;*t!='\0';t++)
				 *(t-1)=*t;
		       *(t-1)=*t;
		  }
		p--;}
	}
	k=0;
	for(a=s1;*a!='\0';a++)
		k++;
	return(k);
}
int main (void)
{
	int strdelete(char *s1, char *s2);
	char s1[20],s2[20];
	int length;
	scanf("%s ",s1);
	scanf("%s",s2);
	length=strdelete(s1,s2);
	printf("%s ",s1);
	printf("%d",length);
	return 0;

}