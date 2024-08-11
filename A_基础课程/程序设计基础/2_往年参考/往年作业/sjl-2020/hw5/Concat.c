#include<stdio.h>
char *strcattype(char *s1, char *s2, int type)
{
	char*strcat,*p,*q;
if(type==1)
	{for(p=s1;*p!='\0';p++);
    for(q=s2;*q!='\0';q++,p++)
		*p=*q;
	*p=*q;
	strcat=s1;
    }

else
	{for(p=s2;*p!='\0';p++);
    for(q=s1;*q!='\0';q++,p++)
		*p=*q;
	*p=*q;
	strcat=s2;
    }
return(strcat);

}
int main(void)
{
	char *strcattype(char *s1, char *s2, int type);
	char arr1[255],arr2[255],*p;
	int type,length=0,i;
	scanf("%s ",arr1);
	scanf("%s ",arr2);
	scanf("%d",&type);
	*strcattype(arr1,arr2,type);
	if(type==1)
		{for(p=arr1;*p!='\0';p++)
			length++;
	        printf("%s ",arr1);
	         printf("%d",length);}
	else
		{for(p=arr2;*p!='\0';p++)
			length++;
	        printf("%s ",arr2);
	         printf("%d",length);}
return 0;


}