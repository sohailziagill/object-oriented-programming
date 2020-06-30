#include<iostream>
using namespace std;
struct node {
	int marks;
	node *next;
	
	
};

int main()
{
	int op;
	node *first=0,*prev=0,*curr=0;
	curr=new node;
	curr->next=0;
	first=prev=curr;
	cout<<"\nEnter the marks  ";
	cin>>curr->marks;
    cout<<"\n If there is another student then press 1 other wise press 0    ";
    cin >>op;
    //To create more linnk lists.
		while(op==1)
		{
			curr=new node;
			curr->next=0;
			prev->next=curr;
			prev=curr;
			cout<<"\nEnter the marks  ";
			cin>>curr->marks;
			cout<<"\n If there is another student then press 1 other wise press 0    ";
            cin >>op;
		}
		//To display link list.
		curr=first;
		while(curr->next!=0)
		{
			cout<<"  \n"<<curr->marks;
			curr=curr->next;
		}

//Search in link list.

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
	

		
	
cout<<endl;
cout<<"\n HAHAHAHAHAHAHAHAHAHaH ";
	system ("pause");
	return 0;
}
