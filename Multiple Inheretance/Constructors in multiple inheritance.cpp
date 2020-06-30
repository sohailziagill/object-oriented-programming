#include<iostream>
#include<string>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////
class sh_it
{
	protected:
		string name;
		string cnic;
	public:
		sh_it(string name1,string cnic1):name(name1),cnic(cnic1)
		{
		}
	virtual	void setter(){
			cout<<"\n Enter the name         ";
			cin>>name;
			cout<<"\n Enter the CNIC number   ";
			cin>>cnic;
			
		}
	virtual	void getter() const
		{
			cout<<"\n The name is           "<<name;
			cout<<"\n The CNIC number is    "<<cnic;
		}
	
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
class emp:virtual public sh_it
{
	protected:
		int eno;
		string design;
		float salary;
	public:
		emp(string name1,string cnic1,int eno1,string design1,float salary1)
		:sh_it(string name1,string cnic1),eno(eno1),design(design1),salary(salary1)
		{
			
		}
		void setter()
		{
			sh_it::setter();
			cout<<"\n Enter the ID          ";
			cin>>eno;
			cout<<"\n Enter the design      ";
			cin.ignore(10,'\n');
			getline(cin,design);
			cout<<"\n Enter the salary      ";
			cin>>salary;
		}
		
	void getter() const
		{
			sh_it::getter();
			cout<<"\n The ID is              "<<eno;
			cout<<"\n The designation is     "<<design;
			cout<<"\n The salaray  is        "<<salary;
		}
	
	
	
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
class student: virtual public sh_it
{
	protected:
		int regno;
		string deg;
		int semester;
		float cgpa;
		public:
		student(string name2,string cnic1,int reg1,string deg1,int semester1,float cgpa1):
		sh_it(string name2,string cnic1),reg(reg1),deg(deg1),semester(semester1),cgpa(cgpa1)
			{
			}
				void setter()
		{
			sh_it::setter();
			cout<<"\n Enter the regitration number  ";
			cin>>regno;
			cout<<"\n Enter the semester no       ";
			cin>>semester;
			cout<<"\n Enter the degree program      ";
			cin.ignore(10,'\n');
			getline(cin,deg);
			cout<<"\n Enter the CGPA     ";
			cin>>cgpa;
		}
		
	void getter() const
		{
			sh_it::getter();
			cout<<"\n The regno of student is          "<<regno;
			cout<<"\n The semester number is           "<<semester;
			cout<<"\n The degree program is            "<<deg;
			cout<<"\n The CGPA  is                     "<<cgpa;
		}
	
	
	
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
class e_st:public emp,public student
{
	protected :
	int year;
	
	
	public:
	e_st (string name1,string cnic1,int eno1,string design1,float salary1,string name2,
	string cnic1,int reg1,string deg1,int semester1,float cgpa1,int year1)
	:emp(string name1,string cnic1,int eno1,string design1,float salary1),
	student(string name2,string cnic1,int reg1,string deg1,	int semester1,float cgpa1),
	year(year1)
	
	{
	}
		void setter()
		{
			cout<<"\n//////////////EMP///////////////////////////////////////////////////////////";

			emp::setter();
		cout<<"\n//////////////Student///////////////////////////////////////////////////////////";

			student::setter();
			cout<<"\n Enter the degree compeletion year         ";
			cin>>year;
		
		}
		
	void getter() const
		{
			cout<<"\n//////////////EMP///////////////////////////////////////////////////////////";

			emp::getter();
			cout<<"\n//////////////Student///////////////////////////////////////////////////////////";

			student::getter();
			cout<<"\n The compeletion year  is              "<<year;
		
		}
};
////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
e_st e1("Sohail","123e1",456,"D.manager",789.0,"Zia",
	"123e4",435,"BSCS",3,3.73,2019);
 //e1.setter();
e1.getter();
//student s1;
//s1.setter();
//s1.getter();
cout<<"\n/////////////////////////////////// E_st//////////////////////////////////////////////////";
//e_st t1;
//t1.setter();
//t1.getter();
cout<<endl;
system("pause");
return 0;	
}
