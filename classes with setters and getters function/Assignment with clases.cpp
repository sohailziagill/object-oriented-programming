#include<iostream>
#include<string>
#define size 10
#define namesize 30
#define sub 5
using namespace std;
  class Date
{public:
	int dd;
	int mm;
	int yy;
};
 class student
 {	public:
 	Date dob; //date of birth
	Date doa;  //date of admission
 	int reg;
string name ;
int mark[sub];
int totmark;
float perc;
char grade;
	
		void  Search(student ss[], int nn );
	void SingleDisplay(student ss[], int nn );
	void Delete(student ss[],int& nn);
};
void SingleDisplay(student ss[], int nn )
   {
   		student *fptr=NULL;
   			fptr=ss;
   		bool found=false;
   	int displayreg,i;
   	cout<<"\n Enter the registration number that you want to display     ";
   	cin>>displayreg;
   			for(i=0;i<nn;i++)
	{
		if((fptr+i)->reg==displayreg){
		found=true;
		break;
		}
			}
	if(found)
	{
	cout<<"\n Result found  at   "<<i+1<<endl;
		(fptr+i)->totmark=0;
		for(int j=0;j<sub;j++)
  		{
  			(fptr+i)->totmark=(fptr+i)->totmark+(fptr+i)->mark[j];
  			}
	(fptr+i)->perc=(fptr+i)->totmark/500.0*100.0;
  		{
  			if ((fptr+i)->perc <= 100 && (fptr+i)->perc >= 80)
			(fptr+i)->grade = 'A';
		else if ((fptr+i)->perc < 80 && (fptr+i)->perc >= 70)
		(fptr+i)->grade = 'B';
		else if ((fptr+i)->perc < 70 && (fptr+i)->perc >= 60)
			(fptr+i)->grade = 'C';
		else if ((fptr+i)->perc < 60 && (fptr+i)->perc >= 50)
			(fptr+i)->grade = 'D';
		else
			(fptr+i)->grade = 'F';
		  }
  			cout << "Student name\tDOB\tDOA \tReg No.\tObt.Marks\t%age\tGrade" << endl;
  		cout<<"\n" <<(fptr+i)->name;
  		cout<<"\t\t"<<(fptr+i)->dob.dd<<"/"<<(fptr+i)->dob.mm<<"/"<<(fptr+i)->dob.yy;
		   cout<<"\t\t"<<(fptr+i)->doa.dd<<"/"<<(fptr+i)->doa.mm<<"/"<<(fptr+i)->doa.yy;
  		cout<<"\t \t"<<(fptr+i)->reg;
  		cout<<"\t   "<<(fptr+i)->totmark;
  		cout<<"\t       "<<(fptr+i)->perc;
  		cout<<" \t         "<<(fptr+i)->grade;
  		cout<<endl<<endl;
  		}
	else
		cout<<"\n Result not  found"<<endl; 
		}
void Delete(student ss[],int& nn)
{
		student *fptr=NULL;
		fptr=ss;
		bool found=false;
	int delelereg,i;
cout<<"\n Enter the student registration number that you want to delele     ";
cin>>delelereg;
for(i=0;i<nn;i++)
	{
		if((fptr+i)->reg==delelereg)
		{
		found=true;
		break;
		}
			}
	if(found)
	{
		cout<<"\n Result found  at   "<<i+1<<endl;
		for(int j=i;j<nn;j++)
		{
		(fptr+j)->reg=(fptr+j+1)->reg;
	(fptr+j)->name=(fptr+j+1)->name;
	(fptr+j)->dob.dd= (fptr+j+1)->dob.dd;
			   (fptr+j)->dob.mm=(fptr+j+1)->dob.mm;
			   (fptr+j)->dob.yy=(fptr+j+1)->dob.yy;
        	   (fptr+j)->doa.dd= (fptr+j+1)->doa.dd;
			   (fptr+j)->doa.mm=(fptr+j+1)->doa.mm;
			   (fptr+j)->doa.yy=(fptr+j+1)->doa.yy;
		for(int k=0;k<sub-1;k++)
		(fptr+j)->mark[k]=(fptr+j+1)->mark[k];
		}
	nn--;
	cout<<"\nRecord Deleted Successfully :\n ";		
	}
else
		cout<<"\n Result not  found"<<endl; 
		}
