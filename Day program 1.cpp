#include<iostream>
#include<string>
using namespace std;
class daytype
{
	int i=0;
	string wday[7];
	string day1,nxtday1,preday1,addday1;
	public:
  daytype() 
{ //Constructor definition
wday[0] = "Mon";
wday[1] = "Tue";
wday[2] = "Wed";
wday[3] = "Thu";
wday[4] = "Fri";
wday[5] = "Sat";
wday[6] = "Sun";
}
       void  setday(); 
       void preday(); 
       void nxtday(); 
       void addday();
       void print();
       void setter();
};
void menu()
{
       cout <<"******************MENU********************"<< endl;
       cout <<"\tEnter 'Sun' for 'Sunday'"<< endl;
       cout <<"\tEnter 'Mon' for 'Monday'"<< endl;
       cout <<"\tEnter 'Tue'for 'Tuesday'"<< endl;
       cout <<"\tEnter 'Wed'for'Wednesday'"<< endl;
       cout <<"\tEnter 'Thu' for 'Thursday'"<< endl;
       cout <<"\tEnter 'Fri' for 'Friday'"<< endl;
       cout <<"\tEnter 'Sat' for'Saturday'"<< endl;
       cout<<endl;
}
void daytype::setter()
{
    cout<<"Enter the day  ";
    cin>>day1;
}
void  daytype::setday()
{
	if(day1==wday[0])
	{
	i=0;
	}
	else if(day1==wday[1])
	{i=1;}
	else if(day1==wday[2])
	{i=2;}
	else if(day1==wday[3])
	{i=3;}
	else if(day1==wday[4])
	{i=4;}
	else if(day1==wday[5])
	{i=5;}
	else if(day1==wday[6])
	{i=6;}
	else 
	{i=7;}
	cout<<"\n The day number is "<<i;
}
void daytype:: preday()
{
	if(i==0)
	preday1=wday[6];
	else
	preday1=wday[i-1];
	
}
void daytype ::nxtday()
{
	if(i==6)
nxtday1=wday[0];
	else
	nxtday1=wday[i+1];
}
void daytype::addday()
{
	int a;
	cout<<"\n Enter the number of add days   ";
	cin>>a;
	a=a+i;
	a=a% 7;
	addday1=wday[a];
 } 
 void daytype ::print()
 {
 	cout<<"\n The current day is  "<<day1;
 	cout<<"\n The previous day is "<<preday1;
 	cout<<"\n The next day is     "<<nxtday1;
    cout<<"\n The added day is    "<<addday1;
 	cout<<endl;
 }
 int main()
 {
 	menu();
 	daytype d;
 	d.setter();
 	d.setday();
 	d.preday();
 	d.nxtday();
   	d.addday();
 	d.print();
 	cout<<endl;
 	system ("pause");
 	return 0;
 }
