#include<iostream>
using namespace std;
class Airtime {
	int hrs,mint,sec;
	public:
		Airtime()
		{
		hrs=mint=sec=6;
		}
		Airtime(int hrs,int mint,int sec):hrs(3),mint(7),sec(5) {
		}
	
	void getter();
 Airtime  operator+=(const Airtime & );
};

void Airtime::getter()
{
	
	cout<<"\n"<<hrs<<":"<<mint<<":"<<sec;
	cout<<endl;
}

Airtime Airtime :: operator+= (const Airtime & tt)
{
	
	hrs+=tt.hrs;
	mint+=tt.mint;
	sec+=tt.sec;
	return Airtime(hrs,mint,sec);
}



int main()
{
	Airtime t1,t2,t3;

	
	t1.getter();
	
	t3=t1+=t2;
	t3.getter();
	t1.getter();
	system ("pause");
	return 0;
}

