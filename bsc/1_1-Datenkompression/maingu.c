/*	Christoph Kempkes - 547623

01 - Aufgabe 01 - Datenkompression
Das Programm wurde in Zusammenarbei mit Rene Kampmeier erstellt.

Letzte Änderung: 22.03.2013 
Testiert am: 22.03.2013 */

/* ToDo: */

/* Bibliotheken laden */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


/* Komprimieren */
void komprimieren(FILE *in, FILE *out) {
	int wert1 = 0, wert2 = 0, shift = 0; float zaehler1 = 0, zaehler2 = 1, grad = 0;
	unsigned char wert1c = 0, wert2c = 0, diff = 0, ausgabe = 0;

	/* Eingabeüberprüfungen */
    if ((in == NULL) || (out == NULL)) {				/* Können Dateien geöffnet werden? */
        printf("Fehler beim Oeffnen der Datei(en)\n");	/* Nein? Fehler und entsprechende Datei schließen */
        if(in != NULL) fclose(in);
        if(out != NULL) fclose(out);	
		exit (1); /* Fehler zurückgeben */
	}		

	fscanf(in, "%02X", &wert1); 
	wert1c = (unsigned char)wert1; 
	fprintf(out, "%02X ", wert1c);	/* Startwert */

	while (!feof(in)) {
		fscanf(in, "%02X", &wert2);		/* Wert als/in Int eingelesen ... */
		wert2c = (unsigned char)wert2;	/* ... aber als usigned char weiter verarbeitet */
        zaehler1++;		/* Jedes Mal wenn ein Wert eingelesen wird hochsetzen. Für die spätere Komprimierungsgradbrechnung */
		
		diff = wert2c - wert1c;     /* Differenz berechnen */

		/* Differenz positiv und 0 <= diff <= 7 */
		if	(diff <= 0x07) { 
			if (shift == 0) {		/* Shift wird genutzt, um die verschiedenen Nibble zu beschreiben. Wechselt zwischen 0 und 1. Hier wird abgefragt, ob es noch 'leer' ist */
				ausgabe = diff; 
				ausgabe = ausgabe << 4; /* Wenn Shift 0 ist, wird nur das obere Nibble gebraucht und beschrieben */
				shift = 1;	
			}
			else if (shift == 1) {	
				ausgabe = ausgabe | diff;	/* Hier wird das untere Nibble beschrieben */
				shift = 0; 
				fprintf(out, "%02X ", ausgabe);	/* Dann ist 'ausgabe' vollständig und kann ausgegeben werden. Dieses Muster wird bei den weiteren Fällen fortgesetzt */
                zaehler2++;		/* Zaehler2 zaehlt, wie viele Werte ausgegeben wurden, um später den Komprimierungsgrad zu berechnen. */ 
			}					/* Da immer ein Startwert vorhanden ist, startet dieser Zaehler bei 1 */
		
		} /* Differenz negativ und -7 <= diff < 0 */
		else if (	(wert2c < wert1c) && ((wert1c - wert2c) <= 0x07)) {	
			diff = (~(wert1c - wert2c)+1) & 0x0F;	/* Wenn diff negativ aber noch im darstellbaren Bereich ist: pos. Diff berechnen und Zweierkomplement bilden */
			if (shift == 0) { 
				ausgabe = diff << 4; 
				shift = 1; 
			}
 			else if (shift == 1) { 
				ausgabe = ausgabe | diff; 
				shift = 0; 
				fprintf(out, "%02X ", ausgabe); 
                zaehler2++;
			}		
		} /* 'Rückwärts-Differenz' - Differenz ist darstellbar allerdings geht das ganze über die '255' hinaus */
		else if (	(wert2c > wert1c) && (diff <= 0xFF) && (diff >= 0xF9)) { 
			if (shift == 0) { 
				ausgabe = diff << 4; 
				shift = 1; 
			} else if (shift == 1) { 
				ausgabe = ausgabe | (diff & 0x0F); 
				shift = 0; 
				fprintf(out, "%02X ", ausgabe); 
                zaehler2++;
			}		
		} /* Zu große Differenz - Neuer Startwert muss gesetzt werden */ else { 
			if (shift == 0) { 
				ausgabe = 0x80; /* Wenn die Differenz zu groß ist, wird eine 8 genutzt um das darzustellen und ins obere Nibble geschrieben */
				ausgabe = ausgabe | (wert2c >> 4);	/* Und der obere Teil des neuen Startwertes muss ins Untere geschrieben werden */
				fprintf(out, "%02X ", ausgabe); 
                zaehler2++;
				ausgabe = (wert2c & 0x0F) << 4; /* Der untere Teil des neuen Startwertes fehlt noch und wird ins obere Nibble der Ausgabe geschrieben, die später ausgegeben wird */
                shift = 1; 
			} else if (shift == 1) { 
				ausgabe = ausgabe | 0x08;	/* Wenn im oberen Nibble etwas steht, muss die 8 ins Untere */
				fprintf(out, "%02X %02X ", ausgabe, wert2c);	/* Wenn die 8 im Unteren ist, kann auch direkt ein neuer Startwert ausgegeben werden */
                zaehler2 = zaehler2 + 2;	/* Dann wird der Zaehler für ausgegebene Werte um 2 erhöht */
				shift = 0; 
			}
		} wert1c = wert2c; /* Der letzte Wert wird an den 'Startwert' übergeben */
	}   fseek(out, -3, SEEK_END);	/* In der Datei 3 Zeichen zurück gehen */
		fscanf(out, "%02X", &wert1);	/* Den letzten ausgegebenen Wert einlesen (Dabei wandert der Cursor in der Datei wieder nach vorne) */
		if(!(wert1 & 0x0F) && wert2c){	/* Wenn der untere Teil dieses Wert ungleich dem ist, der in der Schleife als letztes eingelesen wurde: */
			fseek(out, -3, SEEK_END);	/* Cursor wieder zurück */
			fprintf(out, "%02X", (ausgabe | 0x08)); }	/* Den Wert wieder ausgeben und in das untere Nibble eine 8 schreiben */
        printf("Komprimierungsrate: %.0f %%", 100 - ((float)zaehler2 / (float)zaehler1) * 100); /* Berechnen der Komprimierungsrate und ausgeben */
}

