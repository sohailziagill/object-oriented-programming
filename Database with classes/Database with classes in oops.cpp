#include<iostream>
using namespace std;
#define max 70
class student 
{
int reg[max];
string name[max] ;
int totmark[max];
//int totmark;
float perc[max];
char grade[max];
int num;
public:
	void sort();
	void singledisplay();
	void create();
	void append();
	void search();
	void sorting();
	void update();
	void deletion();
	void display();
};
void student ::sorting()
{
	 for (int i = 0; i <num; i++)
    {
        for (int j = i + 1; j <num; j++)
        {
            if (reg[i] > reg[j])
            {
                swap(reg[i], reg[j]);
                swap(name[i], name[j]);
                swap(totmark[i], totmark[j]);
                swap(grade[i], grade[j]);
                swap(perc[i], perc[j]);
            }
        }
    }
	
}
void student ::singledisplay()
{
	bool found=false;
   	int displayreg,i;
   	cout<<"\n Enter the registration number that you want to display     ";
   	cin>>displayreg;
   	
   		for(i=0;i<num;i++)
	{
		if(reg[i]==displayreg){
		
		found=true;
		break;
		}
			}
	
	if(found)
	{
	
	cout<<"\n Result found  at   "<<i+1<<endl;
		perc[i]=totmark[i]/500.0*100.0;
  		{
  			if (perc[i] <= 100 && perc[i] >= 80)
			grade[i] = 'A';
		else if (perc[i] < 80 && perc[i] >= 70)
			grade[i] = 'B';
		else if (perc[i] < 70 && perc[i] >= 60)
			grade[i] = 'C';
		else if (perc[i] < 60 && perc[i] >= 50)
			grade[i] = 'D';
		else
			grade[i] = 'F';
		  }
  		
  		cout<<"\n The name of student is    "<<name[i];
  		cout<<"\n Registration number of student is     "<<reg[i]<<endl;
  		cout<<"Total marks are      "<<totmark[i]<<endl;
  		cout<<" The percentage is      "<<perc[i]<<endl;
  		cout<<" The grade is     "<<grade[i]<<endl;
  		
}
	else
		cout<<"\n Result not  found"<<endl; 
	
}
void student::create()
{
	do
	{
		cout<<"\n Enter the number of present student  ";
		cin>>num;
		if(num<0||num>max)
		cout<<"\n Invalid Input! Again:";
	}while(num<0||num>max);
	for(int i=0;i<num;i++)
	{
	cout<<"\n Enter registration number of student      ";
	cin>>reg[i];
	cout<<"\n Enter the  full name of student    ";
	cin.ignore(10, '\n');
    getline(cin, name[i]);
     do
        {
            cout << "\nType Obtained Marks of Student out of 600\n";
            cin >> totmark[i];
            if(totmark[i] < 0 || totmark[i] > 600)
            cout<<"\n Invalid Input! Again:";
        } while (totmark[i] < 0 || totmark[i] > 600);
        
	}
}
void student::display()
{
		cout << "Student name \tReg No.\tObt.Marks\t%age\tGrade" << endl;
  	for(int i=0;i<num;i++)
  	{
    perc[i]=(totmark[i]*1.0*100.0)/600.0;
  		{
  			if (perc[i] <= 100 && perc[i] >= 80)
			grade[i] = 'A';
		else if (perc[i] < 80 && perc[i] >= 70)
			grade[i] = 'B';
		else if (perc[i] < 70 && perc[i] >= 60)
			grade[i] = 'C';
		else if (perc[i] < 60 && perc[i] >= 50)
			grade[i] = 'D';
		else
			grade[i] = 'F';
		  }
  		cout<<"\n" <<name[i];
  		cout<<"\t \t"<<reg[i];
  		cout<<"\t   "<<totmark[i];
  		cout<<"\t       "<<perc[i];
  		cout<<" \t         "<<grade[i];
  		}
  	cout<<endl;  	
}
void student::deletion()
{
	bool found=false;
	int x,i;
cout<<"\n Enter the student registration number that you want to delele     ";
cin>>x;

	for(i=0;i<num;i++)
	{
		if(reg[i]==x)
		{
		
		found=true;
		break;
		}
			}
	
	if(found)
	{
		cout<<"\n Result found  at   "<<i+1<<endl;
		for(int j=i;j<num-1;j++)//nn is garbage.
				{
		reg[j]=reg[j+1];
		name[j]=name[j+1];
		totmark[j]=totmark[j+1];
		}
	num--;	
	}
else
		cout<<"\n Result not  found"<<endl; 
	

	
}
void student:: append()
{
	int newnum;
	cout<<"\n \n Enter the number of new students  ";
	cin>>newnum;
	for(int i=num;i<(num+newnum);i++)
{
	
	cout<<"\n Enter registration number of student      ";
	cin>>reg[i];
	cout<<"\n Enter the  name of student    ";
	cin.ignore(10, '\n');
    getline(cin, name[i]);
	do
        {
    cout << "Type Obtained Marks of Student out of 600"; 
     cin >>totmark[i];
     if(totmark[i]< 0 || totmark[i]> 600)
     cout<<"\n An Invalid Input! Again : ";
    } while (totmark[i]< 0 || totmark[i]> 600);
}
num=(num+newnum);
}
void student:: update()
{
	bool found=false;
	int upreg,i;
	cout<<"\nEnter the  registration number to upgarde    ";
	cin>>upreg;
	for(i=0;i<num;i++)
	{
		if(reg[i]==upreg)
		{
		
		found=true;
		break;
		}
			}
	
	if(found)
	{
	
	cout<<"\n Result found  at   "<<i+1<<endl;
	cout<<"\n Enter the updated registration number of student   ";
	cin>>reg[i];
	cout<<"\n Enter the updated  full name of student   ";
	cin.ignore(10, '\n');
    getline(cin, name[i]);
	do
        {
cout << "\nEnter the updated marks of student out of 600";      cin >>totmark[i];
     if(totmark[i]< 0 || totmark[i]> 600)
     cout<<"\n An Invalid Input! Again : ";
    } while (totmark[i]< 0 || totmark[i]> 600);
}
	
	else
		cout<<"\n Result not  found"<<endl;
}
void student::search()
{
	int sreg, i;
	bool found=false;
	cout<<"\n Enter the searching registration number     ";
	cin>>sreg;
	for(i=0;i<num;i++)
	{
		if(reg[i]==sreg){
		
		found=true;
		break;
		}
			}
	
	if(found)
	cout<<"\n Result found  at   "<<i+1<<endl;
	else
		cout<<"\n Result not  found"<<endl; 
}
void choice(int &x)
{
	do { 
		cout<<endl<<endl;
		cout << "welcome to Student Data Base" << endl << endl;
		cout<<endl;
		cout << "1 : To creat Data Base." << endl;
		cout << "2 : to Appent/Insert New Record" << endl;
		cout << "3 : To Search a Record." << endl;
		cout << "4 : To Sort Data Base." << endl;
		cout << "5 : To Update a Record." << endl;
		cout << "6 : To Delete a Record." << endl;
		cout << "7 : To Display single Record." << endl;
		cout << "8 : To display All Records." << endl;
		cout << "9 : To Exit." << endl << endl;
	
		cin >> x;
		if (x < 0 || x>9)
		
			cout << "Invalid output...";
	}
	 while (x < 0 || x>9);
}
int main()
{
cout<<"\n**************************************************************************";
cout<<"\nProgrammer :  Sohail Zia Gill.";
cout<<"\nTitle: Student Result Database using Classes programming.";
cout<<"\nCompiler : Visual Studio 19";
cout<<"\nDated : 27/Oct/19";
cout<<"\nCompiling date : 27/Oct/19";
cout<<"\nIslamic International University Islamabad.";
cout<<"\n***************************************************************************";
	 student s1;
	int x,loop=1;
	do{
	choice(x);
	
	switch(x)
{
	case 1: {
	 	s1.create();
		break;
      }
	case 2:{
	    s1.append();              
		 break;
				}
				
	case 3:
		{
		s1.search();
		break;	
		}
		case 4:{
		             s1.sorting();
					                   break;
					               }
		case 5:{
			
		s1.update();
	   break;
		          }
			case 6:{
			s1.deletion();				
			break;
}
		case 7:{
			              s1.singledisplay();       
			   break;
				}
		case 8:
		{
		
	        s1.display();
		break;
		}
		case 9:
			{
			
	loop=0;
	break;	
	}
			
	
}

	} while (loop == 1);



	system ("pause");
	return 0;
}
