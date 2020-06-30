#include<iostream>
using namespace std;
class publication
{
    private:
    	float price;
    	string title;
    public:
    	virtual void getdata()
    	{
    		cout<<"\n Enter the title of book  ";
    		cin>>title;
    		cout<<"\n Enter the price of book  ";
    		cin>>price;
		}
    	virtual void putdata()
    	{
    		cout<<"\n The title of book is   "<<title;
    		cout<<"\n The price of book is   "<<price;
		}
};
class book :public publication
{
    private:
    	int countPage;
    	public:
    		void getdata()
    		{
    			cout<<"\n Enter the pages of book  ";
    			cin>>countPage;
			}
			void putdata()
			{
		        cout<<"\n The counted book pages are  "<<countPage;
		}
};
class tape:public publication
{
    private:
	float time;
	public:
	void getdata()
	{
	cout<<"\n Enter the time of played tape   ";
	cin>>time;	
	}	
	void putdata()
	{
		cout<<"\n The time of tape played is "<<time;
	}
};
int main()
{
	publication p1;
	p1.getdata();
	p1.putdata();
	book b1;
	b1.getdata();
	b1.putdata();
	tape t1;
	t1.getdata();
	t1.getdata();
	cout<<endl;
	system("pause");
	return 0;
}
