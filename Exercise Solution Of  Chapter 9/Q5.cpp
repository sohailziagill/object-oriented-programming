#include<iostream>
using namespace std;
class employee
{   
    protected:
	string name;
	public:
		void getdata()
		{
			cout<<"\n Enter the name ";
			cin>>name;
		}
		void putdata()
		{
			cout<<"\n The name of employee is "<<name;
		}
	
};
class employee2 :public employee
{
        protected:
            double compen;
            string period;
        public:
        	void getdata()
        	{
        		string p;
        		employee::getdata();
        		cout<<"\n Enter the copensation of employee  ";
        		cin>>compen;
        		cout<<"\n Enter the payment (H,M,W)  ";
        		cin>>p;
				period=p;
			}
		    void putdata()
		    {
		    	employee::putdata();
		    	cout<<"\n The compensation is "<<compen;
		    	cout<<"\n The payment is "<<period;
			}
};
///////////////////////////////////////////////////////////////////////////////////////////
class manager :public employee2 
{
protected:
	string title;
	float cdues;
public:
	void getdata();
	void putdata();

};
void manager::putdata()
{
	employee2 ::putdata();
	cout << " \nManager Title         " << title << "\nClub dues      " << cdues << endl;
}
void manager::getdata()
{
    employee2 ::getdata();
    cout<<"Enter Club Dues  "<<endl;
    cin>>cdues;
	cout<<"Enter Manager Title  "<<endl;
    cin>>title;
}
class scientist :public employee2 
{
	string field;
	int publi;
    public:
	void getdata();
	void putdata();

};
void scientist::putdata()
{
	employee2 ::putdata();
	cout << "\n Feild        " <<field;
	cout<< "\n  no Of publications      " << publi;
}
void scientist::getdata()
{
	employee2 ::getdata();
	cout << "Enter Scientist field  " << endl;
	cin>>field;
	cout << "Enter Scientist number of publications  " << endl;
	cin >> publi;
}
class labour :public employee2
{

	string shift;
	float hrs;
    public:
	void getdata();
	void putdata();


};
void labour::getdata()
{
	employee2::getdata();
	cout << "Enter Labour Shift  " << endl;
	cin>>shift;
	cout << "Enter Labour worked hrs  " << endl;
	cin >> hrs;
}
void labour::putdata()
{
    employee2::putdata();
	cout << "\n Shift      " << shift << " \n Worked Hours        " << hrs;
}
int main()
{
	
	labour l1;
	cout<<"///////////////////////////Labour class //////////////////////////////////////";
	l1.getdata();
	l1.putdata();
	manager m1;
	cout<<"///////////////////////////Manager class //////////////////////////////////////";

	m1.getdata();
	m1.putdata();
	scientist s1;
	cout<<"///////////////////////////Scientist class //////////////////////////////////////";
	s1.getdata();
	s1.putdata();
	cout<<endl;
	system("pause");
	return 0;
}
