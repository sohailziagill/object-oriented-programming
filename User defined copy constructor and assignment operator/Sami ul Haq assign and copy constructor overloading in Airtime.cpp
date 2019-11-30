//header file
#include<iostream>
#include<iomanip>

//including c++ standered library 
using namespace std;

//user define data type (object)
class airTime		//define a class
{
	//class private data
	unsigned int hrs;
	unsigned int min;
	unsigned int sec;

	//using static data member
	static int no_of_obj;

public:
	//constract member function
	airTime() : hrs(0), min(0), sec(0)
	{
		++no_of_obj;
	}

	airTime(int hr, int mn, int sc) :hrs(hr), min(mn), sec(sc)
	{/*Empty*/}

	//class member function
	//void init();
	void setter();
	void getter();
	void increment();
	void decrement();
	//checking increment capability
	void checkIncrementHrs();
	void checkIncrementMin();
	void checkIncrementSec();
	//checking decrement capability
	void checkDecrementHrs();
	void checkDecrementMin();
	void checkDecrementSec();
	//end of checking

	//converting all data to sec
	long time_in_sec();

	//arithmatic operator overloaded
	airTime operator+(const airTime&);
	airTime operator-(const airTime&);
	airTime operator*(const airTime&);
	airTime operator/(const airTime&);
	
	//comparison operator overloaded
	bool operator<(const airTime&);
	bool operator>(const airTime&);
	bool operator==(const airTime&);

	//incrementing using overloaded operator
	airTime operator++();
	//Decrementing using overloaded operator
	airTime operator--();

	//	ASSIGNMENT OPERATOR OVERLOADING
	airTime operator=(const airTime&);
	
	//copy constructor
	airTime(const airTime&);

	~airTime()
	{
		--no_of_obj;
	}
};//end of object

int airTime::no_of_obj = 0;

// class member function recieving data
void airTime::getter()
{
		do
	{
		cout << "Enter the number of hourse: ";
		cin >> hrs;
	} while (hrs > 23);

	do
	{
		cout << "Enter the the number of minutes: ";
		cin >> min;
	} while (min > 59);

	do
	{
		cout << "Enter the the number of seconds: ";
		cin >> sec;
	} while (sec > 59);
}//end of receiveing data function

//class member function output data
void airTime::setter()
{
	cout << endl << "Time is: ";
	if (hrs == 24)
		hrs = 0;

	cout << endl << setw(2) << setfill('0') << hrs << ": "			// manipulate digits as two 
		<< setw(2) << setfill('0') << min << ": "
		<< setw(2) << setfill('0') << sec << endl;

}//endl output function

//class member function of incrementing function
void airTime::increment()
{
	char ch;

	do
	{
		cout << "Enter H to increment the number of hourse by one\n"
			<< "Enter M to increment the number of Minutes by one\n"
			<< "Enter S to increment the number of Seconds by one\n"
			<< "Enter E to exit\n"
			<< "Enter: ";
		cin >> ch;

		switch (ch)
		{
		case 'h':
		case 'H':
			checkIncrementHrs();
			break;

		case 'm':
		case 'M':
			checkIncrementMin();
			break;

		case 's':
		case 'S':
			checkIncrementSec();
			break;

		default:
			if (ch != 'e' && ch != 'E')
				cout << "wrong input! " << endl;
		}
	} while (ch != 'e' && ch != 'E');

	cout << "\n*Incrementing function is terminated!*" << endl;
}//end of incrementing function

//class member decrement data
void airTime::decrement()
{
	char ch;

	do
	{
		cout << "Enter H to decrement the number of hourse by one\n"
			<< "Enter M to decrement the number of Minutes by one\n"
			<< "Enter S to decrement the number of Seconds by one\n"
			<< "Enter E to exit "
			<< "Enter: ";
		cin >> ch;

		switch (ch)
		{
		case 'h':
		case 'H':
			checkDecrementHrs();
			break;

		case 'm':
		case 'M':
			checkDecrementMin();
			break;

		case 's':
		case 'S':
			checkDecrementSec();
			break;

		default:
			if (ch != 'e' && ch != 'E')
				cout << "wrong input! ";
		}
	} while (ch != 'e' && ch != 'E');

	cout << "\n*Decrementing function is terminated!*" << endl;
}//end of decrementing fucnction

