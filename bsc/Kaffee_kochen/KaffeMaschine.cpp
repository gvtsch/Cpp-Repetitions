#include "KaffeMaschine.h"

#include <iostream>
using namespace std;

KaffeMaschine::KaffeMaschine():inhalt_frisch(0),
	inhalt_kaffee(0),inhalt_pulver(0),istWarm(false)
{}


KaffeMaschine::KaffeMaschine(double ifrisch, double ipulver):
	inhalt_frisch(ifrisch),inhalt_kaffee(0),inhalt_pulver(ipulver),
	istWarm(false)
	{}

KaffeMaschine::~KaffeMaschine()
{
	cout << "Kaputt" << endl;
}

void KaffeMaschine::info() {

	cout << "Inhalt Wasserbehaelter " << inhalt_frisch << endl
 		 << "Inhalt Kaffeekanne     " << inhalt_kaffee << endl
		 << "Inhalt Kaffepulver     " << inhalt_pulver << endl
		 << "Warmhalteplatte an ?   " << (istWarm?"ja":"nein") << endl;
		
}

void KaffeMaschine::an(char anzahl, KTG groesse) {
	// --Warmhalteplatte an.
	istWarm=true;
	// --Wasser entnehmen.
	double wasser=0;
	double pulver=0;
	switch (groesse) {
	case klein  : wasser=anzahl*0.1; pulver=anzahl*0.010; break;
	case mittel : wasser=anzahl*0.2; pulver=anzahl*0.020; break;
	case gross  : wasser=anzahl*0.5; pulver=anzahl*0.030; break;
	}
	if (wasser<=inhalt_frisch && pulver<=inhalt_pulver) {
		// --Koche Kaffee.
		inhalt_frisch-=wasser;
		inhalt_kaffee+=wasser;
		inhalt_pulver-=pulver;

		cout << "blubblub..." << flush;
	}
}

void KaffeMaschine::aus() {
	istWarm=false;
}