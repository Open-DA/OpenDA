#include <stdio.h>
void inputMatrix(int M1[][100],int M2[][100],int cr[])
{
	int i,j,k;
	scanf("%d%d",&cr[0],&cr[1]);
	for(i=0;i<cr[0];i++)
		for(j=0;j<cr[1];j++)
			scanf("%d",&M1[i][j]);
	for(i=0;i<cr[1];i++)
		for(j=0;j<cr[0];j++)
			scanf("%d",&M2[i][j]);


}
void InputPosition(int gk[],int cr[])
{
	scanf("%d%d",&gk[0],&gk[1]);cr[2]=0;
	
	while(gk[0]<0||gk[0]>=cr[0]||gk[1]<0||gk[1]>=cr[1])
		{cr[2]++;
	scanf("%d%d",&gk[0],&gk[1]);
	}

}
void MatrixMerge(int M1[][100],int M2[][100],int gk[],int cr[])
{
	int i,j,m,n,p,q;
	m=cr[0],n=cr[1];
	for(i=m;i<gk[0]+n;i++)
		for(j=0;j<n||j<gk[1]+m;j++)
		M1[i][j]=0;
	for(i=0;i<gk[0]+n||i<m;i++)
		for(j=n;j<gk[1]+m;j++)
		M1[i][j]=0;
	for(i=gk[0],p=0;i<gk[0]+n;i++,p++)
		for(j=gk[1],q=0;j<gk[1]+m;j++,q++)
		{
			M1[i][j]+=M2[p][q];
}


}
int main (void)
{
	void inputMatrix(int M1[][100],int M2[][100],int cr[]);
	void InputPosition(int gk[],int cr[]);
	void MatrixMerge(int M1[][100],int M2[][100],int gk[],int cr[]);
	int M1[100][100],M2[100][100],gk[2],cr[3],m,n,i,j;
     inputMatrix(M1,M2,cr);
	 InputPosition(gk,cr);
	 MatrixMerge(M1, M2,gk,cr);
	m=cr[0];
	n=cr[1];
	if(n<gk[1]+cr[0])n=gk[1]+cr[0];
	if(m<gk[0]+cr[1])m=gk[0]+cr[1];
	for(i=0;i<cr[2];i++)
	printf("ERROR\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
{
			if(i!=0&&j==0)printf("\n%d ",M1[i][j]);
			else printf("%d ",M1[i][j]);}
	return 0;
}