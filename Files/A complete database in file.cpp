#include<iostream>
#include<fstream>
#define SIZE 30
#define SUB 6//6 Subjects 
#define TM 600//Total marks
using namespace std;
class student
{
	int roll;
	char name[SIZE];
	int marks[SUB];
	int tmarks;
	float perc;
	char grade;
	public:
		void read()
		{
			tmarks=0;
			do
		{
			cout<<"\n Enter the roll number of student    ";
			cin>>roll;
			if(roll<0||roll>9999)
			cout<<"\n Invalid Input! ";		
		}while(roll<1||roll>9999);
			cout<<"\n Enter the name of student           ";
	        cin>>name;
			for(int k=0;k<SUB;k++)
			{
			do
			{
			cout<<"\n Enter the marks of student in "<<k+1<<"  subject ";
			cin>>marks[k];
			if(marks[k]<0||marks[k]>100)
			cout<<"\n Invalid Input! ";
			}while(marks[k]<0||marks[k]>100);
			tmarks=tmarks+marks[k];				
		    }
			perc=(tmarks*1.0*100.0)/TM;
			{
  			if (perc <= 100 && perc >= 80)
			grade= 'A';
		    else if (perc < 80 && perc >= 70)
			grade = 'B';
		    else if (perc < 70 && perc >= 60)
			grade = 'C';
		    else if (perc < 60 && perc >= 50)
			grade = 'D';
	    	else
			grade = 'F';
		   }
        }
		void display()
		{
			cout<<"\n The roll number of student is       "<<roll;
			cout<<"\n The name of student is              "<<name;
			cout<<"\n The total marks of student is       "<<tmarks;
			cout<<"\n The the percentage of student is    "<<perc;
			cout<<"\n The Grade of student is             "<<grade;
		}
		int rroll()
		{
			return(roll);
		}
};
/////////////////////////////////////////////////////////////////////////
    void append()
    {
    	ofstream wo("Today4.dat",ios::binary|ios::app);
		student s;
    	s.read();
        wo.write((char*)&s,sizeof(s));
	    wo.close();
	}
/////////////////////////////////////////////////////////////////////////
	void insert()
		{
			student s;
			ofstream wo("Today4.dat",ios::binary|ios::app);
	        s.read();
		    wo.write((char*)&s,sizeof(s));
	        wo.close();	
		}
/////////////////////////////////////////////////////////////////////////
    void show()
    {   	
    	    student s;
			ifstream ro;
	        ro.open("Today4.dat",ios::binary|ios::in);
	        while(ro.read((char*)&s,sizeof(s)))
	        {
	        cout<<endl<<endl<<endl; 
	        s.display();	
			}
	        ro.close();
      	
	}
/////////////////////////////////////////////////////////////////////////
    void search(int n)
    {
    	    student s;
			ifstream ro("Today4.dat",ios::binary|ios::in);
    	    while(ro.read((char*)&s,sizeof(s)))
    	    {
    	    	if(n==s.rroll())
    	    	s.display();
			}
			ro.close();
	}    
/////////////////////////////////////////////////////////////////////////
    void Delete(int n)
    {
    	    ofstream w("Temp.dat",ios::binary|ios::app);
    	    ifstream r("Today4.dat",ios::binary|ios::in);
    	    student s;
    	    while(r.read((char*)&s,sizeof(s)))
    	    {
    	    	if(n!=s.rroll())
    	    	w.write((char*)&s,sizeof(s));
			}
			w.close();
			r.close();
			remove("Today4.dat");
			rename("Temp.dat","Today3.dat");
	}
/////////////////////////////////////////////////////////////////////////
    void modify(int n)
    {
    	    student s;
    	    ifstream r("Today4.dat",ios::binary|ios::in);
    	    ofstream w("Temp.dat",ios::binary|ios::out);
    	    while(r.read((char*)&s,sizeof(s)))
    	    {
    	    	if(n==s.rroll())
    	    	s.read();
    	    	w.write((char*)&s,sizeof(s));
			}
    	    w.close();
    	    r.close();
    	    remove("Today4.dat");
    	    rename("Temp.dat","Today3.dat");
    	    
	}
