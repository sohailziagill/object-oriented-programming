#include<iostream>
using namespace std;
int main()
{
	int n;
	int *iptr = 0;
	cout<<"Enter a number  ";
	cin>>n;
	iptr=&n;
	cout<<"\n The entered number is  "<<n;
	cout<<"\n The entrered number's address is   "<<iptr;
	cout<<endl;
	
	
	
	return 0;
}
