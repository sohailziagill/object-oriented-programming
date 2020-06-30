#include<iostream>
#include<fstream>
#include<string>
#include<typeinfo>
#define MAX 100
int ocount=0;
using namespace std;
class employee
{
	protected:
		int enumber;
		char ename[50],CNIC[15];
		//static int count;
	public:
	  virtual void getter()const
		{
		 cout<<"~~~~~~~~~~~~~~~~~~~OUTPUT~~~~~~~~~~~~~~~~~~~"<<endl;	
		 cout<<"    The Serial No of Employee :  "<<enumber<<endl;
	     cout<<"    The name of Employee      :  "<<ename<<endl;
	     cout<<"    The CNIC of Employee      :  "<<CNIC<<endl;
		}
		virtual void setter()
		{
	      cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		  cout<<"    Enter the Serial NO of Employee :  "; 
          cin>>enumber;
	      cout<<"    Enter the Name of Employee      :  ";
	      cin>>ename;
	      cout<<"    Enter the CNIC of Employee      :  ";
	      cin>>CNIC;
		}
		virtual void isoutstanding() = 0; ///pure Virtual Function
		
					 
};

//////////////////////////////////////////////////////////////////////////////

class manager:public employee
{
	protected:
		char title[50];
		float dues;
	public:
	    