void  Update(student ss[], int nn)
{	student *fptr=NULL;
	fptr=ss;
		bool found=false;
	int upgradereg,i;
	cout<<"\nEnter the  registration number to upgarde    ";
	cin>>upgradereg;
	for(i=0;i<nn;i++)
	{
		if((fptr+i)->reg==upgradereg)
		{
				found=true;
		break;
		}
			}
	if(found)
	{
	cout<<"\n Result found  at   "<<i+1<<endl;
	cout<<"\n Enter the updated registration number of student   ";
	cin>>(fptr+i)->reg;
	cout<<"\nEnter the Updated Date of_Birth of  Student ( dd mm yy) : ";
        	   cin>>(fptr+i)->dob.dd>>(fptr+i)->dob.mm>>(fptr+i)->dob.yy;
        	       	cout<<"\nEnter the Updated  Date_of Admisson of  Student ( dd mm yy) : ";
        	   cin>>(fptr+i)->doa.dd>>(fptr+i)->doa.mm>>(fptr+i)->doa.yy;
	cout<<"\n Enter the updated name of student   ";
	cin>>(fptr+i)->name;
	for(int j=0;j<sub;j++)
	{
	cout<<"\nEnter the updated marks of subject  "<<j+1<<"    ";
	cin>>(fptr+i)->mark[j];
  while((fptr+i)->mark[j]<0 || (fptr+i)->mark[j]>100)
				{
				  cout<<"\nError! \nInvalid Input\nEnter marks Again !\n";
		            cin>>(fptr+i)->mark[j];	
					}
}
	}
	else
		cout<<"\n Result not  found"<<endl; 
	}
void  Search(student ss[], int nn )
{	student *fptr=NULL;
fptr=ss;
	int  searchreg, i;
	bool found=false;
	cout<<"\n Enter the searching registration number     ";
	cin>>searchreg;
	for(i=0;i<nn;i++)
	{
			if((fptr+i)->reg==searchreg)
		{
			found=true;
		break;
		}
			}
	if(found){
		cout<<"\n Result found  at   "<<i+1<<endl;
	(fptr+i)->totmark=0;
			for(int j=0;j<sub;j++)
  		{
  			(fptr+i)->totmark=(fptr+i)->totmark+(fptr+i)->mark[j];
  			}
	(fptr+i)->perc=(fptr+i)->totmark/500.0*100.0;
  		{
  			if ((fptr+i)->perc <= 100 && (fptr+i)->perc >= 80)
			(fptr+i)->grade = 'A';
		else if ((fptr+i)->perc < 80 && (fptr+i)->perc >= 70)
		(fptr+i)->grade = 'B';
		else if ((fptr+i)->perc < 70 && (fptr+i)->perc >= 60)
			(fptr+i)->grade = 'C';
		else if ((fptr+i)->perc < 60 && (fptr+i)->perc >= 50)
			(fptr+i)->grade = 'D';
		else
			(fptr+i)->grade = 'F';
		  }
  		cout << "Student name\tDOB\tDOA \tReg No.\tObt.Marks\t%age\tGrade" << endl;
  		cout<<"\n" <<(fptr+i)->name;
  		cout<<"\t\t"<<(fptr+i)->dob.dd<<"/"<<(fptr+i)->dob.mm<<"/"<<(fptr+i)->dob.yy;
		   cout<<"\t\t"<<(fptr+i)->doa.dd<<"/"<<(fptr+i)->doa.mm<<"/"<<(fptr+i)->doa.yy;
  		cout<<"\t \t"<<(fptr+i)->reg;
  		cout<<"\t   "<<(fptr+i)->totmark;
  		cout<<"\t       "<<(fptr+i)->perc;
  		cout<<" \t         "<<(fptr+i)->grade;
  		cout<<endl<<endl;
  		}
	else
		cout<<"\n Result not  found"<<endl; 
		}
