#include<iostream>
using namespace std;
 int *tempPtr;
ptrInput(int arr[][6])
{
	int *inttmp=&arr[0][0];
    tempPtr = &arr[0][0]; 
   for(int i=0;i<36;i++)	
	{
		cin>>*inttmp;
		inttmp++;
	}
}

ptrOutput(int arr[][6])
{
   
   for(int i=0;i<36;i++)	
	{
		
		cout<<*tempPtr<<" \n";
		tempPtr++;
	} 
}

int main()
{
	int arr[6][6];
	ptrInput(arr);
	ptrOutput(arr);
	system("pause");
	return 0;
}
