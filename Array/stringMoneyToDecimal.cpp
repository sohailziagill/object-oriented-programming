//**************************************************************************
//Name :  Taimoor Mansha
//Title:  String Currency to Numeric convert
//Approach : Using object and Class(oop)
//Compiler : Visual Studio 19
//Dated : 26/Oct/19
//Compiling date : 26/Oct/19
//International Islamic University Islamabad
//***************************************************************************


#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include<cstring>
#include<math.h>
#include<string>
#define size 100
using namespace std;
class currency
{
     long double money;
     int temp;
     char s[size];
     char normal[size];
     int n=0;
  
  public:
  	void getter();
  	void setter();
   	void processing();
};

void currency::getter()
{
	temp=strlen(s);
	cout<<"Your Money (";
	for(int i=0;i<temp+1;i++)
	  cout<<s[i];
    cout<<") in rupees is:";
    for(int i=1;i<=n;i++)
    cout<<money;
}

void currency::processing()
{   
   for(int i=0;i<temp+1;i++)
        if(s[i]>='0' && s[i]<='9')
             {            	
             	normal[n]=s[i];
             	n++;
			 }
//	money = _atold(normal);		 
}
void currency::setter()
{
   cout<<"Enter the Money";
   cin>>s;	
}
int main()
{
	currency c;
	c.setter();
	c.processing();
	c.getter();
	
	system("pause");
	return 0;
}
