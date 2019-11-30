#include<iostream>
#include<string>
using namespace std;
class emp
{
    protected:
	string ename;
	int eID;
	string cnic;
    public:
	emp(string ename1, int ID1, string cnic1) :ename(ename1), eID(ID1), cnic(cnic1)
    {
	}
	void getter()const;
	void setter();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
void emp::getter()const
{
	cout<<"\n The is ID:                        "<<  eID;
    cout<<"\n The name of employe is            "<<ename;
	cout<<"\n The CNIC number of employe is     "<<cnic ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void emp::setter()
{
	cout<<"\n Enter Employ ID#                         ";
	cin >> eID;
	cout<<" \nEnter the Employ Name                    ";
	cin.ignore(10, '\n');
	getline(cin, ename);
	cout<<"\n Enter the  Employ CNIC number            ";
	cin.ignore(10, '\n');
	getline(cin, cnic);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
class manager :public emp
{
    protected:
	string title;
	float cdues;
    public:
    manager(string ename1, int ID1, string cnic1, string title2, float cdues2) 
	:emp(ename1, ID1, cnic1), title(title2), cdues(cdues2) 
	{
	}
	void getter()const;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
void manager::getter()const
{
	emp::getter();
	cout<<"\n The is ID:                        "<< eID;
	cout<<"\n The Manager Title is              "<<title;
	cout<<"\n The Club dues dues of manager is  "<<cdues;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
class scientist :public emp
{
	string field;
	int publi;
    public:
    scientist(string name1,int ID1,string cnic1,string field1,int publi1)
	:emp(name1,ID1,cnic1),field(field1),publi(publi1)
	{
	}
	void getter()const;
	void setter();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
void scientist::getter()const
{
	emp::getter();
	cout<<"\n The Feild of scientist is         " <<field;
	cout<<"\n The no Of publications are        " <<publi;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void scientist::setter()
{
	emp::setter();
	cout<<"\nEnter the Scientist field          ";
	cin.ignore(10, '\n');
	getline(cin, field);
	cout<<"\nEnter Scientist no of publications ";
	cin >> publi;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
class labour :public emp
{

	string shift;
	float hrs;
    public:
   	labour (string name1,int ID1,string cnic1,string shift1,float hrs1)
	:emp(name1,ID1,cnic1),shift(shift1),hrs(hrs1)
	{
	}
	void getter()const;
	void setter();
};
void labour::getter()const
{
	emp::getter();
	cout<<"\n The Shift of labour is            " <<shift;
	cout<<"\n The  Worked Hours of labour is    " <<  hrs;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void labour::setter()
{
	emp::setter();
	cout<<"\nEnter the Labour Shift             ";
	cin.ignore(10, '\n');
	getline(cin, shift);
	cout<<"\nEnter the Labour worked hrs         ";
	cin >> hrs;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	manager m1("Sohail",123 ,"1w3-er4" ,"Head mgr" ,34.78);
	scientist s1("Zia" ,456 ,"2e-34-r" ,"Asistant" ,5    );
	labour l1("Gill"   ,789 ,"35h-57y" ,"Morning"  ,6.4  );
	m1.getter();
	s1.getter();
	l1.getter();
    cout<< endl;
	system("pause");
	return 0;
}
