#include<iostream>
#include<string>
using namespace std;
class emp {
protected:
	string ename;
	int eID;
	string cnic;
public:
	void getter()const;
	void setter();
};
//////////////////////////////////////////////////////////////////////////////////////////
void emp::getter()const
{
	cout << " \nID:  " << eID << " \n Name " << ename << " \n CNIC  " << cnic << endl;
}
///////////////////////////////////////////////////////////
void emp::setter()
{
	cout << "Enter Employ ID#  " << endl;
	cin >> eID;
	cout << "Enter Employ Name  " << endl;
	cin.ignore(10, '\n');
	getline(cin, ename);
	cout << "Enter Employ CNIC " << endl;
	cin.ignore(10, '\n');
	getline(cin, cnic);
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
};
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
	   cin.ignore(10,'\n');
   getline(cin,title);
	   }
	   /////////////////////////////////////////////////////////////////////////////////////////////////////
class scientist :public emp
{
	string field;
	int publi;
public:
	void getter()const;
	void setter();
};
//////////////////////////////////////////////////////////////////////////////////////////
void scientist::getter()const
{
	emp::getter();
	cout << "\n Feild        " << field << "  no Of publications      " << publi;
}
///////////////////////////////////////////////////////////
void scientist::setter()
{
	emp::setter();
	cout << "Enter Scientist field  " << endl;
	cin.ignore(10, '\n');
	getline(cin, field);
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
};
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
int main()
{
	manager m1;
	scientist s1;
	labour l1;
	m1.setter();
	m1.getter();
	s1.setter();
	s1.getter();
	l1.setter();
	l1.getter();


	cout << endl;
	system("pause");
	return 0;
}
