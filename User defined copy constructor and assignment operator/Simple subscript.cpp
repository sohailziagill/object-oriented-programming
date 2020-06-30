#include<iostream>
using namespace std;
int x;
class safearray{

	int l[10];
	public :
		 void setter(int ,int );
	int  getter(int );
};
void safearray ::setter(int val,int pos)
{
	if((pos>=0)&&(pos<=10))
	l[pos]=val;
	else
	{
		cout<<"\n Invalid data ";
		cout<<"\n Termination";
		
	}
}
 int safearray:: getter(int pos)
{
	if((pos>=0)&&(pos<=10))
	return l[pos];
	else
	{
		cout<<"\n Invalid data ";
		cout<<"\n Termination";
	
	}	
}
int main()
{
	int r;
	int val,pos;
	safearray s;
	cout<<"\n Enter the value and pos in array     ";
	cin>>val>>pos;
	s.setter(val,pos);
		cout<<"\n Enter the  pos in array       ";
	cin>>pos;
r=	s.getter(pos);
	cout<<"\n "<<r;
	cout<<endl;
	system ("pause ");
	return 0;
}
