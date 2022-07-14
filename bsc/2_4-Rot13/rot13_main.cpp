/*	Christoph Kempkes - 547623

02 - Aufgabe 06 - Rot13

Letzte Änderung: 08.04.2013 
Testiert am: 09.04.2013 */

#include "rot13.h"
#include <iostream>
#include <string>

int main() {

	rot13 text("");		// Konstruktor

	cout << "02 - Aufgabe 06 - rot13\n" << endl;
	cout << "Eingabe: " << endl;

	text.einlesen();

	text.encrypt();
	text.ausgabe();

	text.decrypt();
	text.ausgabe();

	getchar();
	return EXIT_SUCCESS;
}