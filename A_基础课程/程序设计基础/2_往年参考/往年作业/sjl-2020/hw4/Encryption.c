#include <stdio.h>
#include<string.h>
#include <math.h>
int main (void)
{char word[20],key[100],temp,alpha[27];
int i,j,k,m;
for(i=0;i<26;i++)
	alpha[i]='A'+i;
alpha[25]='\0';
scanf("%s ",key);
scanf("%s",word);
for(i=0;key[i]!='\0';i++)
	for(j=i+1;key[j]!='\0';j++)
	if(key[i]==key[j])
		for(k=j;key[k]!='\0';k++)
           key[k]=key[k+1];
for(i=0;i<26;i++)
	for(j=0;j<strlen(key);j++)
		for(k=0;k<26;k++)
	if(key[j]==alpha[k])
		for(m=k;alpha[m]!='\0';m++)
           alpha[m]=alpha[m+1]; 
strcat(key,alpha);
for(i=0;i<strlen(word);i++)
	word[i]=key[word[i]-'A'];
puts(word);


return 0;
}


