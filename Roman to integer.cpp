#include<iostream>
#include<string>
using namespace std;
class romantype
{
	string num;
	int decimal;
	public:
		void setter();
		void romantodecimal();
	
};
void romantype::setter() 
{
	cout<<"\n Enter the roman numbe.  ";
	cin>>num;
}

void romantype:: romantodecimal()
{
	decimal=0;
	for(int i=0;i<num.length();i++)
	{ int total=0;
		switch(num[i])
		{
			case 'M':
                      total = 1000;
                      break;
                 case 'm':
                      total = 1000;
                      break;
                 case 'D':
                      total = 500;
                      break;
                 case 'd':
                      total = 500;
                      break;
                 case 'C':
            
                 	
                      total= 100;
                      break;
                 case 'c':
                      total = 100;
                      break;
                 case 'L':
                      if (i > 0 &&num[i - 1] == 'X')
                total -= 20;
            total += 50;
                      break;
                 case 'l':
                      if (i > 0 &&num[i - 1] == 'x')
                total -= 20;
            total += 50;
                      break;
                 case 'X':
                 	 if (i > 0 && num[i - 1] == 'I')
                total -= 2;
            total+= 10;
                      break;
                 case 'x':
                     if (i > 0 && num[i - 1] == 'i')
                total -= 2;
            total+= 10;
                      break;
                 case 'V':
                 	
        
            if (i > 0 &&num[i - 1] == 'I')
                total -= 2;
             total += 5;
                      break;
                 case 'v':
                      if (i > 0 &&num[i - 1] == 'i')
                total -= 2;
             total += 5;
                      break;
                 case 'I':
                      total = 1;
                      break;
                 case 'i':
                      total = 1;
                      break;
                 default:
                      cout << "Error.." << endl;
		}
	decimal=decimal+total;
	}
	cout<<"\n\n The Roman number in Decimal is   "<<decimal;
}
int main()
{
cout<<"\n**************************************************************************:";
cout<<"\nProgrammer :  Sohail Zia Gill:";
cout<<"\nTitle: Convert the roman numbers into integers:";
cout<<"\nCompiler : Visual Studio 2012:";
cout<<"\nDated : 30/sep/2019:";
cout<<"\nCompiling date : 30/sep/2019:";
cout<<" \nInternational Islamic University Islamabad:";
cout<<"\n***************************************************************************:\n\n\n";
	int op;
	romantype r1;
	do{
	
	r1.setter();
	r1.romantodecimal();
	cout<<"\n Want to run again Enter 1 other wise 0  ";
	cin>>op;

	}while(op==1);
	cout<<endl;
	system("pause");
	return 0;
}
