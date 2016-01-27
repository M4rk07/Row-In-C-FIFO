
#include "redHeaderNiz.h"

// NIZ 2. NACIN
/* Funkcionisanje reda tako sto se svi elementi pomeraju jedno mesto ulevo
svaki put kada se element izbaci. Elementi se unose redom po indeksima.
Tako se uvek zna da je element sa indeksom 0 najduze u redu, a element sa najvecim
indeksom poslednji u redu.
*/

int brojElemenata=0;

// ******************************NIZ 2. NACIN******************************************************
// ubacuje element u niz ko opcije neogranicen
void unesiElementUNiz2 (char noviElement[]) {
	char c;
	int i=0;

	// proveri da li je u pitanju broj, ukoliko nije nece biti moguce traziti sumu svih elemenata
	do {
		c=noviElement[i++];

		if((c<'0' || c>'9') && c!='\0') {
			brojNebrojivihNiz++;
			break;
		}

	} while(c!='\0');

	strcpy(red[brojElemenata++], noviElement);

}

// izbacuje element iz niza kod opcije neogranicen
void izbaciElementNiz2 () {
	int i=0;
	char c;

	if(brojElemenata==0) printf("Red u nizu2 je prazan!\n");
	else {

		if(brojNebrojivihNiz>0) {
			do {
				c=red[0][i++];
				if((c<'0' || c>'9') && c!='\0') {
					break;
				}
				if(c=='\0') brojNebrojivihNiz--;
			} while (c!='\0');
		}

		for(i=0; i<brojElemenata-1; i++) {
			strcpy(red[i], red[i+1]);
		}
		brojElemenata--;
	}

}

// prikazuje red u nizu kod opcije neogranicen
void prikaziRedNiz2() {
	int i;
	
	printf("Red u nizu2: ");

	if(brojElemenata==0) printf("Red u nizu2 je prazan!\n\n");
	else {
		for(i=0; i<brojElemenata; i++) {
			if(i==0) printf("|");
			printf("%s", red[i]);
			if(i!=brojElemenata-1) printf(", ");
		}
		printf("\n\n");
	}
}

// ukoliko je moguce, racuna sumu svih elemenata u redu kod opcije neogranicen
void sumaSvihElemenataNiz2 () {

	if(brojNebrojivihNiz>0) printf("Nije moguce izracunati sumu svih elemenata u nizu2.\nNeki elementi nisu brojevi.\n\n");
	else {
		int i, suma=0;

		for(i=0; i<brojElemenata; i++) {
			suma+=atoi(red[i]);
		}

		printf("Suma svih elemenata u nizu2 je: %d\n\n", suma);
	}

}
// ************************************************************************************************