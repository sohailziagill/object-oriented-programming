 //**************************************************************************
//Programmer :  Taimoor Mansha
//Title: Student Result Database using Structure programming using pointers
//Compiler : Visual Studio 19
//Dated : 29/sep/19
//Compiling date : 29/sep/19
//Islamic International University Islamabad
//***************************************************************************

#include<iostream>
#include<string>
#define size 70
#define sub 5
int r=0;
using namespace std;

struct Date
{
	int dd;
	int mm;
	int yy;
};

struct student
{ 
    string name;
	Date dob; //date of birth
	Date doa;  //date of admission
	int roll;
	int arr[sub]={0};
	int tm; //total marks
	float avg;
	char g; //grades
};
//void recall(student);
//void Create_D_B(student,int);
//student *ptr=NULL;
int searchRec(student S[],int nn,int id)
{
	student *fptr=NULL;
	fptr=S;
	int ind=-1;
    for(int i=0;i<nn;i++)
  	  if((fptr+i)->roll==id)
  	       ind=i;
  	return ind;
}

void deleteR(student S[],int &nn,int id )
{   
	 int i;
     i= searchRec(S,nn,id);
  	 if(i==-1) 
	  cout<<"Record not Found \n";
     else
     {
    student *fptr=NULL;
	fptr=S;
	for(int m=0;m<nn;m++)
	 for(int j=0;j<nn-1;j++)
	   if((fptr+j)->avg < (fptr+j+1)->avg)
	     {
		     swap((fptr+j)->dob.mm ,  (fptr+j+1)->dob.mm); 
          	  swap((fptr+j)->dob.dd ,  (fptr+j+1)->dob.dd);
			  swap((fptr+j)->dob.yy ,  (fptr+j+1)->dob.yy);  
			  
			  swap((fptr+j)->doa.mm ,  (fptr+j+1)->doa.mm); 
          	  swap((fptr+j)->doa.dd ,  (fptr+j+1)->doa.dd);
			  swap((fptr+j)->doa.yy ,  (fptr+j+1)->doa.yy); 
			  
			  swap((fptr+j)->roll ,  (fptr+j+1)->roll);
			  swap((fptr+j)->name ,  (fptr+j+1)->name);
			  
			  for(int k=0;k<sub;k++)
			   swap((fptr+j)->arr[k] ,  (fptr+j+1)->arr[k]);
			  
          	  swap((fptr+j)->tm ,  (fptr+j+1)->tm);
			  swap((fptr+j)->avg ,  (fptr+j+1)->avg);
			  swap((fptr+j)->g , (fptr+j+1)->g);
	     
		 
		 }
	 }
  nn--;
  cout<<"\nRecord Deleted Successfully :-\n ";	
	
	
}

void updateR(student S[],int nn,int id)
{
   student *fptr=NULL;
   fptr=S;
   int i,roll,counter=0,marks;       
    i= searchRec(S,nn,id);
  	if(i==-1) 
	  cout<<"Record not Found \n";
     else
     {
   	  	cout<<"\nEnter the Date_of_Birth of ("<<id<<") Student ( dd mm yy) : ";
        	   cin>>(fptr+i)->dob.dd>>(fptr+i)->dob.mm>>(fptr+i)->dob.yy;
        	   
        	cout<<"\nEnter the Date_of_Admisson of ("<<id<<") Student ( dd mm yy) : ";
        	   cin>>(fptr+i)->doa.dd>>(fptr+i)->doa.mm>>(fptr+i)->doa.yy;
			      
        	  
			 cout<<"\nEnter ("<<id<<") Student Name :-"; 
			 cin>>(fptr+i)->name;
			 
			 for(int j=0;j<sub;j++)
			  {
			    cout<<"\nEnter ("<<id<<") Student Subject "<<j+1<<" Marks : ";
			    cin>>marks;
			    
			    while(marks<0 || marks>100)
				{
				  cout<<"\nError! \nEnter Input Again !\n";
		            cin>>marks;	
				}
			    
			    (fptr+i)->arr[j]=marks;
			    counter=counter+marks;
			  }  
				
	         (fptr+i)->tm=counter;
	         (fptr+i)->avg=(counter*100)/500;
				
				  if (((fptr+i)->avg >=60.0) && ((fptr+i)->avg <= 69.9 ))	
				     (fptr+i)->g='C';
				  else if (((fptr+i)->avg >=70.0) && ((fptr+i)->avg <= 79.9 ))	
				     (fptr+i)->g='B'; 
				  else if (((fptr+i)->avg >=80.0) && ((fptr+i)->avg <= 100.0 ))	
				     (fptr+i)->g='A';
				  else 
				     (fptr+i)->g='F';
				
				counter=0;	 	 	  
              	
		}

  cout<<"\nDataBase Updated!\n";  
	
}

