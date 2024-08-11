#include<stdio.h>

void order(int m, int n, int matrix[20][20])
{int i,j,k,temp,sum[10]={0};
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			for(k=0;k<m-1;k++)
				if(matrix[k][i]>matrix[k+1][i])
					temp=matrix[k][i],
					matrix[k][i]=matrix[k+1][i],
					matrix[k+1][i]=temp;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			sum[i]=sum[i]+matrix[j][i];
	for(i=0;i<n;i++)
		for(j=0;j<n-1;j++)
			if(sum[j]>sum[j+1])
				{
					temp=sum[j],
				    sum[j]=sum[j+1],
				    sum[j+1]=temp;
				    for(k=0;k<m;k++)
						temp=matrix[k][j],
					    matrix[k][j]=matrix[k][j+1],
					    matrix[k][j+1]=temp;
			}
		

}
int main (void)
{
	void order(int m, int n, int matrix[20][20]);
	int m,n,matrix[20][20],i,j,k;
	for(i=0;i<20;i++)
		matrix[i][0]=0;
    scanf("%d %d",&m,&n);
	if(m>0&&m<100&&n>0&&n<100)
	{for(j=0;j<m;j++)
		{for(k=0;k<n;k++)
			scanf("%d",&matrix[j][k]);
	          
	}
order(m,n,matrix);
for(j=0;j<m;j++)
		{for(k=0;k<n-1;k++)
			printf("%d ",matrix[j][k]);
	          printf("%d\n",matrix[j][k]);
        }
	}
	else
		printf("ERROR");
return 0;

}