//-----------------------------------------------------
//
// OOP / SW-Engineering für Mechatronik
//
// File: person.h
//
// Header-File fuer die Klasse "person"
//
//-----------------------------------------------------


#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Person {
private:
  string Name;
  char   Geschlecht;         // m oder w
  double Gewicht;            // Kilogramm
  double Groesse;            // Meter
  int Alter;				 // Alter

public:	
  // --Konstruktor
  Person(const string& n, char gs, double gw, double gr, int a);
  
  // --Methoden zum Setzen von Werten der Attribute
  void setzName(const string& n);
  void setzGeschlecht(char gs);
  void setzGewicht(double gw);      
  void setzGroesse(double gr);
  void setzAlter(int alter);

  // --Methoden zum Abfragen von Attributen
  const string& sagName() const;
  char sagGeschlecht() const;
  double sagGewicht() const;         
  double sagGroesse() const;
  int sagAlter() const;

  // --Weitere Methoden	
  void aendereGewicht(double gr);
  bool Uebergewicht() const;
  bool starkes_Uebergewicht() const;
  int Geburtstag();
  bool Untergewicht() const;
  void sport();
  void Steckbrief();

private:
  double BMI() const; // Body-Mass-Index
};

#endif // PERSON_H

