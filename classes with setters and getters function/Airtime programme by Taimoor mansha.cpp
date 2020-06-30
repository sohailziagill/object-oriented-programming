#include <iostream>
#include<iomanip>
using namespace std;

void menu();
void arrivalmenu();
void departuremenu();

class Airtime
{
	private:
		int hour,min,sec;
	public:
		Airtime()
		{
			hour=min=sec=0;
		}
		void setter();
		void getter();
		void increment();
		void decrement();
		void check();
};

void Airtime:: setter()
{
	do
	{
		cout<<"Enter the Hours (12Hour)Format: ";
		cin>>hour;
		cout<<endl;
	}
	while(hour<0 || hour>12);
	
	do
	{
		cout<<endl<<"Enter the Minutes: ";
		cin>>min;
		cout<<endl;
	}
	while(min<0 || min>59);
	
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
	cout<<setfill('0')<<setw(2)<<hour<<":"<<setfill('0')<<setw(2)<<min<<":"<<setfill('0')<<setw(2)<<sec;
	cout<<endl<<endl;
}

void Airtime:: increment()
{
	hour++;
	min++;
	sec++;
}

void Airtime:: decrement()
{
	hour--;
	min--;
	sec--;
}

void Airtime:: check()
{
	if(sec>=60)
		{
			sec=sec-60;
			min++;
		}
	if(min>=60)
		{
			min=min-60;
			hour++;	
		}
	if(hour>11)	
		{
			hour-=12;
			min=59;
			sec=59;
		}
	if(min<0)	
		{
			cout<<"Seconds Below Range: "<<endl;
		}
	if(min<0)
		{
			cout<<"Minutes Below Range: "<<endl;
		}	
	if(hour<0)
		{
			cout<<"Hour Below Range: "<<endl;
		}
					
	if(sec<0 && min<0 && hour<0)
		{
			cout<<"Second Below Range: "<<endl;
			cout<<"Minutes Below Range: "<<endl;
			cout<<"Hour Below Range: "<<endl;
		}
			
}

void arrivalmenu()
{
	cout<<"1.\tInput Arrival Time."<<endl;
	cout<<"2.\tOutput Arrival Time."<<endl;
	cout<<"3.\tIncrement Arrival Time."<<endl;
	cout<<"4.\tDecrement Arrival Time."<<endl;
	cout<<"5\tTo Enter main Menu"<<endl<<endl<<endl;
}

void departuremenu()
{
	cout<<"1.\tInput Arrival Time."<<endl;
	cout<<"2.\tOutput Departure Time."<<endl;
	cout<<"3.\tIncrement Departure Time."<<endl;
	cout<<"4.\tDecrement Departure Time."<<endl;
	cout<<"5\tTo Enter main Menu"<<endl<<endl<<endl<<endl;
}

void menu()
{
	cout<<"\t\t\t\t\t\t\t\t\t\t<<Welcome to Program>>"<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t<MAIN MENU>\n\n"<<endl;
	cout<<"1.\tArrival."<<endl;
	cout<<"2.\tDeparture."<<endl;
	cout<<"-999\tEnd Program"<<endl<<endl<<endl;
}



int main()
{
	Airtime arr,dep;
	int choice=0,arrchoice=0,depchoice=0;
	do
	{
		menu();
		cout<<endl;
		cout<<"Enter Your choice: ";
		cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 1:
				{
					do
					{	
						arrivalmenu();
						cout<<endl<<"Enter Your choice: ";
						cin>>arrchoice;
						cout<<endl;
					
						switch(arrchoice)
							{
								case 1:
									{
										cout<<"Enter Arrival Time "<<endl<<endl;
										arr.setter();
										cout<<endl;
										system("cls");
										break;	
									}
								case 2:
									{
										cout<<" Flight Arrival Time is "<<endl<<endl;
										arr.getter();
										arr.check();
										cout<<endl;
										break;										
									}
								case 3:
									{
										cout<<" Increment in Arrival Time "<<endl<<endl;
										arr.increment();
										arr.check();
										cout<<endl;
										break;	
									}	
								case 4:
									{
										cout<<" Decrement in Arrival Time "<<endl<<endl;
										arr.decrement();
										arr.check();
										cout<<endl;
										break;
									}
								default:
										cout<<"Invalid choice";		
										cout<<endl;		
							}
					}
					while(arrchoice!=5);
					system("cls");
					break;		
				}
			case 2:
				{
					do
					{
						departuremenu();
						cout<<endl<<"Enter Your choice: ";
						cin>>depchoice;
						cout<<endl;
						switch(depchoice)
							{
								case 1:
									{
										cout<<"Enter departure Time "<<endl;
										dep.setter();
										cout<<endl;
										system("cls");
										break;
									}
								case 2:
									{
										cout<<"Flight departure Time is "<<endl<<endl;
										dep.getter();
										arr.check();
										cout<<endl;
										break;
									}
								case 3:
									{
										cout<<" Increment in departure Time "<<endl<<endl;
										dep.increment();
										dep.check();
										cout<<endl;
										break;
									}	
								case 4:
									{
										cout<<" Decrement in departure Time "<<endl<<endl;
										dep.decrement();
										dep.check();
										cout<<endl;
										break;
									}
								default:
										cout<<"Invalid choice";				
							}
					}
					while(depchoice!=5);
					system("cls");
					break;		
				}	
		}
	}
	while(choice!=-999);

	system("pause");
	return 0;
}



