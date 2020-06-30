#include<iostream>
#include<conio.h>
using namespace std;
#include<cstdlib>
#include<ctime>

enum Suit{ clubs, diamonds, hearts, spades};
const int jack  = 11;
const int queen = 12;
const int king  = 13;
const int ace   = 14;

class card{
      int number;
      Suit suit;
   public:
      void set(int n, Suit s){ suit=s; number=n;}
      void display();};

void card::display()
{
 if(number>=2 && number<=10) cout<<number;
 else switch(number) {
   case jack:     cout<<"J";     break;
   case queen:    cout<<"Q";     break;
   case king:     cout<<"K";     break;
   case ace:      cout<<"A";}
 switch(suit) {
   case clubs:    cout<<char(5); break;
   case diamonds: cout<<char(4); break;
   case hearts:   cout<<char(3); break;
   case spades:   cout<<char(6);}
 cout<<"  ";
}

int main()
{
 cout<<"### Programmed By Amahdy(MrJava) ,right restricted.~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 cout<<"-------------------------------------------------------------------------------\n"<<endl;
 
 card deck[52]; int j, i;

 do{
  i=0;
 for(j=0; j<52; j++){
  int num=(j%13)+2; Suit su=Suit(j/13);
  deck[j].set(num, su);}
 srand(time(NULL));
 for(j=0; j<52; j++){
  int k=rand()%52; card temp=deck[j];
  deck[j]=deck[k]; deck[k]=temp;}
 cout<<"\nHand "<<++i<<": ";
 for(j=0; j<52; j++){ deck[j].display(); if(!((j+1)%13)&&i<4) cout<<"\nHand "<<++i<<": ";;}
 cout<<"\n\n !Press c to continue or any key to exit."<<endl<<endl;
 }while(getch()=='c');
}
