#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
string para="IamSohailZiaGill,Iam20yearsold:";
char ch;
int up=0,lo=0,pn=0,dg=0,al=0;
fstream file;
file.open("File.txt",ios::out);
if(!file)
cout<<"\n Error ";
else
{
	file<<para;
	//cout<<"\n Enter the sentence of type string:   ";
	//cin>>para;
	
}
file.close();
file.open("File.txt",ios::in);
	while(!file.eof())
	{
		ch=file.get();//To take the input from file character by character
		if (isupper(ch))
			up++;
		else if (islower(ch))
			lo++;
		else if (ispunct(ch))//To check punctuation marks.
			pn++;
		else if (isdigit(ch))//To check digits.
			dg++;
		if (isalpha(ch))//To check the alphabets of english.
			al++;
	}
	file.close();
	cout << "UPPER CASE : " << up << endl;
	cout << "LOWER CASE : " << lo << endl;
	cout << "Punctuation  : " << pn << endl;
	cout << "Digits : " << dg << endl;
	cout << "Alphabet : " << al << endl;
cout<<endl;
system("pause");
return 0;
}
