#pragma once
#include "kaffemaschine.h"
class KaffeMaschineDeluxe :
	public KaffeMaschine
{
public:
	KaffeMaschineDeluxe();
	~KaffeMaschineDeluxe();

	// --Aufzählunstyp
	enum MM { schwarz, wenig, kakao };

	KaffeMaschineDeluxe(double iw, double ip, double im);	// --Konstruktor

	void an(char anzahl, KTG groesse, MM milch);

	void info();
private:
	double inhalt_milch;
};

