#include<iostream>
using namespace std;
struct node{
	
	int marks;
	node *next_address;
	
	
};
int main()
{	int option;
	node *first_adress=NULL;
	node *current_address=NULL;
	node *previous_address=NULL;
	current_address=new node;
	cout<<"\n Enter the marks   ";
	cin>>current_address->marks;
	first_adress=previous_address=current_address;
	cout<<"\n If there is another student then enter 1 if not then 0    ";
		cin>>option;
	do{
	
		
		
		current_address=new node;
	cout<<"\n Enter the marks   ";
	cin>>current_address->marks;
		previous_address->next_address=current_address;
		
		previous_address=current_address;
			cout<<"\n If there is another student then enter 1 if not then 0    ";
		cin>>option;
	}
	while(option==1);
	
	
	//To dispaly rewind it
	current_address=	first_adress;
	while(current_address!=0)
	{
		cout<<endl;
		cout<<	current_address->marks;
			current_address=	current_address->next_address;
		
		}	
	cout<<endl;
	
	system ("pause");
	return 0;
}
