#include<stdio.h>
#include<string.h>
typedef struct
{
	char name[50];
	char stu_no[20];
	char birthplace[50];
	char age[10];
	char gender[10];
}Student;
int input(Student infor[128])
{
	int i, k, N;
	char temp[200] = {'\0'}, *T;
	scanf("%d", &N);
	scanf("%*c");
	for(i=0;i<N;i++) 
	{
		gets(temp);
		k=1;
		T=strtok(temp,",");
		while (T!=NULL) 
		{
			switch (k) 
			{
				case 1: strcpy(infor[i].name, T); break;
				case 2: strcpy(infor[i].stu_no, T+1); break;
				case 3: strcpy(infor[i].birthplace, T+1); break;
				case 4: strcpy(infor[i].age, T+1); break;
				case 5: strcpy(infor[i].gender, T+1); break;
				default: break;
			}
			k++;
			T= strtok(NULL, ",");
		}
	}
return N;
}

void output(Student infor[128], int N)
{
	int i;
	for (i=0;i<N;i++) 
	{
		printf("%s, %s, %s, %s, %s\n",infor[i].name,infor[i].stu_no,infor[i].birthplace,infor[i].age,infor[i].gender);
	}
}

void search(Student infor[128], int N)
{
	char temp1[200] = {'\0'}, temp2[5][50], *p;
	int i,j,k,t=0,point;
    memset(temp2, '\0', sizeof(temp2));
	gets(temp1);
while (strcmp(temp1, "quit") != 0) 
	{
		k=0;t=0;
		p = strtok(temp1, ",");
		while (p!=NULL)
		{
			strcpy(temp2[k], p);
			k++;
			p = strtok(NULL, ",");	
	    }
	for(i=0;i<N;i++)
	{
	if(compare(infor+i,temp2,k)==1)
		point=i,t++;
		
	}
		
		if(t==1)
			printf("%s, %s, %s, %s, %s\n",infor[point].name,infor[point].stu_no,infor[point].birthplace,infor[point].age,infor[point].gender);
		else
			printf("error\n");
		gets(temp1);
	}
}


int compare(Student *infor, char temp[5][50], int k)
{int i,m;
	for (i=0;i<k;i++) 
	{if (strcmp(infor->name, temp[i]) == 0 ||strcmp(infor->stu_no, temp[i]) == 0 ||strcmp(infor->birthplace,temp[i]) == 0 ||strcmp(infor->age, temp[i]) == 0 ||strcmp(infor->gender,temp[i]) == 0)
	  m=1;
	else 
	{m=0;break;}
	}
	return m;
}
int main()
{
	Student infor[128];
	int N = 0;
	N = input(infor);
	output(infor, N);
	search(infor, N);
	return 0;
}