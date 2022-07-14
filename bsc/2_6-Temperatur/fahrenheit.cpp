/*	Christoph Kempkes - 547623

02 - Aufgabe 08 - Temperatur

Letzte Änderung: 23.04.2013 
Testiert am: 23.04.2013 */

#include "celsius.h"
#include "kelvin.h"
#include "fahrenheit.h"

// --Ausgabe
void fahrenheit::ausgabe() {
	cout << "Fahrenheit: \t" << f << (char) 248 << "F" << endl;
}

// --Return
double fahrenheit::ret() const {
	return f;
}

// --Celsius in Fahrenheit umrechnen
fahrenheit::fahrenheit(const celsius &c) {
	f = c.ret() * 1.8 + 32;
}

// --Kelvin in Fahrenheit umrechnen
fahrenheit::fahrenheit(const kelvin &k) {
	f = (k.ret() - 273.15) * 1.8 + 32;
}