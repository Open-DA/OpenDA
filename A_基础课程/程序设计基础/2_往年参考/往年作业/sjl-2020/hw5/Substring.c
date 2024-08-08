#include<stdio.h>
#include<string.h>
int Longest_substring(char s1[256], char s2[256], char s3[256], char *buffer)
{
	char ss1[20][20],ss2[20][20],ss3[20][20],TEMP[20],t[20][20];
	int i,k,j,x=0,len;

	
	for(k=0;k<20;k++)
		ss1[k][0]='\0',
		ss2[k][0]='\0',
		ss3[k][0]='\0',
		t[k][0]='\0';
	for(i=0,k=0;s1[i]!='\0';k++)
	{
		for(j=0;s1[i]!=' '&&s1[i]!='\0';i++,j++)
		ss1[k][j]=s1[i];
	    ss1[k][j]=' ';ss1[k][j+1]='\0';
	    if(s1[i]==' ')i++;
	}
	for(i=0,k=0;s2[i]!='\0';k++)
	{
		for(j=0;s2[i]!=' '&&s2[i]!='\0';i++,j++)
		ss2[k][j]=s2[i];
	    ss2[k][j]=' '; ss2[k][j+1]='\0';
	    if(s2[i]==' ')i++;
	}
	for(i=0,k=0;s3[i]!='\0';k++)
	{
		for(j=0;s3[i]!=' '&&s3[i]!='\0';i++,j++)
		 ss3[k][j]=s3[i];
	     ss3[k][j]=' '; ss3[k][j+1]='\0';
	    if(s3[i]==' ')i++;
	}
	for(i=0;ss1[i][0]!='\0';i++)
		for(j=0; ss2[j][0]!='\0';j++)
			{if(strcmp(ss1[i],ss2[j])==0)
			 {
				for(k=0; ss3[k][0]!='\0';k++)
					if(strcmp(ss2[j],ss3[k])==0)
						strcpy(t[x],ss3[k]),x++;
              }
		    }
for(i=0;i<x-1;i++)
	for(j=0;j<x-2;j++)
		if(strlen(t[j])<strlen(t[j+1]))
			strcpy(TEMP,t[j]),
			strcpy(t[j],t[j+1]),
			strcpy(t[j+1],TEMP);
strcpy(buffer,t[0]);
len=strlen(t[0])-1;
for(i=0;strlen(t[i])==strlen(t[i+1]);i++)
	strcat(buffer,t[i+1]);
return(len);


}
int main(void)
{
int Longest_substring(char s1[256], char s2[256], char s3[256], char *buffer);
char*buffer,arr1[256],arr2[256],arr3[256];
int len;
gets(arr1);
gets(arr2);
gets(arr3);
buffer=arr1;
len= Longest_substring(arr1,arr2,arr3,buffer);
if(*buffer=='\0')
	printf("NULL");
else
	printf("%s",buffer),
    printf("%d",len);
return(0);

}