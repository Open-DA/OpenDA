#include<iostream>
#include<string>
using namespace std;
class client
{
private:
	static string servename;
	static int clientnum;
public:
	static void ChangeServerName(string a);
	static void changenum(int a);
	string showname(){return servename;};
	int shownum(){return clientnum;} ;
};
string client::servename="Server1";
int client::clientnum=0;
void client::ChangeServerName(string a)
{
	servename=a;

}
void client::changenum(int a)
{
	clientnum+=a;
}
int main()
{
	client cli;
	cout<<"server name: "<<cli.showname()<<endl;
	cout<<"client number: "<<cli.shownum()<<endl;
	int n;
	scanf("%d",&n);
	string t,newname;
	int num;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		if(t=="rename")
		{
			cin>>newname;
			cli.ChangeServerName(newname);
			cout<<"server name: "<<cli.showname()<<endl;
	        cout<<"client number: "<<cli.shownum()<<endl;
		}
		else if(t=="add")
		{
			cin>>num;
			cli.changenum(num);
			if(cli.shownum()>100000)
			{
				cli.changenum(100000-cli.shownum());
			}
			cout<<"server name: "<<cli.showname()<<endl;
	        cout<<"client number: "<<cli.shownum()<<endl;
		}
		else if(t=="sub")
		{
			cin>>num;
			cli.changenum(-num);
			if(cli.shownum()<0)
			{
				cli.changenum(0-cli.shownum());
			}
			cout<<"server name: "<<cli.showname()<<endl;
	        cout<<"client number: "<<cli.shownum()<<endl;
		}
	}
	return 0;
}