//**************************************************************************
//Name :     Taimoor Mansha
//Title:     Stack(LIFO) implimentation using LinkList
//Approach : Using object and Class(oop)
//Compiler : Visual Studio 19
//Dated :    08/Nov/19
//Compiling date : 08/Nov/19
//International Islamic University Islamabad
//***************************************************************************


#include <iostream>
using namespace std;
struct node
{ 
   int m;
   node *next;
   node *preNext;
};

class stack_linklist
{
	      node *first=NULL,*prev=NULL,*cur=NULL;
	      node *temp;
	public:
		void setter();
		void getter();
};
void stack_linklist::setter()
{
	int marks,op;
	
	
	do{	
	    cur =new node;
	    if(first==NULL)
	        first=prev=cur;
	    cout<<"\nEnter Student Marks : ";
		cin>>marks; 
	    cur->m=marks; 
		cur->next=NULL;
		cur->preNext=prev; 
	    prev->next=cur;
	    prev=cur;
	    cout<<"\nPress 1 to add new student record in Database else 0: ";
		do{			   
	        cin>>op;
	        if(op<0 || op>1)
	          cout<<"\nError!!!\nEnter Right Choice: ";
	      }while(op<0|| op>1);
      }while(op!=0);
      
    temp=cur;///////////////////////////////////////////////////////////////////We should not use directly cur
    
	
}
void stack_linklist::getter()
{
   int op=1;	
   while(op)////////////////////////////////////////////////////////////////////For Output(LIFO) LinkList Data
	{
	    cout<<"\nMarks: "<<temp->m;
		if(first == temp)
		 op=0;
		temp=temp->preNext; 	
	} 	
	
}

int main()
{
	stack_linklist s;
	s.setter();
	s.getter();
	 
	
	system("pause");
	return 0;
}
