/*	Christoph Kempkes - 547623

02 - Aufgabe 08 - Temperatur

Letzte �nderung: 23.04.2013 
Testiert am: 23.04.2013 */

#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H
#include <iostream>

using namespace std;

class celsius;
class kelvin;

class fahrenheit {
private:
	double f;	// Variable f�r Fahrenheit
	
public:
	fahrenheit(const celsius &c);	// Konstruktor f�r Fahrenheit in Celsius
	fahrenheit(const kelvin &k);	// Konstruktor f�r Fahrenheit in Kelvin
	double ret() const;				// Return wird ben�tigt um umzurechnen
	void ausgabe();					// Ausgabe

	fahrenheit()			// Standardkonstruktor mit 0.0
		:f(0.0) {}
	fahrenheit(double fa)	// Konstruktor f�r doubles
		:f(fa) {}
};

#endif