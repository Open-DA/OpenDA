#include<iostream>
#include<string.h>
using namespace std;
class birthday
{
private:
	char year[5];
	char month[3];
	char day[3];
public:
	birthday(){};
	birthday(char* year,char* month,char* day);
	void showbirthday();
};
birthday::birthday(char* year,char* month,char* day)
{
	strcpy(this->year,year);
	strcpy(this->month,month);
	strcpy(this->day,day);
}
void birthday::showbirthday()
{
	cout<<"Birthday: "<<year<<"-"<<month<<"-"<<day<<endl;

}
class people
{
private:
	char name[11];
	char number[7];
	char sex[7];
	birthday date;
	char id[20];
public:
	people
		(char name[11],
	     char number[7],
	     char sex[7],
	     birthday date,
	     char id[20]);
	void showpeople();
};
people::people(char name[11], char number[7], char sex[7], birthday date, char id[20])
{
	strcpy(this->name,name);
	strcpy(this->number,number);
	strcpy(this->sex,sex);
	this->date=date;
	strcpy(this->id,id);
}
void people::showpeople()
{
	cout<<"Name: "<<name<<endl;
	cout<<"Number: "<<number<<endl;
	cout<<"Sex: "<<sex<<endl;
	date.showbirthday();
	cout<<"ID: "<<id<<endl;

}
int main()
{
	void match(char*id,char*year,char*month,char*day);
	char name[11], number[7],sex[7], id[20];
	char year[5],month[3],day[3],birth[11];
	scanf("%s\n%s\n%s\n%s\n%s",name,number,sex,birth,id);
	for(int i=0;i<4;i++)
	year[i]=birth[i];
	year[4]='\0';
	for(int i=0;i<2;i++)
	month[i]=birth[5+i];
	month[2]='\0';
	for(int i=0;i<2;i++)
	day[i]=birth[8+i];
	day[2]='\0';
	match(id,year,month,day);
	birthday date(year,month,day);
	people somebody(name,number,sex,date,id);
	somebody.showpeople();
	return 0;
}
void match(char*id,char*year,char*month,char*day)
{
	char b1[9],b2[9];
	strcpy(b1,year);
	strcat(b1,month);
	strcat(b1,day);
	for(int i=0;i<8;i++)
	{
		b2[i]=id[i+6];
	}
	b2[8]='\0';
	if(strcmp(b1,b2)!=0)
		printf("birthday mismatch!\n");
}