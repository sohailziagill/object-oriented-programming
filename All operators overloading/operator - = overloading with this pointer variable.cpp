#include<iostream>
using namespace std;
class Airtime {
	int hrs,mint,sec;
	public:
		Airtime()
		{
		hrs=mint=sec=0;
		}
	void setter();
	
	void getter();
 bool  operator>(const Airtime & );
};
void Airtime ::setter()
{
	cout<<"\n Enter the time in hrs mint and secs   ";
	cin>>hrs>>mint>>sec;
}
void Airtime::getter()
{
	
	cout<<"\n"<<hrs<<":"<<mint<<":"<<sec;
	cout<<endl;
}

bool Airtime :: operator>(const Airtime & tt)
{
	
	if(hrs>tt.hrs)
	return true;
	if (hrs==tt.hrs &&mint>tt.mint)
	return true;
	if(hrs==tt.hrs&&mint==tt.mint&&sec>tt.sec)
	return true;
	else
	return false;
}



int main()
{
	Airtime t1,t2;

	
	t1.setter();
	t2.setter();
	if(t1>t2)
	t1.getter();
	else
	t2.getter();
	cout<<endl;
	system ("pause");
	return 0;
}

