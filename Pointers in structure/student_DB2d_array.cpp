#define row 70
#define col 9
#include<iostream>
using namespace std;
void sorting(int ,float,char ,int);
int searchRec(int s_r[][col],int id,int nn)
{
	
   	int ind=0;
    	for(int i=0;i<nn;i++)
  	     if(s_r[i][1]==id)
  	       ind=i;
  	return ind;	
}

void DispAll(int s_r[][col],float avg[],char grade[],int n)
{
	
	cout<<"SR#:-\tRoll#:-\tSub 1:-\tSub 2:-\tSub 3:-\tSub 4:-\tSub 5:-\tSub 6:-\tTotal:-\tPercentage:-\tGrade\n ";      
      //cout<<"\t";
	  for(int i=0;i<n;i++)
	  {
	  
	   for(int j=0;j<col;j++)	   
         cout<<s_r[i][j]<<"\t";
      cout<<avg[i]<<"\t\t"<<grade[i]<<"\n";
      }
}
void deleteR(int s_r[][col],float avg[],char grade[],int id,int &n)
{
 int ind=0;
 ind= searchRec(s_r,id,n);
 if(ind==0)
    cout<<"\nRecord Not Found \n"; 
 else
      {
      	for(int i=ind;i<n-1;i++)
      	{
      	   for(int j=1;j<col;j++)
      	     swap(s_r[i][j],s_r[i+1][j]);
      	  swap(avg[i],avg[i+1]);
		  swap(grade[i],grade[i+1]); 
	    }
	    n--;
	   //sorting (s_r,avg,grade,n);
	  }	 
}	 
void updateR(int s_r[][col],float avg[],char grade[],int id,int n)
{
  int ind=0,roll,counter=0;
  ind=searchRec(s_r,id,n);
  if(ind==0)
     cout<<"\nRecord Not Found\n";
  else
  {
   	  cout<<"Enter Roll No :-";
  	  cin>>roll;
  	  while(roll<1000 || roll>9999)
  	  {
  	  	cout<<"Error! \nEnter Input Again !\n";
		cin>>roll;
	  }
	  s_r[ind][1]=roll;
	  for(int j=2;j<8;j++)
	     {
	     	cout<<"Enter Subject "<<j-1<<" Marks";
	     	cin>>s_r[ind][j];
	     	counter=counter+s_r[ind][j];
		 }
	  s_r[ind][8]=counter;
	  avg[ind]=(counter*100)/600.0;
	 if ((avg[ind] >=60.0) && (avg[ind] <= 69.9 ))	
		 grade[ind]='C';
	 else if ((avg[ind] >=70.0) && (avg[ind] <= 79.9 ))	
		 grade[ind]='B'; 
	 else if ((avg[ind] >=80.0) && (avg[ind] <= 100.0 ))	
		 grade[ind]='A';
     else 
		 grade[ind]='F';
	counter=0;	 	 
  }   
}
void sorting(int s_r[][col],float avg[],char grade[],int nn)
{
  for(int k=0;k<nn;k++)
   for(int i=0;i<nn-1;i++)
     if(avg[i]<avg[i+1])
          {
          	 for(int j=1;j<col;j++)
          	   swap(s_r[i][j],s_r[i+1][j]);
          	swap(avg[i],avg[i+1]);
			swap(grade[i],grade[i+1]);     
	      }     
          
  cout<<"\nSorting Successfully!\n";	
}

void search(int s_r[][col],float avg[],char grade[] ,int id,int nn)
{
  	int ind=0;
  //	for(int i=0;i<nn;i++)
  //	 if(s_r[i][1]==id)
  	     ind= searchRec(s_r,id,nn);
  	if(ind==0) 
	  cout<<"Record not Found \n";
	else
	{
	
	  cout<<"SR#:-\tRoll#:-\tSub 1:-\tSub 2:-\tSub 3:-\tSub 4:-\tSub 5:-\tSub 6:-\tTotal :-\tPercentage:-\tGrade\n ";
	   //cout<<"\t";
	  for(int i=0;i<col;i++)
        cout<<s_r[ind][i]<<"\t";
      cout<<"\t"<<avg[ind]<<"\t\t"<<grade[ind]<<"\n"; 
    }
}

