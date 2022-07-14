#ifndef COLOUR_H_
#define COLOUR_H_

#include "Sensor.h"

/*! Die Klasse Colour implementiert den Fischertechnik-Farbsensor. Der Farbsensor
 *  liefert ein analoges Signal. */

class Colour : public Sensor
{
public:
	/*! Der Standardkonstruktor. */
	Colour();
	/*! Der Destruktor. */
	virtual ~Colour();
};

#endif