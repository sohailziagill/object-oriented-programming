#include <iostream>
using namespace std;
class publication
{
private:
 string title;
 float price;
public:
 void getdata(void)
 {
  string t;
  float p;
  cout << "\n\nEnter title of publication: ";
  cin >> t;
  cout << "\nEnter price of publication: ";
  cin >> p;
  title = t;
  price = p;
 }
 void putdata(void)
 {
  cout << "\n\nPublication title: " << title << endl;
  cout << "\nPublication price: " << price << endl;
 }
};
class publication2:public publication
{
	int year;
	public:
		void getdata()
		{
			publication::getdata();
			cout<<"Enter the publication date    ";
			cin>>year;
		}
		void putdata()
		{
			publication::putdata();
			cout<<"\n The publication date is "<<year<<endl;
			
	    }
};
class sales
{
private:
 float s1, s2, s3;
public:
 void getdata(void)
 {
  cout << "Enter month 1 sale: $";
  cin >> s1;
  cout << "Enter month 2 sale: $";
  cin >> s2;
  cout << "Enter month 3 sale: $";
  cin >> s3;
 }
 void putdata(void)
 {
  cout << "Month 1 sale: $" << s1 << endl;
  cout << "Month 2 sale: $" << s2 << endl;
  cout << "Month 3 sale: $" << s3 << endl;
 }
};
class book :public publication2, public sales
{
private:
 int pagecount;
public:
 void getdata(void)
 {
  publication2::getdata();
  sales::getdata();
  cout << "Enter Book Page Count: ";
  cin >> pagecount;
 }
 void putdata(void)
 {
  publication2::putdata();
  sales::putdata();
  cout << "Book page count: " << pagecount << endl;
 }
};
class tape :public publication2, public sales
{
private:
 float ptime;
public:
 void getdata(void)
 {
  publication2::getdata();
  sales::getdata();
  cout << "Enter tap's playing time: ";
  cin >> ptime;
 }
 void putdata(void)
 {
  publication2::putdata();
  sales::putdata();
  cout << "Tap's playing time: " << ptime << endl;
 }
};
class disk :public publication2
{
private:
	int userchoice;
public:
 void getdata(void)
 {
  char a;
  publication2::getdata();
  cout << "Enter disk type (c or d) for CD and DVD: ";
  cin >> a;
  if (a == 'c')
   userchoice = 1;
  else
   userchoice = 2;

 }
 void putdata()
 {
  publication2::putdata();
  cout  << "Disk type is: ";
  if (userchoice == 1)
   cout << "CD";
  else if(userchoice == 2)
   cout << "DVD";
   else
   cout<<"\n Invalid output   ";
 }
};
int  main()
{
	cout<<"/n///////////////////////////Book Data/////////////////////////////////////////////\n\n\n";
 book b1;
 b1.getdata();
 b1.putdata();
	cout<<"/n///////////////////////////Tape Data/////////////////////////////////////////////\n\n\n";
 tape t1;
 t1.getdata();
 t1.putdata();	
	cout<<"/n///////////////////////////Disk Data////////////////////////////////////////////\n\n\n";
 disk d;
 d.getdata();
 d.putdata();
 cout<<endl;
 system("pause");
 return 0;
}
