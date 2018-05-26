/*
Walter Hicks
CSIT 575
Lab #7B
Sec 15150
*/


//include chunk
#include <iostream>
#include <fstream>
#include <string>

int minmaxavg(int myarray[], int arraysize);
void overavg(int myarray[], int arraysize, int avg);
using namespace std;
ifstream infile;
ofstream outfile;


int main() {
	int tempnum;
	int evenctr = 0;
	int even[100];
	int evenAvreage = 0;
	int oddctr = 0;
	int odd[100];
	int oddAverage;


	infile.open("Input.txt");
	while (!infile) {
		cout << "Cannot open file, terminating program" << endl;
		system("pause");
		exit(1);
	}
	outfile.open("Output.txt");

	while (!infile.eof()) {
		infile >> tempnum;
		if (tempnum % 2 == 0) {
			even[evenctr] = tempnum;
			evenctr++;
		}
		else {
			odd[oddctr] = tempnum;
			oddctr++;
		}

	}

	outfile << "EVEN AREA" << endl;

	outfile << "Even Array:\t";
	for (int ctr = 0; ctr < evenctr; ctr++) {
		outfile << even[ctr] << "\t";
	}
	outfile << endl;

	evenAvreage = minmaxavg(even, evenctr);
	outfile << "Even over Avreage:\t";
	overavg(even, evenctr, evenAvreage);


	outfile << "ODD AREA" << endl;

	outfile << "Odd Array:\t";
	for (int ctr = 0; ctr < oddctr; ctr++) {
		outfile << odd[ctr] << "\t";
	}
	outfile << endl;

	oddAverage = minmaxavg(odd, oddctr);
	outfile << "Odd over Avreage:\t";
	overavg(odd, oddctr, oddAverage);



	infile.close();
	outfile.close();
	system("pause");


	return 0;
}


int minmaxavg(int myarray[], int arraysize) {
	int num;
	int min = 0;
	int max = 0;
	int total = 0;
	int average;
	for (int ctr = 0; ctr < arraysize; ctr++) {
		num = myarray[ctr];
		if (ctr == 1) {
			min = num;
			max = num;
		}
		if (num<min) {
			min = num;
		}
		if (num>max) {
			max = num;
		}
		total += num;
	}
	average = total / arraysize;
	outfile << endl << "Minimum: " << min << endl << "Maximum: " << max << endl << "Total: " << total << endl << "Average: " << average << "\n\n\n\n";
	return average;
}


void overavg(int myarray[], int arraysize, int avg) {
	int num;
	for (int ctr = 0; ctr < arraysize; ctr++) {
		num = myarray[ctr];
		if (num > avg) {
			outfile << num << "\t";
		}

	}
	outfile << "\n\n" << endl;
}


/*
EVEN AREA
Even Array:	46	30	82	90	56	16	48	26	4	58	0	78	92	60	12	90	14	52	16	80	102	34	10	92	88	66	64	92	66	64

Minimum: 0
Maximum: 102
Total: 1628
Average: 54



Even over Avreage:	82	90	56	58	78	92	60	90	80	102	92	88	66	64	92	66	64


ODD AREA
Odd Array:	17	95	21	63	47	19	41	85	-9	71	79	51	95	79	95	61	89	63	39	5

Minimum: -9
Maximum: 95
Total: 1106
Average: 55



Odd over Avreage:	95	63	85	71	79	95	79	95	61	89	63



*/