#include<iostream>
using namespace std;
class Airtime{
int hrs,mint,sec;
	public:	
		airtime()
		{
			hrs=mint=sec=0;
		}
		
		void setter();
		void getter ();
		void increment();
		void decrement();
};


void menu(int &x)
{
	do { 
				cout<<"\n<<Welcome to the program.>>"<< endl << endl;
				cout<<"Enter the choice.\n\n ";
		cout << "1 : To input Arrrival time ." << endl;
		cout << "2 : To output the Arrival time." << endl;
		cout << "3 : To Increment Arrival time." << endl;
		cout << "4 : To Decrement Arrival time." << endl;
		cout << "5 : To input Departure  time ." << endl;
		cout << "6 : To output Departure  time ." << endl;
		cout << "7 : To Increment  Departure time." << endl;
		cout << "8 : To Decrement  Departure time." << endl;
		cout << "9 : To Exit." << endl << endl;
	cin >> x;
		if ( x < 0 ||  x>9)
				cout << "Invalid output...";
	}
	 while ( x < 0 ||  x>9);



}



void Airtime:: setter()
{
	do
	{
		cout<<"Enter the Hours (12Hour)Format: ";
		cin>>hrs;
		cout<<endl;
	}
	while(hrs<0 || hrs>12);
	
	do
	{
		cout<<endl<<"Enter the Minutes: ";
		cin>>mint;
		cout<<endl;
	}
	while(mint<0 || mint>59);
	
	do
	{
			cout<<"Enter the Seconds: ";
	   		cin>>sec;
			cout<<endl;
	}
	while(sec<0 || sec>59);
}


void Airtime:: getter()
{
	cout<<"Time is ";
	cout<<hrs<<" : "<<mint<<" : "<<sec;
	cout<<endl<<endl;
}


void Airtime:: increment()
{
	hrs++;
	mint++;
	sec++;
}

void Airtime:: decrement()
{
	hrs--;
	mint--;
	sec--;
}


int main()
{
Airtime arr,dep;
int x=0,loop=1;
do{

menu(x);

switch(x)
{
	case 1: {
		
		arr.setter();
		break;
			}
	case 2:{
			 
		             arr.getter();              
					 				 break;
				}
		case 3:
		{
			arr.increment();
			 break;	
		}
		case 4:
		             arr.decrement();                  break;
		case 5:{
		dep.setter();
					                  break;
									   }
			case 6:{
	dep.getter();				
					   break;
}
		case 7:{
dep.increment( );        
					   break;
				}
		case 8:
		{
		dep.decrement( );
		break;
		}
		case 9:
			{
			loop=0;
	break;	
	}
			}

}while(loop==1);







	
system ("pause");
return 0;	
	
}
