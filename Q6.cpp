#include <iostream>
#include <conio.h>
using namespace std;
#include <process.h> //for exit()
const int LIMIT = 100; //array size
/////////////////////////////// It is a simple subscript overloaded function.////////////////////////
class safearay
{
private:
 int arr[LIMIT];
public:
 int& operator [](int n) //note: return by reference
 {
  if (n< 0 || n >= LIMIT)
  {                                              
   cout << "\nIndex out of bounds"; 
   exit(1);
  }
  return arr[n];
 }
};
/////////////////////////////We declare our own upper and lower limit of the array/////////////////
class safehilo :public safearay
{
private:
 int llimit, ulimit;
public:
 safehilo(int a, int b) :llimit(a), ulimit(b)// Maxima constructor 
 {
  if ((b - a) > LIMIT)//to check the user givven limit is exceed or not?
  {
   cout << "Array limits exceed maximum permissible range.";
    exit(1);
  }
 }
 int& operator [](int n)//n is the user givven limit.
 {
  if (n < llimit || n >= ulimit)//n must be exist b/w the lower and upper limit.
  {
   cout << "\nIndex out of bounds"; _getch(); exit(1);
  }
  safearay::operator[](n - llimit);//calling the subscript overloaded function.
 }
};
////////////////////////////////////////////////////////////////
int  main()
{
 safehilo sa1(100,175);//To set the lower and upper limit
 
            /////// //inserting  elements////////
 for (int j = 100; j<120; j++) 
  sa1[j] = j * 10; 
  
             ////////////display elements//////////////
 for (int j = 100; j<120; j++) 
 {
  int temp = sa1[j]; 
  cout << "Element " << j << " is " << temp << endl;
 }
 
 cout<<endl;
 system("pause");
 return 0;
}
