/*	Christoph Kempkes - 547623

01 - Aufgabe 02 - Wörterbuch

Letzte Änderung: 17.03.2013 
Testiert am: 19.03.2013 */

/* Foto: http://bit.ly/166W5BM */

/* Bibliotheken laden */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WOERTER 1000		/* Wörter */
#define BUCHSTABEN 6	/* Anzahl der Buchstaben */

/* Print Funktion */
void print(int *gez_woerter, char tabelle[WOERTER+1][BUCHSTABEN+1], FILE *out){
	int w = 0;
	for (w = 0; w < (*gez_woerter); w++) fprintf(out, "%s ", tabelle[w]); 		
}
 
/* Sortieren */
void sort(char tabelle[WOERTER+1][BUCHSTABEN+1], int *gez_woerter) {
    int w = 0, b = 0, k = 0; char dreieck[BUCHSTABEN+1];	/* Für den Dreieckstausch */

    for(w = 0; w < (*gez_woerter); w++) {				/* Simplesort: Das 0te Wort mit den anderen vergleichen */
        for(b = w + 1; b < (*gez_woerter); b++) {		/* Beim ersten Durchlauf mit dem 1. - Sind diese im folgenden richtig sortiert mit dem 2., dem 3., ... */
            if(strcmp(tabelle[w], tabelle[b]) > 0) {	/* Vergleichen zweier Strings. Wenn strcmp > 0 -> Falsche Reihenfolge: */
                strcpy(dreieck, tabelle[w]); strcpy(tabelle[w], tabelle[b]); strcpy(tabelle[b], dreieck);	/* Dreieckstausch */
			}	     
		} 
    }
}

/* Dubles nach hinten schieben */
void del(char tabelle[WOERTER+1][BUCHSTABEN+1], int *gez_woerter, int *dubles){
	int oben = 0, unten = 0, start = 0; char buffer[BUCHSTABEN+1];	/* Für Dreieckstausch */
	(*dubles) = 0;
	
	for(start = 0, unten = start + 1, oben = start; unten <= (*gez_woerter); start++, unten = start + 1, oben = start ) {
		if(strcmp(tabelle[unten], tabelle[oben]) == 0) {	/* Sind die beiden Strings gleich? */
			(*dubles)++;	/* Dann Dubles +1. Dieser Wert wird später von den gezählten Wörtern
							abgezogen, damit entsprechend viele im Wörterbuch abgelegt werden */
			while(strcmp(tabelle[oben],tabelle[unten]) == 0) {		/* Wenn ==, dann Unten bis != bewegen und oben+1. */ 
				unten++; }	oben++;
			/* Danach Dreieckstausch des Strings bis zum Ende - Das Duble wird bis zum Ende durchgereicht */
			for(unten; unten < (*gez_woerter); unten++, oben++) {	
				strcpy(buffer, tabelle[oben]); strcpy(tabelle[oben], tabelle[unten]); strcpy(tabelle[unten], buffer);
			}				
		}  
	} 
}


