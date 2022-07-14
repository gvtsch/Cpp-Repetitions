/*	Christoph Kempkes - 547623

02 - Aufgabe 07 - Bank

Letzte �nderung: 14.04.2013 
Testiert am:  15.04.2013 */

#ifndef BANK_H
#define BANK_H
#include <string>
#include <iostream>

using namespace std;

class Bank {
private:
	string Name;
	double Guthaben;
	double ZinsPos;
	double ZinsNeg;

public:
	// --Konstruktor
	Bank(const string& n, double gh, double ZinsPos, double ZinsNeg);

	// --Methoden zur Ausgabe 
	const string& sagName() const { return Name; }	// Namen erstellen und zur�ckgeben	
	double sagGuthaben() { return Guthaben; }		// Guthaben zur�ckgeben
	double sagZinsPos() { return ZinsPos; }			// Zinssatz f�r positives Guthaben zur�ck geben
	double sagZinsNeg() { return ZinsNeg; }			// Zinssatz f�r negatives Guthaben zur�ck geben
	
	// --Methoden zum Setzen
	string SetzName(const string& n) { return Name = n; }		// Namen erstellen	
	double SetzZinsPos(double ZinsPos) { return ZinsPos = ZinsPos; }	// Zinssatz f�r positives Guthaben zur�ck geben
	double SetzZinsNeg(double ZinsNeg) { return ZinsNeg = ZinsNeg; }	// Zinssatz f�r negatives Guthaben zur�ck geben

	// --Andere Methoden
	double einzahlen(int b) { return Guthaben += b; }	// Guthaben um Betrag b erh�hen
	double abheben(int b) { return Guthaben += b; }		// Guthaben um Betrag b erh�hen (b ist in diesem fall negativ, wird letztlich abgezogen)
	void verzinsen();		// verzinsen
	void abfrage();			// Kontoinformationen ausgeben
};

#endif 