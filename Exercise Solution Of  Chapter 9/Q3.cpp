#include<iostream>
using namespace std;
class publication
{
    private:
    	float price;
    	string title;
    public:
    virtual	void getdata()
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
class sales
{
	private:
		float sale1,sale2,sale3;
	public:
	virtual	void getdata()
		{
			cout<<"\n Enter the 1st month sale  ";
			cin>>sale1;
			cout<<"\n Enter the 2nd month sale  ";
			cin>>sale2;
			cout<<"\n Enter the 3rd month sale  ";
			cin>>sale3;
		}
	virtual	void putdata()
		{
			cout<<"\n The 1st month sale is  "<<sale1;
			cout<<"\n The 2nd month sale is  "<<sale2;
			cout<<"\n The 3rd month sale is  "<<sale2;
			
		}
    	
};
class book :public publication,public sales
{
    private:
    	int countPage;
    	public:
    		void getdata()
    		{
    			sales::getdata();
    			publication::getdata();
    			cout<<"\n Enter the pages of book  ";
    			cin>>countPage;
			}
			void putdata()
			{
				sales::putdata();
				publication::putdata();
		        cout<<"\n Thee counted book pages are  "<<countPage;
		}
};
class tape:public publication,public sales
{
    private:
	float time;
	public:
	void getdata()
	{
		publication::getdata();
		sales::getdata();
	cout<<"\n Enter the time of played tape   ";
	cin>>time;	
	}	
	void putdata()
	{
		sales::putdata();
		publication::putdata();
		cout<<"\n The time of tape played is "<<time;
	}
};
int main()
{
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
