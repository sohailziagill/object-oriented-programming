#include<iostream>
using namespace std;
class node 
{
	private:
		node *first,*curr,*prev;
	int marks;
	node *next=0;
	public:
		node()
		{
			first=curr=prev=0;		}
		void insert();
		void inset();
		void deletion();
		void getter();
		void search();
		
};
///////////////////////////////////////////////////////////////////////////////////////////////////
	void node::deletion ()
	{
		//for deletion at start.
	int del;
	cout<<"\n Enter the number that you want to delete. ";
	cin>>del;
	curr=prev=first;
	if(del==first->marks)
	{
		cout<<"\n Deleted ";
		first=first->next;
		delete curr;
	}
	//for middle and at end deletion 
	else
	{
		while(curr->next!=0)
		{
			if(del==curr->marks)
			{
			cout<<"\n Deleted.";
			prev->next=curr->next;
			delete curr;
			break;
		}
		
		else
		{
			prev=curr;
			curr=curr->next;
		}
	}

}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void node::insert()
{

	bool insert=false;
	//insertion operation
	node *newnode=0;
	newnode=new node;
	newnode->next=0;
	cout<<"\n Enter the value in an insertion operator   ";
	cin>>newnode->marks;
	//for beginning insertion
	if(newnode->marks<=first->marks)
	{
		newnode->next=first;
		first=newnode;
		insert=true;
	}
	//for mid insertion
	else
	{
			curr=prev=first;
		while	(curr!=0)
		{
		if(newnode->marks>=curr->marks)
		{
		
		prev=curr;
		curr=curr->next;
  	    }
  	    else
  	    {
  	    	prev->next=newnode;
  	    	newnode->next=curr;
  	    	insert=true;
  	    	break;
		  }
    }
}
///For end insertion.
if(insert==false)
prev->next=newnode;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
	// outputt
	void node::getter()
	{
			prev=curr=first;
	while(curr->next!=0)
	{
		cout<<"\n "<<curr->marks;
		curr=curr->next;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////
		void node::inset()
		{
			
		
		curr=new node;
			cout<<"\n Enter the value                     ";
	cin>>curr->marks;
	if(first==0)
	first=prev=curr;
	else
	{
			
	prev->next=curr;
	prev=curr;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//Search in link list.
void node::search()
{
	

int num;
bool flag;
cout<<"\n Enter the number that you want to search   ";
cin>>num;
curr=first;
while(curr->next!=0)
{
	if(curr->marks ==num)
	{
		flag =true;
		break;
	}
	curr=curr->next;
	
}
if(flag==true)
cout<<"\n The entered number is found at  "<<curr;
		else
		cout<<"\n The entered number is not found  ";
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int op;
	node game;
	
	do
	{
		game.inset();
	cout<<"\n For another student enter 1 else 0        ";
	cin>>op;
	if(op==0)
	break;
	}
	while(op==1);
	// outputt
    game.getter();
	game.insert();
    game.getter();
    game.search();
    game.deletion();
    game.getter();
	cout<<endl;
	system("pause");
	return 0;
}