void sorting(student S[],int nn)
{
	student *fptr=NULL;
	fptr=S;
	for(int i=0;i<nn;i++)
	 for(int j=0;j<nn-1;j++)
	   if((fptr+j)->avg < (fptr+j+1)->avg)
	     {
		     swap((fptr+j)->dob.mm ,  (fptr+j+1)->dob.mm); 
          	  swap((fptr+j)->dob.dd ,  (fptr+j+1)->dob.dd);
			  swap((fptr+j)->dob.yy ,  (fptr+j+1)->dob.yy);  
			  
			  swap((fptr+j)->doa.mm ,  (fptr+j+1)->doa.mm); 
          	  swap((fptr+j)->doa.dd ,  (fptr+j+1)->doa.dd);
			  swap((fptr+j)->doa.yy ,  (fptr+j+1)->doa.yy); 
			  
			  swap((fptr+j)->roll ,  (fptr+j+1)->roll);
			  swap((fptr+j)->name ,  (fptr+j+1)->name);
			  
			  for(int k=0;k<sub;k++)
			   swap((fptr+j)->arr[k] ,  (fptr+j+1)->arr[k]);
			  
          	  swap((fptr+j)->tm ,  (fptr+j+1)->tm);
			  swap((fptr+j)->avg ,  (fptr+j+1)->avg);
			  swap((fptr+j)->g , (fptr+j+1)->g);
	     
		 
		 }
}

void search(student S[],int nn,int id )
{
    int i;  
    i= searchRec(S,nn,id);
    student *fptr=NULL;
    fptr=S;
  	if(i==-1) 
	  cout<<"Record not Found \n";
	else
	{
	   cout<<(fptr+i)->dob.dd<<"/"<<(fptr+i)->dob.mm<<"/"<<(fptr+i)->dob.yy<<"\t"<<(fptr+i)->doa.dd<<"/"<<(fptr+i)->doa.mm<<"/"<<(fptr+i)->doa.yy<<"\t"
	   <<(fptr+i)->roll<<"\t"<<(fptr+i)->name<<"\t\t";
	   for(int j=0;j<sub;j++)
	     cout<<(fptr+i)->arr[j]<<"\t";
	   cout<<(fptr+i)->tm<<"\t"<<(fptr+i)->avg<<"%\t"<<(fptr+i)->g<<endl;
	  
    }		
	
}

