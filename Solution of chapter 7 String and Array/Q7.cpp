#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string>
using namespace std;

long mstold(char strm[])
{
 string s=" 0123456789"; char ret[20];
 //long double x;
 for(int i=0, j=0; i<strlen(strm); i++)
  if(s.find(strm[i])<20) ret[j++]=strm[i];
  return atol(ret);
}

int main()
{
 cout<<"### Programmed By Amahdy(MrJava) ,right restricted.~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 cout<<"-------------------------------------------------------------------------------\n"<<endl;
 
 char mon[20];

 do{
 cout<<"Enter a monetary value: "; cin>>mon; cout<<mstold(mon);
 cout<<"\n\n !Press c to continue or any key to exit."<<endl<<endl;
 }while(getch()=='c');
}
