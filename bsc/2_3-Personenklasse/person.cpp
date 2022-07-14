//-----------------------------------------------------
//
// OOP / SW-Engineering für Mechatronik
//
// File: person.cpp
//
// Methoden fuer die Klasse "person"
//
//-----------------------------------------------------

 
#include "person.h"

Person::Person(const string& n, char gs, double gw, double gr, int a)
: Name(n), Geschlecht(gs), Gewicht(gw), Groesse(gr), Alter(a)  {
    if (Gewicht<0) Gewicht = 0;
}

void Person::setzName(const string& n) {
  Name=n;
}

void Person::setzGeschlecht(char gs) {
  if(gs=='w' || gs=='m') Geschlecht=gs;
}

void Person::setzGewicht(double gw){
  if(0 < gw && gw < 200) Gewicht=gw;
}

void Person::setzGroesse(double gr){
  if(0 < gr && gr < 2.3) Groesse=gr;
}

// ...
void Person::setzAlter(int a){
	Alter = a;
}


const string& Person::sagName() const { return Name; }
char Person::sagGeschlecht() const {return Geschlecht;}
double Person::sagGewicht() const {return Gewicht;}
double Person::sagGroesse() const { return Groesse; }
int Person::sagAlter() const { return Alter; }	// ...

void Person::aendereGewicht(double gw) { 
	if (-1<=gw && gw<=1) Gewicht +=gw; 
}

// sonstige Methoden 
double Person::BMI() const {
  if(Gewicht==0 || Groesse==0) return 22; // Standardwert
  return Gewicht/(Groesse*Groesse);
}

bool Person::Uebergewicht() const {
  return BMI() > 25. ;
}

bool Person::starkes_Uebergewicht() const {
  return BMI() > 27. ;
}

// ...
bool Person::Untergewicht() const {
	return BMI() < 19. ;
}

// ...
void Person::sport() {
	if((Gewicht / (Groesse * Groesse)) > 19.) Gewicht -= 0.3;	
}

// ...
int Person::Geburtstag() {
	Alter +=1;
	return Alter;
}

// ...
void Person::Steckbrief() {
	cout << "Steckbrief fuer " << Name << endl;
	cout << "Geschlecht\t: " << Geschlecht << endl;
	cout << "Gewicht\t\t: " << Gewicht << " kg" << endl;
	cout << "Groesse\t\t: " << Groesse << " m" << endl;
	cout << "BMI\t\t: " << Gewicht / (Groesse * Groesse) << endl;
}