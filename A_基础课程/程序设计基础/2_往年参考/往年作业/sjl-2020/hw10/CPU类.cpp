#include<iostream>
using namespace std;
enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7};
class CPU
{
public:
	CPU(int rank,int frequency, float voltage);
	void run();
	void stop();
	~CPU();
private:
	CPU_Rank rank;
	int frequency;
	float voltage;
};
CPU::CPU(int rank,int frequency, float voltage)
{
	this->rank=(CPU_Rank)rank;
	this->frequency=frequency;
	this->voltage=voltage;
	cout<<"CPU Construct"<<endl;
}
void CPU::run()
{
	cout<<"CPU RUN"<<endl;
	cout<<"CPU rank: P"<<rank<<endl;
	cout<<"CPU frequency: "<<frequency<<" MHz"<<endl;
	printf("CPU voltage: %.2f V\n",voltage);
}
void CPU::stop()
{
	cout<<"CPU STOP"<<endl;
}
CPU::~CPU()
{
	cout<<"CPU Destroy"<<endl;
}
int main()
{
	int r,f;
	float v;
	cin>>r>>f>>v;
	CPU c1(r,f,v);
	c1.run();
	c1.stop();

}