//class member check hourse capability of hourse
void airTime::checkIncrementHrs()
{
	if (hrs == 23)
	{
		cout << "Cannot increment!" << endl;
	}
	else
	{
		++hrs;
		cout << "Incremented successfully! " << endl;
	}

}//end of function

//class member check hourse capability of minuts
void airTime::checkIncrementMin()
{
	if (min == 59)
	{
		int temp;
		temp = hrs;

		checkIncrementHrs();
		if (temp != hrs)
			min = 0;
	}

	else
	{
		++min;
		cout << "Incremented successfully! " << endl;
	}
} //end of function

//class member check hourse capability of minuts
void airTime::checkIncrementSec()
{
	if (sec == 59)
	{
		int temp;
		temp = min;

		checkIncrementMin();
		if (temp != min)
			sec = 0;
	}

	else
	{
		++sec;
		cout << "Incremented successfully! " << endl;
	}
}//end of function

//class member checks the capability of decrementing
void airTime::checkDecrementHrs()
{
	if (hrs == 0)
		cout << "Cannot decrement!" << endl;

	else
	{
		--hrs;
		cout << "\n Decremented successfully!" << endl;
	}
}//end of function

//class member checks the capability of decrementing
void airTime::checkDecrementMin()
{
	if (min == 0)
	{
		int temp;
		temp = hrs;

		checkDecrementHrs();
		if (temp != hrs)
			min = 59;
	}
	else
	{
		--min;
		cout << "\n Decremented successfully!" << endl;
	}
}//end of function

//class member checks the capability of decrementing
void airTime::checkDecrementSec()
{
	if (sec == 0)
	{
		int temp;
		temp = min;

		checkDecrementMin();
		if (temp != min)
			min = 59;
		
		sec = 59;
	}
	else
	{
		--min;
		cout << "\n Decremented successfully!" << endl;
	}
}//end of function

//converting time into sec
long airTime::time_in_sec()
{
	cout << "\nNumber of Object: " << no_of_obj << endl;
	return(hrs * 3600 + min * 60 + sec);

}

//Arithmatic opetator overloded
//+
airTime airTime::operator+(const airTime& tt)
{
	airTime temp;
	temp.hrs=hrs+tt.hrs;
	temp.min=min+tt.min;
	temp.sec=sec+tt.sec;
	return temp;
}

//-
airTime airTime::operator-(const airTime& tt)
{
	airTime temp;
	temp.hrs = hrs - tt.hrs;
	temp.min = min - tt.min;
	temp.sec = sec - tt.sec;
	return temp;
}

//*
airTime airTime::operator*(const airTime& tt)
{
	airTime temp;
	temp.hrs = hrs * tt.hrs;
	temp.min = min * tt.min;
	temp.sec = sec * tt.sec;
	return temp;
}

// /
airTime airTime::operator/(const airTime& tt)
{
	airTime temp;
	temp.hrs = hrs / tt.hrs;
	temp.min = min / tt.min;
	temp.sec = sec / tt.sec;
	return temp;
}

//comparison operator overloaded
//  ==
bool airTime::operator==(const airTime& tt)
{

	if (hrs == tt.hrs)
		if (min == tt.min)
			if (sec == tt.sec)
				return true;
			else
				return false;
		else
			return false;
	else return false;
	
}

//<
bool airTime::operator<(const airTime& tt)
{
	if (hrs < tt.hrs)
		return true;
	else if (hrs == tt.hrs)
		if (min < tt.min)
			return true;
		else if (min == tt.min)
			if (sec < tt.sec)
				return true;
			else
				return false;
		else
			return false;
	else return false;
		
}
//>
bool airTime::operator>(const airTime& tt)
{
	if (hrs > tt.hrs)
		return true;
	else if (hrs == tt.hrs)
		if (min > tt.min)
			return true;
		else if (min == tt.min)
			if (sec > tt.sec)
				return true;
			else
				return false;
		else
			return false;
	else return false;

}

//incrementing using overloaded operator
airTime airTime::operator++()
{
	++hrs;
	++min;
	++sec;
	return *this;
}

