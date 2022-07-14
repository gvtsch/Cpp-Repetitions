///////////////////////////////////////////////////////////
//  Counter.h
//  Implementation of the Class Counter
//  Created on:      21-Mai-2010 11:53:22
//  Original author: Michael Uelschen
///////////////////////////////////////////////////////////

#if !defined(EA_1148C1A7_1E97_45d2_8050_EF7F5DCDCE4D__INCLUDED_)
#define EA_1148C1A7_1E97_45d2_8050_EF7F5DCDCE4D__INCLUDED_

#include "Sensor.h"

/*! Diese Klasse realisiert einen Zähler als Sensor. Es werden die Anzahl
 *  der Impulse (beispielsweise von einem Radencoder) summiert. */  

class Counter : public Sensor
{

public:
	/*! Der Standardkonstruktor. */
	Counter();
	/*! Der Destruktor. */
	virtual ~Counter();
	/*! Diese Methode setzt den Zähler zurück auf null. */
	bool clear();

};
#endif // !defined(EA_1148C1A7_1E97_45d2_8050_EF7F5DCDCE4D__INCLUDED_)