void  AppendDB(student ss[], int& n,int newstunumber)
{	student *fptr=NULL;
	fptr=ss;
for(int i=n;i<(n+newstunumber);i++)
{
	cout<<"\n Enter registration number of student      ";
	cin>>(fptr+i)->reg;
	cout<<"\n Enter the  name of student    ";
		cout<<"\nEnter the Date of_Birth of  Student ( dd mm yy) : ";
        	   cin>>(fptr+i)->dob.dd>>(fptr+i)->dob.mm>>(fptr+i)->dob.yy;
        	           	cout<<"\nEnter the Date_of Admisson of  Student ( dd mm yy) : ";
        	   cin>>(fptr+i)->doa.dd>>(fptr+i)->doa.mm>>(fptr+i)->doa.yy;
	cin>>(fptr+i)->name;
	for(int j=0;j<sub;j++)
	{
		cout<<"\n Enter the "<<j+1<<" subject  mark      ";
		cin>>(fptr+i)->mark[j];
	  while((fptr+i)->mark[j]<0 || (fptr+i)->mark[j]>100)
				{
				  cout<<"\nError! \nInvalid Input \nEnter Marks Again !\n";
		            cin>>(fptr+i)->mark[j];	
				}
			}
				}
				n=(n+newstunumber);	
}
void choice(int &x)
{
	do { 
				cout << "welcome to Student Data Base" << endl << endl;
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
void myinput( student ss[],int nn)
{
		student *fptr=NULL;
		fptr=ss;
for(int i=0;i<nn;i++)
{
	cout<<"\n Enter registration number of student      ";
	cin>>(fptr+i)->reg;
	cout<<"\n Enter the  name of student    ";
	cin>>(fptr+i)->name;
			cout<<"\nEnter the Date of_Birth of  Student ( dd mm yy) : ";
        	   cin>>(fptr+i)->dob.dd>>(fptr+i)->dob.mm>>(fptr+i)->dob.yy;
        	       	cout<<"\nEnter the Date_of Admisson of  Student ( dd mm yy) : ";
        	   cin>>(fptr+i)->doa.dd>>(fptr+i)->doa.mm>>(fptr+i)->doa.yy;
		for(int j=0;j<sub;j++)
	{
		cout<<"\n Enter the "<<j+1<<" subject  mark      ";
		cin>>(fptr+i)->mark[j];
		 while((fptr+i)->mark[j]<0 || (fptr+i)->mark[j]>100)
				{
				  cout<<"\nError! \nInvalid Input \nEnter Marks Again !\n";
		            cin>>(fptr+i)->mark[j];	
				}
				}
		}	
		}
  void result(student ss[],int nn)
  {
  	student *fptr=NULL;
  	fptr=ss;
  		cout << "Student name \tDOB\t\tDOA\t      Reg No.\t    Obt.Marks\t%age\tGrade" << endl;
  	for(int i=0;i<nn;i++)
  	{
 	ss[i].totmark=0;
  		for(int j=0;j<sub;j++)
  		{
  				(fptr+i)->totmark=(fptr+i)->totmark+(fptr+i)->mark[j];
  			 }
  		(fptr+i)->perc=(fptr+i)->totmark/500.0*100.0;
  		{
  			if ((fptr+i)->perc <= 100 && (fptr+i)->perc >= 80)
			(fptr+i)->grade = 'A';
		else if ((fptr+i)->perc < 80 && (fptr+i)->perc >= 70)
			(fptr+i)->grade = 'B';
		else if ((fptr+i)->perc < 70 && (fptr+i)->perc >= 60)
		(fptr+i)->grade = 'C';
		else if ((fptr+i)->perc < 60 &&(fptr+i)->perc >= 50)
			(fptr+i)->grade = 'D';
		else
		(fptr+i)->grade = 'F';
		  }
  		cout<<"\n" <<(fptr+i)->name;
  		 cout<<"\t\t"<<(fptr+i)->dob.dd<<"/"<<(fptr+i)->dob.mm<<"/"<<(fptr+i)->dob.yy;
		   cout<<"\t\t"<<(fptr+i)->doa.dd<<"/"<<(fptr+i)->doa.mm<<"/"<<(fptr+i)->doa.yy;
  		cout<<"      \t"<<(fptr+i)->reg;
  		cout<<"\t    "<<(fptr+i)->totmark;
  		cout<<"\t\t "<<(fptr+i)->perc;
  		cout<<" \t"<<(fptr+i)->grade;
  		}
  	cout<<endl<<endl;
	  }	
	int main()
{
	cout<<"\n**************************************************************************:";
cout<<"\nProgrammer :  Sohail Zia Gill:";
cout<<"\nTitle: Student Result Database using Structure programming using pointers:";
cout<<"\nCompiler : Visual Studio 2012:";
cout<<"\nDated : 30/sep/2019:";
cout<<"\nCompiling date : 30/sep/2019:";
cout<<" \nInternational Islamic University Islamabad:";
cout<<"\n***************************************************************************:\n\n\n";
	student data[size];
int n,x,loop = 1,newstunumber;
do {
choice(x);
switch(x)
{
	case 1: {
		cout<<"Enter the number of student      ";
cin>>n; 
		myinput(data,n);
		break;
			}
	case 2:{
				cout<<"Enter the number of student      ";
cin>>newstunumber; 
		             AppendDB(data, n,newstunumber);              
					 				 break;
				}
			case 3:
		{
			Search(data, n );
			 break;	
		}
	/*	case 4:
		             Sort(user_array, percentage, grade, size, isDBcreated);                  break;
		*/case 5:{
			Update(data, n);
					                  break;
									   }
			case 6:{
	 Delete(data,n);				
					   break;
}
		case 7:{
	 SingleDisplay(data, n );        
					   break;
				}
		case 8:
		{
		 result( data, n);
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






