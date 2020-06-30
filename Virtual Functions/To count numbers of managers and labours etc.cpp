#include<iostream>
#include<string>
#include<typeinfo>
# define size 10
using namespace std;
class emp {
protected:
	string ename;
	int eID;
	string cnic;
public:
	virtual void isout()=0;
	virtual void getter()const;
	virtual void setter();
};
//////////////////////////////////////////////////////////////////////////////////////////
void emp::getter()const
{
	cout << " \nID:  " << eID << " \n Name " << ename << " \n CNIC  " <<cnic << endl;
}
///////////////////////////////////////////////////////////
void emp::setter()
{
	cout << "Enter Employ ID#  " << endl;
	cin >> eID;
	cout << "Enter Employ Name  " << endl;
	cin>>ename;
	cout << "Enter Employ CNIC " << endl;
	cin>>cnic;
}
///////////////////////////////////////////////////////////////////////////////////////////
class manager :public emp
{
protected:
	string title;
	float cdues;
public:
	void getter()const;
	void setter();
		void isout();

};
///////////////////////////////////////////////////////////////////////////////////////////////
void manager ::isout()
{
	if(cdues<10000)
	cout<<"\n Yes, this is outstanding   ";
}
//////////////////////////////////////////////////////////////////////////////////////////
void manager::getter()const
{
	emp::getter();
	cout << " \nManager Title         " << title << "\nClub dues      " << cdues << endl;
}
///////////////////////////////////////////////////////////
void manager::setter()
{
emp::setter();
   cout<<"Enter Club Dues  "<<endl;
   cin>>cdues;
	   cout<<"Enter Manager Title  "<<endl;
	   cin>>title;
	   }
/////////////////////////////////////////////////////////////////////////////////////////////////////

class scientist :public emp
{
	string field;
	int publi;
public:
	void getter()const;
	void setter();
	 void isout();

};
//////////////////////////////////////////////////////////////////////////////////////////
void  scientist::isout()
{
	if(publi<5)
	cout<<"\n Yes, this is outstanding   ";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

void scientist::getter()const
{
	emp::getter();
	cout << "\n Feild        " <<field;
	cout<< "\n  no Of publications      " << publi;
}
///////////////////////////////////////////////////////////
void scientist::setter()
{
	emp::setter();
	cout << "Enter Scientist field  " << endl;
	cin>>field;
	cout << "Enter Scientist number of publications  " << endl;
	cin >> publi;
}
////////////////////////////////////////////////////////////////////////////////////////////////
class labour :public emp
{

	string shift;
	float hrs;
public:
	void getter()const;
	void setter();
	 void isout();

};
//////////////////////////////////////////////////////////////////////////////////////////
void  labour::isout()
{
	if(hrs<8)
	cout<<"\n Yes, this is outstanding   ";
}
///////////////////////////////////////////////////////////////////////////////////////////
void labour::getter()const
{
	emp::getter();
	cout << "\n Shift      " << shift << " \n Worked Hours        " << hrs;
}
///////////////////////////////////////////////////////////
void labour::setter()
{
	emp::setter();
	cout << "Enter Labour Shift  " << endl;
	cin.ignore(10, '\n');
	getline(cin, shift);
	cout << "Enter Labour worked hrs  " << endl;
	cin >> hrs;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
class forman:public labour
{
float salary;
public:
 void setter();
 void getter();	
 void isout();
};
////////////////////////////////////////////////////////////////////////////////////////////////////
void forman ::setter()
{
	labour::setter();
	cout<<"\n Enter the salary of forman  ";
	cin>>salary;
}
//////////////////////////////////////////////////////////////////////////////////////////
void  forman::isout()
{
	if(salary<100000)
	cout<<"\n Yes, this is outstanding   ";
}
///////////////////////////////////////////////////////////////////////////////////////
void forman::getter()
{
	labour::getter();
	cout<<"\n The salary is   "<<salary;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	unsigned int count =0;
	
	int ch=0,mc=0,sc=0,lc=0,fc=0;
	emp *p[size];
	/*manager m1;
	scientist s1;
	forman f1;
	labour l1;*/
	do
	{
		
	cout<<"\n Enter 1 for manager data entry ";
	cout<<"\n Enter 2 for Scientist data entry ";
	cout<<"\n Enter 3 for labour data entry     ";
	cout<<"\n Enter 4 for foreman data entry ";
	cout<<"\n Enter 5 to display all data ";
	cout<<"\n Enter the 6 to exit ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			p[count]=new manager;
			cout<<"\n Enter manager data entry \n";
			p[count++]->setter();
	
			break;
		case 2:
				p[count]=new scientist;
			p[count++]->setter();
			break;
		case 3:
				p[count]=new labour  ;
			p[count++]->setter();
			break;
		case 4:
				p[count]=new forman ;
			p[count++]->setter();
			break;
		case 5:
			for(int i=0;i<=count;i++)
			{
			
			p[i]->getter();
			if(typeid(*p[i])==typeid(manager))
			mc++;
			else if(typeid(*p[i])==typeid(scientist))
			sc++;
			else if(typeid(*p[i])==typeid(labour))
			lc++;
			else 
			fc++;
		
			
			}
			cout<<"\n The number of Managers are  "<<mc;
            cout<<"\n The number of Scientists are   "<<sc;
            cout<<"\n The number of Labours are       "<<lc;
            cout<<"\n The number of Foremans are       "<<fc;
			break;
		case 6:
			exit(0);
			break;
	}
	/*	cout<<"\nManager data entry \n";
	m1.setter();
	m1.getter();
	cout<<"\n Scientist data entry\n";
	s1.setter();
	s1.getter();
	cout<<"\n labour data entry\n";
	l1.setter();
	l1.getter();
	cout<<"\n Foreman data entry\n";
    f1.setter();
    f1.getter();*/
}
while(count!=size);

	cout << endl;
	system("pause");
	return 0;
}
