/*	Christoph Kempkes - 547623

02 - Aufgabe 08 - Temperatur

Letzte Änderung: 23.04.2013 
Testiert am: 23.04.2013 */

#ifndef CELSIUS_H
#define CELSIUS_H
#include <iostream>

class kelvin;
class fahrenheit;

using namespace std;

class celsius {
private:
	double c;	// Variable für Celsius
	
public:
	celsius(const kelvin &k);		// Konstruktor Celsius in Kelvin
	celsius(const fahrenheit &f);	// Konstruktor Celsius in Fahrenheit
	void ausgabe();					// Ausgabe
	double ret() const;				// Return wird benötigt um umzurechnen

	celsius()			// Standardkonstruktor mit 0.0
		:c(0.0) {}
	celsius(double ce)	// Konstruktor für doubles
		:c(ce) {}

};

#endif