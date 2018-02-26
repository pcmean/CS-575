/*
Walter Hicks
CSIT 575
Lab #2c

*/
#include <iostream>;
#include <string>;
#include <iomanip>;
using namespace std;
void main() {
	string customer_name;
	float hours_labor;
	float parts_and_supplies;
	float tax;
	float cost_for_labor;
	float total;
	const float hrcost = 35.0;
	const float taxprecent = 0.09;


	cout << "What is the customer's name?";
	cin >> customer_name;


	cout << "how many hours of labor were there?";
	cin >> hours_labor;


	cout << "how much were the parts and supplies?";
	cin >> parts_and_supplies;


	cost_for_labor = hrcost * hours_labor;
	tax = parts_and_supplies * taxprecent;
	total = cost_for_labor + parts_and_supplies + tax;

	cout << fixed << showpoint << setprecision(2);
	cout << "Customer Name\t\t" << customer_name << endl;
	cout << "Hours of labor\t\t" << setw(8) << hours_labor << endl;
	cout << "Cost for labor\t\t" << setw(8) << cost_for_labor << endl;
	cout << "Parts and supplies\t" << setw(8) << parts_and_supplies << endl;
	cout << "Tax\t\t\t" << setw(8) << tax << endl;
	cout << "Total amount Due\t" << setw(8) << total << endl;

	system("pause");

}


/*
What is the customer's name?jones
how many hours of labor were there?4.5
how much were the parts and supplies?97
Customer Name           jones
Hours of labor              4.50
Cost for labor            157.50
Parts and supplies         97.00
Tax                         8.73
Total amount Due          263.23
*/

/*
What is the customer's name?Smith
how many hours of labor were there?2.25
how much were the parts and supplies?200
Customer Name           Smith
Hours of labor              2.25
Cost for labor             78.75
Parts and supplies        200.00
Tax                        18.00
Total amount Due          296.75
*/

/*
What is the customer's name?lee
how many hours of labor were there?3
how much were the parts and supplies?0
Customer Name           lee
Hours of labor              3.00
Cost for labor            105.00
Parts and supplies          0.00
Tax                         0.00
Total amount Due          105.00
*/