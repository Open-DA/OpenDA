#include<stdio.h>
#include<string.h>
 void shift_solit_matrix(int m, int n, int *matrix, int number)
 {
	 int tmp[100],temp,i;
	 for(;number>m*n;number-=m*n);
	 for(;number<0;number+=m*n);
	 for(i=0;i<number;i++)
		 tmp[i]=matrix[i+n*m-number];
	 for(i=m*n;i>=number;i--)
		 matrix[i]=matrix[i-number];
     for(i=0;i<number;i++)
		matrix[i]= tmp[i];


 }
 int main (void)
 {
	 void shift_solit_matrix(int m, int n, int *matrix, int number);
	 int m,n,mtr[100],num;
	 int i,j,k;

	 scanf("%d %d",&m,&n);
	 if(m>0&&m<100&&n>0&&n<100)
	 {
		 for(i=0;i<m;i++)
			 for(j=0;j<n;j++)
			 {
				 if(i!=0&&j==0)scanf("%*c");
				 if(i%2==0)
				 scanf("%d",&mtr[i*n+j]);
				 if(i%2==1)
                 scanf("%d",&mtr[i*n+n-j-1]);
				 
			 }
     scanf("%d",&num);

	 shift_solit_matrix(m, n, mtr,num);
	 for(i=0;i<m;i++)
			 for(j=0;j<n;j++)
                 {
				 if(i!=0&&j==0)printf("\n");
			     if(i%2==0&&j!=0)
				 printf(" %d",mtr[i*n+j]);
				 if(i%2==1&&j!=0)
                 printf(" %d",mtr[i*n+n-j-1]);
				 if(i%2==0&&j==0)
				 printf("%d",mtr[i*n]);
				 if(i%2==1&&j==0)
                 printf("%d",mtr[i*n+n-1]);
			    }
	 }
	 else printf("ERROR");
	 return 0;

 }