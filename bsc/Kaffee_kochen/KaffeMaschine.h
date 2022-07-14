#pragma once
class KaffeMaschine
{
public:

	enum KTG { klein, mittel, gross };

	KaffeMaschine(); // <--- Konstruktor
	KaffeMaschine(double ifrisch, double ipulver =0.5);

	~KaffeMaschine();

	void an(char anzahl, KTG groesse);
	void aus(); // --Warmhalteplatte aus

	virtual void info();	// --virtual Teil vom Konzept des Polymorphismus

private:

	double inhalt_frisch; // --Liter
	double inhalt_kaffee; // --Liter	
	double inhalt_pulver; // --Kilogramm

	bool istWarm;
};

