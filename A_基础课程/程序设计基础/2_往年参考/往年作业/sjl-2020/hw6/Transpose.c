#include<stdio.h>

void transpose(int m, int n, int (*matrix)[100])
{
	int temp[100][100],i,j;
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	{
		temp[i][j]=matrix[j][i];
    }
	for(i=0;i<100;i++)
	for(j=0;j<100;j++)
	{
		matrix[i][j]=temp[i][j];
    }

}
void multiply(int m, int n,  int q, int p, int (*matrix1)[100], int (*matrix2)[100], int (*M)[100])
{
	int i,j,k;
	for(i=0;i<100;i++)
	for(j=0;j<100;j++)
	{M[i][j]=0;}
	for(i=0;i<m;i++)
	for(j=0;j<p;j++)
	for(k=0;k<n;k++)
	M[i][j]+=matrix1[i][k]*matrix2[k][j];
}
int main (void)
{  
	void transpose(int m, int n, int (*matrix)[100]);
	void multiply(int m, int n,  int p, int q, int (*matrix1)[100], int (*matrix2)[100], int (*M)[100]);
	int m,n,p,q,mtr1[100][100],mtr2[100][100],i,j,M[100][100];
	scanf("%d %d",&m,&n);
	scanf("%d %d",&p,&q);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			{
					if(i!=0&&j==0)scanf("%*c");
                    scanf("%d",&mtr1[i][j]);
			}
	for(i=0;i<p;i++)
	for(j=0;j<q;j++)
			{
					if(j==0)scanf("%*c");
                    scanf("%d",&mtr2[i][j]);
			}

	transpose(p,q,mtr2);
	multiply(m,n,q,p,mtr1,mtr2,M);
	
	if(m>0&&n>0&&p>0&&q>0&&m<100&&n<100&&p<100&&q<100)
	for(i=0;i<q;i++)
	  for(j=0;j<p;j++)
			{
					if(i!=0&&j==0)printf("\n");
                    if(j==0)printf("%d",mtr2[i][j]);
					else printf(" %d",mtr2[i][j]);
			}
	else printf("ERROR") ; 
	  if(n==q)
	  for(i=0;i<m;i++)
	      for(j=0;j<p;j++)
			{
					if(j==0)printf("\n");
                    if(j==0)printf("%d",M[i][j]);
					else printf(" %d",M[i][j]);
			}
	  else printf("\nINVALID");
return 0;
}
