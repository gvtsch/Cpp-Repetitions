/*	Christoph Kempkes - 547623

02 - Aufgabe 07 - Bank

Letzte Änderung: 14.04.2013 
Testiert am:  15.04.2013 */

#include "Bank.h"
#include <string>
#include <iostream>
	
using namespace std;

Bank::Bank(const string& n, double gh, double ZinsPos, double ZinsNeg)
	: Name(n), Guthaben(gh), ZinsPos(ZinsPos), ZinsNeg(ZinsNeg) {
}

// --Verzinsen
void Bank::verzinsen() {
	if (Guthaben >= 0) {									// Wenn Guthaben positiv, ZinsPos nutzen
		Guthaben *= ( 1 + (ZinsPos / 100));					// Verzinsen
		Guthaben = (int)(Guthaben * 100 + 0.5) / 100.0;		// Runden
	}
	else {													// Wenn Guthaben negativ, ZinsNeg nutzen
		Guthaben *= (1 + (ZinsNeg / 100));					// Verzinsen
		Guthaben = (int)(Guthaben * 100 + 0.5) / 100.0;		// Runden
	}
}

// --Kontoinformationen 
void Bank::abfrage() {
	cout << "Inhaber\t\t\t: " << Name << endl;
	cout << "Aktuelles Guthaben\t: " << Guthaben << " EUR" << endl;
	cout << "Positiver Zinssatz\t: " << ZinsPos << "%" << endl;
	cout << "Negativer Zinssatz\t: " << ZinsNeg << "%" << endl << endl << endl;
}