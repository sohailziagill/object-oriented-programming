#include<iostream>
#include<fstream>
using namespace std;
class student
{
	int roll;
	char name[30];
	public:
		void read()
		{
			cout<<"\n Enter the roll number of student    ";
			cin>>roll;
			cout<<"\n Enter the name of student           ";
			cin>>name;
		}
		void display()
		{
			cout<<"\n The roll number of student is       "<<roll;
			cout<<"\n The name of student is              "<<name;
		}
		int rroll()
		{
			return(roll);
		}
};
//////////////////////////////////////////////////////////////////////////
	void insert()
		{
			student s;
			ofstream wo("Today2.dat",ios::binary|ios::app);
	        s.read();
		    wo.write((char*)&s,sizeof(s));
	        wo.close();	
		}
//////////////////////////////////////////////////////////////////////////
    void show()
    {
    	    student s;
			ifstream ro;
	        ro.open("Today2.dat",ios::binary|ios::in);
	        while(ro.read((char*)&s,sizeof(s)))
	        {
	        s.display();	
			}
	        ro.close();
      	
	}
//////////////////////////////////////////////////////////////////////////
    void search(int n)
    {
    	    student s;
			ifstream ro("Today2.dat",ios::binary|ios::in);
    	    while(ro.read((char*)&s,sizeof(s)))
    	    {
    	    	if(n==s.rroll())
    	    	s.display();
			}
			ro.close();
	}
//////////////////////////////////////////////////////////////////////////
    void Delete(int n)
    {
    	    ofstream w("Temp.dat",ios::binary|ios::app);
    	    ifstream r("Today2.dat",ios::binary|ios::in);
    	    student s;
    	    while(r.read((char*)&s,sizeof(s)))
    	    {
    	    	if(n!=s.rroll())
    	    	w.write((char*)&s,sizeof(s));
			}
			w.close();
			r.close();
			remove("Today2.dat");
			rename("Temp.dat","Today2.dat");
	}
//////////////////////////////////////////////////////////////////////////
    void modify(int n)
    {
    	    student s;
    	    ifstream r("Today2.dat",ios::binary|ios::in);
    	    ofstream w("Temp.dat",ios::binary|ios::out);
    	    while(r.read((char*)&s,sizeof(s)))
    	    {
    	    	if(n==s.rroll())
    	    	s.read();
    	    	w.write((char*)&s,sizeof(s));
			}
    	    w.close();
    	    r.close();
    	    remove("Today2.dat");
    	    rename("Temp.dat","Today2.dat");
    	    
	}
//////////////////////////////////////////////////////////////////////////
int main()
{
	student s;
	int loop=0,snum,dnum,upnum;
	cout<<"\n Enter the number of student        ";
	cin>>loop;
    for(int i=0;i<loop;i++)
	{
		insert();
	}
	show();
	cout<<"\n Enter the roll no of student to search  ";
	cin>>snum;
	search(snum);
	cout<<"\n Enter the roll no that you want to delete ";
	cin>>dnum;
	Delete(dnum);
	show();
	cout<<"\n Enter the rool  no that you want to modify/update  ";
	cin>>upnum;
	modify(upnum);
	show();
	cout<<endl;
	system("pause");
	return 0;
}
