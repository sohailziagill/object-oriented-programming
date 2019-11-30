#include<iostream>
using namespace std;
class Airtime
{
	int hrs,mint,sec;
	public :
		Airtime ()
		{
			hrs=mint=sec=6;
		}
		void setter();
		void getter();
		Airtime  operator%(const Airtime & );
};
Airtime Airtime :: operator%(const Airtime & tt)
{
	Airtime temp;
	temp.sec=sec%tt.sec;
	temp.mint=mint%tt.mint;
	temp.hrs=hrs%tt.hrs;
	return temp; 
	
}

void Airtime :: getter()
{
	cout<<"\n"<<hrs<<":"<<mint<<":"<<sec<<endl;
}
void Airtime :: setter()
{
do 
{

	cout<<"\nEnter the hours (in formet of 12 hrs)    ";
	cin>>hrs;
}while(hrs<0||hrs>12);

do 
{
	cout<<"\n Enter the minutes    ";
	cin>>mint;
}while(mint<0||mint>59);
do
{
	cout<<"\nEnter the seconds   ";
	cin>>sec;
}while(sec<0||sec>59);




}
int main()
{
	Airtime t1,t2,t3;
	t1.setter();
	t2.setter();
	t3=t1%t2;
	t1.getter();
	t2.getter();
	t3.getter();
	cout<<endl;
	system ("pause");
	return 0;
}
