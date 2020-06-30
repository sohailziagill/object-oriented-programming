#include<iostream>
using namespace std;
#include<fstream>

class shamiburger {
private: 
	int bun, shami;
public: 
	void init();
	void sale();
	void stock();
};
void shamiburger::init() {
	do {
		cout << "ENTER NO OF BUNS: ";
		cin >> bun;
		cout << "ENTER NO OF SHAMIS: ";
		cin >> shami;
		if (bun != shami)
			cout << "\n                     ~~~~~~~~~~~~~~~~~~~~~~~~~ ERROR BUNS AND SHAMI MUST BE EQUAL ~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
		else if (bun < 0 || shami < 0) 
			cout << "\n                     ~~~~~~~~~~~~~~~~~~~~~~~~~ ERROR BUNS AND SHAMI MUST BE POSITIVE ~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
		else
			break;
		} while (1);
		
}
void shamiburger::sale() {
	if (bun != 0 && shami != 0) {
		--bun;
		--shami;
	}
}
void shamiburger::stock() {

	cout << "No. OF BUNS = " << bun << endl;
	cout << "No. OF SHAMI = " << shami << endl;
}



int main() {
	ofstream outf;
	ifstream inf;
	system("color 6F");
	shamiburger s1, s2, s3, s4;
	ofstream outfile;
	int choice;
	do {
		cout << "************************************ MENUE *********************************************" << endl;
		cout << "ENTER 1 TO INITIALIZE DATA OF ALL SHOPS"<<endl;
		cout << "ENTER 2 FOR SALE"<<endl;
		cout << "ENTER 3 TO SHOW DATA OF PARTICULAR SHOP"<<endl;
		cout << "ENTER 5 TO EXIT"<<endl;
		cout << "ENTER 4 TO STORE DATA IN FILE  "<<endl;
		cout << "************************************************************************************" << endl;
		cin >> choice;
		switch (choice) {
		case 1: 
			cout << "\n                             ~~~~~~~~~~~~~~~~~~~~~~ ENTER DATA FOR SHOP:1 ~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
			s1.init();
			cout << "\n                             ~~~~~~~~~~~~~~~~~~~~~~ ENTER DATA FOR SHOP:2 ~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
			s2.init();
			cout << "\n                             ~~~~~~~~~~~~~~~~~~~~~~ ENTER DATA FOR SHOP:3 ~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
			s3.init();
			cout << "\n                             ~~~~~~~~~~~~~~~~~~~~~~ ENTER DATA FOR SHOP:4 ~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
			s4.init();
			break;
		case 2:
			int shop;
			do {
				cout << "\n                        ~~~~~~~~~~~~~~~~~~~~~~ ENTER SHOP NO. WHICH DONE HIS SALE ~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
				cin >> shop;
			} while (shop < 1 || shop>4);
			if(shop == 1)
			s1.sale();
			else if (shop == 2)
				s2.sale();
			else if (shop == 3)
				s3.sale();
			else if (shop == 4)
				s4.sale();
			break;
		case 3:
			int display;
			do {
				cout << "\n                        ~~~~~~~~~~~~~~~~~~~~~~ ENTER SHOP NO. TO DISPLAY HIS DATA ~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
				cin >> display;
			} while (display < 1 || display>4);
			if (display == 1)
				s1.stock();
			else if (display == 2)
				s2.stock();
			else if (display == 3)
				s3.stock();
			else if (display == 4)
				s4.stock();
			break;
		case 4:
			cout<<"\n To save data in file   ";
			outfile.open("mydata.dat",ios::out | ios::binary);
			if(!outfile)
			cout<<"\nEror";
			else
			{
				outfile.write((char*)&s1,sizeof(shamiburger));
				outfile.write((char*)&s2,sizeof(shamiburger));
				outfile.write((char*)&s3,sizeof(shamiburger));
				outfile.write((char*)&s4,sizeof(shamiburger));
				outfile.close();
			}
                break;
        case 5:
        	choice =4;
        	
		}
   } while (choice != 4);
	return 0;
	system("pause");
}
