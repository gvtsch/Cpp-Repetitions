/*	Christoph Kempkes - 547623

02 - Aufgabe 08 - Temperatur

Letzte Änderung: 23.04.2013 
Testiert am: 23.04.2013 */

#ifndef KELVIN_H
#define KELVIN_H
#include <iostream>

using namespace std;

class celsius;
class fahrenheit;

class kelvin {
private:
	double k;	// Variable für Kelvin
	
public:
	kelvin(const celsius &c);		// Konstruktor Kelvin in Celsius
	kelvin(const fahrenheit &f);	// Konstruktor Kelvin in Fahrenheit
	void ausgabe();					// Ausgabe
	double ret() const;				// Return wird benötigt um umzurechnen

	kelvin()				// Standardkonstruktor mit 0.0
		:k(0.0) {}
	kelvin(double ke)		// Konstruktor für doubles
		:k(ke) {}

};

#endif