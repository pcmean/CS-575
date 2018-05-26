/*
Walter Hicks
CSIT 575
Lab #8
Sec 15150
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
struct home{
	string ID;
	float income;
	int occupants;
};
ifstream infile;
ofstream outf1, outf2, outf3, outf4, outf5, errors;
void printinputdata(home homesarray[], int size);

int main() {
	home homes[16];
	int order[16];
	int inctr = 0;
	int option;
	infile.open("Infile.txt");
	outf1.open("Outf1.txt");
	outf2.open("Outf2.txt");
	outf3.open("Outf3.txt");
	outf4.open("Outf4.txt");
	outf5.open("Outf5.txt");
	errors.open("Errors.txt");
	while (!infile) {			//there was an error on open, file not found
		cout << "Cannot open file, terminating program" << endl;
		system("pause");
		exit(1);
	}
	while (!infile.eof()) {
		infile >> homes[inctr].ID;
		infile >> homes[inctr].income;
		infile >> homes[inctr].occupants;
		inctr++;
	}
	bool exit = false;
	while (!exit) {
		cout << fixed << showpoint << setprecision(2);
		outf1 << fixed << showpoint << setprecision(2);
		cout << "\n\n\n\n\n\n" << endl;
		cout << "1\tPrint all of the input data with appropriate column headings." << endl;
		cout << "2\tCalculate the average household income and list the identification codes and income of each household whose income is greater than the average." << endl;
		cout << "3\tDetermine the percentage of households having an income below the poverty level.The formula for determining the poverty level is P = $8000.00 + $500.00 * (M - 2) where M is the number of members of the household." << endl;
		cout << "4\tPrint all of the input data sorted by household income." << endl;
		cout << "5\tCalculate and print the median household income.The median is the middle value of a sorted list.If the list contains an even number of entries, the median is the average of the two middle values." << endl;
		cout << "6\tExit Program.\n\n\n" << endl;
		cin >> option;

		switch (option) {
		case 1:
			printinputdata(homes, inctr);
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			cout << "End of Program.\n";
			break;
		case 6:
			cout << "End of Program.\n";
			exit = true;
			break;
		default:
			cout << "Not a Valid Choice. \n"
				<< "Choose again.\n";
			break;
		}
	}
		system("pause");
		return 0;
	}

void printinputdata(home homesarray[], int size) {
	cout << "House ID\t    Income\tHousehold Members" << endl;
	outf1 << "House ID\t    Income\t\tHousehold Members" << endl;
	for (int ctr = 0; ctr < size; ctr++) {
		cout << homesarray[ctr].ID <<"\t\t" << setw(12) << homesarray[ctr].income << "\t" << homesarray[ctr].occupants << endl;
		outf1 << homesarray[ctr].ID << "\t\t" << setw(12) << homesarray[ctr].income << "\t" << homesarray[ctr].occupants << endl;
	}
}

void poverty(home homesarray[], int size) {
	cout << "House ID\t    Income\tHousehold Members" << endl;
	outf1 << "House ID\t    Income\t\tHousehold Members" << endl;
	int p = 0, m = 0;
	for (int ctr = 0; ctr < size; ctr++) {
		p = 8000.00 + 500.00 * (homesarray[ctr].occupants - 2);
		if (homesarray[ctr].income < p) {
			cout << homesarray[ctr].ID << "\t\t" << setw(15) << homesarray[ctr].income << "\t\t" << homesarray[ctr].occupants << endl;
			outf2 << homesarray[ctr].ID << "\t\t" << setw(15) << homesarray[ctr].income << "\t" << homesarray[ctr].occupants << endl;
		}
	}

}