/*	Christoph Kempkes - 547623

02 - Aufgabe 06 - Rot13

Letzte Änderung: 08.04.2013 
Testiert am: 09.04.2013 */

#ifndef ROT13_H
#define ROT13_H
#include <string>
#include <iostream>

using namespace std;

class rot13 {
private:
	string eingabe;
public:
	rot13(const string &ein);
	void einlesen();
	void ausgabe();
	void encrypt();
	void decrypt();
};

#endif