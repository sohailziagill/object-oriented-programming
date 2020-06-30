#include<iostream >
using namespace std;
struct student {
	char name;
	int reg; 
double salary;	
};
int main()
{
	student std;
	cout<<"Enter the details of student like name,reg and salary    ";
	cin>>std->name;
		cin>>std->reg;
			cin>>std->salary;
	
	
	student person *ptr=NULL;
	*ptr=&std;
	cout<<"\n The entered details of student is  ";
	cout<<"\n Name  "<<ptr->name;
	cout<<"\nRegistration number is   "<<ptr->reg;
	cout<<"\n The salary is    "<<ptr->salary;
	
	
	system ("pause");
	return 0;
	
	
}
