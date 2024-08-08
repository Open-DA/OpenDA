#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct infor
{
	char number[11];
	char name[11];
	int salary;
	struct infor *next;
} ;
typedef struct infor *staff;
typedef struct infor staffn;
int main (void)
{
	staff link(staff list1 ,staff list2,int n );
	void sort(staff list ,staff sorted[] , int n);
	void createlist(staff *list,int n);
	void destroylist(staff list);
	int  n1,n2,n,i;
	staff *sorted,Link1,Link2,*list1=&Link1,*list2=&Link2,newlink;
	scanf("%d\n",&n1);
	createlist(list1,n1);
	scanf("\n");
    scanf("%d\n",&n2);
	createlist(list2,n2);
	n=n1+n2;
	sorted=(staff*)malloc(n*sizeof(staff));
	newlink=link(Link1 ,Link2, n);
	sort(newlink,sorted ,n);
    for(i=0;newlink->next!=NULL;i++)
		{
			newlink=newlink->next;
			printf("{%s, %s, %d}\n",newlink->number,newlink->name,newlink->salary);
	}
	printf("\n");
	for(i=0;i<n;i++)
		printf("{%s, %s, %d}\n",sorted[i]->number,sorted[i]->name,sorted[i]->salary);
destroylist(Link1);
destroylist(Link2);
destroylist(newlink);
return 0;
}
staff link(staff list1 ,staff list2,int n )
{
staff newlist;
staff p=list1,q=list2,t;
int i,j,TEMP;
char temp[11];
newlist=(staff)malloc(sizeof(staffn));
t=newlist;
while(p->next!=NULL)
{p=p->next;
t->next=(staff)malloc(sizeof(staffn));
t=t->next;
strcpy(t->number,p->number),
strcpy(t->name,p->name),
t->salary=p->salary;
}
while(q->next!=NULL)
{q=q->next;
t->next=(staff)malloc(sizeof(staffn));
t=t->next;
strcpy(t->number,q->number),
strcpy(t->name,q->name),
t->salary=q->salary;
}
t->next=NULL;
for(i=0;i<n;i++)
	{
		p=(newlist->next),q=p->next;
	    for(j=0;j<n-1;j++)
		{if(strcmp((p->number),(q->number))>0)
			{
			strcpy(temp,q->number),
			strcpy(q->number,p->number),
			strcpy(p->number,temp),
			strcpy(temp,q->name),
			strcpy(q->name,p->name),
			strcpy(p->name,temp),
			TEMP=p->salary,
			p->salary=q->salary,
			q->salary=TEMP;
	        }
		p=p->next,q=q->next;}
}

return newlist;
}
void sort(staff list ,staff sorted[] , int n)
{
	int i,j;
	staff p,temp;
	p=list;
	p=p->next;
	for(i=0;p!=NULL;i++)
	{sorted[i]=p;
	p=p->next;
    }
	for(i=0;i<n;i++)
		for(j=0;j<n-1;j++)
			if(sorted[j]->salary>sorted[j+1]->salary)
            temp=sorted[j],
			sorted[j]=sorted[j+1],
			sorted[j+1]=temp;

	

}
void createlist(staff *list,int n)
{
staff p,s;
*list=(staff)malloc(sizeof(staffn));
(*list)->next=NULL;
p=*list;
for(;n>0;n--) 
{
	s=(staff)malloc(sizeof(staffn));
    scanf("%s %s %d",s->number,s->name,&s->salary);
          if(n!=1)scanf("\n");                                    
    p->next=s,p=s;
}
p->next=NULL;
}
void destroylist(staff list)
{staff q,p=list;
while(p!=NULL)
{
q=p->next;
free(p);
p=q;
}
list=NULL;
}
