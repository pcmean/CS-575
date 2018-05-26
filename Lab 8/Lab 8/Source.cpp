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
#include <conio.h>
#include <stdio.h>

using namespace std;

struct home{
	string ID;
	float income;
	int occupants;
};
ifstream infile;
ofstream outf1, outf2, outf3, outf4, outf5, errors;
int menu();
void openFiles();
void Formating();
void printinputdata(home homesarray[], int size);
void Average(home homesarray[], int sixe);
void poverty(home homesarray[], int size);
void sorted(home homesarray[], int size);
void clrscr();
void closeFiles();

int main() {
	home homes[16];
	int order[16];
	int inctr = 0;
	bool exitprogram = false;

	openFiles();

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
	Formating();
	while (!exitprogram) {
		switch (menu()) {
		case 1:
			printinputdata(homes, inctr);
			system("pause");
			break;
		case 2:
			Average(homes, inctr);
			system("pause");
			break;
		case 3:
			poverty(homes, inctr);
			system("pause");
			break;
		case 4:
			sorted(homes, inctr);
			system("pause");
			break;
		case 5:
			system("pause");
			break;
		case 6:
			cout << "End of Program.\n";
			exitprogram = true;
			system("pause");
			break;
		default:
			cout << "Not a Valid Choice. \n" << "Choose again.\n" << endl;
			system("pause");
			break;
		}
		clrscr();
	}
	return 0;
}
void openFiles() {
	infile.open("Infile.txt");
	outf1.open("Outf1.txt");
	outf2.open("Outf2.txt");
	outf3.open("Outf3.txt");
	outf4.open("Outf4.txt");
	outf5.open("Outf5.txt");
	errors.open("Errors.txt");
}
void Formating() {
	cout << fixed << showpoint << setprecision(2);
	outf1 << fixed << showpoint << setprecision(2);
	outf2 << fixed << showpoint << setprecision(2);
	outf3 << fixed << showpoint << setprecision(2);
	outf4 << fixed << showpoint << setprecision(2);
	outf5 << fixed << showpoint << setprecision(2);
}
int menu() {
	int option;
	cout << "\n\n\n\n\n\n" << endl;
	cout << "Please enter the number of the item you want to run\n" << endl;
	cout << "1\tPrint all of the input data with appropriate column headings." << endl;
	cout << "2\tCalculate the average household income and list the identification codes and income of each household whose income is greater than the average." << endl;
	cout << "3\tDetermine the percentage of households having an income below the poverty level.The formula for determining the poverty level is P = $8000.00 + $500.00 * (M - 2) where M is the number of members of the household." << endl;
	cout << "4\tPrint all of the input data sorted by household income." << endl;
	cout << "5\tCalculate and print the median household income.The median is the middle value of a sorted list.If the list contains an even number of entries, the median is the average of the two middle values." << endl;
	cout << "6\tExit Program.\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cin >> option;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	return option;
}
void printinputdata(home homesarray[], int size) {
	cout << "House ID\t    Income\tHousehold Members" << endl;
	outf1 << "House ID\t    Income\t\tHousehold Members" << endl;
	for (int ctr = 0; ctr < size; ctr++) {
		cout << homesarray[ctr].ID <<"\t\t" << setw(12) << homesarray[ctr].income << "\t" << homesarray[ctr].occupants << endl;
		outf1 << homesarray[ctr].ID << "\t\t" << setw(12) << homesarray[ctr].income << "\t" << homesarray[ctr].occupants << endl;
	}
}
void Average(home homesarray[], int size) {
	float total = 0.0;

	for (int ctr = 0; ctr < size; ctr++) {
		total = homesarray[ctr].income + total;
	}

	float avg = total / size;

	cout << "House ID\t		Income\tMemebers of Household" << endl;
	outf2 << "House ID\t		Income\t\tMemeber of Household" << endl;
	for (int ctr = 0; ctr < size; ctr++) {
		if (homesarray[ctr].income > avg) {
			cout << homesarray[ctr].ID << "\t\t" << setw(12) << homesarray[ctr].income << "\t" << homesarray[ctr].occupants << endl;
			outf2 << homesarray[ctr].ID << "\t\t" << setw(12) << homesarray[ctr].income << "\t" << homesarray[ctr].occupants << endl;
		}
	}

}
void poverty(home homesarray[], int size) {
	cout << "House ID\t    Income\tHousehold Members" << endl;
	outf3 << "House ID\t    Income\t\tHousehold Members" << endl;
	float p = 0.0;
	for (int ctr = 0; ctr < size; ctr++) {
		p = 8000.00 + 500.00 * (homesarray[ctr].occupants - 2);
		if (homesarray[ctr].income < p) {
			cout << homesarray[ctr].ID << "\t\t" << setw(12) << homesarray[ctr].income << "\t\t" << homesarray[ctr].occupants << endl;
			outf3 << homesarray[ctr].ID << "\t\t" << setw(12) << homesarray[ctr].income << "\t" << homesarray[ctr].occupants << endl;
		}
	}
}
void sorted(home homesarray[], int size) {
	
}


void clrscr() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}
void closeFiles() {
	infile.close();
	outf1.close();
	outf2.close();
	outf3.close();
	outf4.close();
	outf5.close();
	errors.close();
}