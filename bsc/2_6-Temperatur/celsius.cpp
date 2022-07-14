/*	Christoph Kempkes - 547623

02 - Aufgabe 08 - Temperatur

Letzte Änderung: 23.04.2013 
Testiert am: 23.04.2013 */

#include "celsius.h"
#include "kelvin.h"
#include "fahrenheit.h"

// --Return:
double celsius::ret() const {
	return c;
}

// --Ausgabe:
void celsius::ausgabe() {
	cout << "Celsius: \t" << c << (char) 248  << "C" << endl;	// (char)248 um ° darzustellen
}

// --Fahrenheit in Celsius umrechnen
celsius::celsius(const fahrenheit &f) { 
	c = ( f.ret() - 32 ) * 5/9;
}

// --Kelvin in Celsius umrechnen
celsius::celsius(const kelvin &k)	{
	c = k.ret() - 273.15;
}