void Create_D_B(int s_r[][col],float avg[],char grade[],int nn)
{
 int counter=0,roll,marks;
   for(int i=0;i<nn;i++)
    for(int j=0;j<col;j++)
        {
        	if(j==0)
        	s_r[i][j]=i+1;
        	else if(j==1)
        	  {
        	  	cout<<"Enter Roll No of "<<i+1<<" Student";
        	  	cin>>roll;
        	  	 while(roll<1000 || roll>9999)
				  {
				  	cout<<"Error! \nEnter Input Again !\n";
		            cin>>roll;
				  }
				s_r[i][j]=roll;  
			  }
			else if( j==2 || j==3 || j==4 || j==5 || j==6 || j==7 )
			  {
				cout<<"Student "<<i+1<<" Subject "<<j-1<<" Marks\n";
				cin>>marks;
				while(marks<0 || marks>100)
				{
				  cout<<"Error! \nEnter Input Again !\n";
		            cin>>marks;	
				}
				s_r[i][j]=marks;
				counter=counter+marks;
			  }  
	        else
	          {
	          	s_r[i][j]=counter;
				avg[i]= (counter*100)	/ 600.0;
				  if ((avg[i] >=60.0) && (avg[i] <= 69.9 ))	
				     grade[i]='C';
				  else if ((avg[i] >=70.0) && (avg[i] <= 79.9 ))	
				     grade[i]='B'; 
				  else if ((avg[i] >=80.0) && (avg[i] <= 100.0 ))	
				     grade[i]='A';
				  else 
				     grade[i]='F';
				
				counter=0;	 	 	  
              }
	
		}


}
void recall(int s_r[][col],float avg[],char grade[])
{
	int ch,n,id;
	cout<<"Press the Relevant No code \n 1 :- Creat New DataBase \n 2 :- Append New Record \n 3 :- Search via Roll No \n 4 :- Sort via Roll No \n 5 :- Update Record \n 6 :- Delete Record \n 7 :- Display Result \n 8 :- Exit DataBase \n ";
	cin>>ch;
	while(ch<1 || ch>8)
	  {
		cout<<"Error! \nEnter Input Again !\n";
		cin>>ch;
      }
      
     
			 
      switch (ch)
	  {
	     case  1:
	     	cout<<" Welcome to New DataBase \n Enter Present Student in the Class :-  ";
			 cin>>n;
			 while(n<1 || n>70)
	            {
	             	cout<<"Error! \nEnter Input Again !\n";
		            cin>>n;
                }
			 Create_D_B(s_r,avg,grade,n);
			 recall(s_r,avg,grade);
	      break;
	     case 2:
	     	cout<<"Working on it \n";
	        recall(s_r,avg,grade);
	      break;
		 case 3: 
		    cout<<"Enter Student roll no";
		    cin>>id;
		    while(id<1000 || id>9999)
		    {
		       cout<<"Error! \nEnter Input Again !\n";
		       cin>>id;
			}
			 search( s_r,avg,grade,id,n );
			 recall(s_r,avg,grade);
	      break;
	     case 4:
	     	sorting(s_r,avg,grade,n);	     	
	     	recall(s_r,avg,grade);
	      break;
	     case 5:
	     	cout<<"\nEnter Student Roll No for Update Record:- ";
	     	cin>>id;
	     	updateR(s_r,avg,grade,id,n);	     	
	     	recall(s_r,avg,grade);
	      break;
	     case 6:
		    cout<<"\nEnter student Roll No:- "; 
		    cin>>id;
		    deleteR (s_r,avg,grade,id,n );	     	
	     	recall(s_r,avg,grade);
	      break;
		 case 7:
			DispAll(s_r,avg,grade,n); 
			recall(s_r,avg,grade);
		  break;
		  	 case 8:
			 exit(0);	
	  }
}


int main()
{
	
	int s_r[row][col]={0};
	float avg[row]={0.0};
	char grade[row];
	cout<<"Student DataBase \n Welcome to main Menu\n";
	recall(s_r,avg,grade);
	
    system("pause");
    return 0;
}
