#include <iostream>
using namespace std;

void insertionSort(int list[], int nn)
{
int  location,xv;
for (int i = 1; i < nn ; i++)
if (list[i] < list[i - 1])
{
xv= list[i];
location = i;
do
{
list[location] = list[location - 1];
location--;
}
while (location > 0 && list[location - 1] > xv);
list[location] = xv;
}
}


int main()
{
	
int list[10] ; //Line 1
int i; //Line 2
cout<<"Enter 10 values     ";
for (i = 0; i < 10; i++) //Line 5
cin >> list[i];
cout << endl; //Line 7
insertionSort(list, 10); //Line 3
cout << "After sorting, the list elements are:"
<< endl; //Line 4
for (i = 0; i < 10; i++) //Line 5
cout << list[i] << " "; //Line 6
cout << endl; //Line 7
return 0; //Line 8
}


