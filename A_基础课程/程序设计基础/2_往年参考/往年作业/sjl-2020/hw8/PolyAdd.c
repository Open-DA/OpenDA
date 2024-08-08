#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	int n;
	struct node*next;
};
typedef struct node *poly;
typedef struct node po;

void createlist(poly L,int n)
{
poly p,q;
p=L;
for(;n>0;n--)
{
	q=(poly)malloc(sizeof(po));
	scanf("%d%d",&q->a,&q->n);
	p->next=q,p=q;
}
p->next=NULL;
}
poly sum(poly L1,poly L2)
{
	void createlist(poly L,int n);
	poly L,temp,l,m=L1,p=L2->next,t;
	int i;
	L=(poly)malloc(sizeof(po));
	l=L;
	m=m->next;
	l->next=(poly)malloc(sizeof(po));
	l=l->next;
	l->a=m->a,l->n=m->n;
	l->next=NULL;
	m=m->next;
	while(m!=NULL)
	{
			t=(poly)malloc(sizeof(po));
			l->next=t;
			t->next=NULL;
			t->a=m->a;
			t->n=m->n;
			m=m->next;
			l=l->next;
		
	}
	while(p!=NULL)
	{
		temp=L;l=L->next;
		while((l->n)<(p->n))
		{
			if(l->next==NULL) break;
			else temp=l,l=l->next;
		}
		if(l->next==NULL&&(l->n)<(p->n))
		{
			t=(poly)malloc(sizeof(po));
			l->next=t;
			t->next=NULL;
			t->a=p->a;
			t->n=p->n;
		}
		else
		{
			if((l->n)==(p->n))
			{l->a+=p->a;
			}
			if((l->n)>(p->n))
			{
			t=(poly)malloc(sizeof(po));
			temp->next=t;
			t->next=l;
			t->a=p->a;
			t->n=p->n;
			}
		}
		p=p->next;
	}
	return(L);
}
void destroylist(poly L)
{
	poly p,q=L;
	while(q!=NULL)
	{p=q->next;
	free(q);
	q=p;
	}
}
int main (void)
{
	void createlist(poly L,int n);
	poly sum(poly L1,poly L2);
	void destroylist(poly L);
	poly L1,L2,L,p;
	int n1,n2,k=0;
	L1=(poly)malloc(sizeof(po));
	L2=(poly)malloc(sizeof(po));
	scanf("%d\n",&n1);
	createlist(L1,n1);
	scanf("%d",&n2);
	createlist(L2,n2);
	L=sum(L1,L2);
	p=L->next;
	while(p!=NULL)
	{
		if(p->a!=0)
		k++;
		p=p->next;
	}
	if(k==0)printf("0");
	else
	{
	printf("%d\n",k);
	p=L->next;
	while(p!=NULL)
	{
		if((p->a)!=0)
		printf("%d %d\n",p->a,p->n);
		p=p->next;
	}
	}
	destroylist(L);
	destroylist(L1);
	destroylist(L2);
	return 0;
}


