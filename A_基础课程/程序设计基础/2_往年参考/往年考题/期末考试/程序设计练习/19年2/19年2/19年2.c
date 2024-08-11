#include<stdio.h>
#include<stdlib.h>
int main()
{
	void InputMatrix(int ***A,int ***B,int*m,int*n);
	void InputPosition(int *g,int*k,int m,int n);
	int** MatrixMerge(int **A,int**B,int m,int n,int g,int k);
	int maxi(int a,int b);
	int m,n,**A,**B,**C,g,k,i,j;
	InputMatrix(&A,&B,&m,&n);
	InputPosition(&g,&k,m,n);
	C=MatrixMerge(A,B, m, n, g,k);
	for(i=0;i<maxi((g+n),m);i++)
		for(j=0;j<maxi((k+m),n);j++)
		{
			printf("%-3d",C[i][j]);
			if(j==maxi((k+m),n)-1)
				printf("\n");
		}
	for(i=0;i<m;i++)
		free(*(A+i));
	free(A);
	for(i=0;i<n;i++)
		free(*(B+i));
	free(B);
	for(i=0;i<maxi((g+n),m);i++)
		free(*(C+i));
	free(C);
	return 0;
}
void InputMatrix(int ***A,int ***B,int*m,int*n)
{
	int i,j ;
	printf("请输入m，n\n");
	scanf("%d%d",m,n);
	*A=(int**)malloc(sizeof(int*)**m);
	for(i=0;i<*m;i++)
	{
		*(*A+i)=(int*)malloc(sizeof(int)**n);
	}
	*B=(int**)malloc(sizeof(int*)**n);
	for(i=0;i<*n;i++)
	{
		*(*B+i)=(int*)malloc(sizeof(int)**m);
	}
	printf("请输入矩阵A(%d*%d)\n",*m,*n);
	for(i=0;i<*m;i++)
		for(j=0;j<*n;j++)
		{
			scanf("%d",*(*A+i)+j);
		}
	
	printf("请输入矩阵B(%d*%d)\n",*n,*m);
	for(i=0;i<*n;i++)
		for(j=0;j<*m;j++)
		{
			scanf("%d",*(*B+i)+j);
		}
}
void InputPosition(int *g,int*k,int m,int n)
{
	printf("请输入两个表示合并位置的非负整数g、k：");
	scanf("%d%d",g,k);
	while(*g<0||*g>=m||*k<0||*k>=n)
	{
		printf("错误，重新输入");
		scanf("%d%d",g,k);
	}
}
int** MatrixMerge(int **A,int**B,int m,int n,int g,int k)
{
	int maxi(int a,int b);
	int **C,i,j;
	C=(int**)malloc(sizeof(int*)*maxi((g+n),m));
	for(i=0;i<(g+n);i++)
		*(C+i)=(int*)malloc(sizeof(int)*maxi((k+m),n));
	for(i=0;i<maxi((g+n),m);i++)
		for(j=0;j<maxi((k+m),n);j++)
		{
			C[i][j]=0;
		}
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			C[i][j]=A[i][j];
		}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			C[g+i][k+j]+=B[i][j];
		}
	return C;
}
int maxi(int a,int b)
{
	int k;
	if(a>b)
		k=a;
	else
		k=b;
	return k;
}