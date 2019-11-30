//**************************************************************************
//Name :  Taimoor Mansha
//Title:  Tic Tac Toe Game implementation
//Approach : using object and Class(oop)
//Compiler : Visual Studio 19
//Dated : 25/Oct/19
//Compiling date : 25/Oct/19
//International Islamic University Islamabad
//***************************************************************************


#include<iostream>
#define size 3
#include<string>
int u=-1;
using namespace std;
class tikTok
{
  private:
  //	char inp;
 // static int ctrl;
  	int pos;
    int arr[size][size]; 
    string name_1;
    string name_2;
  
  public:
  	tikTok()
  	{
  		int k=1;
  	  //ctrl=1;	
	  for(int i=0;i<3;i++)
	   for(int j=0;j<3;j++)
	   {	   
         arr[i][j]=-k;
         k++;
         
		}
    }
    void getName();
  	void control();
	void setter(int );
  	void getter();
    int duplicate(int );
    void winner();
    void looser();
	
};

void tikTok::looser()
{
	if(u==-1)
	 cout<<"OOPS!  "<<name_1<<" & "<<name_2<<"  You Both are LOOSERS!!!\n\n";
}

void tikTok::winner()
{  
	
	if( (arr[0][0]==0 && arr[0][1]==0 && arr[0][2]==0)  ||  (arr[1][0]==0 && arr[1][1]==0 && arr[1][2]==0)  ||  (arr[2][0]==0 && arr[2][1]==0 && arr[2][2]==0)  || (arr[0][0]==0 && arr[1][0]==0 && arr[2][0]==0)  ||  (arr[0][1]==0 && arr[1][1]==0 && arr[2][1]==0) ||  (arr[0][2]==0 && arr[1][2]==0 && arr[2][2]==0)  || (arr[0][0]==0 && arr[1][1]==0 && arr[2][2]==0) || (arr[0][2]==0 && arr[1][1]==0 && arr[2][0]==0) )
	   {
	   u= 0;
	   if(u==0)
	     cout<<"Congratulations!  "<<name_1<<"  You win!!!\n\n";
		 exit(0);	      
       }
    if( (arr[0][0]==1 && arr[0][1]==1 && arr[0][2]==1)  ||  (arr[1][0]==1 && arr[1][1]==1 && arr[1][2]==1)  ||  (arr[2][0]==1 && arr[2][1]==1 && arr[2][2]==1)  || (arr[0][0]==1 && arr[1][0]==1 && arr[2][0]==1)  ||  (arr[0][1]==1 && arr[1][1]==1 && arr[2][1]==1) ||  (arr[0][2]==1 && arr[1][2]==1 && arr[2][2]==1)  || (arr[0][0]==1 && arr[1][1]==1 && arr[2][2]==1) || (arr[0][2]==1 && arr[1][1]==1 && arr[2][0]==1) )
	   {
	   u= 1;
	   if(u==1)
	     cout<<"Congratulations!  "<<name_2<<"  You win!!!\n\n";
		 exit(0);	      
       }
     
	
}

 int tikTok::duplicate(int pos)
 {   
    switch(pos)
		{
			case 1:
			if(arr[0][0]==0 || arr[0][0]==1)
			     return 0;
			  else
			    return 1;   
			break;
			case 2:
			if(arr[0][1]==0 || arr[0][1]==1)
			     return 0;
			else
			    return 1;   
			break;
			case 3:
			if(arr[0][2]==0 || arr[0][2]==1)
			     return 0;
			else
			    return 1; 
			break;
			case 4:
			if(arr[1][0]==0 || arr[1][0]==1)
			     return 0;
			else
			    return 1; 
			break;
			case 5:
			if(arr[1][1]==0 || arr[1][1]==1)
			     return 0;
			else
			    return 1; 
			break;
			case 6:
	     	if(arr[1][2]==0 || arr[1][2]==1)
			     return 0;
			else
			    return 1; 
			break;
			case 7:
			if(arr[2][0]==0 || arr[2][0]==1)
			     return 0;
			else
			    return 1; 
			break;
			case 8:
			if(arr[2][1]==0 || arr[2][1]==1)
			     return 0;
			else
			    return 1; 
			break;
			case 9:
			if(arr[2][2]==0 || arr[2][2]==1)
			     return 0;
			else
			    return 1; 
			break;
			
			
		}  
    	
 }