//Decrementing using overloaded operator
airTime airTime::operator--()
{
	--hrs;
	--min;
	--sec;
	return *this;
}

airTime airTime::operator=(const airTime& tt)
{
	cout << "\n============== Asign Ope ===========\n";
	hrs = tt.hrs + 2;
	min = tt.min + 2;
	sec = tt.sec + 2;
	return *this;
}

airTime::airTime(const airTime& tt)
{
	cout << "\n============= Copy Cons ==============\n";
	hrs = tt.hrs +2;
	min = tt.min +2;
	sec = tt.sec +2;

}

// main function
int main()
{
	airTime T1(1, 2, 3), T2(4, 5, 6), T3;
	//T1.setter();
	//T2.setter();
	//T3.setter();

	T1=T2 = T3;

	T1.setter();
	T2.setter();
	T3.setter();

	/*// output
	cout << setw(80) << setfill('*')
		<< "Welcome to time management program"
		<< setw(40) << setfill('*') << '*' << endl
		<< "by: Samiulhaq chardiwall" << endl
		<< "a program wich control time"<<endl
		<< "date: oct.9.2019" << endl << endl;

	cout << endl << endl;

	airTime time1;		//define objects of class airTime
	airTime time2;
	airTime time3;

	int option;

	//calling member functions
	//time.init();
	cout << "Enter Time 1"<<endl;
	time1.getter();
	cout << "Enter Time 2" << endl;
	time2.getter();



	do
	{
		system("pause");
		system("cls");
		cout << "Enter 1 to increment data" << endl
			<< "Enter 2 to decrement data" << endl
			<< "Enter 3 to display data" << endl
			<< "Enter 4 to add time 1 and time 2" << endl
			<< "Enter 5 to subtruct time 1 from time 2" << endl
			<< "Enter 6 to multiply time to a number" << endl
			<< "Enter 7 to divide time by a number" << endl
			<< "Enter 8 to compare time 1 with time 2" << endl
			<< "Enter 9 to Encrement using overloading operator" << endl
			<< "Enter 10 to decrement using overloading operator" << endl
			<< "Enter 11 to convert time into seconds" << endl
			<< "Enter 12 to execute assignment overload function" << endl
			<< "Enter 0 to exit program" << endl
			<< "Enter: ";

		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Increment time 1" << endl;
			time1.increment();
			cout << "Increment time 1" << endl;
			time2.increment();
			break;

		case 2:
			cout << "Decrement time 1" << endl;
			time1.decrement();
			cout << "Decrement time 2" << endl;
			time2.decrement();
			break;
		case 3:
			cout << "\nTime 1 setter";
			time1.setter();
			cout << "\nTime 1 setter";
			time2.setter();
			break;
		case 4:
			time3=time1 + time2;
			time3.setter();
			break;
		case 5:
			time3 = time1 - time2;
			time3.setter();
			break;
		case 6:
			time3 = time1 * time2;
			time3.setter();
			break;
		case 7:
			time3 = time1 / time2;
			time3.setter();
			break;
		case 8:
			if (time1 < time2)
				cout << "time 1 is less then time 2 !" << endl;
			else if (time1 > time2)
				cout << "Time 1 is greater then time 2 !" << endl;
			else if (time1 == time2)
				cout << "Time 1 and Time are equal !" << endl;
			else
				cout << "wrong input!";
			system("pause");
			break;
		case 9:
			++time1;
			++time2;
			time1.setter();
			time2.setter();
			break;
		case 10:
			--time1;
			--time2;
			time1.setter();
			time2.setter();
			break;
		case 11:
			cout << "Total time in seconds are of time 1: "
				<< time1.time_in_sec()
				<< "\nTotal time in seconds are of time 2: "
				<< time2.time_in_sec() << endl;
			break;
		case 12:
			time1 = time3 = time2;
			cout << "\nTime 1: ";		 time1.setter();
			cout << "\nTime 2: ";		 time2.setter();
			cout << "\nTime 3: ";		 time3.setter();
			break;

		default:
			if (option != 0)
				cout << "Wrong input!: " << endl;

		}
	} while (option != 0);
	*/
	cout << "***Program is terminated!***" << endl;
	system("pause");
}//end of main function
