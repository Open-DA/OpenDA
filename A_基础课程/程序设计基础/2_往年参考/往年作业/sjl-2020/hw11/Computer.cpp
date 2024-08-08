#include<iostream>
#include<string>
using namespace std;

class CPU
{
public:
	CPU(){};
	CPU(int rank,int frequency, float voltage);
	void run();
	void stop();
private:
	int rank;
	int frequency;
	float voltage;
};
CPU::CPU(int rank,int frequency, float voltage)
{
	this->rank=rank;
	this->frequency=frequency;
	this->voltage=voltage;
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
class RAM
{
private:
	string type;
public:
	RAM(){};
	RAM(string type);
	void run();
	void stop();

};
RAM::RAM(string type)
{
	this->type=type;
}
void RAM::run()
{
	cout<<"RAM RUN"<<endl;
	cout<<"RAM type: "<<type<<endl;
}
void RAM::stop()
{
	cout<<"RAM STOP"<<endl;
}
class CDROM
{
	private:
	string type;
public:
	CDROM(){};
	CDROM(string type);
	void run();
	void stop();
};
CDROM::CDROM(string type)
{
	this->type=type;
}
void CDROM::run()
{
	cout<<"CDROM RUN"<<endl;
	cout<<"CDROM type: "<<type<<endl;
}
void CDROM::stop()
{
	cout<<"CDROM STOP"<<endl;
}
class computer
{
private:
	CPU cpu;
	RAM ram;
	CDROM cdrom;
public:
	computer(CPU cpu,RAM ram,CDROM cdrom);
	void run();
	void stop();

};
computer::computer(CPU cpu,RAM ram,CDROM cdrom)
{
	this->cpu=cpu;
	this->ram=ram;
	this->cdrom=cdrom;
}
void computer::run()
{
	cout<<"Computer RUN"<<endl;
	cpu.run();
	ram.run();
	cdrom.run();

}
void computer::stop()
{
	cdrom.stop();
	ram.stop();
	cpu.stop();
	cout<<"Computer STOP"<<endl;
}
int main()
{
	int cpur,cpuf,i=0;
	float cpuv;
	string ramr,cdr,t;
	while(i<3)
	{
	cin>>t;
	if(t=="CPU")
	cin>>cpur>>cpuf>>cpuv;
	else if(t=="RAM")
	cin>>ramr;
	else if(t=="CDROM")
	cin>>cdr;
	i++;
	}
	CPU cpu(cpur,cpuf,cpuv);
	RAM ram(ramr);
	CDROM cdrom(cdr);
	computer com(cpu,ram,cdrom);
	com.run();
	com.stop();
	return 0;
}