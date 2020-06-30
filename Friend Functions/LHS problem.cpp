#include<iostream>
using namespace std;
class Airtime {
	int hrs,mint,sec;
	public:
	/*	Airtime()
		{                      //Default Argument.
		hrs=mint=sec=0;
		}*/
	Airtime(int H=0,int M=0,int S=0): hrs(H),mint(M),sec(S)
	{
		
	}
	void setter()
{
	cout<<"\n Enter the hrs  ";
	cin>>hrs;
	cout<<"\n Enter the minuts  ";
	cin>>mint;
	cout<<"\n Enter the seconds  ";
	cin>>sec;
}
    friend Airtime operator+ ( Airtime & ,  Airtime & );

	void getter();
};


void Airtime::getter()
{
	
	cout<<"\n"<<hrs<<":"<<mint<<":"<<sec;
	cout<<endl;
}

Airtime operator+ (  Airtime & TT1, Airtime & TT2)
{
	Airtime temp;
    temp.hrs=TT1.hrs+TT2.hrs;		
	temp.mint=TT1.mint +TT2.mint;
	temp.sec=TT1.sec+TT2.sec;
	return temp ;
}



int main()
{
	Airtime t1,t2,t3;
    t1.setter();
    t2.setter();
	
	t1.getter();
	
	t3=t1+10;
	t3.getter();
	t1.getter();
	system ("pause");
	return 0;
}

