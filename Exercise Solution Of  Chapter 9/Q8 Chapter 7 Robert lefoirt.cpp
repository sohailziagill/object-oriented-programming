#include<iostream>
#include<conio.h>
using namespace std;

const int limit=100;

class safearray{
 int arr[limit];
public:
 void setter();
 int getter();
 };
 int safearray::getter()
 {
 	int index;
 	cout<<"\n The position or index number that you want to see   ";
 	cin>>index;
  if(index>-1 && index<limit)
   return arr[index];
   }
void safearray::setter()
{
	int index,value;
	cout<<"\n Enter the index number or position   ";
	cin>>index;
	cout<<"\n Enter the value at index  "<<index<<"  ";
	cin>>value;
 if(index>-1 && index<limit) 
 arr[index]=value;
 }
int main()
{
	char op;
cout<<"-------------------------------------------------------------------------------\n"<<endl;
 cout<<"### Programmed By Sohail Zia Gill ,right restricted.~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 cout<<"-------------------------------------------------------------------------------\n"<<endl;
 
 safearray sa1; int temp=123;//https://www.onlinegdb.com/#tab-stdin45;
 do{
    sa1.setter();
	 temp=sa1.getter();
 cout<<"\nThe value is  "<<temp;
 cout<<"\n\n !Press c to continue or any key to exit."<<endl<<endl;
 cin>>op;
 }while(op=='c'||op=='C');

    cout<<endl;
    system ("pause");
    return 0;
    
}
