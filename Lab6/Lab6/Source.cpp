/*
**REVISED** CSIT 575 – Programming Fundamentals Lab #6C
Objectives
To learn to code, compile and run a program containing functions for a catering company.
Assignment—phase 1
The problem-- A catering company needs to calculate the charges for parties they are going to work on.
Function 1:  Create a function to input data from a user at the keyboard. See sample data below. Validate the data—meal type must be S or D, Weekend must be Y or N, deposit cannot be negative.  Output errors with appropriate messages to the screen.  Test this module.
Function 2:  Calculate cost of the meals for adults and children. For adults, the deluxe meals will cost $25.80 per person and the standard meals will cost $21.75 per person.  Children's meals will cost 60 percent of adult meals. Everyone within a given party must be served the same meal type.  Return the total cost of the meals.
Function 3:  Calculate additional costs. Calculate tip and tax. All customers will be charged the same rate for tip and tax, (currently 18 percent applied only to the cost of the food). Calculate surcharge, currently 7 percent, which is added to the total bill if the catering is to be done on the weekend (Friday, Saturday, or Sunday).  Return the tip/tax and the surcharge.
Function 4:  Calculate total bill and output data to the screen. Output: an itemized bill listing the party ID, number of adults, children, cost for meals, surcharge (if appropriate), tax and tip, total cost of the party, deposit (if any), total balance due.
Input
Party ID ,Number of adults, number of children, meal type (D, S) character indicating whether or not date is a weekend (Y/N), amount of any deposit. Create the data file below in text editor or Notepad.
Data File
1	10 	0	S	Y	100.00
2	27	3	D	Y	57.50
3	125	17	D	N	0.00
4	4	0	S	N	25.00
5	0		25	S	Y	23.75
6	250	43	D	N	500.00
7	0	0	D	N	0.0
8	10	0	R	Y	10.00
9	17	3	D	R	15.00
10	5	0	D	Y	275.00
11	-3	10	D	Y	20.00
12	14	-1	S	N	30.00
13	20	3	D	Y	-10.00

Output:  Screen output showing party ID, Number of adults, number of Children,Meal type, total meal cost,  tax/tip, surcharge, total party cost.  Errors show on screen with type of error specified.

Assignment Phase 2:  Change the input to be from a file.  Change the error output to be to a file, not on the screen.

To hand in:  The structure chart, the program listing, and the output.

*/

/*
Walter Hicks
CSIT 575
Fun With Loops
Sec 15150
*/

//include chunk
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void getGata(int & id, int & adults, int & kids, char & mealType, char & weekend, float & deposit);
float mealCost(int adults, int kids, char meal);
void extraCost(float mealcost, float & tax, float & tip, float & surcharge, char weekend);
void output(int id, int adults, int kids, char mealType, float totalDue, float deposit, float tip, float surcharge, float tax, float toatlMealCost);
const float taxpresent = 0.18;
const float tippresent = 0.18;
const float surchargePrecent = 0.07;

int main() {
	int id;
	int adults;
	int kids;
	char mealType;
	char weekend;
	float deposit = 0.0;
	float tip;
	float surcharge;
	float tax;
	float toatlMealCost;
	float totalDue;
	bool good_return = false;
	string continue_question;
	bool continue_loop = true;
	while (continue_loop) {

		cout << fixed << showpoint << setprecision(2);

		getGata(id, adults, kids, mealType, weekend, deposit);
		//cout << "id:\t" << id << "\tadults:\t" << adults << "\tkids:\t" << kids << "\tMeal Time:\t" << mealType << "\tWeekend:\t" << weekend << endl;
		toatlMealCost = mealCost(adults, kids, mealType);
		extraCost(toatlMealCost, tax, tip, surcharge, weekend);
		totalDue = (toatlMealCost + tax + tip + surcharge) - deposit;
		output(id, adults, kids, mealType, totalDue, deposit, tip, surcharge, tax, toatlMealCost);

		good_return = false;
		cout << "\n\n\n\ndo you want to run this again \"yes\" or \"no\"" << endl;
		while (!good_return) {
			cin >> continue_question;
			if (cin && (continue_question == "no" || continue_question == "No" || continue_question == "yes" || continue_question == "Yes")) {
				if (continue_question == "yes" || continue_question == "yes") {
					cout << "OK here we go again \n\n\n\n\n\n\n\n\n\n" << endl;
					good_return = true;
				}
				else if (continue_question == "no" || continue_question == "no") {
					continue_loop = false;
					good_return = true;
				}
			}
			else {
				cout << "Please enter \"yes\" or \"no\"" << endl;
				cin.clear();
				cin.ignore();
			}
		}
	}
	system("pause");
	return 0;
}
//Function 1:  Create a function to input data from a user at the keyboard.See sample data below.Validate the data—meal type must be S or D, Weekend must be Y or N, deposit cannot be negative.Output errors with appropriate messages to the screen.Test this module.

