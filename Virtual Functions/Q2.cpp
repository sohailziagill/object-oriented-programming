#include<iostream>
using namespace std;
class Distance 
{
	private:
		float inches;
		float feet;
	public:
	    friend float square(Distance );
		void setter()
		{
			cout<<"\n Enter the distance in inches   ";
			cin>>inches;
			cout<<"\n Enter the distance in feets    ";
			cin>>feet;
		}
    	void getter()
    	{
		    cout<<"\n The distance in inches is     "<<inches;
 		    cout<<"\n The distance in feets is      "<<feet;
    	}
};
float square(Distance d)
{
	float d3;
	d3=d.inches*10;
	return d3;
}
int main()
{
	Distance d1;
	float d2;
	cout<<"\n///////////////////////////// The d1 setter/////////////////////////////";
	d1.setter();
	cout<<"\n///////////////////////////// The d1 getter/////////////////////////////";
    d1.getter();
	cout<<"\n////////////////////The d2 is the multiplicative of d1/////////////////\n\n";
	d2=square(d1);
	cout<<d2;
	cout<<endl<<endl;
	system("pause");
	return 0;
}