void appendN(student S[],int &nn,int n1)
{
	student *fptr=NULL;
	fptr=S;
	
	 int counter=0,roll,marks,k=1; 
     for(int i=nn;i<nn+n1;i++)
        {
        	cout<<"\nEnter the Date_of_Birth of ("<< k<<") Student ( dd mm yy) : ";
        	   cin>>(fptr+i)->dob.dd>>(fptr+i)->dob.mm>>(fptr+i)->dob.yy;
        	   
        	cout<<"\nEnter the Date_of_Admisson of ("<<k <<") Student ( dd mm yy) : ";
        	   cin>>(fptr+i)->doa.dd>>(fptr+i)->doa.mm>>(fptr+i)->doa.yy;
			      
        	  	cout<<"\nEnter Roll No of "<<k<<" Student : ";
        	  	cin>>roll;
        	  	 while(roll<1000 || roll>9999)
				  {
				  	cout<<"\nError! \nEnter Input Again !\n";
		            cin>>roll;
				  }
				  
				(fptr+i)->roll=roll; 
			 cout<<"\nEnter ("<<k <<") Student Name : "; 
			 cin>>(fptr+i)->name;
			 
			 for(int j=0;j<sub;j++)
			  {
			    cout<<"\nEnter ("<<k <<") Student Subject "<<j+1<<" Marks : ";
			    cin>>marks;
			    
			    while(marks<0 || marks>100)
				{
				  cout<<"\nError! \nEnter Input Again !\n";
		            cin>>marks;	
				}
			    
			    (fptr+i)->arr[j]=marks;
			    counter=counter+marks;
			  }  
				
	         (fptr+i)->tm=counter;
	         (fptr+i)->avg=(counter*100)/500;
				
				  if (((fptr+i)->avg >=60.0) && ((fptr+i)->avg <= 69.9 ))	
				     (fptr+i)->g='C';
				  else if (((fptr+i)->avg >=70.0) && ((fptr+i)->avg <= 79.9 ))	
				     (fptr+i)->g='B'; 
				  else if (((fptr+i)->avg >=80.0) && ((fptr+i)->avg <= 100.0 ))	
				     (fptr+i)->g='A';
				  else 
				    (fptr+i)->g='F';
				k++;
				counter=0;
		}
 nn=nn+n1;
	
}

void DispAll(student S[],int nn )
{
   student *fptr;
   fptr=S;
   cout<<"DOB\t\tDOA\t\tRoll#\tName\t\tS1\tS2\tS3\tS4\tS5\tTotal\tAvg\tGrade\n";
	
   for(int i=0;i<nn; i++)
   {
       cout<<(fptr+i)->dob.dd<<"/"<<(fptr+i)->dob.mm<<"/"<<(fptr+i)->dob.yy<<"\t"<<(fptr+i)->doa.dd<<"/"<<(fptr+i)->doa.mm<<"/"<<(fptr+i)->doa.yy<<"\t"
	   <<(fptr+i)->roll<<"\t"<<(fptr+i)->name<<"\t\t";
	   for(int j=0;j<sub;j++)
	     cout<<(fptr+i)->arr[j]<<"\t";
	   cout<<(fptr+i)->tm<<"\t"<<(fptr+i)->avg<<"%\t"<<(fptr+i)->g<<endl;
   }
	
}

void Create_D_B(student S[],int nn)
{
	student *fsptr;
	fsptr=S;
	int counter=0,roll,marks; 
    for(int i=0;i<nn;i++)
        {
        	cout<<"\nEnter the Date_of_Birth of ("<<i+1 <<") Student ( dd mm yy) : ";
        	   cin>>(fsptr+i)->dob.dd>>(fsptr+i)->dob.mm>>(fsptr+i)->dob.yy;
        	   
        	cout<<"\nEnter the Date_of_Admisson of ("<<i+1 <<") Student ( dd mm yy) : ";
        	   cin>>(fsptr+i)->doa.dd>>(fsptr+i)->doa.mm>>(fsptr+i)->doa.yy;
			      
        	  	cout<<"\nEnter Roll No of "<<i+1<<" Student : ";
        	  	cin>>roll;
        	  	 while(roll<1000 || roll>9999)
				  {
				  	cout<<"\nError! \nEnter Input Again !\n";
		            cin>>roll;
				  }
				  
				(fsptr+i)->roll=roll; 
			 cout<<"\nEnter ("<<i+1 <<") Student Name : "; 
			 cin>>(fsptr+i)->name;
			 
			 for(int j=0;j<sub;j++)
			  {
			    cout<<"\nEnter ("<<i+1 <<") Student Subject "<<j+1<<" Marks : ";
			    cin>>marks;
			    
			    while(marks<0 || marks>100)
				{
				  cout<<"\nError! \nEnter Input Again !\n";
		            cin>>marks;	
				}
			    
			    (fsptr+i)->arr[j]=marks;
			    counter=counter+marks;
			  }  
				
	         (fsptr+i)->tm=counter;
	         (fsptr+i)->avg=(counter*100)/500;
				
				  if (((fsptr+i)->avg >=60.0) && ((fsptr+i)->avg <= 69.9 ))	
				     (fsptr+i)->g='C';
				  else if (((fsptr+i)->avg >=70.0) && ((fsptr+i)->avg <= 79.9 ))	
				     (fsptr+i)->g='B'; 
				  else if (((fsptr+i)->avg >=80.0) && ((fsptr+i)->avg <= 100.0 ))	
				     (fsptr+i)->g='A';
				  else 
				     (fsptr+i)->g='F';
				
				counter=0;	 	 	  
              	
		}

cout<<"\nYour Data Successfully Stored in Database !\n";
	
}


