#include<iostream>
using namespace std;
class Airtime {
	int hrs,mint,sec;
	public :
		void setter();
		void getter();
Airtime (const Airtime &);
	Airtime operator=(const Airtime &  );
};
//Assignment operator overloding.
Airtime Airtime ::operator=(const Airtime & tt )
{
	hrs=tt.hrs-1;
	mint=tt.mint;
	sec=tt.sec+2;
	return *this;
	
}
//For copy constructor.
Airtime ::Airitme (const Airtime &tt)
{
	hrs=tt.hrs+10;
	mint=tt.mint;
	sec=tt.sec+10;

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
void Airtime::getter()
{
	
	cout<<"\n"<<hrs<<":"<<mint<<":"<<sec;
	cout<<endl;
}




int main()
{
Airtime t1,t2,t3;
t1=t3=t2;	

t1.setter();
t2.setter();
t3.setter();


t1.getter();
t2.getter();
t3.getter();	
	
	
	system("pause");
	return 0;
}
