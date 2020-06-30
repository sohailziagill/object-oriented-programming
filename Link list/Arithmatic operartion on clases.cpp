#include<iostream>
using namespace std;
class airtime {
	int hrs,min,sec;
	public:
		void setter();
		int  timeinsec();
};
void airtime::setter()
{
	cout<<"\n Enter the time in hrs     ";
	cin>>hrs;
	cout<<"\n Enter the time in minutes ";
	cin>>min;
	cout<<"\n Enter the time in seconds ";
	cin>>sec;
}
int airtime::timeinsec()
{
return (hrs*3600+min*60+sec);	
}
int main()
{
	airtime t1,t2;
	t1.setter();
	t2.setter();
    int res;
    res=t1.timeinsec();
    cout<<"\n The time of t1 is in seconds   "<<res;
    res=t2.timeinsec();
    cout<<"\n The time of t2 is in seconds   "<<res;
	
	
	cout<<endl;
	system("pause");
	return 0;
}