/* Dekomprimieren */
void dekomprimieren(FILE *in, FILE *out) {
	int wert2 = 0, shift = 0, diff = 0;
	unsigned char wert2c = 0, diffc = 0, ausgabe = 0;

	/* Eingabeüberprüfungen */
    if ((in == NULL) || (out == NULL)) {				/* Können Dateien geöffnet werden? */
        printf("Fehler beim Oeffnen der Datei(en)\n");	/* Nein? Fehler und entsprechende Datei schließen */
        if(in != NULL) fclose(in);
        if(out != NULL) fclose(out);	
		exit (1); }		/* Fehler zurückgeben */

	fscanf(in, "%02X", &diff);
	diffc = (unsigned char)diff; 
	ausgabe = diffc;
	fprintf(out, "%02X ", ausgabe);     /* Startwert */

	while(!feof(in)){   
		fscanf(in, "%02X", &diff);      /* Nächster Messwert (Differenz) */
        if(feof(in)) break;             /* Wenn Dateiende erreicht wurde abbrechen. Ohne wird evtl. ein Wert am Ende angehängt. */
		diffc = (unsigned char) diff;   /* Casten zum weiteren Verarbeiten */

        /* Oberes Nibble = 8? Dann Unteres neuer Startwert */
		if( (diffc & 0xF0) == 0x80 ) {
			ausgabe = (( diffc & 0x0F ) << 4);	/* Wenn Oberes eine 8 ist, dann in Ausgabe das Untere */
			fscanf(in, "%02X", &diff);		/* Und neuen Wert einlesen */
			diffc = (unsigned char)diff;	
			ausgabe = ausgabe | (( diffc & 0xF0 ) >> 4);	/* Oberes Nibble des neuen Wertes in das Untere der Ausgabe ... */
			fprintf(out, "%02X ", ausgabe);					/* ... und ausgeben */
		} else {    /* Wenn oberes Nibble != 8, dann ist es Differenz. */
			if( (diffc & 0xF0) & 0x80 ) {	/* Negativ? */
				ausgabe = ausgabe - ((~(diffc >> 4) & 0x0F) + 1);	/* Wenn negativ (z.b. 9) dann das Zweierkomplement rückgängig machen und verrechnen ... */				
				fprintf(out, "%02X ", ausgabe);						/* ... und ausgeben */
			} else {    /* Wenn nicht negativ, dann positiv */
				ausgabe = ausgabe + ((diffc & 0xF0) >> 4);	/* Wenn positiv, dann einfach verrechnen ... */
				fprintf(out, "%02X ", ausgabe);				/* ... und ausgeben */
			}
		}

        /* Unteres Nibble = 8? Dann neuen nächster Wert */
		if( (diffc & 0x0F) == 0x08 ){
			fscanf(in, "%02X", &diff);		/* Wenn das untere eine 8 ist, kann direkt ein neuer Wert eingelesen werden */
			if(feof(in)) break;		/* Wie oben */
			diffc = (unsigned char)diff;
			ausgabe = diffc;	/* Neuen Wert noch an ausgabe übergeben und dann ... */
			fprintf(out, "%02X ", ausgabe);	/* ... ausgeben */
		} else {    /* Wenn unteres Nibble != 8, dann ist es Differenz. */		
			if( (diffc & 0x0F) & 0x08 ) {	/* Negativ? */
				ausgabe = ausgabe - ((~diffc) + 1 ) & 0x0F;		/* Wenn negativ (z.b. 9) dann das Zweierkomplement rückgängig machen und verrechnen ... */					
				fprintf(out, "%02X ", ausgabe);					/* ... und ausgeben */
			} else {    /* Wenn nicht negativ, dann positiv */
				ausgabe = ausgabe + (diffc & 0x0F);		/* Wenn positiv, dann einfach verrechnen ... */
				fprintf(out, "%02X ", ausgabe);			/* ... und ausgeben */
			}
		}
	}
}

int main(int argc, char **argv) {
	FILE *in = NULL, *out = NULL; 
	int arg = 0;
	
	/* Komprimieren */
	if (argc == 3) { 
		in = fopen (argv[1], "r"); out = fopen (argv[2], "w+");		/* Daten übergen */
		printf("01 Aufgabe 01 - Datenkompression\n- Komprimieren -\n\nEingabedatei: %s\nAusgabedatei: %s\n\n", argv[1], argv[2]);
		
		komprimieren(in, out);

	/* Dekomprimieren */
	} else if ((argc == 4) && (*argv[1] == '-') && (argv[1][1] == 'd')) { 
		in = fopen (argv[2], "r"); out = fopen (argv[3], "w+");		/* Daten übergeben */

		printf("01 Aufgabe 01 - Datenkompression\n- Dekomprimieren -\n\nEingabedatei: %s\nAusgabedatei: %s\n\n", argv[2], argv[3]);
		dekomprimieren(in, out);
	
	/* Falsche Eingabe */
	} else { 
		printf("Fehler: Falsche Parametereingabe.\nKomprimieren: \t'main.exe infile outfile'\nDekomprimieren: 'main.exe -d infile outfile'\n");
		getchar(); exit(1); }

	fclose(in); fclose(out);
	printf("\n\n");
	getchar();
	return 0;
}