#include<iostream>
#define max 10
using namespace std;
class mystack
{
int l[max];
 int top;
public:
	mystack():top(-1){}
	void push(int );
	int pop();
    int access();
	void display();
};
int mystack::access()
{
	return top; 
}
void mystack::display()
{
for(int i=top;i>=0;i--)
cout<<"\n "<<l[i];
}
void mystack:: push(int d)
{
	
	//Over flow check;
	if(top<max-1)
	{
	
	top++;
	l[top]=d;
}
else{

cout<<"\n Over flow   ";
exit(-1);
}
}
int mystack::pop()
{
	if(top>=0)
	{
		return l[top--];
	}
	else
	{
		cout<<"\n Under flow   ";
		exit(-1);
	}
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


s.push(d);
}

	s.display();
	temp=s.access();
cout<<"\n The value of temp is "<<temp;
	cout<<endl;
	system("pause");
	return 0;
}
