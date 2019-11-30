#include<iostream>
using namespace std;
class Airtime
{
	
	public:int hrs,mint,sec;
		setters();
		getters();
		timeinsec();
		 addtime(const Airtime);
};
void Airtime ::addtime(const Airtime & tt)
	{
	Airtime temp;
	temp.hrs=hrs+tt.hrs;
		temp.mint=mint+tt.mint;
		temp.sec=sec+tt.sec;
		return temp;
	}
	
void Airtime ::timeinsec()
{
	return (hrs*3600+mint*60+sec);
}
void Airtime :: setters()
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
}

void Airtime:: getter(Airtime t3)
{
	cout<<"Time is ";
	cout<<t3.hrs<<" : "<<t3.mint<<" : "<<t3.sec;
	cout<<endl<<endl;
}

 int main()
 {
 	
 	
 	Airtime t1(1,2,3);
 	Airtime t2(4,5,6),t3;
 	long result;
 	result=t1 timeinssec();
 	t3=t1 addtime(t2);
 	
 	getter(t3);
 	system("pause");
 	return 0;
  } 
