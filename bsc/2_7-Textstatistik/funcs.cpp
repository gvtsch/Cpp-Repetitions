/*	Christoph Kempkes - 547623

02 - Aufgabe 09 - Textstatistik

Letzte Änderung: 06.05.2013 
Testiert am:  */

#include "funcs.h"

// --Einlesen
void einlesen(set<string>&woerterbuch, string infile, int alphabet[26]) {
/* Liest ein - Prüft ob Wort mehr als 2 Buchstaben hat - Löscht Sonderzeichen - 
Schreibt alle Buchstaben klein - Fügt Wort ins Set<> ein - Ruft Funktion zum Buchstaben zählen auf */	

	string wort;
	ifstream ifs;
	ifs.open(infile);
	int index = 0;

	// --Wenn Datei nicht geöffnet werden kann
	if ( !ifs ) {			
		cerr << "Kann nicht geoeffnet werden" << endl;
		getchar();
	}

	// --Einlesen
	while(ifs >> wort) {
		if(wort.length() >= 2) {			
			transform(wort.begin(), wort.end(), wort.begin(), tolower);	// Buchstaben werden "klein gemacht"
		
			do {	// --Sonderzeichen löschen
				index = wort.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
				if(index != std::string::npos) // wenn gefunden ...:
					wort.erase(index, 1);	// entsprechendes löschen
			} while (index != std::string::npos);	// Solange suchen, bis keines mehr findet
			
			woerterbuch.insert(wort);	// Wort ins "Woerterbuch" einfügen
			buchstaben(wort, alphabet);	// Funktion zum Buchstaben zaehlen

		} else wort.erase();	// Wenn < 2 Buchstaben -> kein Wort -> kann weg
	} ifs.close();	// Filestream schliessen
}

// --Zaehlen
void zaehlen(set<string>&woerterbuch) {
/* Zählt die Buchstaben in einem Wort und schreibt in einem
Array wie viele Worte es mit n Buchstaben gibt. Gibt "Tabelle" aus */	
	
	int n = 0;
	int anzahl[21] = {0};	// Es werden zwar nur 19 Felder gebraucht, aber das gestaltet die Ausgabe einfacher
	
	set<string>::iterator wort;
	for(wort = woerterbuch.begin(); wort != woerterbuch.end(); ++wort) {	// durch das Woerterbuch iterieren
		
		n = wort->length();		// Laenge
		anzahl[n]++;	// Entsprechenden Eintrag im Array um einen erhöhen
	}
	// --Ausgabe
	cout << endl << "Anzahl der Woerter mit 2 - 20 Buchstaben: " << endl;
	for(n = 2; n <= 20; n++) {	// Bei 2 beginnen. Ersten beiden Einträge im Array sind über
		cout << n << " Buchstaben: " << anzahl[n] << endl;
	}
}

// --Ausgeben
void ausgeben(set<string>&woerterbuch, int &m) {
/* Gibt die Wörter aus, die n (bzw m) Buchstaben haben */	
	
	int i = 1;	// Nur für "tabellarische" Auflistung

	set<string>::iterator wort;
	for (wort = woerterbuch.begin(); wort != woerterbuch.end(); ++wort) {	// Durch das Woerterbuch iteriere	
		if (wort->length() == m) {					// Wenn Wort so lang, wie eingegeben:
			cout << i << " - " << *wort << endl;	// Wort ausgeben
			i++;	// Zähler einen hoch
		}
	} 
}

 // --Buchstaben
void buchstaben(string &wort, int alphabet[26]) {
/* Array erstellen und mit Werten hochzählen.
Über eine Schleife ausgeben */

	for (unsigned int i = 0; i < wort.size(); i++) {
		char buchstabe = (char)wort[i];
		++(alphabet[buchstabe - 97]);
	}
}