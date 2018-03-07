/*
Walter Hicks
CSIT 575
Lab #3c
Sec 15150
*/

//include chunk
#include <iostream>;
#include <string>;
#include <iomanip>;
void packageA();
void packageB();
void packageC();
using namespace std;


//Package A constants
const float packageA_Base = 9.95;
const float packageA_hrs = 10;
const float packageA_extra = 2.0;


//Package B constants
const float packageB_Base = 14.95;
const float packageB_hrs = 20;
const float packageB_extra = 1.0;


//Package C constant 
const float packageC_Base = 19.95;


//random variables
string package = "";
float hrs_used = 0.0;
bool propper_package = false;
bool propper_hrs = false;
float temp_extra_hrs = 0.0;
float extra_price = 0.0;
float output_price = 0.0;
string package_used = "";
float baseprice = 0.0;


//Main
int main() {
	while (!propper_package) {//checks to verify you entered the correct package
		cout << "What package are you using \"A\" \"B\" or \"C\"" << endl;
		cin >> package;
		if (package == "a" || package == "A" || package == "b" || package == "B" || package == "c" || package == "C") {
			propper_package = true;
		}
		else {
			cout << "please enter a proppor package" << endl;
		}
	}

	while (!propper_hrs) {//checks to make sure you enterd a number <= 200
		cout << "how many hours have you used this billing cycle? (Please enter a int or float.)" << endl;
		cin >> hrs_used;

		if (hrs_used <= 200) {
			propper_hrs = true;
		}
		else {
			cout << "Your time is over 200 hrs!" << endl;
		}

	}

	if (package == "a" || package == "A") {
		packageA();//runs package A
	}
	else if (package == "b" || package == "B") {
		packageB();//runs package B
	}
	else if (package == "c" || package == "C") {
		packageC();//runs package C
	}

	//Output:  the bill.  Include the package purchased, the number of hours used, the base charge, the hourly charges and the total.

	cout << fixed << showpoint << setprecision(2);
	cout << "You chose:\t\t\t" << package_used << endl;
	cout << "You used:\t\t\t " << hrs_used << " hours." << endl;
	cout << "The base price is:\t\t" << setw(8) << baseprice << endl;
	cout << "The Hourly charges are:\t\t" << setw(8) << extra_price << endl;
	cout << "Total Price\t\t\t" << setw(8) << output_price << endl;
	system("pause");
	return(0);
}


//Package A math
void packageA() {
	cout << "Package A" << endl;
	package_used = "Package A";
	temp_extra_hrs = 0.0;
	baseprice = packageA_Base;
	temp_extra_hrs = hrs_used - packageA_hrs;
	if (!(temp_extra_hrs <= 0)) {
		extra_price = temp_extra_hrs * packageA_extra;
		output_price = packageA_Base + extra_price;
	}
	else {
		output_price = packageA_Base;
	}
}


//Package B math
void packageB() {
	cout << "Package B" << endl;
	package_used = "Package B";
	temp_extra_hrs = 0.0;
	baseprice = packageB_Base;
	temp_extra_hrs = hrs_used - packageB_hrs;
	if ((!temp_extra_hrs <= 0)) {
		extra_price = temp_extra_hrs * packageA_extra;
		output_price = packageA_Base + extra_price;
	}
	else {
		output_price = packageA_Base;
	}
}


//Package C math
void packageC() {
	cout << "Package C" << endl;
	package_used = "Package C";
	baseprice = packageC_Base;
	extra_price = 0.0;
	output_price = packageC_Base;
}


/*
What package are you using "A" "B" or "C"
a
how many hours have you used this billing cycle? (Please enter a int or float.)
8
Package A
You chose:                      Package A
You used:                        8.00 hours.
The base price is:                  9.95
The Hourly charges are:             0.00
Total Price                         9.95
Press any key to continue . . .



What package are you using "A" "B" or "C"
a
how many hours have you used this billing cycle? (Please enter a int or float.)
800
Your time is over 200 hrs!
how many hours have you used this billing cycle? (Please enter a int or float.)








*/