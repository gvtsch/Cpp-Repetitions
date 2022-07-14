#ifndef _REACTIVEMODEL_H
#define _REACTIVEMODEL_H

#include "Model.h"
#include "InputPort.h"
#include "MotorPort.h"
#include "TxControllerSupervision.h"

/*! Die Reactive-Model-Klasse realisiert ein Fischertechnik-Modell, welches eine
 *  ereignisorientierte Ablaufsteuerung besitzt. Die Klasse ist die Basisklasse oder
 *  Oberklasse f�r ein reales Fischertechnik-Modell. Die Methoden on_XYZ_Changed
 *  werden automatisch aufgerufen, sobald bestimmte Sensorwerte sich �ndern. Durch
 *  �berladen der Methoden kann dadurch eine Reaktion implementiert werden (daher 
 *  kommt auch der Klassenname - ReactiveModel). */

class ReactiveModel : public Model {
public:

	/*! Ein Bitfield ist ein Bitmuster der L�nge 8. */
	typedef unsigned char Bitfield;

	/*! Der Standardkonstruktor. */
	ReactiveModel();

	/*! Diese Methode liefert das zum Modell geh�rige TX-Controller-Objekt zur�ck. */
	TxControllerSupervision* controller() const;

	/*! Die folgenden Methoden werden automatisch aufgerufen, wenn sich die
	 *  Werte an den Sensoren �ndern. �ber das Bitfield-Argument kann festgestellt
	 *  werden, welche Eing�nge (k�nnen mehrere ein) sich ge�ndert haben. Jedem
	 *  Eingang ist ein Bit zugeordnet. */
	
	/*! Die Methode onCounterChanged wird aufgerufen, wenn sich ein Z�hlereingang
	 *  �ndert.
	 *  \param bfield gibt den Z�hlereingang C1,...,C4 an. C1 ist das L(east)S(significant)B(it). */  
	virtual void onCounterChanged(Bitfield bfield);

	/*! Die Methode onCounterConfChanged wird aufgerufen, wenn ein Z�hler neukonfiguriert
	 *  wird. Ein Z�hler wird bei der Motorsteuerung im intelligenten Modus konfiguriert.
	 *  \param bfield gibt den Z�hlereingang C1,...,C4 an. */
	virtual void onCounterConfChanged(Bitfield bfield);

	/*! Die Methode onInputChanged wird aufgerufen, wenn an einem der Universaleing�nge
	 *  ein neuer Wert anliegt. 
	 *  \param bfield gibt den Universaleingang I1,...,I8 an. I1 ist das LSB. */
	virtual void onInputChanged(Bitfield bfield);

	/*! Diese Methode onMotorStopped wird aufgerufen, wenn (i) der Motor im intelligenten
	 *  Modus seine endg�ltige Position erreicht hat (wird durch die definierten Drehimpulse
	 *  festgelegt) oder (ii) der Motor explizit gestoppt wird.
	 *  \param bfield gibt den Motor M1,...,M4 an. M1 ist das LSB. */
	virtual void onMotorStopped(Bitfield bfield);

	/*! Diese Methode wird in der aktuellen Version nicht unterst�tzt. */
	virtual void onMotorAborted(Bitfield bfield);
	/*! Diese Methode wird in der aktuellen Version nicht unterst�tzt. */
	virtual void onTimeChanged();

	/*! Die Methode onStart wird aufgerufen, wenn das reaktive Modell gestartet wird. Durch
	 *  �berladen der Methode k�nnen vorbereitende Arbeiten, beispielsweise das Einschalten
	 *  von Lampen, durchgef�hrt werden. */
	virtual void onStart();
	
	/*! Die Methode onStop wird aufgerufen, wenn das reaktive Modell beendet wird.
	 *  Durch �berladen der Methode k�nnen bestimmte Aufr�umarbeiten am Modell (z.B.
	 *  Lampen ausschalten) vorgenommen werden. */
	virtual void onStop();

	/*! Die Methode setIsFinished kann aus einem Modell heraus aufgerufen werden, um 
	 *  die Ausf�hrung des reaktiven Modells zu stoppen. Dieses kann beispielsweise in
	 *  Fehlerf�llen notwendig sein. 
	 *  \param val Gibt an, ob das Signal gesetzt (true) oder gel�scht (false) werden soll. */
	void setIsFinished(bool val =true);

	/*! Mit dieser Methode kann das Signal zum Beenden des reaktiven Modells abgefragt werden. */
	virtual bool isFinished();
	
	/*! Die Methode onError wird aufgerufen, wenn Fehlersitautionen erkannt werden. Die
	 *  Methode kann �berladen werden, ob die Ausgabe in eine Datei o.�. zu realisieren.
	 *  Standardm��ifg wird in den cerr-Fehlerstrom geschrieben.
	 *  \param err Gibt den Fehlertext an. */
	virtual void onError(const char* err);

	/*! Die folgenden Methoden erm�glichen es, die Bitmasken f�r die Signalisierung von
	 *  �nderungen an den Eing�ngen, Z�hlern und Motoren abzufragen. */
	Bitfield counterMask() const;
	Bitfield counterConfMask() const;
	Bitfield inputMask() const;
	Bitfield motorMask() const;

	/*! Diese Methode wird in der aktuellen Version nicht unterst�tzt. */
	Bitfield abortMask() const;
		
protected:

	/*! Die folgenden Bitfelder geben an, f�r welche Eing�nge, Z�hler und Motoren
	 *  ein Signalisierung (Aufruf der entsprechenden on_XYZ_Changed-Methode) ausgef�hrt
	 *  werden soll. Standardm��ig wird jede �nderung ber�cksichtigt (die Masken
	 *  besitzen den Wert 0xff). Soll beispielsweise nur auf �nderungen am Universaleingang I1
	 *  reagiert werden, dann muss die Maske auf 0x01f gesetzt werden. */
	Bitfield	_counterMask;
	Bitfield	_counterConfMask;
	Bitfield	_inputMask;
	Bitfield	_motorMask;
	Bitfield    _abortMask;

private:

	/*! Bit zur Beendigung des reaktiven Modells. */
	bool _isFinished;

};


#endif
