/*	Christoph Kempkes - 547623

02 - Aufgabe 08 - Temperatur

Letzte Änderung: 23.04.2013 
Testiert am: 23.04.2013 */

#include "celsius.h"
#include "kelvin.h"
#include "fahrenheit.h"

// --Ausgabe
void kelvin::ausgabe() {
	cout << "Kelvin: \t" << k << "K" << endl;
}

// --Return
double kelvin::ret() const {
	return k;
}

// --Celsius in Kelvin umrechnen
kelvin::kelvin(const celsius &c) {
	k = c.ret() + 273.15;
}

// --Fahrenheit in Kelvin umrechnen
kelvin::kelvin(const fahrenheit &f) {
	k = ( (f.ret() - 32 ) / 1.8 ) + 273.15;
}