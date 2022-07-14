//-----------------------------------------------------
//
// OOP / SW-Engineering für Mechatronik
//
// File: person_main.cpp
//
// Testprogramm fuer die Klasse "person"
//
//-----------------------------------------------------

// File: personmain.cpp
#include "person.h"
#include <iostream>
using namespace std;	

int main() {
	Person ich("Karl Toffel",'m', 60, 1.85, 25);	//Konstruktor
	
	// Übergewicht
	if (ich.Uebergewicht()) {
		while (!ich.Untergewicht()) {
			cout << "Trainiere ... " << endl;
			ich.sport();
		}
	}
	
	// Untergewicht
	 else if (ich.Untergewicht()) {
		while (!ich.Uebergewicht() ) {
    		cout << "Ich esse ..." << endl;
			ich.aendereGewicht(0.5);
		}
		cout << "Nun wiege ich " << ich.sagGewicht() << "kg." << endl;
		cout << "Ich steige auf die Waage und esse aus Frust noch mehr ..." << endl;
		ich.aendereGewicht(0.5);
		cout << "Nun wiege ich " << ich.sagGewicht() << "kg." << endl;
	}
	
	ich.Steckbrief();
	getchar();
}
