/*	Christoph Kempkes - 547623

02 - Aufgabe 08 - Temperatur

Letzte Änderung: 23.04.2013 
Testiert am: 23.04.2013 */

#include "celsius.h"
#include "kelvin.h"
#include "fahrenheit.h"
#include <iostream>

using namespace std;

bool istgleich(celsius x, celsius y);

int main () {
	
#if 1
	// --Test mit gegebenem Celsius Wert
	cout << "Test mit gegebenem Celsius Wert:" << endl;	// Test 1
	celsius testc(0);			// Gegeben in Celsius
	testc.ausgabe();			// Ausgabe von Celsius
	
	fahrenheit testfahrenheit(testc);		// Klasse Test für Fahrenheit erstellen mit Wert von Celsius
	kelvin testkelvin(testc);	// Klasse testkelvin erstellen mit Wert von Celsius
	testfahrenheit.ausgabe();	// Ausgeben des Fahrenheitwertes
	testkelvin.ausgabe();		// Ausgeben des Kelvinwertess
	// --Test Celsius Ende

	// --Test mit gegebenem Kelvin Wert, im Prinzip wie Test mit gegebenem Celsius Wert
	cout << endl << "Test mit gegebenem Kelvin Wert:" << endl;	
	kelvin testk(273.15);		
	testk.ausgabe();			

	fahrenheit testfahrenheitk(testk);
	celsius testcelsius(testk);
	testfahrenheitk.ausgabe();
	testcelsius.ausgabe();
	// --Test Kelvin Ende

	// --Test mit gegebenem Fahrenheitwert, im Prinzip wie Test mit gegebenem Celsius Wert
	cout << endl << "Test mit gegebenem Fahrenheitwert:" << endl; 
	fahrenheit testf(32.0);
	testf.ausgabe();

	celsius testcelsiusf(testf);
	kelvin testkelvinf(testf);
	testcelsiusf.ausgabe();
	testkelvinf.ausgabe();
	// --Test Fahrenheit Ende
#endif


	// --istgleich?
	celsius a(42);
	kelvin c(315.15);
	
	cout << endl << endl << "Test 'IstGleich?':" << endl;
	a.ausgabe();	// Ausgabe des Wertes
	c.ausgabe();	// Ausgabe des Wertes

	if (istgleich(a, c))	// c wird als Celsius konstruiert und kann so verglichen werden
		cout << endl << "Ja!" << endl;
	else
		cout << endl << "Nein!" << endl;
	// --Ende istgleich

	getchar();
	return EXIT_SUCCESS;
}

// --istgleich
bool istgleich(celsius x, celsius y) {
	if (abs (x.ret() - y.ret()) <= 0.01 )
		return true;
	else
		return false;
}