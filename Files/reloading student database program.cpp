#include<iostream>
#include<fstream>
using namespace std;
class student
{
  int roll;
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
};
int main()
{
	int i;
	student s1[10];
	ofstream fout;
	ifstream fin;//
///////////////////////////////To reload the prevoius data in program from file //////////////////////
    fin.open("D:\\IIUI\\3 semester\\3 Final\\OOPs\\Files\\myfile1.txt",ios::out|ios::binary);
	if(!fin)
	cout<<"\n An error occured   ";
	else
	{
		fin.read((char*)&i,sizeof(int));
		fin.read((char*)&s1,i*sizeof(student));
		for(int k=0;k<i;k++)
		{
		
		s1[k].getter();
	}
		fin.close();
	}
////////////////////////To write the data/////////////////////////////////////////////////////////////
	cout<<"\n Enter the number of students ";
	cin>>i;
	fout.open("D:\\IIUI\\3 semester\\3 Final\\OOPs\\Files\\myfile1.txt",ios::out|ios::binary);
	if(!fout)
	cout<<"\n An error occured ";
	else
	{
		fout.write((char*)&i,sizeof(int));
		for(int j=0;j<i;j++)
		{
		s1[j].setter();
	}
		fout.write((char*)&s1,i*sizeof(student));
	    fout.close();
	}
/////////////////////////////////////////////To display data/////////////////////////////////////////
		fin.open("D:\\IIUI\\3 semester\\3 Final\\OOPs\\Files\\myfile1.txt",ios::out|ios::binary);
	if(!fin)
	cout<<"\n An error occured   ";
	else
	{
		fin.read((char*)&i,sizeof(int));
		fin.read((char*)&s1,i*sizeof(student));
		for(int k=0;k<i;k++)
		{
		
		s1[k].getter();
	}
		fin.close();
	}
	cout<<endl;
	system("pause");
	return 0;
}
