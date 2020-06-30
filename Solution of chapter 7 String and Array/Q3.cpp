#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
using namespace std;

class Distance{
      int feet; float inches;
   public:
   Distance(): feet(0), inches(0) {}
      void getdist(){
      cout<<"\nEnter feet: "; cin>>feet;
      cout<<"Enter inches: "; cin>>inches;}
   void add_dist(Distance d2, Distance d3);
   void div_dist(Distance d2, int divisor);
      void showdist() const { cout<<feet<<"\'-"<<inches<<'\"';}};

void Distance::add_dist(Distance d2, Distance d3)
{
   inches=d2.inches+d3.inches; feet=0;
   if(inches>=12.0){ inches -= 12.0; feet++;}
   feet += d2.feet+d3.feet;
}

void Distance::div_dist(Distance d2, int divisor)
{
   float fltfeet=d2.feet+d2.inches/12.0;
   fltfeet /= divisor; feet=int(fltfeet);
   inches=(fltfeet-feet)*12.0;
}

int main()
{
 cout<<"### Programmed By Amahdy(MrJava) ,right restricted.~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 cout<<"-------------------------------------------------------------------------------\n"<<endl;
 
 Distance dist[100], tmp; int i=0;
 
 do{
 while(true){
 dist[i].getdist(); tmp.add_dist(tmp, dist[i++]);
 if(i<100){
  cout<<"Enter more ? (y) to continue : ";
  if(toupper(getche())=='Y') continue;}
 break;}
 tmp.div_dist(tmp, i); cout<<"\nAverage is: "; tmp.showdist();
 cout<<"\n\n !Press c to continue or any key to exit."<<endl<<endl;
 }while(getch()=='c');
}

