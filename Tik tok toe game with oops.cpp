#include<iostream>
using namespace std;
#define size 3
#include<string>
class tiktok
{
	int matrix[size][size];
    int a;
    public:
    	int player;
    	string name1,name2;
    void setter();
   	void getname();
    void draw();
	void input();
	int duplicate(int );
	void toggleplayer();
	int win();	
};
int tiktok::duplicate(int a )//To check for duplicate position.
{
	switch(a)
		{
			case 1:
			if(matrix[0][0]==0 || matrix[0][0]==1)
			     return 0;
			  else
			    return 1;   
			break;
			case 2:
			if(matrix[0][1]==0 || matrix[0][1]==1)
			     return 0;
			else
			    return 1;   
			break;
			case 3:
			if(matrix[0][2]==0 || matrix[0][2]==1)
			     return 0;
			else
			    return 1; 
			break;
			case 4:
			if(matrix[1][0]==0 || matrix[1][0]==1)
			     return 0;
			else
			    return 1; 
			break;
			case 5:
			if(matrix[1][1]==0 || matrix[1][1]==1)
			     return 0;
			else
			    return 1; 
			break;
			case 6:
	     	if(matrix[1][2]==0 || matrix[1][2]==1)
			     return 0;
			else
			    return 1; 
			break;
			case 7:
			if(matrix[2][0]==0 || matrix[2][0]==1)
			     return 0;
			else
			    return 1; 
			break;
			case 8:
			if(matrix[2][1]==0 || matrix[2][1]==1)
			     return 0;
			else
			    return 1; 
			break;
			case 9:
			if(matrix[2][2]==0 || matrix[2][2]==1)
			     return 0;
			else
			    return 1; 
			break;
			
			
		}  
}

void tiktok ::setter()//To assign negative values to array index.
{
	player=0;
	int k=1;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
	{
		matrix[i][j]=-k;
		k++;
	}
}
void tiktok::getname()
{
	cout<<"\n Enter the name of first palyer.   ";
     	cin>>name1;
     	cout<<"\n Enter the name of second player.   ";
     	cin>>name2;
}
void tiktok::draw()//The display function.
{
	
	cout<<"\n The Tik Tok Toe Game.  \n\n\n  ";
	for(int i=0;i<size;i++)
	{
	for(int j=0;j<size;j++)
    {
    	cout<<matrix[i][j]<<"\t";
	}
    cout<<endl;
    }
}
void tiktok:: input()//To take the position from user.
{
	int c;
//Check for duplicate.
do	
	{
		cout<<"\n\nEnter the number. ";
	cin>>a;
	 c=duplicate(a);
	if(c!=1)
	cout<<"\nError! \nNumber Duplicate!";
	}
	while(c != 1);
//To assign the values for player 1 and 2.
	if(a==1)
	matrix[0][0]=player;
	else if(a==2)
	matrix[0][1]=player;
	else if(a==3)
	matrix[0][2]=player;
	else if(a==4)
	matrix[1][0]=player;
	else if(a==5)
	matrix[1][1]=player;
	else if(a==6)
	matrix[1][2]=player;
	else if(a==7)
	matrix[2][0]=player;
	else if(a==8)
	matrix[2][1]=player;
	else if(a==9)
	matrix[2][2]=player;
	else
	cout<<"\n Invalid Input!  ";
}
void tiktok:: toggleplayer()//To change player.
{
	if(player==0)
	player=1;
	else
	player=0;
}
int tiktok::win()//To find winner palyer.
{
	//For first palyer.
	if(matrix[0][0]==0&&matrix[0][1]==0&&matrix[0][2]==0)
    return 0;
    if(matrix[1][0]==0&&matrix[1][1]==0&&matrix[1][2]==0)
    return 0;
    if(matrix[2][0]==0&&matrix[2][1]==0&&matrix[2][2]==0)
    return 0;
    if(matrix[0][0]==0&&matrix[1][0]==0&&matrix[2][0]==0)
    return 0;
    if(matrix[0][1]==0&&matrix[1][1]==0&&matrix[2][1]==0)
    return 0;
    if(matrix[0][2]==0&&matrix[1][2]==0&&matrix[2][2]==0)
    return 0;
    if(matrix[0][2]==0&&matrix[1][1]==0&&matrix[2][0]==0)
    return 0;
    if(matrix[0][0]==0&&matrix[1][1]==0&&matrix[2][2]==0)
    return 0;
	
	//For player two.
	if(matrix[0][0]==1&&matrix[0][1]==1&&matrix[0][2]==1)
    return 1;
    if(matrix[1][0]==1&&matrix[1][1]==1&&matrix[1][2]==1)
    return 1;
    if(matrix[2][0]==1&&matrix[2][1]==1&&matrix[2][2]==1)
    return 1;
    if(matrix[0][0]==1&&matrix[1][0]==1&&matrix[2][0]==1)
    return 1;
    if(matrix[0][1]==1&&matrix[1][1]==1&&matrix[2][1]==1)
    return 1;
    if(matrix[0][2]==1&&matrix[1][2]==1&&matrix[2][2]==1)
    return 1;
    if(matrix[0][2]==1&&matrix[1][1]==1&&matrix[2][0]==1)
    return 1;
    if(matrix[0][0]==1&&matrix[1][1]==1&&matrix[2][2]==1)
    return 1;
	return 100;//Return any real int type number.
     }
     int main()
     {
     	tiktok t1;
     	t1.setter();
     	cout<<"player "<<t1.player;
     	cout<<"\nWelcome to game  ";
     	t1.draw();
     	t1.getname();
     	int c=0;
     	t1.draw();
     	while(c<9)//Number of turns.
     	{
		 t1.input();
     	t1.draw();
     if(t1.win()==0)
     	{
     		cout<<"\nThe  "<<t1.name1<<" ('x') is  winer";
     		break;
		 }
		else if(t1.win()==1)
		 {
		 	cout<<"\nThe "<<t1.name2<<"  ('o')is winer ";
		 	break;
		 }
		 t1.toggleplayer();
		 c++;
	
	}
	cout<<endl;
	system("pause");
	return 0;
	 }
