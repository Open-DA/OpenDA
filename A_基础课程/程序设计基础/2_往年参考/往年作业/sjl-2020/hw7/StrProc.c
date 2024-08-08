#include<stdio.h>
#include<string.h>
void Input(char str1[],char str2[],int*g1,int*k2)
{
	int g,k;
	gets(str1);
	gets(str2);
	scanf("%d",&g);
	
	while(g<0||g>=strlen(str1))
   {
	scanf("%d",&g);
	}
	scanf("%d",&k);
	while(k<1&&k>=strlen(str2))
   {
	scanf("%d",&k);
	}
	*g1=g,*k2=k;
}
void Combine(char str1[],char str2[],int g)
{
	int i,k,len1,len2;
	len1=strlen(str1);
	len2=strlen(str2);
	for(i=len1;i>g;i--)
		str1[i+len2]=str1[i];
	for(i=g+1,k=0;str2[k]!='\0';k++,i++)
		str1[i]=str2[k];
}
void KReverse(char str3[],int k)
{
	int len3,t,i,j,m;
	char temp[200];
	len3=strlen(str3);
	t=len3/k;
	strcpy(temp,str3);
	for(i=0,j=0;i<t;i++,j+=k)
		for(m=0;m<k;m++)
			str3[j+m]=temp[j+k-m-1];



}
int main (void)
{
	void Input(char str1[],char str2[],int*g1,int*k2);
	void Combine(char str1[],char str2[],int g);
	void KReverse(char str3[],int k);
	char str1[200],str2[200],str3[200];
	int G[1],K[1],*g1,*k2;
	g1=G,k2=K;
	Input(str1,str2,g1,k2);
	Combine(str1,str2,G[0]);
	strcpy(str3,str1);
	puts(str3);
	KReverse(str3,K[0]);
	puts(str3);
	return 0;
}