#include <iostream>
using namespace std;
class publication
{
private:
 string title;
 float price;
public:
 virtual void getdata()
 {
  string t;
  float p;
  cout << "\nEnter title of publication: ";
  cin >> t;
  cout << "\nEnter price of publication: ";
  cin >> p;
  title = t;
  price = p;
 }
 virtual void putdata(void)
 {
  cout << "\nPublication title: " << title << endl;
  cout << "\nPublication price: " << price << endl;
 }
};
class sales
{
private:
 float s1, s2, s3;
public:
 void getdata(void)
 {
  cout << "\nEnter month 1 sale: $";
  cin >> s1;
  cout << "\nEnter month 2 sale: $";
  cin >> s2;
  cout << "\nEnter month 3 sale: $";
  cin >> s3;
 }
 void putdata(void)
 {
  cout << "\nMonth 1 sale: $" << s1 << endl;
  cout << "Month 2 sale: $" << s2 << endl;
  cout << "Month 3 sale: $" << s3 << endl;
 }
};
class book :public publication, public sales
{
private:
 int pagecount;
public:
 void getdata(void)
 {
  publication::getdata();
  sales::getdata();
  cout << "Enter Book Page Count: ";
  cin >> pagecount;
 }
 void putdata(void)
 {
  publication::putdata();
  sales::putdata();
  cout << "\nBook page count: " << pagecount << endl;
 }
};
class tape :public publication, public sales
{
private:
 float ptime;
public:
 void getdata(void)
 {
  publication::getdata();
  sales::getdata();
  cout << "\nEnter tap's playing time: ";
  cin >> ptime;
 }
 void putdata(void)
 {
  publication::putdata();
  sales::putdata();
  cout << "\nTap's playing time: " << ptime << endl;
 }
};
int  main()
{
	int size=100;
	int count=0;
	publication *p[size];
	int ch;
 do
 {
 	cout<<"\n Enter 1 for the book data      ";
 	cout<<"\n Enter 2 for the tape data      ";
 	cout<<"\n Enter 3 to dispaly all the data";
 	cout<<"\n Enter 4 to exit the program    ";
 	cin>>ch;
 	 switch(ch)
 {
 	case 1:
 		p[count]=new book;
 		cout<<"\n//////////////The book data entry/////////////////////////";
 		p[count++]->getdata();
 		break;
    case 2:
    	p[count]=new tape;
    	cout<<"\n ///////////////////////The tape data entry///////////////////////";
    	p[count++]->getdata();
    	break;
    case 3:
    	for(int i=0;i<count;i++)
    	{
    		p[i]->putdata();
		}
    	break;
    case 4:
    	exit(-1);
}
 }while(count!=size);

 cout<<endl;
 system("pause");
 return 0;
}
