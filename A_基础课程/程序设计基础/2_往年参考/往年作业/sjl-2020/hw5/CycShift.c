#include<stdio.h>

void shift_vector(int m, int *vector, int number)
{int*p,array_end,i;
while(number<0)
{number+=m;
}
while(number>m)
{number-=m;
}
for(i=0;i<number;i++)
{
	array_end=*(vector+m-1);
    for(p=vector+m-1;p>vector;p--)
	*p=*(p-1);
    *vector=array_end;
}
}
int main (void)
{
	int*vector,m,number,arr[100],i;
	void shift_vector(int m, int *vector, int number);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	scanf("%d",&arr[i]);
	scanf("%d",&number);
	vector=arr;
    if(m>0&&m<100)
    {
		shift_vector(m,vector,number);
	     for(i=0;i<m-1;i++)
	     printf("%d ",arr[i]);
		 printf("%d",arr[i]);
	}
    else printf("ERROR");
	return 0;
}
