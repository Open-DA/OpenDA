#include<stdio.h>
#include<stdlib.h>

 struct stu 
 {
  int num;
  struct stu *next;

}; 
 typedef struct stu *number;
 typedef struct stu numb;
 void createlist(number*L,int N)
 {
	 int n=N;
	 number s,p;
	 *L=(number)malloc(sizeof(numb));
	 s=*L;
	 s->next=NULL;
	 for(;n>0;n--)
	 {
		  p=(number)malloc(sizeof(numb));
		  p->num=N-n+1;
		  s->next=p;
		  s=p;
	 }
	 s->next=NULL;

 }
 number dele(number s,int m)
 {
	number temp1,temp2;
	int i;
	temp1=s;
	for(i=0;i<m-1;i++)
    temp1=(temp1->next);
	temp2=temp1->next;
	temp1->next=temp2->next;
	free(temp2);
	return (temp1);
 }
 int main()
 {
	 void createlist(number*L,int N);
	 number dele(number L,int m);
	 number l,*L=&l,*s=&l,p,temp;
	 int N,i,m;
	 scanf("%d\n",&N);
	 scanf("%d",&m);
	 createlist(L,N);
	 p=l;
	 for(i=0;i<N;i++)
	 p=p->next;
	 p->next=l->next;
	 if(m!=1)
	 for(i=0;i<N-1;i++)
	 *s=dele(*s,m);
	 if(m==1)
	 {*s=p;
	 p=p->next;
	 for(i=0;i<N-1;i++)
	 temp=p->next,free(p),p=temp;
	 p->next=NULL;}
	 printf("%d",(*s)->num);
	 free(*s);
	 *s=NULL;
	 free(*L);
	 *L=NULL;
	 return 0;
 }

