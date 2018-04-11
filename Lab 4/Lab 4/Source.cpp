/*
Walter Hicks
CSIT 575
Lab #4
Sec 15150
*/

//include chunk
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


bool continue_loop = true;
bool propper_mg = false;
bool propper_hr = false;
bool good_return = false;
string continue_question = "";
string drink = "";
string tempdrink;
int hours_since_drink = 0;
int hr_time = 0;
int maxhr = 59;
float mg_caffeine = 0.0;


int main() {
	while (continue_loop) {
		cout << "What drink do you have?" << endl;
		cin.ignore();
		getline(cin, drink);
		while (!propper_mg) {	//checks to verify you entered the correct ammount of caffeine
			cout << "How many MG of caffeine does your drink have?" << endl;
			cin >> mg_caffeine;
			//system("pause");
			if (cin) {
				if (mg_caffeine <= 350) { propper_mg = true; }
				else { cout << "That is way to much!!!" << endl; }
			}
			else {
				cout << "Please enter a proper ammount of caffeine." << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}

		}

		while (!propper_hr) {//checks to verify you entered the correct ammount of hrs
			cout << "How many hrs do you want to see?" << endl;
			cin >> hr_time;
			if (cin) {
				if (hr_time <= maxhr) { propper_hr = true; }
				else { cout << "That is to much time." << endl; }
			}
			else {
				cout << "Please enter a proper ammount of time." << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}
		}

		//OUTPUT
		cout << fixed << showpoint << setprecision(2);
		cout << "\n\n\n\n\n\nDrink name: " << drink << "mg" << endl;
		cout << "0\t" << mg_caffeine << endl;


		for (int ctr = 1; ctr <= hr_time; ctr++) {
			mg_caffeine = mg_caffeine - mg_caffeine * 0.13;
			cout << ctr << "\t" << mg_caffeine << "mg" << endl;
		}



		//rerun?
		good_return = false;
		cout << "do you want to run this again \"yes\" or \"no\"" << endl;
		while (!good_return) {
			cin >> continue_question;
			if (cin && (continue_question == "no" || continue_question == "No" || continue_question == "yes" || continue_question == "Yes")) {
				if (continue_question == "yes" || continue_question == "yes") {
					cout << "OK here we go again \n\n\n\n\n\n\n\n\n\n" << endl;
					good_return = true;
					propper_hr = false;
					propper_mg = false;
					continue_loop = true;
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
	return(0);

}

/*
test data:
cout << "cin good:" << cin.good() << " bad:" << cin.bad() << " fail:" << cin.fail() << " eof:" << cin.eof() << endl;


What drink do you have?
16 oz Starbucks coffee
How many MG of cafeen dose your drink have?
310
How many hrs do you want to see?
10






Drink name: 6 oz Starbucks coffeemg
0       310.00
1       269.70mg
2       234.64mg
3       204.14mg
4       177.60mg
5       154.51mg
6       134.42mg
7       116.95mg
8       101.75mg
9       88.52mg
10      77.01mg
do you want to run this again "yes" or "no"
yes
OK here we go again










What drink do you have?
5-hr Energy drink
How many MG of cafeen dose your drink have?
245
How many hrs do you want to see?
7






Drink name: 5-hr Energy drinkmg
0       245.00
1       213.15mg
2       185.44mg
3       161.33mg
4       140.36mg
5       122.11mg
6       106.24mg
7       92.43mg
do you want to run this again "yes" or "no"
yes
OK here we go again










What drink do you have?
Black tea
How many MG of cafeen dose your drink have?
47
How many hrs do you want to see?
5






Drink name: Black teamg
0       47.00
1       40.89mg
2       35.57mg
3       30.95mg
4       26.93mg
5       23.43mg
do you want to run this again "yes" or "no"
yes
OK here we go again










What drink do you have?
Red Bull
How many MG of cafeen dose your drink have?
80
How many hrs do you want to see?
12






Drink name: Red Bullmg
0       80.00
1       69.60mg
2       60.55mg
3       52.68mg
4       45.83mg
5       39.87mg
6       34.69mg
7       30.18mg
8       26.26mg
9       22.84mg
10      19.87mg
11      17.29mg
12      15.04mg
do you want to run this again "yes" or "no"
*/