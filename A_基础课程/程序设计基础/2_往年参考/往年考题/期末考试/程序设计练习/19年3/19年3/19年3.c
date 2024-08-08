#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	char num[5];
	char cla;
	int h;
	struct student *next;

};
typedef struct student list;
typedef struct student *linklist;
linklist mycreate()
{
	linklist L,p,q;
	char n[5];
	p=L=(linklist)malloc(sizeof(list));
	scanf("%s",n);
	n[4]=0;
	while(strcmp(n,"0000")!=0)
	{
		q=(linklist )malloc(sizeof(list));
		strcpy(q->num,n);
		scanf(" %c %d\n",&q->cla,&q->h);
		p->next=q;
		p=q;
		scanf("%s",n);
		n[4]=0;
	}
	p->next=NULL;
	scanf(" %*c %*d\n");
	return L;
}
void Myprint (linklist L)
{
	linklist s=L->next;
	printf("(%s %c %d)",s->num,s->cla,s->h);
	s=s->next;
	while(s!=NULL)
	{
		printf("->(%s %c %d)",s->num,s->cla,s->h);
		s=s->next;
	}
	printf("\n");
}
void MyFree(linklist L)
{
	linklist p=L,q;
	while(p!=NULL)
	{
		q=p->next;
		free(p);
		p=q;

	}
}
void MySort(linklist L)
{
	int i,j,k=0;
	linklist s=L->next,p,q,temp;
	while(s!=NULL)
	{
		k++;
		s=s->next;
	}
	p=L->next;
	q=p->next;
	for(i=0;i<k;i++)
	{
		s=L;
		p=L->next;
	    q=p->next;
		for(j=0;j<k-1;j++)
		{
			if(p->cla>q->cla)
			{
				s->next=q;
				p->next=q->next;
				q->next=p;
				s=s->next;
				q=p->next;
			}
			else if(p->cla<q->cla)
			{
				s=s->next;
				p=p->next;
				q=q->next;

			}
			else if(p->cla==q->cla)
			{
				if(p->h>q->h)
				{
				s->next=q;
				p->next=q->next;
				q->next=p;
				s=s->next;
				q=p->next;
				}
				else if(p->h<q->h)
			    {
				s=s->next;
				p=p->next;
				q=q->next;
			    }
				else if(p->h==q->h)
				{
				    if(strcmp(p->num,q->num)>0)
				      {
				        s->next=q;
				        p->next=q->next;
				        q->next=p;
				        s=s->next;
				        q=p->next;
				       }
				     else if(strcmp(p->num,q->num)<0)
	                     {
				          s=s->next;
				          p=p->next;
				          q=q->next;
			             }
				}
			}
		}
	}

}
void Mysearch(char c,int k,linklist L)
{
	linklist s=L->next,p;
	int i,j,m=0;
	while(s!=NULL)
	{
		if(s->cla==c)
			m++;
		s=s->next;
	}
	if(k>m)
	{
		printf("未找到相关信息");
	}
	else
	{
		s=L->next;
		while(s->cla!=c)
		{
			s=s->next;
		}
		for(i=m-k;i>0;i--)
		{
			s=s->next;
		}
	    printf("(%s %c %d)",s->num,s->cla, s->h);
	}
}
int main()
{
	linklist mycreate();
	void Myprint (linklist L);
	void MyFree(linklist L);
	void MySort(linklist L);
	void Mysearch(char c,int k,linklist L);
	linklist L;
	char c;
	int k;
	L=mycreate();
	Myprint (L);
	MySort( L);
	Myprint (L);
	scanf("%c %d",&c,&k);
	Mysearch(c,k,L);

}
