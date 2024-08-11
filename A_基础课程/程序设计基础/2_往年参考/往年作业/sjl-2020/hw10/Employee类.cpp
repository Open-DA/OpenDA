 #include<iostream>
#include<cstring>
#include<string>
#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;
class Employee
{
private:
	char name[20];
	char city[20];
	char street[100];
	int postcode;
public:
	Employee(char *name,char*city,char*street,int postcode);
	void change_name(char *newname);
	void display();
};
Employee::Employee(char *name,char*city,char*street,int postcode)
{
	strcpy(this->name,name);
	strcpy(this->city,city);
	strcpy(this->street,street);
	this->postcode=postcode;

}
void Employee::change_name(char *newname)
{
	strcpy(this->name,newname);
}
void Employee::display()
{
	cout<<"Name: "<<name;
	cout<<"City: "<<city;
	cout<<"Address: "<<street;
	cout<<"Postcode: "<<postcode<<endl;
}
int main()
{
	char name[20],city[20],street[100],newname[20];
	int postcode;
	fgets(name,10,stdin);
	fgets(city,10,stdin);
	fgets(street,100,stdin);
	scanf("%d\n",&postcode);
	fgets(newname,10,stdin);
	Employee a(name,city,street,postcode);
	a.display();
	a.change_name(newname);
	a.display();
	return 0;
}