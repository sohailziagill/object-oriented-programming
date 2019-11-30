#include<iostream>
#define max 10
using namespace std;
class mystack
{
int l[max];
 int top;
public:
	mystack():top(-1){}
    int access();
int & operator[](int );
};
int & mystack::operator[](int pos)
{
	if(pos>=0||pos<max)
	return l[pos];
	else
	cout<<"Out of bound ";
}
int mystack::access()
{
	return top; 
}


int main()
{
	mystack s;
int d,temp;
temp=s.access();
cout<<"\n The value of temp is "<<temp;
for(int i=0;i<3;i++)
{
	
	cout<<"\n Enter the value at "<<i+1<<"   ";
	cin>>d;
	s[i]=d;
}
int r;
for(int i=0;i<3;i++)
{
r=s[i];
cout<<"\n\n"<<r;
}
	temp=s.access();
cout<<"\n The value of temp is "<<temp;
	cout<<endl;
	system("pause");
	return 0;
}
