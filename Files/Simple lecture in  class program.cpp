#include<iostream>
using namespace std;
int mian()
{
	int m=328,n=4000;
	float f1=23.56;
	char c1='g';
	ofstream outfile;
	outfile("D:\\ABC.txt","ios::out");
	if(!outfile)
	{
		cout<<"\n Error   ";
		exit(-1);
	}
	outfile<<m<<" "<<n<<" "<<f1<<" "<<c1;
	cout<<endl;
	system("pause");
	return 0;
}
