#include<iostream>
using namespace std;
# define max 3
int tp;
class mystack
{
	int top;
	
	int arr[max];
public:
mystack() :top(-1) {}
	int & operator[](int );
	int gettop();
	void setter();
	void getter();
};
int& mystack::operator[](int tp)
{
	if (tp <= max - 1 && top >= 0)
		return arr[tp];
	else
	{
		cout << "\n Error!";
	exit(-1); 
	}
		
}
void mystack::getter()
{
	cout << endl;
	for (int i = 0; i < max;i++)
	{
		cout << arr[tp--] << endl;
	}
}
void mystack::setter()
{
	int d;
	for (int i = 0; i < max; i++)
	{
		cout << "\n Enter the value at "<<i + 1 << "  ";
		cin >> d;
			arr[++tp] = d;
	}
}
int mystack::gettop()
{
	return top;
}
int main()
{

	mystack s;
	tp = s.gettop();
	s.setter();
	s.getter();

	cout << "\n";
	system("pause");
	return 0;
}
