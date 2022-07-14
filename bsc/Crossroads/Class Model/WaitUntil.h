#ifndef WAITUNTIL_H_
#define WAITUNTIL_H_

#include "Button.h"
#include "Sensor.h"
#include "Contact.h"
#include "Photo.h"

#include <windows.h>

inline void WaitUntilIsOver(int timeout) {
	Sleep(timeout);
}

inline void WaitUntilIsPressed(Button& button, int spin =100) {
	while (!button.isPressed())
	 Sleep(spin);
}

inline void WaitUntilIsContacted(Contact& contact, int spin =100) {
	while (!contact.isContacted())
		Sleep(spin);
}

inline void WaitUntilIsDark(Photo& photo, int spin =100) {
	while (!photo.isDark())
		Sleep(spin);
}


#endif