void getGata(int & id, int & adults, int & kids, char & mealType, char & weekend, float & deposit) {
	cout << "What is the party ID?" << endl;
	cin >> id;
	cout << "How many adults are in your party?" << endl;
	cin >> adults;
	cout << "How many kids are in your party?" << endl;
	cin >> kids;
	cout << "Enter the meal type either \"D\" or \"S\"" << endl;
	cin >> mealType;
	cout << "Is it a weekend" << endl;
	cin >> weekend;
	cout << "What is the ammount deposit" << endl;
	cin >> deposit;
}

//Function 2 : Calculate cost of the meals for adults and children. For adults, the deluxe meals will cost $25.80 per person and the standard meals will cost $21.75 per person.Children's meals will cost 60 percent of adult meals. Everyone within a given party must be served the same meal type.  Return the total cost of the meals.
float mealCost(int adults, int kids, char meal) {
	float totalMealCost = 0.0;
	float deluxMeal = 25.80;
	float standardMeal = 21.75;
	if (meal == 'S') {
		totalMealCost = (adults*standardMeal) + (kids*(standardMeal*0.6));
	}
	else if (meal == 'D') {
		totalMealCost = (adults*deluxMeal) + (kids*(deluxMeal*0.6));
	}
	return totalMealCost;
}

//Function 3 : Calculate additional costs. Calculate tip and tax. All customers will be charged the same rate for tip and tax, (currently 18 percent applied only to the cost of the food).Calculate surcharge, currently 7 percent, which is added to the total bill if the catering is to be done on the weekend(Friday, Saturday, or Sunday).Return the tip / tax and the surcharge.

void extraCost(float totalmealcost, float & tax, float & tip, float & surcharge, char weekend) {

	tax = taxpresent * totalmealcost;
	tip = tippresent * totalmealcost;

	if (weekend == 'Y') {
		surcharge = totalmealcost * surchargePrecent;
	}
	else if (weekend == 'N') {
		surcharge = 0.0;
	}


}


/*Function 4 : Calculate total bill and output data to the screen.Output : an itemized bill listing the
party ID,
number of adults,
children,
cost for meals,
surcharge(if appropriate),
tax and tip,
total cost of the party,
deposit(if any),
total balance due.
*/
void output(int id, int adults, int kids, char mealType, float totalDue, float deposit, float tip, float surcharge, float tax, float toatlMealCost) {
	cout << "id:\t\t\t\t" << id << endl;
	cout << "adults:\t\t\t\t" << adults << endl;
	cout << "kids:\t\t\t\t" << kids << endl;
	cout << "Meal Cost:\t\t\t" << setw(8) << toatlMealCost << endl;
	cout << "Tax and Tip:\t\t\t" << setw(8) << tax + tip << endl;
	cout << "Total Cost for the party:\t" << setw(8) << tax + tip + surcharge + toatlMealCost << endl;
	cout << "deposit(if any)\t\t\t" << setw(8) << deposit << endl;
	cout << "total balance due:\t\t" << setw(8) << totalDue << endl;
}