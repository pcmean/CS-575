/*
Walter Hicks
CSIT 575
Lab #5
Sec 15150
*/

//include chunk
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(){	
	ifstream infile;
	ofstream outfile;
	int total=0;
	int max=0;
	int min=0;
	int num=0;
	int average;
	infile.open("Input.txt");
	while(!infile){			//there was an error on open, file not found
		cout << "Cannot open file, terminating program" << endl;
		system("pause");
		exit(1);
	}
	outfile.open("Output.txt");
							//this is called a priming read, only used once
	
	while (!infile.eof()){	
		
		for (int crt = 1; crt <= 7; crt++) {
			infile >> num;
			if (crt == 1) {
				min = num;
				max = num;
			}
			if (num<min) {
				min = num;
			}
			if (num>max) {
				max = num;
			}
			outfile << num<<"   ";
			total += num;
		}
		average = total / 7;
		outfile << endl << "Minimum: " << min << endl << "Maximum: " << max << endl << "Total: " << total << endl << "Average" << average << "\n\n\n\n";
	}
	infile.close();
	outfile.close();
	system("pause");
	return 0;
}
/*
346   130   982   90   656   117   595
Minimum: 90
Maximum: 982
Total: 2916
Average416



415   948   126   4   558   571   87
Minimum: 4
Maximum: 948
Total: 5625
Average803



42   360   412   721   463   47   119
Minimum: 42
Maximum: 721
Total: 7789
Average1112



441   190   985   214   509   2   571
Minimum: 2
Maximum: 985
Total: 10701
Average1528



77   81   681   651   995   93   74
Minimum: 74
Maximum: 995
Total: 13353
Average1907



310   9   995   561   92   14   288
Minimum: 9
Maximum: 995
Total: 15622
Average2231



466   664   892   8   766   34   639
Minimum: 8
Maximum: 892
Total: 19091
Average2727



151   64   98   813   67   834   369
Minimum: 64
Maximum: 834
Total: 21487
Average3069



369   369   369   369   369   369   369
Minimum: 369
Maximum: 369
Total: 24070
Average3438
*/