/* Auslesen */
void auslesen(char tabelle[WOERTER+1][BUCHSTABEN+1], FILE *in, FILE *out, int *gez_woerter, int *dubles) {
    int b = 0, c = 0, i = 0, test = 0; char buffer[100] = {'\0'};	/* Zum Zwischenspeichern */
   
    while (((c = fgetc(in)) != EOF) && ((*gez_woerter) < WOERTER)) {	/* Schleife ausführen bis End Of File bzw. die max. Wörter erreicht wurde */
		/* Abfrage, ob es sich um einen der definierten Buchstaben handelt */
        if (	((c >= 65) && (c <= 90)) /* Großbuchstaben*/ || 
				((c >= 97) && (c <= 122)) /*Kleinbuchstaben*/ ||  
				(c == 252) /* ü */ || (c == 220) /* Ü */ || 
				(c == 228) /* ä */ || (c == 196) /* Ä */ || 
				(c == 246) /* ö */ || (c == 214) /* Ö */ || 
				(c == 223) /* ß */ ) {
			
			if ( ((c >= 65) && (c <= 90)) || (c == 220) || (c == 196) || (c == 214) ) /* Großbuchstabe? */ c = c + 32;	/* Großbuchstabe >> Kleinbuchstabe */
			
			buffer[i] = c;      /* Falls es ein Buchstabe ist in Buffer ablegen */
			i++;				/* und i +1, damit das nächste Zeichen hinter vorherigen abgelegt wird */

		} else {	/* Wenn kein Buchstabe: */
			buffer[i] = '\0';	/* Am Ende des Wortes '\0' */
			
			if((i <= BUCHSTABEN) && (buffer[0] != '\0')) {	/* Wenn Wort kürzer als vorgegeben */
				strcpy(tabelle[*gez_woerter], buffer);	/* String aus Buffer in Tabelle schreiben */
				(*gez_woerter)++;	/* Zähler für Wörter hochsetzen */
				
				if((*gez_woerter) > 1) {	/* Gibt es schon was zu vergleichen? */
					sort(tabelle, gez_woerter);		/* Simplesort Funktion */
					del(tabelle, gez_woerter, dubles);	/* Nach Dubles suchen Funktion */
					(*gez_woerter) = (*gez_woerter) - (*dubles);	/* Zähler für Wörter um Dubles verringern */
				}
			} if(i > BUCHSTABEN) { printf("Wort zu lang: %s\n", buffer); }
			i = 0; buffer[0] = '\0'; /* Wort zu lang - Links beginnen und "Array" leeren */
			
		}
	} if((c = fgetc(in)) != EOF) printf("Max Wortzahl erreicht.\n");
}
 
/* Main */
int main(int argc, char **argv) {
    char tabelle[WOERTER+1][BUCHSTABEN+1];    /* 2D Array für die Wörter - +1 für '\0' */
    int w = 0, b =0 , c = 0, gez_woerter = 0, dubles = 0;
    FILE *in = NULL, *out = NULL; 
        
    /* "Genug" Parameter eingegeben? */
    if (argc != 3) {
        printf("Fehler: Ein- und Ausgabedatei muessen uebergeben werden\n\n"); 
		getchar(); 
		return EXIT_FAILURE; 
	}
        
    /* Parameter übergeben */
    in = fopen (argv[1], "r");
    out = fopen (argv[2], "w");
    
	for(w = 0; w < WOERTER+1; w++) {
		for(b = 0; b < BUCHSTABEN+1; b++) {
			tabelle[w][b] = '\0';
		}
	}

    printf("01 - Aufgabe 2 - Woerterbuch\n\nMax Woerter: %d\nMax Buchstaben: %d\n\n", WOERTER, BUCHSTABEN);
 
    /* Ausgabe der Dateien im stdout */
    printf("Infile: %s\n", argv[1]); printf("Outfile: %s\n\n", argv[2]);
    
    /* Eingabeüberprüfungen */
    if ((in == NULL) || (out == NULL)) {				/* Können Dateien geöffnet werden? */
        printf("Fehler beim Oeffnen der Datei(en)\n");	/* Nein? Fehler und entsprechende Datei schließen */
        if(in != NULL) fclose(in);
        if(out != NULL) fclose(out);	
        return EXIT_FAILURE;		/* Fehler zurückgeben */
    }
    
    /* Auslesen, sortieren, dubles suchen, ... */
    auslesen(tabelle, in, out, &gez_woerter, &dubles); 	 

    /* Ausgabe des Wörterbuchs */
    fprintf(out, "Anzahl der Woerter: %d\n", gez_woerter);
	print(&gez_woerter, tabelle, out);
    printf("\n\nAusgabedatei angelegt.\n");
    
    /* Dateien schließen, Programm beenden*/
	fclose(out); fclose(in);
	printf("\n\n\n"); getchar(); return 0;
}
