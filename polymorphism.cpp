#include<iostream>
using namespace std;
class A
{
	public:
		virtual void display()
		{
			cout<<endl<<"-A-";
		}
};
class B :public A
{
	public:
		void display()
		{
			cout<<endl<<"-B-";
		}
};
class C :public A
{
	public:
		void display()
		{
			cout<<endl<<"-C-";
		}
};
int main()
{
	A aobj;
	B bobj;
	C cobj;
	cout<<endl<<sizeof(A)<<endl;
		cout<<endl<<sizeof(B)<<endl;
	cout<<endl<<sizeof(C)<<endl;
	aobj.display();
	A *aptr=NULL;
	aptr = &aobj;
	aptr->display();
    aptr = &bobj;
	aptr->display();
	aptr = &cobj;
	aptr->display();
	cout<<endl;
	system("pause");
	return 0;
}
