#include<iostream>
using namespace std;
class Airtime {
	int hrs,mint,sec;
	public :
		Airtime ()
		
	{
		hrs=mint=sec=0;
		}
	Airtime operator--();
		void getter ();
	   void  setter ();
};
	
Airtime  Airtime :: operator--()
{
	--hrs;
	--mint;
	--sec;
	return *this;
	
}


void Airtime ::setter ()
{
	do
	{
		cout<<"Enter the Hours (12Hour)Format: ";
		cin>>hrs;
		cout<<endl;
	}
	while(hrs<0 || hrs>12);
	
	do
	{
		cout<<endl<<"Enter the Minutes: ";
		cin>>mint;
		cout<<endl;
	}
	while(mint<0 || mint>59);
	
	do
	{
			cout<<"Enter the Seconds: ";
	   		cin>>sec;
			cout<<endl;
	}
	while(sec<0 || sec>59);
}



void Airtime ::getter ()
{
	cout<<"\n"<<hrs<<":"<<mint<<":"<<sec<<endl;
}
int main()
{
	Airtime t1,t2;
	t1.setter();
	t2.setter();
--t1;
t2=--t1;
	t1.getter();
cout<<endl;
	t2.getter();
	cout<<endl;
	system ("pause");
	return 0;
}
