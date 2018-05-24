/*
Walter Hicks
CSIT 575
Fun With Loops
Sec 15150
*/

//include chunk
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void loop1();
void loop2();
void loop3(int base1);
void loop4(int base2);
int loop1ctr = 1;

int main() {
	int baseLoop3 = 0;
	int baseLoop4 = 0;
	
	cout << "loop 1" << endl;
	loop1();
	cout << "\n\n\n\n\n\nloop 2\n";
	loop2();
	cout << "\n\n\n\n\n\nloop 3\n";
	cout << "Please enter a number of x's to see in the base of your perimyd." << endl;
	cin >> baseLoop3;
	loop3(baseLoop3);
	cout << "\n\n\n\n\n\nloop 4\n";
	cout << "Please enter a number of of x's to see in the base of your perimyd with mirror." << endl;
	cin >> baseLoop4;
	loop4(baseLoop4);
	system("pause");
	return 0;
}

void loop1() {
	for (int ctr=1; ctr <= 3; ctr++) {
		for (int ctr2=1; ctr2 <= 4; ctr2++) {
			cout << loop1ctr << "\t";
			loop1ctr++;
		}
		cout << endl;
	}
}

void loop2() {
	for (int ctr = 1; ctr <= 5; ctr++) {
		for (int ctr2 = 1; ctr2 <= ctr; ctr2++) {
			cout << ctr << " ";
		}
		cout << endl;
	}
}

void loop3(int base1) {

	for (int ctr = 0; ctr <= base1; ctr++) {
		for (int spaces = 0; spaces < base1 - ctr; spaces++) {
			cout << " ";
		}
		for (int ctr2 = 0; ctr2 <= ctr * 2; ctr2++) {
			cout << 'X';
		}
		cout << endl;
	}

}
void loop4(int base2) {
	int ctr1;
	for (ctr1 = 0; ctr1 <= base2; ctr1++) {
		for (int spaces = 0; spaces < base2 - ctr1; spaces++) {
			cout << " ";
		}
		for (int ctr2 = 0; ctr2 <= ctr1 * 2; ctr2++) {
			cout << 'X';
		}
		cout << endl;
	}
	for (int ctr2 = ctr1 - 2; ctr2 >= 0; ctr2--) {
		for (int spaces = 0; spaces < base2 - ctr2; spaces++) {
			cout << " ";
		}
		for (int ctr3 = 0; ctr3 <= ctr2 * 2; ctr3++) {
			cout << 'X';
		}
		cout << endl;
	}
}


/*
int loop3(int base1) {
	for (int ctr=0; ctr <= base1; ctr++) {
		for (int spaces=0; spaces < base1 - ctr; spaces++) {
			cout << " ";
		}
		for (int ctr2=0; ctr2 <= ctr*2; ctr2++) {
			cout << 'X';
		}
		cout << endl;
	}
	return 0;
}

int loop4(int base2) {
	int ctr1;
	for (ctr1 = 0; ctr1 <= base2; ctr1++) {
		for (int spaces = 0; spaces < base2 - ctr1; spaces++) {
			cout << " ";
		}
		for (int ctr2 = 0; ctr2 <= ctr1 * 2; ctr2++) {
			cout << 'X';
		}
		cout << endl;
	}
	for (int ctr2 = ctr1-2; ctr2 >=0; ctr2--) {
		for (int spaces = 0; spaces < base2 - ctr2; spaces++) {
			cout << " ";
		}
		for (int ctr3 = 0; ctr3 <= ctr2 * 2; ctr3++) {
			cout << 'X';
		}
		cout << endl;
	}

	return 0;
*/



/*
loop 1
1       2       3       4
5       6       7       8
9       10      11      12






loop 2
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5






loop 3
Please enter a number of lines to see in your perimyd.
10
          X
         XXX
        XXXXX
       XXXXXXX
      XXXXXXXXX
     XXXXXXXXXXX
    XXXXXXXXXXXXX
   XXXXXXXXXXXXXXX
  XXXXXXXXXXXXXXXXX
 XXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXX






loop 4
Please enter a number of lines to see in your perimyd with mirror.
10
          X
         XXX
        XXXXX
       XXXXXXX
      XXXXXXXXX
     XXXXXXXXXXX
    XXXXXXXXXXXXX
   XXXXXXXXXXXXXXX
  XXXXXXXXXXXXXXXXX
 XXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXX
 XXXXXXXXXXXXXXXXXXX
  XXXXXXXXXXXXXXXXX
   XXXXXXXXXXXXXXX
    XXXXXXXXXXXXX
     XXXXXXXXXXX
      XXXXXXXXX
       XXXXXXX
        XXXXX
         XXX
          X
Press any key to continue . . .
*/