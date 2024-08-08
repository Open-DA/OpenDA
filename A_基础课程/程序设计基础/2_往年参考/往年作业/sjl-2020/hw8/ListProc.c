#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	char num[5];
	char cla;
	int height;
	struct student*next;

};
typedef struct student *infor;
typedef struct student stu;
infor MyCreate()
{
	infor L,p,q;
	char number[5],clas;
	int high;
	L=(infor)malloc(sizeof(stu));
	q=L;
	while(1)
	{
		scanf("%s ",number);
		scanf("%c ",&clas);
		scanf("%d%*c",&high);
		if(strcmp(number,"0000")==0)break;
		p=(infor)malloc(sizeof(stu));
		strcpy(p->num,number);
		p->cla=clas;
		p->height=high;
		q->next=p;
		q=p;
	}
	q->next=NULL;
	return L;

}
void MyPrint(infor L)
{
	infor p;
	p=L->next;
	printf("(%s %c %d)",p->num,p->cla,p->height);
	p=p->next;
	while(p!=NULL)
	{
		printf("->(%s %c %d)",p->num,p->cla,p->height);
		p=p->next;
	}
	printf("\n");
}
void MyFree(infor L)
{
	infor p=L,q;
	while(p!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	}

}
infor MySort(infor L)
{
	infor temp,temp1,LL,p,q;
    q=L->next;
	LL=(infor)malloc(sizeof(stu));
	p=(infor)malloc(sizeof(stu));
	strcpy(p->num,q->num);
	p->cla=q->cla;
	p->height=q->height;
	LL->next=p;
	p->next=NULL;
	q=q->next;
	while(q!=NULL)
	{
		temp=LL;temp1=LL->next;
		p=(infor)malloc(sizeof(stu));
		strcpy(p->num,q->num);
	    p->cla=q->cla;
	    p->height=q->height;
		while(temp1->cla<q->cla)
		{
			temp=temp1,temp1=temp1->next;
			if(temp1==NULL)break;
		}
		if(temp1==NULL)
		{
			temp->next=p;
		    p->next=NULL;
		}
		else if(temp1->cla==q->cla)
		{
			while(temp1->height<q->height&&temp1->cla==q->cla)
		    {
			temp=temp1,temp1=temp1->next;
			if(temp1==NULL)break;
		    }
			  if(temp1==NULL)
		       {
			   temp->next=p;
		       p->next=NULL;
		       }
			  else if(temp1->height==q->height)
			  {
				  while(strcmp(temp1->num,q->num)<0&&temp1->height==q->height&&temp1->cla==q->cla)
		              {
			          temp=temp1,temp1=temp1->next;
			          if(temp1==NULL)break;
		              }
			          if(temp1==NULL)
		                  {
			              temp->next=p;
		                  p->next=NULL;
		                  }
					  else
					  {
						  temp->next=p;
		                  p->next=temp1;
					   }
			  }
			  else
		      {
			  temp->next=p;
		      p->next=temp1;
		      }
		}
		else
		{
			temp->next=p;
		    p->next=temp1;
		}
	q=q->next;
	}
	return LL;
}
void MySearch(infor L)
{
	char searchclass;
	int k=0,searchnum;
	infor p=L->next,q;
	scanf("%c",&searchclass);
	scanf("%d",&searchnum);
	while(p!=NULL)
	{
		if(p->cla==searchclass)
			{
				k++;
				if(k==searchnum){ printf("(%s %c %d)",p->num,p->cla,p->height);break;}
		    }
		p=p->next;
	}
	if(k!=searchnum)printf("error");
}
infor inverse(infor L)
{
	infor p,q,LLL,s;
	LLL=(infor)malloc(sizeof(stu));
	s=(infor)malloc(sizeof(stu));	
	q=L->next;
	strcpy(s->num,q->num);
	s->cla=q->cla;
	s->height=q->height;
	s->next=NULL;
	LLL->next=s;
	q=q->next;
	while(q!=NULL)
	{
		p=(infor)malloc(sizeof(stu));
		strcpy(p->num,q->num);
	    p->cla=q->cla;
	    p->height=q->height;
		LLL->next=p;
		p->next=s;
		s=p;
		q=q->next;
	}
	return LLL;
}
int main ()
{
	infor MyCreate();
	infor MySort(infor L);
	infor inverse(infor L);
	void MyPrint(infor L);
	void MySearch(infor L);
	void MyFree(infor L);
	infor L,LL,LLL;
	L=MyCreate();
	MyPrint(L);
	LL=MySort(L);
	MyPrint(LL);
	LLL=inverse(LL);
	MySearch(LLL);
	MyFree(L);
	MyFree(LL);
	MyFree(LLL);
	return 0;
}