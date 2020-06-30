/*
Program Name : RESULT MARK-VIII.
Program Operation : Student's Result Creation, Display and Manipulation.
Programmer : Umer Sadiq.
Reg No.    : 3995 BSCS F18 A.
Instructor : Mr M. Nadeem.
Subject    : Object Oriented Paradigm.
Date       : 26th October 2019.
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<conio.h>
#include<cctype>
#include<locale>
#include<limits>

using namespace std;

#define SIZE 70
#define SUB 6
#define TM 600.00
#define WIDTH 102  
const char separator = ' ';

//<>Structure to Store Date:
struct date
{
	int dd, mm, yy;
	
	date(int ddd = 0, int mmm = 0, int yyy = 0) : dd(ddd), mm(mmm), yy(yyy) {}
	~date(){}
};

//<> Class to Store Student Data:
class student
{
	int mnky, reg[SIZE];
	string name[SIZE], fname[SIZE], key;
	int marks[SIZE][SUB];
	int tmo[SIZE];
	float perc[SIZE];
	char grade[SIZE];
	date dob[SIZE], doa[SIZE];
	
	public :
		student()
		{
			key = "---";
			
			for(int i = 0; i < SIZE; i++)
			{
				reg[i] = 0;
				name[i] = "---";
				fname[i] = "---";
				perc[i] = 0;
				grade[i] = '-';
				
				for(int j = 0; j < SUB; j++)
					marks[i][j] = 0;	
			}
		}
		void crt();
		void apnd();
		void srch();
		void srt ();
		void upd ();
		void del ();
		void dispRslt();
		void prepRslt();
		void grade_calc(int *);
		~student(){}
};

//<>Function Prototypes:
void menu();
int  error_check(int *);
void error_msg_disp();
void rpt_menu(int *);

void reg_check(int *, int *, string *);
void name_check(string &, int *);
void date_check(int *, int *, int *, int *, string *);
void marks_check(int *, int *, string *); 
void integer_check(int *, string *); 

void line();
void star();

//<> Member Function's Definition of Class Student:
// 01. Function to Create a New Data Base:
void student :: crt()
{
	for(int i = 0; i < 1; )
	{
		system("cls");

		cout<<right<<setw(WIDTH)<<setfill(separator)<<"||| Welcome to Create New Data Base Window |||"<<endl<<endl;
		cout<<right<<setw(90)<<setfill(separator)<<"||| Attention User |||"<<endl<<endl;
		cout<<"<> Note that the data you enter should not exceed 70 students. "<<endl<<endl;

		int counter=0, counter0=0;

		cout<<"<> Enter number of students in your class. "<<endl<<endl<<endl;
		cout<<">>> ";cin>>mnky;

		key = "number Of students";

		integer_check(&mnky, &key);

		system("cls");

		if(mnky <= 0 || mnky > 70)
		{
			error_msg_disp();
		}
		else
		{
			while(counter < mnky)
			{
				counter0 = 0;
				do
				{
					for(int j = 0; j < 1; )
					{
						cout<<"<> Enter 4 digit registration no. of student no. "<<counter+1<<endl<<endl;
						cout<<">>> ";cin>>reg[counter];
						cout<<endl;
							
						key="4 digit registration No. ";
							
						reg_check(&reg[counter], &j, &key);
					}
					if(counter != 0)
					{
						for(int k = 0; k < counter; k++)
						{
							if(reg[counter] == reg[k])
							{
								cout<<right<<setw(WIDTH)<<setfill(separator)<<"Error!!!!!"<<endl;
								cout<<"\a\a";
								cout<<"<> Your Input is Invalid."<<endl;
								cout<<"<> Your Entered Registration No. Already Exists in The Data Base. "<<endl<<endl;				
								system("pause");
								system("cls");
								
								counter0 = 0;
								
								break;
							}
							else 
								counter0 = 1;
						}
					}
					else if(counter == 0)
						counter0 = 1;
			   	}
			    while(counter0 != 1);
			    
				for(int l = 0; l < 1; )
				{
					cin.ignore();
					cout<<"<> Enter full name of student no. "<<counter+1<<endl<<endl;
					cout<<">>> ";getline(cin,name[counter]);
					cout<<endl;
					
					name_check(name[counter], &l);
				}
				
				for(int m = 0; m < 1; )
				{
					cout<<"<> Enter Father's name of student no. "<<counter+1<<endl<<endl;
					cout<<">>> ";getline(cin,fname[counter]);
					cout<<endl;
					
					name_check(fname[counter], &m);
				}
				key="date of birth";
				
				for(int n = 0; n < 1; )
				{
					cout<<"<> Enter date of birth of student no. "<<counter+1<<endl<<endl;
					cout<<"<> Day <space> Month <space> Year <enter>. "<<endl<<endl;
					cout<<">>> ";cin>>dob[counter].dd;
					cout<<">>> ";cin>>dob[counter].mm;
					cout<<">>> ";cin>>dob[counter].yy;
					cout<<endl;
				
					date_check(&dob[counter].dd, &dob[counter].mm, &dob[counter].yy, &n, &key);
				}
				key="date of addmission";
				
				for(int o = 0; o < 1; )
				{
					cout<<"<> Enter date of birth of student no. "<<counter+1<<endl<<endl;
					cout<<"<> Day <space> Month <space> Year <enter>. "<<endl<<endl;
					cout<<">>> ";cin>>doa[counter].dd;
					cout<<">>> ";cin>>doa[counter].mm;
					cout<<">>> ";cin>>doa[counter].yy;
					cout<<endl;
				
					date_check(&doa[counter].dd, &doa[counter].mm, &doa[counter].yy, &o, &key);
				}
				key="marks";
				
				for(int p = 0; p < 6; p++)
				{
					for(int q = 0; q < 1;)
					{
						cout<<"<> Enter marks of subject "<<p+1<<" of student no. "<<counter+1<<endl<<endl;
						cout<<">>> ";cin>>marks[counter][p];
						cout<<endl;

						marks_check(&marks[counter][p], &q, &key);
 					}
				}
				system("cls");
				
				counter++;
			}
			i++;
		}
	}
	prepRslt();

	cout<<"\a"<<right<<setw(WIDTH)<<setfill(separator)<<"||| Creation Successful |||"<<endl<<endl;

	system("pause");
}

// 02. Function to Append New Data:
void student :: apnd()
{
	int counter = 0;

	cout<<right<<setw(WIDTH)<<setfill(separator)<<"||| Welcome to Append New Data Window |||"<<endl<<endl;
	cout<<right<<setw(90)<<setfill(separator)<<"||| Attention User |||"<<endl<<endl;
	cout<<"<> Please Enter Following Details of the New Student. "<<endl<<endl;

	key="4 digit registration No. of the new student"; 
	do
	{
		for(int i = 0; i < 1; )
		{
			cout<<"<> Enter 4 digit registration No. of the new student. "<<endl<<endl;
			cout<<">>> ";cin>>reg[mnky];
			cout<<endl;

			reg_check(& reg[mnky], &i, &key);
		} 
		for(int j = 0; j < mnky; j++)
		{
			if(reg[mnky] == reg[j])
			{
				cout<<right<<setw(WIDTH)<<setfill(separator)<<"Error!!!!!"<<endl;
				cout<<"\a\a";
				cout<<"<> Your Input is Invalid. "<<endl;
				cout<<"<> Your Entered Registration No. Already Exists in The Data Base. "<<endl<<endl;
				system("pause");
				system("cls");
				
				counter = 0;
				
				break;
			}
			else
				counter = 1;
		}
    }
    while(counter != 1);
	
	for(int k = 0; k < 1; )
	{
		cin.ignore();
		
		cout<<"<> Enter full name of the new student. "<<endl<<endl;
		cout<<">>> ";getline(cin,name[mnky]);
		cout<<endl;
		
		name_check(name[mnky], &k);
	}
	
	for(int l = 0; l < 1; )
	{
		cout<<"<> Enter Father's name of the new student. "<<endl<<endl;
		cout<<">>> ";getline(cin,fname[mnky]);
		cout<<endl;
		
		name_check(fname[mnky], &l);
	}
	
	for(int m = 0; m < 1; )
	{
		cout<<"<> Enter date of birth of the new student. "<<endl<<endl;
		cout<<"<> Day <space> Month <space> Year <enter>."<<endl<<endl;
		cout<<">>> ";cin>>dob[mnky].dd;
		cout<<">>> ";cin>>dob[mnky].mm;
		cout<<">>> ";cin>>dob[mnky].yy;
		cout<<endl;
		
		date_check(&dob[mnky].dd, &dob[mnky].mm, &dob[mnky].yy, &m, &key);
	}
	
	key = "date of addmission";
	
	for(int n = 0; n < 1; )
	{
		cout<<"<> Enter date of birth of the new student. "<<endl<<endl;
		cout<<"<> Day <space> Month <space> Year <enter>."<<endl<<endl;
		cout<<">>> ";cin>>doa[mnky].dd;
		cout<<">>> ";cin>>doa[mnky].mm;
		cout<<">>> ";cin>>doa[mnky].yy;
		cout<<endl;
		
		date_check(&doa[mnky].dd, &doa[mnky].mm, &doa[mnky].yy, &n, &key);
	}
	
	key = "marks";

	for(int o = 0; o < 6; o++)
	{
		for(int p = 0; p < 1;)
		{
			cout<<"<> Enter marks of subject "<<o+1<<" of the new student. "<<endl<<endl;
			cout<<">>> ";cin>>marks[mnky][o];
			cout<<endl;

			marks_check(&marks[mnky][o], &p, &key);
		}
	}
	mnky += 1;

	prepRslt();
}

// 03. Function to Search Data:
void student :: srch()
{
	int findReg, counter = 0;

	cout<<right<<setw(WIDTH)<<setfill(separator)<<"||| Welcome to Search Data Window |||"<<endl<<endl;
	cout<<right<<setw(90)<<setfill(separator)<<"||| Attention User |||"<<endl<<endl;
	
	
	key="4 digit registration number ";
	
	for(int i = 0; i < 1;)
	{
		cout<<"<> Enter 4 digit registration number of student to search for. "<<endl;
		cout<<">>> ";cin>>findReg;
		reg_check(&findReg, &i, &key);
	}
	system("cls");

	for(int j = 0; j < mnky; j++)
	{
		if(findReg == reg[j])
		{
			cout<<"<> Registration No.   = "<<reg[j]<<endl;
			cout<<"<> Student's Name     = "<<name[j]<<endl;
			cout<<"<> Father's Name      = "<<fname[j]<<endl;
			cout<<"<> Date of Birth      = "<<dob[j].dd<<"-"
											<<dob[j].mm<<"-"
											<<dob[j].yy<<endl;
			cout<<"<> Date of Addmission = "<<doa[j].dd<<"-"
											<<doa[j].mm<<"-"
											<<doa[j].yy<<endl;								
			for(int k = 0; k < 6; k++)
			{
				cout<<"<> Marks in Subject-"<<j+1<<" = "<<marks[j][k]<<endl;
			}
			cout<<"<> Total Marks        = "<<tmo[j]<<endl;
			cout<<"<> Percentage         = "<<perc[j]<<endl;
			cout<<"<> Grade              = "<<grade[j]<<endl;

			counter++;

			system("pause");
		}
	}
  	if (counter == 0)
    {
        error_msg_disp();
    }
    else
    {
        cout<<"\a"<<right<<setw(WIDTH)<<setfill(separator)<<"||| Searching Successful |||"<<endl<<endl;

		system("pause");
    }
}

// 04. Function to Sort Data:
void student :: srt()
{
	int counter = 0, tempInteger;
	date tempDate;
	string tempString;
	float tempPerc;
	char tempGrade;

	for (int i = 0; i < mnky; i++)
    {
        for (int j = 0; j < mnky-1; j++)
        {
            if (reg[j] > reg[j+1])
            {
			    tempInteger = reg[j];
			    reg[j] = reg[j+1];
			    reg[j+1] = tempInteger;

			    tempString = name[j];
			    name[j] = name[j+1];
			    name[j+1] = tempString;

			    tempString = fname[j];
			    fname[j] = fname[j+1];
			    fname[j+1] = tempString;

			    tempDate = dob[j];
			    dob[j] = dob[j+1];
			    dob[j+1] = tempDate;
			    
			    tempDate = doa[j];
			    doa[j] = doa[j+1];
			    doa[j+1] = tempDate;

			    for(int k = 0; k < 6; k++)
				{
					tempInteger = marks[j][k];
					marks[j][k]= marks[j+1][k];
					marks[j+1][k] = tempInteger;
				}
				
				tempInteger = tmo[j];
			    tmo[j] = tmo[j+1];
			    tmo[j+1] = tempInteger;
       
			    tempPerc = perc[j];
			    perc[j] = perc[j+1];
			    perc[j+1] = tempPerc;

			    tempGrade = grade[j];
			    grade[j] = grade[j+1];
			    grade[j+1] = tempGrade;

			    counter++;
			}
        }
    }
    if (counter == 0)
    {
        error_msg_disp();
    }
    else
    {
        cout<<"\a"<<right<<setw(WIDTH)<<setfill(separator)<<"||| Sorting Successful |||"<<endl<<endl;

        system("pause");

        dispRslt();
    }
}

// 05. Function to Update Result:
void student :: upd()
{
    int updReg, counter = 0, counter0 = 0;

    cout<<right<<setw(WIDTH)<<setfill(separator)<<"|||Welcome to Update Data Window|||"<<endl<<endl;
	cout<<right<<setw(90)<<setfill(separator)<<"||| Attention User |||"<<endl<<endl;
	
	key="4 digit registration number";
	
    for (int i = 0; i < 1;)
    {
    	cout<<"<> Enter 4 digit registration number of student to Update the record of. "<<endl<<endl;
		cout<<">>> ";cin>>updReg;
	    reg_check(&updReg, &i, &key);
	}
    for (int j = 0; j < mnky; j++)
    {
        if (reg[j] == updReg)
        {
			do
			{
				for(int k = 0; k < 1; )
				{
					cout<<"<> Enter new 4 digit registration no. of the student."<<endl<<endl;
					cout<<">>> ";cin>>reg[j];

  					reg_check(&reg[j], &k, &key);

  					counter0 = 1;
				}
				for(int l = 0; l < j || l > j; l++)
				{
					if(reg[j] == reg[l])
					{
						cout<<right<<setw(WIDTH)<<setfill(separator)<<"Error!!!!!"<<endl;
						cout<<"\a\a";
						cout<<"<> Your Input is Invalid."<<endl;
						cout<<"<> Your Entered Registration No. Already Exists in The Data Base. "<<endl<<endl;
						system("pause");
						system("cls");

						counter0 = 0;

						break;
					}
					else
						counter0 = 1;
				}
			}
		    while(counter0 != 1);

			for(int m = 0; m < 1; )
			{
					cin.ignore();
		
					cout<<"<> Enter full name of the student. "<<endl<<endl;
					cout<<">>> ";getline(cin,name[m]);
					cout<<endl;
					
					name_check(name[m], &m);
			}
			
			for(int n = 0; n < 1; )
			{
				cout<<"<> Enter Father's name of the student. "<<endl<<endl;
				cout<<">>> ";getline(cin,fname[n]);
				cout<<endl;
									
				name_check(fname[n], &n);
			}
			key = "date of birth";
			
			for(int o = 0; o < 1; )
			{
				cout<<"<> Enter date of birth of the student. "<<endl<<endl;
				cout<<"<> Day <space> Month <space> Year <enter>. "<<endl<<endl;
				cout<<">>> ";cin>>dob[o].dd;
				cout<<">>> ";cin>>dob[o].mm;
				cout<<">>> ";cin>>dob[o].yy;
				cout<<endl;
				
				date_check(&dob[o].dd, &dob[o].mm, &dob[o].yy, &o, &key);
			}
			key = "date of addmission";
			
			for(int p = 0; p < 1; )
			{
				cout<<"<> Enter date of addmission of the student. "<<endl<<endl;
				cout<<"<> Day <space> Month <space> Year <enter>. "<<endl<<endl;
				cout<<">>> ";cin>>doa[p].dd;
				cout<<">>> ";cin>>doa[p].mm;
				cout<<">>> ";cin>>doa[p].yy;
				cout<<endl;
				
				date_check(&doa[p].dd, &doa[p].mm, &doa[p].yy, &p, &key);
			}
			key="marks";
			
			for(int q = 0; q < 6; q++)
			{
				for(int r = 0; r < 1;)
				{
					cout<<"<> Enter marks of subject "<<q+1<<" of the student."<<endl<<endl;
					cout<<">>> ";cin>>marks[j][q];
					cout<<endl;

					marks_check(&marks[j][q], &r, &key);
				}
			}
			counter++;
        }
    }
    if (counter == 0)
    {
        error_msg_disp();
    }
    else
    {
        cout<<"\a"<<right<<setw(WIDTH)<<setfill(separator)<<"||| Updation Successful |||"<<endl<<endl;

		prepRslt();

		system("pause");
    }
}

// 06. Function to Delete Data:
void student :: del()
{
    int delReg, counter = 0;

    cout<<right<<setw(WIDTH)<<setfill(separator)<<"||| Welcome to Delete Data Window |||"<<endl<<endl;
	cout<<right<<setw(90)<<setfill(separator)<<"||| Attention User |||"<<endl<<endl;
	
	key="4 digit registration number";
	
	for (int i=0; i<1;)
    {
		cout<<"<> Enter 4 digit registration number of student Delete the record of. "<<endl<<endl;
		cout<<">>> ";cin>>delReg;
	    reg_check(&delReg, &i, &key);
	}
	for (int j = 0; j < mnky; j++)
    {
        if(delReg == reg[j])
        {
            for(int k = j; k < (mnky - 1); k++)
            {
                reg[k] = reg[k+1];

				name[k] = name[k+1];
                fname[k] = fname[k+1];

                for(int l = 0; l < 6; l++)
                {
                	marks[k][l] = marks[k+1][l];
				}
				tmo[k] = tmo[k+1];
				perc[k] = perc[k+1];
                grade[k] = grade[k+1];
            }
            counter++;
        }
    }
    if (counter == 0)
    {
        error_msg_disp();
    }
    else
    {
        cout<<"\a"<<right<<setw(WIDTH)<<setfill(separator)<<"||| Deletion Successful |||"<<endl<<endl;
        mnky -= 1;
		system("pause");		
    }
    
}

// 07. Function to Display Result:
void student :: dispRslt()
{
	cout<<right<<setw(WIDTH)<<setfill(separator)<<"||| Welcome to Display Result Window |||"<<endl<<endl;
	cout<<"<1> To Display Result of The Whole Class. "<<endl<<endl;
	cout<<"<2> To Display Result of A Single Student. "<<endl<<endl;

	int option;

	cout<<">>> ";cin>>option;

	system("cls");

	if(option == 1)
	{
		system("cls");

		cout<<"\n";
		star();
		cout<<setw(95)<<"RESULT TABLE\n";
		star();
		line();

		cout<<"S.No. |"<<" Reg No.|"<<setw(28)<<"Student's Name"<<setw(28)<<"Father's Name"<<setw(18)<<"D.O.B"
		<<setw(18)<<"D.O.A"<<setw(8)<<"  S1"<<setw(8)<<"  S2"<<setw(8)<<"  S3"<<setw(8)<<"  S4"<<setw(8)<<"  S5"<<setw(8)<<"  S6"
		<<setw(10)<<"  TMO"<<setw(14)<<"Percentage"<<setw(8)<<"Grade"<<endl;
		line();
		
		cout<<"       "<<"         "<<setw(28)<<" "<<setw(28)<<" "<<setw(10)<<"dd-"<<setw(3)<<"mm-"<<setw(5)<<"yyyy"
		<<setw(10)<<"dd-"<<setw(3)<<"mm-"<<setw(5)<<"yyyy"<<setw(8)<<" "<<setw(8)<<" "<<setw(8)<<" "<<setw(8)<<" "<<setw(8)<<" "<<setw(8)<<" "
		<<setw(10)<<" "<<setw(14)<<" "<<setw(8)<<" "<<endl;
		line();
		
			for(int i = 0; i < mnky; i++)
			{
				cout<<"     "<<i+1<<"|"<<"    "<<reg[i]<<"|"<<setw(28)<<name[i]<<setw(28)<<fname[i]
				<<setw(9)<<dob[i].dd<<setw(3)<<dob[i].mm<<setw(6)<<dob[i].yy
				<<setw(9)<<doa[i].dd<<setw(3)<<doa[i].mm<<setw(6)<<doa[i].yy;
				
				for(int j = 0; j < 6; j++)
					cout<<setw(8)<<marks[i][j];
				//<<setw(8)<<marks[i][0]<<setw(8)<<(sptr+i)->marks[1]<<setw(8)<<(sptr+i)->marks[2]<<setw(8)<<(sptr+i)->marks[3]<<setw(8)<<(sptr+i)->marks[4]<<setw(8)<<(sptr+i)->marks[5]
				cout<<setw(10)<<tmo[i]<<setw(13)<<setprecision(3)<<showpoint<<perc[i]<<setw(1)<<"%"<<setw(8)<<grade[i]<<endl;
	
				line();
	
				cout<<endl;
			}
			line();

		cout<<endl;
				
		star();
		cout<<setw(95)<<"Finish\n";
		star();
		cout<<"\n\n";
	
		system("pause");
	}
	else if(option == 2)
	{
		srch();
	}
	else
	{
		error_msg_disp();
    }
}

// 08. Function to Prepare Result:
void student :: prepRslt()
{
	for(int i = 0; i < mnky; i++)
	{
		tmo[i] = marks[i][0]+marks[i][1]+marks[i][2]+marks[i][3]+marks[i][4]+marks[i][5];
		perc[i] = static_cast<float>((tmo[i] * 100 ) / TM);
		grade_calc(&i);
	}
}

//09. Function to Calculate Grade:
void student :: grade_calc(int * counter)
{
	//char calculatedGrade;
	
	if(perc[*counter] >= 80.0)
		grade[*counter] = 'A';
	else if (perc[*counter] < 80.0 && perc[*counter] >= 70.0 )
		grade[*counter] = 'B';
	else if (perc[*counter] < 70.0 && perc[*counter] >= 60.0 )
		grade[*counter] = 'C';
	else if (perc[*counter] < 60.0 && perc[*counter] >= 50.0 )
		grade[*counter] = 'D';
	else if (perc[*counter] < 50.0 )
		grade[*counter] = 'F';
}
//<> End of Member Function's Definition of Class Student:

//<> Other Functions:
//<> Function to Display Menu on Output Screen:
void menu()
{
	cout<<right<<setw(WIDTH)<<setfill(separator)<<"|||Welcome to IIUI Result Handling System|||"<<endl<<endl<<endl;
	cout<<setw(90)<<setfill(separator)<<"|||MAIN MENU|||"<<endl<<endl;
	cout<<"<1> Create Data Base :"<<endl;
	cout<<"<2> Append New Data :"<<endl;
	cout<<"<3> Search Data :"<<endl;
	cout<<"<4> Sort Data :"<<endl;
	cout<<"<5> Update Data :"<<endl;
	cout<<"<6> Delete Data :"<<endl;
	cout<<"<7> Display Result :"<<endl;
	cout<<"<8> Save to Disk :"<<endl;
	cout<<"<9> Reload files :"<<endl;
	cout<<"<10> Exit Menu :"<<endl;
}

//<> Function to Check Authencity of the Choice Entered:
int error_check(int * choice)
{
	while(1)	
	{
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			error_msg_disp();
			menu();
			cout<<"\n\n";
			cout<<">>> ";cin>>*choice;
		}
		if(!cin.fail())
			break;
	}
	for(int i = 0; i < 1; )
	{
		if(*choice > 0 && *choice <= 8)
		{
			i++;
		}
		else if(*choice == 0 || i != *choice)
		{
			error_msg_disp();
		    cin.clear();
			cin.ignore();
			menu();
			cout<<"\n\n";
			cout<<">>> ";cin>>*choice;
		}
	}
}

//<> Function to Output Error Message:
void error_msg_disp()
{
	system("cls");
	cout<<right<<setw(WIDTH)<<setfill(separator)<<"Error!!!!!"<<endl;
	cout<<"\a\a";
	cout<<"<> Your Input is Invalid."<<endl;
	system("pause");
	system("cls");
}

//<> Function to Output Menu Again:
void rpt_menu(int * choice)
{
	system("cls");
	menu();
	cout<<endl;
	cout<<">>> ";cin>>*choice;
	system("cls");
}

//<> Function to Print Line of '-':
void line()
{
    for(int i = 0; i < 97; i++)
    	cout<<"--";
    cout<<"\n";
}

//<> Function to Print Line of '*':
void star()
{
    for(int i = 0; i < 97; i++)
        cout<<"**";
    cout<<"\n";
}

//<> Function to Check Registration Number's Validity:
void reg_check(int  * num, int * counter, string * key)
{
	integer_check(num, key);

	if(*num > 999 && *num < 9999)
	{
		*counter = 1;
	}
	else
	{
		error_msg_disp();
		system("cls");
	}
}

//<> Function to Check Name's Validity:
void name_check(string & name, int * counter )
{
	for(int i = 0; i < name.length(); i++)
	{
		if(isalpha (name[i]) || name[i] == ' ')
		{
			*counter = 1;
		}
		else 
		{
			error_msg_disp();
			*counter = 0;
		}
	}
}

//<> Function to Check Date's Validity:
void date_check(int * dd, int * mm, int * yy, int * counter, string * key)
{
	//Day Check
	integer_check(dd, key);
	
	if(*dd >= 1 && *dd <= 31)
		*counter = 1;
	else
	{
		*counter = 0;
		error_msg_disp();
	}
	
	//Month Check
	integer_check(mm, key);
	
	if(*mm >= 1 && *mm <= 12)
		*counter = 1;
	else
	{
		*counter = 0;
		error_msg_disp();
	}
	
	//Year Check
	integer_check(yy, key);
	
	if(*yy >= 1900 && *yy <= 2019)
		*counter = 1;
	else
	{
		*counter = 0;
		error_msg_disp();
	}
}

//<> Function to Check Mark's Validity:
void marks_check(int * num, int * counter, string * key)
{
	integer_check(num, key);

	if(*num >= 0 && *num <= 99)
		*counter = 1;
	else
	{
		*counter = 0;
		error_msg_disp();
	}
}

//<> Function to Check Input Data Type's Validity:
void integer_check(int * num, string * key)
{
	while(1)	
	{
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			error_msg_disp();
			cout<<"Please Enter "<<*key<< " Again :"<<endl;
			cin>>*num;
		}
		if(!cin.fail())
			break;
	}
}

//<> Main Function:
int main()

{
	student s[SIZE];
    int count=0;
	if(count==0)
	{
			
    
	ifstream wo("Today5.dat",ios::binary|ios::in);
	wo.read((char*)&s,sizeof(student));
	wo.close();	
	}
	else
	{
		cout<<"\n Create database";
	}
	system("color 27");
	
	

	menu();

	int option, counter = 0;

	cout<<endl;

	do
	{
		cout<<"\n\n";
		cout<<">>> ";cin>>option;

		error_check(&option);
		
		if(option == 8)
			counter = 1;

		else if(option != 1)
		{
			cout<<right<<setw(WIDTH)<<setfill(separator)<<"Error!!!!!"<<endl;
			cout<<"\a\a";
			cout<<"<> Your Input is Invalid. "<<endl;
			cout<<"<> You Must Create Data Base First Hand Before Using Any Other Facility. "<<endl<<endl;
			system("pause");
			system("cls");

			s->crt();

			rpt_menu(&option);

			counter = 1;
		}
		else
			counter = 1;
	}
	while(counter != 1 );

	do
	{
		if(option == 1)
		{
			s->crt();

			rpt_menu(&option);

			error_check(&option);
		}
	  	if(option == 2)
	  	{
			s->apnd();

			rpt_menu(&option);

			error_check(&option);
		}
		if(option == 3)
		{
			s->srch();
			
			rpt_menu(&option);

			error_check(&option);
		}
		if(option == 4)
		{
			s->srt();

			rpt_menu(&option);

		    error_check(&option);
		}
		if(option == 5)
		{
			s->upd();
				
			rpt_menu(&option);

			error_check(&option);
		}
		if(option == 6)
		{
			s->del();
			
			rpt_menu(&option);
			
			error_check(&option);
		}
		if(option == 7)
		{
			s->dispRslt();

			rpt_menu(&option);

			error_check(&option);
		}
		if(option == 8)
		{
		ofstream wo("Today5.dat",ios::binary|ios::out);
		wo.write((char*)&s,sizeof(student));
	    wo.close();
			
		}
		if(option==9)
		{
		ifstream wo("Today5.dat",ios::binary|ios::in);
		wo.read((char*)&s,sizeof(student));
	    wo.close();	
		}
	}
	while(option != 10);

	cout<<setw(WIDTH)<<setfill(separator)<<"\a"<<"||| Good Bye |||"<<endl;

	system("pause");
	return '0';
}

