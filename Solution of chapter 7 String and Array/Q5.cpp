#include<iostream>
#include<conio.h>
using namespace std;

class fraction{
 char c;
 int numerator, denominator;
public:
 void fadd(fraction a, fraction b);
 void fdiv(fraction a, fraction b);
 void getfrac(){ cout<<"Enter fraction: "; cin>>numerator>>c>>denominator;}
 void disp() const { cout<<"Maximum = "<<numerator<<"/"<<denominator;}
 float getFl(){ if(denominator) return numerator/denominator; else return 0;}};

void fraction::fadd(fraction a, fraction b){
 numerator  =a.numerator*b.denominator+a.denominator*b.numerator;
 denominator=a.denominator*b.denominator;}

void fraction::fdiv(fraction a, fraction b){
 if(b.numerator != 0){
 numerator  =a.numerator*b.denominator;
 denominator=b.numerator*a.denominator;}
 else         cout<<"Math error !"<<endl;}
 
int maxfrc(fraction arr[], int bound){ 
 int max=0; 
 for(int j=1; j<bound; j++) max= arr[max].getFl()>arr[j].getFl()? max:j;
 return max;}

int main()
{
 cout<<"### Programmed By Amahdy(MrJava) ,right restricted.~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 cout<<"-------------------------------------------------------------------------------\n"<<endl;
 
 do{
  fraction a[100]; int i=1;
 cout<<"([0] to quit):\n"; a[0].getfrac();
 while(a[i-1].getFl() || i==100) a[i++].getfrac();
 a[maxfrc(a, i)].disp();
 cout<<"\n\n !Press c to continue or any key to exit."<<endl<<endl;
 }while(getch()=='c');
}
