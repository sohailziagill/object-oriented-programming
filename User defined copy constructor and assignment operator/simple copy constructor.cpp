 #include<iostream>
using namespace std;
class Airtime {
int hrs,sec,mint;
public:
void getter();
void setter();
Airtime (const Airtime &);
Airtime(const Airtime&);
};
Airtime::Airtime(const Airtime& tt)
{
	cout << "\n============= Copy Cons ==============\n";
	hrs = tt.hrs +2;
	mint = tt.mint +2;
	sec = tt.sec +2;

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
	Airtime t3(t1);
	cout<<"\n The T1 is ";
	t1.getter();
	cout<<"\n The T2 is ";
	t2.getter();
	cout<<"\n The T3 is ";
	t3.getter();
	cout<<endl;
	system ("pause");
	return 0;
}
