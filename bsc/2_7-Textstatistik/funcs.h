/*	Christoph Kempkes - 547623

02 - Aufgabe 09 - Textstatistik

Letzte Änderung: 06.05.2013 
Testiert am:  */
#ifndef _FUNCS_H
#define _FUNCS_H


#include <fstream>		// Dateistream
#include <iostream>		// I/O - Stream
#include <string>		// Container String
#include <set>			// Container set zum aufseten
#include <map>
#include <algorithm>	// Container Algorithm für versch. Algorithmen - hier für transform (Kleinbuchstaben)

using namespace std;

void einlesen(set<string>&woerterbuch, string infile, int alphabet[26]);
void zaehlen(set<string>&woerterbuch);
void ausgeben(set<string>&woerterbuch, int &m);
void buchstaben(string &wort, int alphabet[26]);

#endif