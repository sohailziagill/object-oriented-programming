#include<iostream>
using namespace std;
struct node{
	int marks;
	node *next;	
};
int main()
{
int option=1;
	node *first=NULL,*current=NULL,*prev=NULL;
do//input operation.
{
	current=new node;
	current->next=NULL;
	cout<<"\n Enter the marks       ";
	cin>>current->marks;
	if(first==0)
	first=prev=current;
	else
	{
	prev->next=current;	
	prev=current;
	}
	cout<<"\n Enter 0 or 1  :";
	cin>>option;
	
	}
	while(option==1);	
	//output operation.
	current=first;
	while(current!=0)
	{
		cout<<current->marks<<endl;
		current=current->next;
		
	}

cout<<"\nHAHAHHAHAHHAHAHA "<<endl;

	
	//Insertion operation.
	node *newnode=NULL;
	newnode= new node;
	newnode->next=NULL;
	bool insertdone=false;
	cout<<"\nEnter the marks  ";
	cin>>newnode->marks;
	if(newnode->marks<=first->marks)
	
	{
		newnode->next=first;
		first=newnode;
		
		
	}
	else {
		current=prev=first;
		while	(current!=0)
		{//for mid insertion.
			if(newnode->marks>=current->marks)
			{
		
	prev=current;
	current=current->next;	
				insertdone=true;
		}
		else
		{
			newnode->next=current;
			prev->next=newnode;
				insertdone=true;
			break;
		}
		
}
	}//for end insertion.
	if(insertdone==false)
	prev->next=newnode;
	
	
	
	//output operation.
	current=first;
	while(current!=0)
	{
		cout<<current->marks<<endl;
		current=current->next;
		
	}
	
	


	
	system("pause");
	return 0;
}
