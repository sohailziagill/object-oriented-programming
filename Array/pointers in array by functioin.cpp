#include<iostream>
using namespace std;

//The name of array passing by pointers
float  myfun(int *ilptr,int nn)
{
//to revined the array.
int *tprl=ilptr;	
	for(int i=0;i<nn;i++)
	{
		*(ilptr+i)=*(ilptr+i)+10;
	}
	for(int i=0;i<nn;i++)
	cout<<*ilptr++<<endl;
}

int main()
{
	
	int l[100],nn;
	cout<<"Enter the number of array  ";
	cin>>nn;
	for(int i=0;i<nn;i++){
	
	cout<<"\n Enter the value in index  "<<i+1<<"      ";
	cin>>l[i];
	}
	myfun(l,nn);
	return 0;
	
	
	
	
}
