#include<iostream>
#include<string>
using namespace std;
class emp {
protected:
	string ename;
	int eID;
	string cnic;
public:
	emp(string ename1, int ID1, string cnic1) :ename(ename1), eID(ID1), cnic(cnic1) {}
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
	manager(string ename1, int ID1, string cnic1, string title2, float cdues2) :emp(ename1, ID1, cnic1), title(title2), cdues(cdues2) {
	}
	void getter()const;
	//void setter();
};
//////////////////////////////////////////////////////////////////////////////////////////
void manager::getter()const
{
	emp::getter();
	cout << " \nManager Title         " << title << "\nClub dues      " << cdues << endl;
}
///////////////////////////////////////////////////////////
/*void manager::setter()
{
emp::setter();
   cout<<"Enter Club Dues  "<<endl;
   cin>>cdues;
	   cout<<"Enter Manager Title  "<<endl;
	   cin.ignore(10,'\n');
   getline(cin,title);
	   }*/
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
cout<<"\n**************************************************************************:";
cout<<"\nProgrammer :  Sohail Zia Gill:";
cout<<"\nTitle: Inheritence without constructors:";
cout<<"\nCompiler : Visual Studio 2012:";
cout<<"\nDated : 30/sep/2019:";
cout<<"\nCompiling date : 30/sep/2019:";
cout<<" \nInternational Islamic University Islamabad:";
cout<<"\n***************************************************************************:\n\n\n";
	manager m1("sohail", 123, "1w3-er4", "45df3", 34.78);
	//scientist s1;
//	labour l1;
//	m1.setter();
	m1.getter();
	/*s1.setter();
	s1.getter();
	l1.setter();
	l1.getter();
*/

	cout << endl;
	system("pause");
	return 0;
}
