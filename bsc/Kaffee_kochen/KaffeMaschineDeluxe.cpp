#include "KaffeMaschineDeluxe.h"
#include <iostream>
using namespace std;


KaffeMaschineDeluxe::KaffeMaschineDeluxe():inhalt_milch(0.0)
{
}

void KaffeMaschineDeluxe::info() {
	cout << "Inhalt Milchbehaelter  " << inhalt_milch << endl;
	KaffeMaschine::info();
}

KaffeMaschineDeluxe::~KaffeMaschineDeluxe()
{
}

// --Konstruktor
KaffeMaschineDeluxe::KaffeMaschineDeluxe(double iw, double ip, double im):
	KaffeMaschine(iw, ip), inhalt_milch(im) 
{
}

void KaffeMaschineDeluxe::an(char anzahl, KTG groesse, MM milch) {
	KaffeMaschine::an(anzahl, groesse);
	
	double benoetigte_milch = 0;
	if (milch == wenig)
		benoetigte_milch = anzahl * 0.05;
	else if (milch == kakao)
		benoetigte_milch = anzahl * 0.2;

	// --Milch aufschäumen
	if (inhalt_milch >= benoetigte_milch) {
		cout << "\nschlupp schlupp\n" << flush;
		inhalt_milch -= benoetigte_milch;
	}
}