void tikTok::getter()
{
	for(int i=0;i<3;i++)
	{
	
	   for(int j=0;j<3;j++)
	       if(arr[i][j]==0)
             cout<<"\t"<<"X"<<"   ";
            else if(arr[i][j]==1)
			 cout<<"\t"<<"O" <<"   ";
			else 
			cout<<"\t"<<"..."<<"   "; 
       cout<<"\n\n";
    }
        
}
void tikTok::setter(int user)
{
  int c;
  
  if(user==1 || user==3 || user==5 || user ==7 || user==9)
    user=1;
  else
    user=2;
 if(user==1)
  cout<<" "<<name_1<<" Its your turn\n";
 else
  cout<<""<<name_2<<" Its your turn\n";
   			
   cout<<"Enter the relevent position\n"
	"1) for position row 1, col 1\n"
	"2) for position row 1, col 2\n"
	"3) for position row 1, col 3\n"
	"4) for position row 2, col 1\n"
	"5) for position row 2, col 2\n"
	"6) for position row 2, col 3\n"
	"7) for position row 3, col 1\n"
	"8) for position row 3, col 2\n"
	"9) for position row 3, col 3\n";
	
           do{////////////////////////////////////////////////////////Duplicate input check
			   cin>>pos;
        	  	 while(pos<1 || pos>9)
				  {
				  	cout<<"\nError! \nEnter correct position !\n";
		            cin>>pos;
				  }
				  
				  c=duplicate(pos);////////////////////////////////////for checking the duplicate entries 
				  if(c != 1)
				  	cout<<"\nError! \nPosition Duplicate!\nEnter position again :";
		            
			 }while(c != 1);
	switch(pos)
		{
		  case 1:
			if(user==1)	
			 {
			 arr[0][0]=0;
		     void winner();
			}
			else
			{			
			 arr[0][0]=1;
		     void winner();
		    }
			break;
	      case 2:
			if(user==1)
			{
			 arr[0][1]=0;
			 void winner();
		    }
			else
			 {
			 arr[0][1]=1;
			 void winner();
		     }
			break;
		  case 3:
		  	if(user==1)
			  {
				
			 arr[0][2]=0;
			 void winner();
			 }
			else
			 {
			 arr[0][2]=1;
			 void winner();
			 } 
			break;
		  case 4:
		  	if(user==1)	
			  {
			 arr[1][0]=0;
			 void winner();
			 }
			else
			 {
			 arr[1][0]=1;
			 void winner();
			 }
			break;
		  case 5:
		  	if(user==1)	
			  {
			 arr[1][1]=0;
			 void winner();
			 }
			else
			  {
			 arr[1][1]=1;
			 void winner();
			 }
			break;
		  case 6:
		  	if(user==1)	
			  {
			 arr[1][2]=0;
			 void winner();
			 }
			else
			  {
			 arr[1][2]=1; 
			 void winner();
			 }
			break;
		  case 7:
		  	if(user==1)	
			  {
			 arr[2][0]=0;
			 void winner();
			 }
			else
			  {
			 arr[2][0]=1;
			 void winner(); 
			 }
			break;
		  case 8:
		  	if(user==1)	
			  {
			 arr[2][1]=0;
			 void winner();
			 }
			else
			  {
			 arr[2][1]=1;
			 void winner(); 
			 }
			break;
		  case 9:
		  	if(user==1)	
			  {
			 arr[2][2]=0;
			 void winner();
			 }
			else
			  {
			 arr[2][2]=1;
			 void winner(); 
	        	}
			break;
			
			
		}	 
      
}

 void tikTok::getName()
 { 
    cout<<"Enter the Name of First Player :   ";
    cin>>name_1;
 	cout<<"Enter the Name of Second Player :   ";
    cin>>name_2;
 }

int main()
{   
    tikTok t1;
    cout<<"Welcome to Game\n";
    cout<<"Player 1 input symbol 'X'\nPlayer 2 input symbol 'O'\n";
     t1.getName();
	 t1.getter();
    for(int i=1;i<=9;i++)
     {
	 
	 t1.setter(i);
     t1.getter();
	 t1.winner();
	 if(i==9)
	   t1.looser();
	}
	system("pause");
	return 0;
}




