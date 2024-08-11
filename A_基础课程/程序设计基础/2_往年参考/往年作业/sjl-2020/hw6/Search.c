#include<stdio.h>
#include<string.h>
int main (void)
{
	char language[17][20],PUTIN[20];
	int i,j,k,p,m;
	for(i=0;i<17;i++)
		language[i][0]='\0';
strcpy(language[0],"C");
strcpy(language[1],"C++");
strcpy(language[2],"Python");
strcpy(language[3],"Java");
strcpy(language[4],"Basic");
strcpy(language[5],"C#");
strcpy(language[6],"PHP");
strcpy(language[7],"Javascript");
strcpy(language[8],"SQL");
strcpy(language[9],"Ruby");
strcpy(language[10],"Matlab");
strcpy(language[11],"Go");
strcpy(language[12],"Perl");
strcpy(language[13],"R");
strcpy(language[14],"Fortran");
strcpy(language[15],"Pascal");
strcpy(language[16],"Swift");
scanf("%s",PUTIN);
for(i=0;i<17;i++)
	for(p=0;language[i][p]!='\0';p++)
{for(j=0,k=0,m=p;j<strlen(PUTIN);j++)
if(PUTIN[j]==language[i][m])k++,m++;
if(k==strlen(PUTIN)){puts(language[i]);break;}
}
	return 0;
}