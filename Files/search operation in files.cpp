#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string sname;

class student
{
  int roll,reg;
  string name;
  public:
  void setter()
  {
  	cout<<"\n Enter the roll number of student  ";
  	cin>>roll;
  	cout<<"\n Enter the name of student   ";
  	cin>>name;
  }	
  void getter()
  {
  	cout<<"\n The roll number is "<<roll;
  	cout<<"\n The name of  student is  "<<name;
  }
  void search(char *sname)
  {
  	ifstream fin;
  	fin.open("D:\\IIUI\\3 semester\\3 Final\\OOPs\\Files\\myfile1.dat",ios::out|ios::binary);
  	if(!fin)
  	 cout<<"\n File not found ";
  	else
  	{
	fin.open("D:\\IIUI\\3 semester\\3 Final\\OOPs\\Files\\myfile1.dat",ios::out|ios::binary);

  		while(!fin.eof())
  		{
  			if(comp(sname,name))
  			{
			  	cout<<"\n Yes found ";
			  	getter();
			  	break;
			
  		}
		  }
		  fin.close();

	}
  }
};
int main()
{
	student s1;
	
	ofstream fout;
	ifstream fin;
	fout.open("D:\\IIUI\\3 semester\\3 Final\\OOPs\\Files\\myfile1.dat",ios::out|ios::binary);
	if(!fout)
	cout<<"\n An error occured ";
	else
	{
		
		s1.setter();
	
	    fout.close();
	}
	fin.open("D:\\IIUI\\3 semester\\3 Final\\OOPs\\Files\\myfile1.dat",ios::out|ios::binary);
	if(!fin)
	cout<<"\n An error occured   ";
	else
	{
		
		
		s1.getter();
	
		fin.close();
	}
	cout<<"\n Enter the name that you want to search  ";
	cin>>sname;
	s1.search(sname);
	cout<<endl;
	system("pause");
	return 0;
}
