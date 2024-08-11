#include<stdio.h>
void shift_2d_matrix(int m, int n, int (*matrix)[100], int *number)
{
	 int i,j,k,temp;
	 for(;number[0]>n;number[0]-=n);
	 for(;number[0]<0;number[0]+=n);
	 for(;number[1]>m;number[1]-=m);
	 for(;number[1]<0;number[1]+=m);
	 for(i=0;i<m;i++)
	 for(j=0;j<number[0];j++)
			 {
				 temp=matrix[i][n-1];
				 for(k=n-1;k>0;k--)
					  matrix[i][k]=matrix[i][k-1];
				 matrix[i][0]=temp;
		 }
     for(i=0;i<n;i++)
		 for(j=0;j<number[1];j++)
			 {
				 temp=matrix[m-1][i];
				 for(k=m-1;k>0;k--)
					  matrix[k][i]=matrix[k-1][i];
				 matrix[0][i]=temp;
		 }
}
int main (void)
 {
	 void shift_2d_matrix(int m, int n, int (*matrix)[100], int *number);
	 int m,n,mtr[100][100],num[2];
	 int i,j,k;

	 scanf("%d %d",&m,&n);
	 if(m>0&&m<100&&n>0&&n<100)
	 {
		 for(i=0;i<m;i++)
			 for(j=0;j<n;j++)
			 {
				 if(i!=0&&j==0)scanf("%*c");
				 scanf("%d",&mtr[i][j]);
             }
			   scanf("%d%d",&num[0],&num[1]);
			  shift_2d_matrix(m,n,mtr,num);
         for(i=0;i<m;i++)
			 for(j=0;j<n;j++)
			 {
				 if(i!=0&&j==0)printf("\n");
				 if(j==0)printf("%d",mtr[i][j]);
				 else printf(" %d",mtr[i][j]);
             }
	 }
  
				 
				 
				 
				 
				 else printf("ERROR");
	 return 0;
     }