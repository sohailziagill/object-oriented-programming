#include<iostream>
#include<conio.h>
using namespace std;

const int LIMIT=100;

class safearay{
 int arr[LIMIT];
public:
 void putel(int index, int value){ if(index>-1 && index<LIMIT) arr[index]=value;}
 int getel(int index){ if(index>-1 && index<LIMIT) return arr[index];}};

int main()
{
 cout<<"### Programmed By Amahdy(MrJava) ,right restricted.~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 cout<<"-------------------------------------------------------------------------------\n"<<endl;
 
 safearay sa1; int temp=12345;

 do{
    sa1.putel(7, temp); temp=sa1.getel(7);
 cout<<temp;
 cout<<"\n\n !Press c to continue or any key to exit."<<endl<<endl;
 }while(getch()=='c');
}