void recall(student S[])
{
	student *sptr;
	//sptr=S;
	//ptr=S;
	int ch,n,n1,id;
	if(r==0)	
	{
	cout<<" Enter the present NO of Students :   ";
			 cin>>n;
			 while(n<1 || n>size)
	            {
	             	cout<<"Error! \nEnter Input Again !\n";
		            cin>>n;
                }
			 Create_D_B(S,n);
			 r++;	
		
	}
	 
			 
	cout<<"\nPress the Relevant No \n 1 :  Creat New DataBase \n 2 :  Append New Record \n 3 :  Search via Roll No \n 4 :  Sort via Percentage \n 5 :  Update Record \n 6 :  Delete Record \n 7 :  Display Result \n 8 :  Exit DataBase \n ";
	cin>>ch;
	while(ch<1 || ch>8)
	  {
		cout<<"Error! \nEnter Input Again !\n";
		cin>>ch;
      }   
	  			 
      switch (ch)
	  {
	     case  1:
	     	cout<<" Welcome to New DataBase \n Enter Present Student in the Class :   ";
			 cin>>n;
			 while(n<1 || n>70)
	            {
	             	cout<<"Error! \nEnter Input Again !\n";
		            cin>>n;
                }
			Create_D_B(S,n);
			 recall(S);
	      break;
	     case 2:
	     	cout<<"You can add "<<size-n<<" More Record/s \n";
		    if((size-n)==0)
		     cout<<"Memory Full !\nYou can't add More Record/s\n ";
		    else
			{
				cout<<"Enter no of New Stuents :  ";
				cin>>n1;
				while(((n1+n) >size ) || n1<1)
				{
				  cout<<"Error! \nEnter Input Again !\n";
		          cin>>n1;	
				}
			appendN(S,n,n1);				
		    } 
	        recall(S);
	      break;
		 case 3: 
		    cout<<"Enter Student roll no : ";
		    cin>>id;
		    while(id<1000 || id>9999)
		    {
		       cout<<"Error! \nEnter Input Again !\n";
		       cin>>id;
			}
			 search( S,n,id );
			 recall(S);
	      break;
	     case 4:
	     	sorting(S,n);	     	
	     	recall(S);
	      break;
	     case 5:
	     	cout<<"\nEnter Student Roll No for Update Record:  ";
	     	cin>>id;
	     	updateR(S,n,id);	     	
	     	recall(S);
	      break;
	     case 6:
		    cout<<"\nEnter student Roll No:  "; 
		    cin>>id;
		   deleteR (S,n,id );	     	
	     	recall(S);
	      break;
		 case 7:
			DispAll(S,n); 
			recall(S);
		  break;
		  	 case 8:
			 exit(0);	
	  }
}


int main()
{
	student S[size];
/*	student *sptr;
	sptr=S;
	ptr=S;
	for(int i=0;i<3;i++)
	  cin>>(sptr+i)->dob.dd;
	  
	for(int i=0;i<3;i++)
	  cout<<(sptr+i)->dob.dd<<endl; 
*/
	recall(S); 
	  
	system("pause");
	return 0;
}



