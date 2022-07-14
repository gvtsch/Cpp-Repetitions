/*	Christoph Kempkes - 547623

02 - Aufgabe 09 - Textstatistik

Letzte Änderung: 06.05.2013 
Testiert am:  */

#include "funcs.h"

using namespace std;

// --Main
int main ( int argc, char **argv) {	// Parameter aus der Konsole
	int m = 0;	
	int alphabet[26] = {0};
	set<string> woerterbuch;	// Liste mit den Wörtern

	// --Eingabeüberprüfung
	if ( argc != 2 ) {		
		cerr << "Falsche Eingabe" << endl << "Korrekte Eingabe: infile" << endl;
		getchar();
		return EXIT_FAILURE;
	}

	cout	<< "Aufgabe 09 - Textstatistik" << endl << endl << endl
			<< "Eingabedatei: " << argv[1] << endl;

	einlesen(woerterbuch, argv[1], alphabet);		// Einlesen
	
	cout << endl << "Hauefigkeit der Buchstaben: " << endl;
	for(int j = 97, i = 0; i < 26; j++, i++) {
		cout << (char)j << " - " << alphabet[i] << endl;
	}

	zaehlen(woerterbuch);							// Zaehlen
	cout << endl << endl << "Welche Woerter sollen ausgegeben werden? n = ";
	cin >> m;
	fflush(stdin);

	ausgeben(woerterbuch, m);	// Woerter mit m Buchstaben ausgeben

	getchar();
	return EXIT_SUCCESS;
}