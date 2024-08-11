#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	void Input(char *str1,char*str2,int*g,int*k);
	char* Combine(char*str1,char*str2,int g);
	void KReverse(char*str3,int k);
	char str1[101],str2[101],*str3;
	int g,k;
	Input(str1,str2,&g,&k);
	str3=Combine(str1,str2,g);
	puts(str3);
	KReverse(str3,k);
	puts(str3);
	free(str3);
	return 0;
}
void Input(char *str1,char*str2,int*g,int*k)
{
	printf("请输入字符串str1（最大长度不超过100）：");
	gets(str1);
	printf("请输入字符串str2（最大长度不超过100）：");
	gets(str2);
	printf("请输入整数g（0<=g<字符串str1的长度）");
	scanf("%d",g);
	while(*g<0||*g>=strlen(str1))
	{
		printf("请重新输入g：");
		scanf("%d",g);
	}
	printf("请输入整数k（1<k<=字符串str1的长度）");
	scanf("%d",k);
	while(*k<=1||*k>strlen(str2))
	{
		printf("请重新输入k：");
		scanf("%d",k);

	}
}
char* Combine(char*str1,char*str2,int g)
{
	char*str3;
	int i;
	str3=(char*)malloc(sizeof(char)*(strlen(str2)+strlen(str1)+1));
	strncpy(str3,str1,g+1);
	str3[g+1]=0;
	strcat(str3,str2);
	for(i=0;i<(strlen(str1)-g);i++)
		str3[g+strlen(str2)+1+i]=str1[g+i+1];
	return str3;
}
void KReverse(char*str3,int k)
{
	char str[200];
	int m=strlen(str3)/k,i;
	while(m>0)
	{
		for(i=0;i<k;i++)
			str[i]=str3[(strlen(str3)/k-m+1)*k-1-i];
		for(i=0;i<k;i++)
			str3[(strlen(str3)/k-m)*k+i]=str[i];
		m--;
	}

}