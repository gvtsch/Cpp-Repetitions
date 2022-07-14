/*	Christoph Kempkes - 547623

02 - Aufgabe 03 - Referenzen

Letzte Änderung: 24.03.2013 
Testiert am:  

ToDo: http://bit.ly/14lFqho 
"Rundungsfehler" */

/* Bibliotheken laden */
#include <iostream>

using namespace std;

void summe(double &sum, int laenge, double arr[]);

int main() {
	double sum = 0, test[1000];

	/* Zum einfachen testen der Summenfunktion sollen 1000 1 summiert werden */
	for (int i = 0; i < 1000; i++) {
		test[i] = 1;
	}

	/* Summenfunktion */
	summe(sum, 1000, test);

	/* Ausgabe der Summe */
	cout << "Summe: " << sum << endl;
	
	/* Testsumme richtig? Modultest */
	if (sum == 1000) {
		cout << "Summe wurde RICHTIG berechnet." << endl;
	} else {
		cout << "Summe wurde FALSCH berechnet." << endl;
	}

	getchar();
	return 0;
}

void summe(double &sum, int laenge, double arr[]) {
	sum = 0;
	for (int i = 0; i < laenge; i++) {
		sum += arr[i];
	}
}