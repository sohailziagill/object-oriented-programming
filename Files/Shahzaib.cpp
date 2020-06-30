#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class statistics
{
	string inp;
	int digit,punc,upper,lower,space,tchar,bytes;
	int end,start,bb;
	float kilobytes;
	char read;
	fstream file;
	fstream newfile;
public:
	statistics(int d=0,int p=0,int u=0,int l=0,int s=0,int t=0,int bb=0,float kb=0.0):digit(d),punc(p),upper(u),lower(l),space(s),tchar(t),bytes(bb),kilobytes(kb){}
	void setter();
	void getter();
	void copyfile();
	void dispStat();
};

void statistics::setter()
{	
	file.open("statistic.txt",ios::app|ios::in);
	if(!file)
	{
		cout<<"Error!!!\n";
		exit(-1);
	}
		cout<<"enter the data: ";
		cin.ignore();
		getline(cin,inp);
		file<<inp;
	file.close();
}

void statistics::getter()
{	
	file.open("statistic.txt",ios::app|ios::in);
	if(!file)
	{
		cout<<"Error!!!\n";
		exit(-1);
	}
	while(file.get(read))
	{
	  cout<<read;
	}
	cout<<endl;
	file.close();
}

void statistics::copyfile()
{
     file.open("statistic.txt",ios::in);
	if(!file)
	{
		cout<<"Error!!!\n";
		exit(-1);
	}
	newfile.open("copy.txt",ios::out);
		if(!newfile)
	{
		cout<<"Error!!!\n";
		exit(-1);
	}
	while (file.get(read))
	{
		newfile.put(read);
	}
	newfile.close();
	file.close();
    
}

void statistics::dispStat()
{
    file.open("statistic.txt",ios::in);
	if(!file)
	{
		cout<<"Error!!!\n";
		exit(-1);
	}
	while(file.get(read))
	{
	     ++bytes;
			if(isupper(read)){
				tchar++;
				upper++;
			}
			else if(islower(read)){
				tchar++;
				lower++;
			}
			else if(isdigit(read)){
				tchar++;
				digit++;
			}
			else if(ispunct(read)){
				tchar++;
				punc++;
			}
			else if(isspace(read)){
				tchar++;
				space++;
			}
	}
	file.close();
	file.open("statistic.txt",ios::in);
	file.seekg(0,ios::beg);
	start=file.tellg();
	file.seekg(0,ios::end);
	end=file.tellg();
	file.close();
	bb=end-start;  //bb is no of bytes
	cout<<"\n\n\n The size of file is "<<end-start<<"\n\n\n";
	kilobytes=(bytes*1.0)/1024;
		cout<<"----------------Statistics-----------------\n"
			<<"Total words are:\t"<<tchar<<endl
			<<"Total uppercase letters are: \t"<<upper<<endl
			<<"Total lowercase letters are: \t"<<lower<<endl
			<<"Total digits are: \t"<<digit<<endl
			<<"Total punctuation marks are: \t"<<punc<<endl
			<<"Total spaces are: \t"<<space<<endl
			<<"no of bytes:"<<bb<<endl
			<<"no of kilobytes"<<kilobytes<<endl;
		//	<<"bytes:"<<bb<<endl;
}

int main()
{
	statistics file1;
	int choice;
	do
	{
	cout<<"1. Enter the data.\n2. Display file data.\n3. Display statistics.\n4. copy file\t5. exit\nWhat's your choice:\t";
	cin>>choice;
	switch(choice)
	{
	case 1:
		file1.setter();
		break;
	case 2:
		file1.getter();
		break;
	case 3:
		file1.dispStat();
		break;
	case 4: file1.copyfile();
	         break;
	case 5:
	        exit (-1);         
		  	break;
	default:
		cout<<"invalid choice!!!\n";
	}
	}while(1);
	system("pause");
	return 0;
}
