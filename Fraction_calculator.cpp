//**************************************************************************
//Name :  Taimoor Mansha
//Title:   To Show Numbers in a/b form
//Approach : Using object and Class(oop)
//Compiler : Visual Studio 19
//Dated : 26/Oct/19
//Compiling date : 26/Oct/19
//International Islamic University Islamabad
//***************************************************************************

#include <iostream>
using namespace std;
class fraction
{
    int a,b,c,d,r;
    char m; 
  
  public:
      fraction():a(0),b(0),c(0),d(0)
	  	  {	 }
    
   void getter();
   void setter();  
};

void fraction::getter()
{ 
     cout<<a<<m<<b<<" + "<<c<<m<<d<<" = "<<a*d+b*c<<m<<d*b<<endl;	
}

void fraction::setter()
{ 
     cout<<"Enter first friction value(a/b):  ";
	 cin>>a>>m>>b;
	 cout<<"Enter second friction value(c/d):  ";
	 cin>>c>>m>>d;
	 	
}

int main()
{
	int ch;
    fraction f;
    while(1)
	{  
	   do{  
	        cout<<"Enter the relevant key: \n";
	        cout<<"1) Enter new value: \n"
	              "2) For Display result: \n"
	              "3) For Exit: \n";
	        cin>>ch;
			if(ch<1 || ch>3)
			  cout<<"\nError!\nInput Again: ";   
          }while(ch<1 || ch>3);
	   switch(ch)
	   {
	   	 case 1:
			f.setter();
		 break;
		 case 2:
			f.getter();
		 break;	
		 case 3:
			exit(0);
		 break;		   	
	   	
	   }
   	  
    }
	system("pause");
	return 0;
}
