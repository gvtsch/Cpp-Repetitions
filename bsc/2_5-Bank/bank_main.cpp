/*	Christoph Kempkes - 547623

02 - Aufgabe 07 - Bank

Letzte Änderung: 14.04.2013 
Testiert am:  15.04.2013 */

#include "bank.h"
#include <iostream>
#include <ctime>

using namespace std;

int main () {

	Bank test("Max Mustermann", 100, 2.00, 3.00);	// Konstruktor mit Namen, Startguthaben, Zinssatz für positives / negatives Guthaben

	cout << "Am Anfang: " << endl;	
	test.abfrage();		// Kontoinformationen ausgeben

	int a = 0, b = 0, Laufzeit = 5;		// a und b für Zufallszahlen, Laufzeit hier 5, um alles angezeigt zu bekommen
	srand(time(NULL));					// Von der Zeit abhängige "Zufallszahl" erstellen	

	for (int i = 0; i < Laufzeit; i++) {	// Solange Laufzeit
		a = (rand() % 25);					// Zufallszahl für Kontobewegungen
		cout << "Anzahl Kontobewegungen: " << a << endl;

		for (int j = 0; j < a; j++) {	// Solange Kontobewegungen
			b = (rand () % 500) - 250;	// Zufallszahl für Betrag (-250 bis 250)
			cout << "Betrag: " << b << endl;	

			if (b > 0) test.einzahlen(b);	// Guthaben um positiven Betrag erhöhen
			else test.abheben(b);			// Guthaben um negativen Betrag erhöhen
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