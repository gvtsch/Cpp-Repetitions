//#include <iostream>
//#include <string>
//#include <sstream>
//using namespace std;
//
//bool einlesen(string &input, istringstream &tin) {
//
//    cout << "Text eingeben (Platt): " << endl;
//    if (getline(cin, input)) {	/* Ganze Zeile einlesen */
//
//		for(int i = 0; i < input.size() ; i++) {
//			if ( ((input[i] >= 65) && (input[i] <= 90)) || (input[i] == 220) || (input[i] == 196) || (input[i] == 214) ) 
//				input[i] += 32; } /* Gro�buchstabe >> Kleinbuchstabe */
//		istringstream tin(input);	/*  */
//		extract(tin);	/* Extract aufrufen */
//		return true; }	/* Falls eine Zeile eingelesen werden konnte */
//	else { 
//		return false; } /* Falls nicht ... */
//}
//
//void extract(istringstream &tin) {
//	string output, temp;
//	
//	while(tin >> temp) {	/* Wort in temp schieben */
//		translate(temp);	/* >> Kedelkloppersprook */
//		output += temp;		/* Zur Ausgabe wieder aneinander h�ngen und ... */
//	} cout << "\nKedelkloppersprook: " << output << endl;	/* ... und ausgeben */
//}
//
//void translate(string &temp) {
//	int index = 0;
//	string neu;
//
//	index = temp.find_first_of("aeiou");		/* Bei welchem Index taucht der erste Vokal auf? */
//	neu = temp.replace(0, index, "") + temp.substr(0, index) + "i";		/* Bis zum Vokal l�schen und hinter das Wort das "Gel�schte" anh�ngen */
//	
//	index = neu.find_first_of(".,:;-!?");	/* Existiert in dem Wort ein Satzzeichen? Wo ist das erste Satzzeichen in dem Wort? */
//	if(index != 0xffffffff) {				/* Wenn ein Satzzeichen vorhanden ist: */
//		neu = neu.erase(index, 1);			/* Das Satzzeichen an der Stelle l�schen und ... */
//		neu.push_back(temp[index]);			/* ... nach hinten ans Wort schieben */
//	}	/* Keine �nderung, wenn es kein Satzzeichen gab */
//
//	temp = neu + " ";	/* temp das "neue Wort" zuweisen */	
//}