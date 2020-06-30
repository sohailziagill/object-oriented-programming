#include<iostream>
using namespace std;
float myfun(int *n1,int *n2)
{

float s;
s=*n1+*n2;
return s;



}



int main ()
{
	
	int n1,n2;
	float  s;
	cout<<"Enter the two numbers  ";
	cin>>n1>>n2;
	s=myfun(&n1,&n2)
;
cout<<"\n The sum of two numbers are   "	
<<s<<endl;
return 0;	
	
	
	
}
