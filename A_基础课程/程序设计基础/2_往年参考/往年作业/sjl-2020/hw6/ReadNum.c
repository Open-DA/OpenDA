#include<stdio.h>
#include<string.h>
void underthousand(int a,char *readnum)
{

	if(a/100==1) strcat(readnum,"ONE HUNDRED");
	if(a/100==2) strcat(readnum,"TWO HUNDRED");
	if(a/100==3) strcat(readnum,"THREE HUNDRED");
	if(a/100==4) strcat(readnum,"FOUR HUNDRED");
	if(a/100==5) strcat(readnum,"FIVE HUNDRED");
	if(a/100==6) strcat(readnum,"SIX HUNDRED");
	if(a/100==7) strcat(readnum,"SEVEN HUNDRED");
	if(a/100==8) strcat(readnum,"EIGHT HUNDRED");
	if(a/100==9) strcat(readnum,"NINE HUNDRED");
	if(a%100/10>0&&a>100)strcat(readnum," ");
	if(a%100/10==2)strcat(readnum,"TWENTY");
	if(a%100/10==3)strcat(readnum,"THIRTY");
	if(a%100/10==4)strcat(readnum,"FORTY");
	if(a%100/10==5)strcat(readnum,"FIFTY");
	if(a%100/10==6)strcat(readnum,"SIXTY");
	if(a%100/10==7)strcat(readnum,"SEVENTY");
	if(a%100/10==8)strcat(readnum,"EIGHTTY");
	if(a%100/10==9)strcat(readnum,"NINTY");
	if(a%100==11)strcat(readnum,"ELEVEN");
	if(a%100==12)strcat(readnum,"TWELVE");
	if(a%100==13)strcat(readnum,"THIRTEEN");
	if(a%100==14)strcat(readnum,"FOURTEEN");
	if(a%100==15)strcat(readnum,"FIFTEEN");
	if(a%100==16)strcat(readnum,"SIXTEEN");
	if(a%100==17)strcat(readnum,"SEVENTY");
	if(a%100==18)strcat(readnum,"EIGHTEEN");
	if(a%100==19)strcat(readnum,"NINETEEN");
	if(a%10>0&&(a%100<10||a%100>19)&&a>10)strcat(readnum," ");
	if(a%10==1&&a%100!=11)strcat(readnum,"ONE");
	if(a%10==2&&a%100!=12)strcat(readnum,"TWO");
	if(a%10==3&&a%100!=13)strcat(readnum,"THREE");
	if(a%10==4&&a%100!=14)strcat(readnum,"FOUR");
	if(a%10==5&&a%100!=15)strcat(readnum,"FIVE");
	if(a%10==6&&a%100!=16)strcat(readnum,"SIX");
	if(a%10==7&&a%100!=17)strcat(readnum,"SEVEN");
	if(a%10==8&&a%100!=18)strcat(readnum,"EIGHT");
	if(a%10==9&&a%100!=19)strcat(readnum,"NINE");
	
	

}
int main (void)
{  
	void underthousand(int a,char *readnum);
	int amount;
	char read1[100],read2[100];
	read1[0]='\0';
	read2[0]='\0';
    scanf("%d",&amount);
	if(amount<65535&&amount>0)
	{
		if(amount<1000)
	{
    underthousand(amount,read1);
	printf("%s",read1);
	}
	else
	{
		 underthousand(amount%1000,read1);
		  underthousand(amount/1000,read2);
		  printf("%s THOUSAND %s",read2,read1);
	}
	}
	else printf("ERROR");
	return 0;

}