#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	int num;
	char name[21];
	struct student *next;
};
typedef struct student*infor;
typedef struct student stu;
int createlist(infor L)
{
	int number;
	char namename[21],tag;
	infor p,q=L,temp;
	scanf("%d",&number);
	scanf("%c",&tag);
	scanf("%s",namename);
	p=(infor)malloc(sizeof(stu));
	p->num=number;
	strcpy(p->name,namename);
	p->next=NULL;
	q->next=p;
	q=p;
	while(1)
	{
	scanf("%d",&number);
	scanf("%c",&tag);
	if(tag!=',')break;
	scanf("%s",namename);
	q=L->next;
	temp=L;
	while((q->num)<number)
	{
		
		if(q->next==NULL)break;
		else temp=q,q=q->next;
	}
	if(q->next==NULL&&(q->num)<number)
	{
	p=(infor)malloc(sizeof(stu));
	p->num=number;
	strcpy(p->name,namename);
	p->next=NULL;
	q->next=p;
	}
	else
	{

	    p=(infor)malloc(sizeof(stu));
	    p->num=number;
	    strcpy(p->name,namename);
	    p->next=q;
		temp->next=p;
    }
	}


	return(number);
}
void print(infor L)
{
	if(L->next==NULL)printf("%d, %s\n",L->num,L->name);
	else print(L->next),printf("%d, %s\n",L->num,L->name);

}
void search(infor L,int numb)
{
	infor temp=L,s=L->next;
	while(1)
	{
		if(s->num==numb&&s!=NULL)
		{
			if(temp==L)
			{s=s->next,printf("%d, %s",s->num,s->name);break;}
			else if(s->next==NULL) 
			{printf("%d, %s",temp->num,temp->name);break;}
			else 
			{printf("%d, %s\n",temp->num,temp->name);s=s->next,printf("%d, %s",s->num,s->name);break;}
		}
		temp=s;
		s=s->next;
		if(s==NULL)
		{printf("ERROR");break;}
	}
}
int main (void)
{
	int createlist(infor L);
	void search(infor L,int num);
	infor L,s,temp;
	int searchnum,k=0;
	L=(infor)malloc(sizeof(stu));
	searchnum=createlist(L);
	s=L->next;
	while(s!=NULL)
		k++,s=s->next;
	printf("%d\n",k);
	print(L->next);
	search(L,searchnum);
	while(L!=NULL)
	{
		temp=L->next;
		free(L);
		L=temp;
	}
	return 0;

}