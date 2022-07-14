/*	Christoph Kempkes - 547623

02 - Aufgabe 06 - Rot13

Letzte Änderung: 08.04.2013 
Testiert am: 09.04.2013 */

#include "rot13.h"

rot13::rot13(const string &ein)
	: eingabe(ein) {
}

void rot13::einlesen() {
	getline(cin, eingabe);
}

void rot13::ausgabe() {
	cout << eingabe << endl;
}

// Kodieren
void rot13::encrypt() {

	for (int i = 0; i < eingabe.size(); i++) {

		if (	((eingabe[i] >= 65) && (eingabe[i] <= 90)) /* Großbuchstaben */ || 		
			((eingabe[i] >= 97) && (eingabe[i] <= 122)) /* Kleinbuchstaben */ ) {

			if ( (eingabe[i] > 77 && eingabe[i] <= 90) || (eingabe[i] > 109 && eingabe[i] <= 122) ) {
				eingabe[i] -= 13;
			} else {
				eingabe[i] += 13;
			}
		}
	}
}

// Dekodieren
void rot13::decrypt() {
	return encrypt();
}