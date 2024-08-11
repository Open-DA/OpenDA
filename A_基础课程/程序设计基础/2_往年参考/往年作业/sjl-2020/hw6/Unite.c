#include<stdio.h>
#include<string.h>
void analysis(char *s, int vector[]) 
{
	int i,j,k;
	if(s[strlen(s)-1]>'0'&&s[strlen(s)-1]<='9'&&s[strlen(s)-2]=='+')vector[0]=s[strlen(s)-1]-'0';
    if(s[strlen(s)-1]>'0'&&s[strlen(s)-1]<='9'&&s[strlen(s)-2]=='-')vector[0]='0'-s[strlen(s)-1];
	if(s[strlen(s)-1]=='x')
		{
				 if(s[strlen(s)-3]=='-')vector[1]='0'-s[strlen(s)-2];
			 if(s[strlen(s)-3]=='+')vector[1]=s[strlen(s)-2]-'0';
			 if(s[strlen(s)-2]=='-')vector[1]=-1;
			  if(s[strlen(s)-2]=='+')vector[1]=1;
			 }
	for(i=strlen(s)-2;i>=0;i--)
	{	
		if(s[i]=='x'&&s[i+1]=='^')
		{if(i>=1)
				{
					if(s[i-1]=='-')vector[s[i+2]-'0']=-1;
					   if(s[i-1]=='+')vector[s[i+2]-'0']=1;
					      if(s[i-1]>'0'&&s[i-1]<='9')
					      {
						   if(i>1)
						   {
							   if(s[i-2]=='+')vector[s[i+2]-'0']=s[i-1]-'0';
						       if(s[i-2]=='-')vector[s[i+2]-'0']='0'-s[i-1];
						   }
						   else vector[s[i+2]-'0']=s[i-1]-'0';
						  }
		         }
			if(i==0)vector[s[i+2]-'0']=1;
          }
	
			if(s[i]=='x'&&s[i+1]!='^')
		{
		if(i==0)vector[1]=1;
		if(i!=0)
			{
				if(i==1)
					{if(s[i-1]!='-')vector[1]=s[i-1]-'0';
				if(s[i-1]=='-')vector[1]=-1;}
		           if(i>1)
			            {
				 if(s[i-2]=='-')vector[1]='0'-s[i-1];
			 if(s[i-2]=='+')vector[1]=s[i-1]-'0';
			 if(s[i-1]=='-')vector[1]=-1;
			 if(s[i-1]=='+')vector[1]=1;
			 }
		   }
		  }
		}

	}

int polycomb(char *s1, char *s2, char *buffer) 
{
	int v1[51]={0},v2[51]={0},v[51]={0},i,maxindex;
	
	analysis(s1,v1);
	analysis(s2,v2);
	for(i=0;i<51;i++)
		v[i]=v1[i]+v2[i];
	for(i=50;v[i]==0;i--);
	maxindex=i;
	for(i=maxindex;i>=0;i--)
		{if(i==maxindex&&v[i]!=1&&v[i]!=-1)printf("%dx^%d",v[i],i);
	    if(i==maxindex&&v[i]==1)printf("x^%d",i);
		if(i==maxindex&&v[i]==-1)printf("-x^%d",i);
		if(i!=maxindex&&i>1&&v[i]!=0&&v[i]!=1&&v[i]!=-1)printf("%+dx^%d",v[i],i);
	    if(i!=maxindex&&i>1&&v[i]==1)printf("+x^%d",i);
		if(i!=maxindex&&i>1&&v[i]==-1)printf("x^%d",i);
		if(i==1&&v[i]!=0&&v[i]!=1&&v[i]!=-1)printf("%+dx",v[i]);
		if(i==1&&v[i]!=0&&v[i]==1)printf("+x");
	    if(i==1&&v[i]!=0&&v[i]==-1)printf("-x");
		if(i==0&&v[i]!=0)printf("%+d",v[i]);}

	return (v[maxindex]);

	
}
int main(void)
{
	void analysis(char *s, int vector[]) ;
	int polycomb(char *s1, char *s2, char *buffer) ;
	char a[100],b[100],buffer[20];
	int vector[10],re;
	gets(a);
	gets(b);
	re=polycomb(a,b,buffer);
	printf(" %d",re);
	return 0;
}