/////////////////////////////////////////////////////////////////////////
    void choice(int &x)
    {
	do
	{ 
		cout<<endl<<endl;
		cout << "welcome to Student Data Base\n\n\n";
		cout << "1 : To Creat Data Base.\n";
		cout << "2 : To Update/Modify The Record. \n";
		cout << "3 : To Search a Record.\n";
		cout << "4 : To Delete a Record.\n";
		cout << "5 : To Display All Records.\n";
		cout << "6 : To Only Single Record.\n";
		cout << "7 : To Append The Record.\n";
		cout << "8 : To Check The Size of File.\n";
		cout << "9 : To Exit." << endl << endl;
	    cin >> x;
		if (x < 0 || x>9)
		
			cout << "Invalid output...";
	}
	    while (x < 0 || x>9);
    }
/////////////////////////////////////////////////////////////////////////
int main()
{
    cout<<"\n**********************************************************";
    cout<<"\nProgrammer :  Sohail Zia Gill.";
    cout<<"\nTitle: Student Database Using Classes in Files.";
    cout<<"\nCompiler : Visual Studio 19";
    cout<<"\nDated : 22/Dec/2019";
    cout<<"\nCompiling date : 22/Dec/2019";
    cout<<"\nInternational Islamic University Islamabad.";
    cout<<"\n**********************************************************";
	student s;
	int mnky=0,snum,dnum,upnum,x,loop=1;
	do
 {
	choice(x);
	switch(x)
  {
	case 1: 
	{
		do
		{
		
		cout<<"\n Enter the number of student        ";
	    cin>>mnky;
	    if(mnky<0||mnky>1000)
	    cout<<"\n Invalid Input! ";
	    }while(mnky<0||mnky>1000);
		for(int i=0;i<mnky;i++)
	{
		insert();
	}
		break;
    }
	case 2:
	{
		do
		{
		
		cout<<"\n Enter the roll  no that you want to modify/update  ";
	    cin>>upnum;
	    if(upnum<1||upnum>9999)
	    cout<<"\n Invalid Input!";
	    }while(upnum<1||upnum>9999);
	    modify(upnum);              
		break;
	}
				
	case 3:
	{
		do
		{
		cout<<"\n Enter the roll no of student to search  ";
	    cin>>snum;
	    if(snum<1||snum>9999)
	    cout<<"\n Invalid Input!";
	    }while(snum<1||snum>9999);
		search(snum);
		break;	
	}
	case 4:
	{
		do
		{
	    cout<<"\n Enter the roll no that you want to delete ";
	    cin>>dnum;
	    if(dnum<1||dnum>9999)
	    cout<<"\n Invalid Input!";
	    }while(dnum<1||dnum>9999);
		Delete(dnum);				
		break;
    }
	case 5:
	{
		show();
		break;
	}
	case 6:
	{
		do
		{
		cout<<"\n Enter the roll no of student to display record  ";
	    cin>>snum;
	    if(snum<1||snum>9999)
	    cout<<"\n Invalid Input!";
	    }while(snum<1||snum>9999);
		search(snum);
		break;	
	}
	case 7:
	{
		int m;
    	do
		{
		cout<<"\n Enter the number of student        ";
	    cin>>m;
	    if(m<0||m>(1000-mnky))
	    cout<<"\n Invalid Input! ";
	    }while(m<0||m>1000);
    	
    	for(int i=0;i<m;i++)
	    append();
	    mnky=mnky+m;
		break;	
	}
	case 8://To check the size of file.
	{
	int end;
	ifstream obj;
	obj.open("Today4.dat",ios::in|ios::binary);
	obj.seekg(0,ios::end);
	end=obj.tellg();
	cout<<"\nSize of file in bytes is:  "<<end<<endl;
	obj.close();
	break;	
	}	
	case 9:
    {
		loop=0;
	    break;	
	}
  }

 } while (loop == 1);

	cout<<endl;
	system("pause");
	return 0;
}