    	void getter()const;
		void setter();	
		void isoutstanding();
};
void manager::setter()
{
	employee::setter();
	cout<<"    Enter the Post of Employee      :  ";
	cin>>title;
    cout<<"    Enter the Club Dues             :  ";
	cin>>dues;
		
	
 }
 void manager::getter()const
 {
 	employee::getter();	    
	 	cout<<"    The Post  of Employee     :  "<<title<<endl;
		cout<<"    The Club Dues of Employee :  "<<dues<<endl; 	
	 
 }
 void manager::isoutstanding()
 {
 	
 	if(dues<10000)
 {	
	cout<<"    ~~~Is Outstanding~~~   "<<endl;
	ocount++;}
 }
 ////////////////////////////////////////////////////////////////////////
 class scientist:public employee 
 {
 	protected:
 		char field[30];
 		int book_num;
 	public:
	   	void setter();
		void getter()const;
		void isoutstanding();
		
			
 };
 void scientist::isoutstanding()
 {
 	
 	if(book_num>=5)
 {	
	cout<<"    ~~~Is Outstanding~~~    "<<endl;
	ocount++;}
 }
 void scientist::setter()
 {
 	employee::setter();
	    
	 	cout<<"    Enter the Field of Employee     :  ";
	 	cin>>field;
	 	cout<<"    Enter the Number of Books Read  :  ";
	 	cin>>book_num;
	 
 }
 void scientist::getter()const
 {
 	employee::getter();
	    
		cout<<"    The Field of Employee     :  "<<field<<endl;
	 	cout<<"    The Number of Books Read  :  "<<book_num<<endl;
	 
 }
 ///////////////////////////////////////////////////////////////////
 class labour:public employee
 {
 	protected:
 		char shift[20];
 		float hrs_work;
 	public:	
 	    void setter();
 	    void getter()const;
 	    void isoutstanding();
 };
 void labour::isoutstanding()
 { 	
 	if(hrs_work>8)
 {	cout<<"     ~~~Is Outstanding~~~  "<<endl;
	ocount++;}
 }
 void labour::setter()
 {
 	employee::setter();
 		cout<<"    Enter Employee Shift            :  ";
 		cin>>shift;
 		cout<<"    Enter Working Hours of Employee :  ";
 		cin>>hrs_work;
	 
 }
 void labour::getter()const
 {
 	employee::getter();
 	cout<<"    The Serial No of Employee :  "<<enumber<<endl;
 	cout<<"    The Shift of Employee     :  "<<shift<<endl;
 	cout<<"    Working Houes of Employee :  "<<hrs_work<<endl;
    
 }
 ///////////////////////////////////////////////////////////////////////
 class foreman:public labour
 {
 	protected:
 		char fname[30];
 		int l_num;
 	public:
	   void setter();
	   void getter()const;	
	   void isoutstanding();
 };
 void foreman::isoutstanding()
 {
 	
 	if(l_num>5)
 	{cout<<"     ~~~Is Outstanding~~~   "<<endl;
	ocount++;}
 }
 void foreman::setter()
 {
 	labour::setter();
 	cout<<"    Enter the Name of Foreman :  ";
 	cin>>fname;
 }
 void foreman::getter()const
 {
 	labour::getter();
 	cout<<"    The Name of Foreman is    :  "<<fname<<endl;
 	cout<<"    The Labour Under Foreman  :  "<<l_num<<endl;
 }
 
 
 ////////////////////////////////////////////////////////////////////////
 int main()
 {
	int  count=0, ch , pos;
	int mc=0,sc=0,lc=0,fc=0;
    char c; //for filing use
 	employee *e[MAX] ;
 	 
	
	 ifstream inpfile;
	 inpfile.open("EmpFile.dat",ios::in| ios::binary);
	 inpfile.seekg(0,ios::beg) ;
	 inpfile.read((char*)&count , sizeof(count));
	 if( count !=0 )
	    {
		    cout<<"\n  For data loading the value of count is "<<count<<endl;;
	        for(int i=0;i<count;i++) 
	         {
	       	    inpfile.read((char*)&c,sizeof(c));
	       	    if(c == 'm')
	       	      {
					e[i] = new manager;						        	      	
	       	      	inpfile.read((char*)(e[i]) ,sizeof(manager));
	       	      
				  }
			   else	if(c == 's')
	       	      {
					e[i]  = new scientist;		 	       	      	
	       	      	inpfile.read((char*)(e[i]) ,sizeof(scientist));
	       	      	
				  } 
			   else	if(c == 'l')
	       	      {
					e[i] = new labour;	 	       	      	
	       	      	inpfile.read((char*)(e[i]) ,sizeof(labour));
	       	      	 
				  }
			   else 
			      {	
					e[i] = new foreman;         	      	
	       	      	inpfile.read((char*)(e[i]) , sizeof(foreman));
	       	      	
			      	
				  }     
		     }
	    }
	inpfile.close();
		 
	ofstream ofobj;
        ofobj.open("EmpFile.dat" , ios::app | ios::binary);	
 	
 	do{
		cout<<"~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~\n\n"
		      "          ENTER CHOICE     \n"
			  "    1.Create Manager Object\n"
		      "    2.Create Scientist Object\n"
			  "    3.Create Labour Object\n"
			  "    4.Create Foreman Object\n"
			  "    5.Display All Data\n"
			  "    6.Exit \n\n"
			  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
 		cin>>ch;
 		switch(ch)
 		{
 			case 1:			 				 
 				cout<<"\t\t~~~~~MANAGER~~~~~"<<endl;
				e[count]  = new manager;
 				e[count]->setter();
 				 
 			   	c='m';					 
				ofobj.write((char*)&c , sizeof(c)); //store character for judge it is going to store emp obj data
				ofobj.write((char*)(e[count]) , sizeof(manager)); 	
				count++; 
				
				 break;
 			case 2: 				 
				cout<<"\t\t~~~~~SCIENTIST~~~~~"<<endl;
				e[count] =  new scientist;
 				e[count]->setter();
 				 
				c='s'; 
				ofobj.write((char*)&c , sizeof(c)); //store charecter for judge it is going to store Scientist obj data
				ofobj.write((char*)(e[count]) , sizeof(scientist)); 
				count++; 
				
				 break;
			case 3:
			{	
			    cout<<"\t\t~~~~~LABOUR~~~~~"<<endl;			
 				e[count] =  new labour;;
 				e[count]->setter();
 				
				c='l'; 
				ofobj.write((char*)&c , sizeof(c)); //store charecter for judge it is going to store labour obj data
				ofobj.write((char*)(e[count]), sizeof(labour)); 
 		        count++;
 		        
			 }
				 break;
			case 4:
			 {
				cout<<"\t\t~~~~~FOREMAN~~~~~"<<endl;	 
 				e[count] =  new foreman;
 				e[count]->setter();
 				 
				c='f'; 
				ofobj.write((char*)&c , sizeof(c)); //store charecter for judge it is going to store foreman obj data
				ofobj.write((char*)(e[count]) , sizeof(foreman)); 
 		        count++;
 		  
			  }
			 break;
 			
			case 5:
			    if(count !=0)
			    {
			
				 for(int i=0;i<count;i++)
				  {
					e[i]->getter();
					e[i]->isoutstanding();
					if(typeid(*e[i])==typeid(manager))
/*To display the objects */		mc++;
					else if(typeid(*e[i])==typeid(scientist))
						sc++;
					else if(typeid(*e[i])==typeid(labour))
						lc++;
					else if(typeid(*e[i])==typeid(foreman))
						fc++;
				  }
				cout<<"          ~~~~~~~Objects~~~~~~~\n"<<endl;
				cout<<"            Total Objects   : "<<count<<endl;
				cout<<"            Outstanding are : "<<ocount<<endl;				
				cout<<"            Manager are     : "<<mc<<endl;
				cout<<"            Scientist are   : "<<sc<<endl;
				cout<<"            Labour are      : "<<lc<<endl;
				cout<<"            Foreman are     : "<<fc<<endl;
				cout<<"\n         ~~~~~~~~~~~~~~~~~~~~~~"<<endl;				
		       	}
		       else
			     cout<<"Enter Data First"<<endl;	
				break;
				
			case 6: 
			   break;
			   	 	
		 }
	 }while(ch != 6);	 
	 ofobj.close();
	 cout<<"\n The value of count befor the store "<<count<<endl;
	 ofobj.open("EmpFile.dat" , ios::ate | ios::binary);
     ofobj.seekp(0,ios::beg);
	 ofobj.write((char*)&count , sizeof(count));
	 ofobj.close();
	 system("pause");
 	return 0;
 }
