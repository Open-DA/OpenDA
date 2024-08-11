#include<stdio.h>

int main (void)
{
	int x[20][2],i=0,j,k,len,tmp,big[10]={0};
    while(1)
		{
			scanf("%d%d",&x[i][0],&x[i][1]);
			if(x[i][0]==0)break;
			else i++;
	}
	while(1)
	{
		scanf("%d%d",&x[i][0],&x[i][1]);
	if(x[i][0]==0)break;
			else i++;
	}
	len=i;
	for(k=0;k<len;k++)
		for(j=0;j<len-1;j++)
			if(x[j][0]>x[j+1][0])
				      tmp=x[j][0],
					  x[j][0]=x[j+1][0],
					  x[j+1][0]=tmp,
					   tmp=x[j][1],
					  x[j][1]=x[j+1][1],
					  x[j+1][1]=tmp;
	for(k=1;x[k][0]!=0;k++)
		if(x[k][0]==x[k-1][0])
			{
				x[k-1][1]=(x[k-1][1]+x[k][1])/2;
				for(j=k;x[j-1][0]!=0;j++)
					 x[j][0]=x[j+1][0],
					  x[j][1]=x[j+1][1];
				k--;
		}
	for(k=0;x[k][0]!=0;k++)
		if(x[k][1]>x[big[0]][1])big[0]=k;
	for(k=0,i=0;x[k][0]!=0;k++)
		if(x[k][1]==x[big[0]][1])
			big[i]=k,i++;
	for(k=0;x[k][0]!=0;k++)
		printf("%d %d\n",x[k][0],x[k][1]);
	printf("(%d,%d)",x[big[0]][0],x[big[0]][1]);
	for(i=1;big[i]!=0;i++)
		printf("\n(%d,%d)",x[big[i]][0],x[big[i]][1]);
	return 0;
}