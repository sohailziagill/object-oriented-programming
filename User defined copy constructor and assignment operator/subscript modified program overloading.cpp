#include<iostream>
using namespace std;
int x;
class safearray{

	int l[10];
	public :
		 int & operator[](int  );

};
int & safearray :: operator[](int pos)
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
s[pos]=val;
		cout<<"\n Enter the  pos in array       ";
	cin>>pos;
r=	s[pos];
	cout<<"\n "<<r;
	cout<<endl;
	system ("pause ");
	return 0;
}
