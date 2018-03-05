/*
Walter Hicks
CSIT 575
Lab #3c
Sec 15150
*/
#include <iostream>;
#include <string>;
#include <iomanip>;
using namespace std;


const float packageA_Base = 9.95;
const float packageA_hrs = 10;
const float packageA_extra = 2.0;

const float packageB_Base = 14.95;
const float packageB_hrs = 20;
const float packageB_extra = 1.0;

const float packageC_Base = 19.95;

string package = "";
float hrs_used = 0.0;
bool propper_package = false;
bool propper_hrs = false;
float temp_extra_hrs = 0.0;
float extra_price = 0.0;
float output_price = 0.0;
string package_used = "";
float baseprice = 0.0;



void packageA() {
	cout << "Package A" << endl;
	package_used = "Package A";
	temp_extra_hrs = 0.0;
	baseprice = packageA_Base;
	temp_extra_hrs = hrs_used - packageA_hrs;
	if (!temp_extra_hrs <= 0) {
		extra_price = temp_extra_hrs * packageA_extra;
		output_price = packageA_Base + extra_price;
	}
	else {
		output_price = packageA_Base;
	}
}


void packageB() {
	cout << "Package B" << endl;
	package_used = "Package B";
	temp_extra_hrs = 0.0;
	baseprice = packageB_Base;
	temp_extra_hrs = hrs_used - packageB_hrs;
	if (!temp_extra_hrs <= 0) {
		extra_price = temp_extra_hrs * packageA_extra;
		output_price = packageA_Base + extra_price;
	}
	else {
		output_price = packageA_Base;
	}
}


void packageC() {
	cout << "Package C" << endl;
	package_used = "Package C";
	baseprice = packageC_Base;
	extra_price = 0.0;
	output_price = packageC_Base;
}

int main() {
	while (!propper_package) {
		cout << "What package are you using \"A\" \"B\" or \"C\"" << endl;
		cin >> package;
		if (package == "a" || package == "A" || package == "b" || package == "B" || package == "c" || package == "C") {
			propper_package = true;
		}
		else {
			cout << "please enter a proppor package" << endl;
		}
	}
	while (!propper_hrs) {
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
		packageA();
	}
	else if (package == "b" || package == "B") {
		packageB();
	}
	else if (package == "c" || package == "C") {
		packageC();
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