/*	Christoph Kempkes - 547623

02 - Aufgabe 07 - Bank

Letzte �nderung: 14.04.2013 
Testiert am:  15.04.2013 */

#include "bank.h"
#include <iostream>
#include <ctime>

using namespace std;

int main () {

	Bank test("Max Mustermann", 100, 2.00, 3.00);	// Konstruktor mit Namen, Startguthaben, Zinssatz f�r positives / negatives Guthaben

	cout << "Am Anfang: " << endl;	
	test.abfrage();		// Kontoinformationen ausgeben

	int a = 0, b = 0, Laufzeit = 5;		// a und b f�r Zufallszahlen, Laufzeit hier 5, um alles angezeigt zu bekommen
	srand(time(NULL));					// Von der Zeit abh�ngige "Zufallszahl" erstellen	

	for (int i = 0; i < Laufzeit; i++) {	// Solange Laufzeit
		a = (rand() % 25);					// Zufallszahl f�r Kontobewegungen
		cout << "Anzahl Kontobewegungen: " << a << endl;

		for (int j = 0; j < a; j++) {	// Solange Kontobewegungen
			b = (rand () % 500) - 250;	// Zufallszahl f�r Betrag (-250 bis 250)
			cout << "Betrag: " << b << endl;	

			if (b > 0) test.einzahlen(b);	// Guthaben um positiven Betrag erh�hen
			else test.abheben(b);			// Guthaben um negativen Betrag erh�hen
		} 
		cout << "Guthaben unverzinst: " << test.sagGuthaben() << endl;	// Guthaben ausgeben
		test.verzinsen();	// verzinsen
		cout << "Ende Jahr " << i + 1 << " - Guthaben: " << test.sagGuthaben() << endl << endl;		// Verzinstes Guthaben ausgeben
		
	}

	cout << "Am Ende: " << endl;
	test.abfrage();		// Kontoinformationen ausgeben

	getchar();
	return EXIT_SUCCESS;
}