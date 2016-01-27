
#include "redHeaderNiz.h"

// NIZ 1. NACIN
/* Ilustruje rad sa redom po principu glava-rep, pri tome red je ogranicenog kapaciteta.
Glava prati element koji je najduze u redu, rep prati poslednji ubacen.
*/

int glava=0, rep=0, prazan=0;

// ************************************************************************************************
// *********************** NIZ 1. NACIN ***********************************************************
// ubacuje element u niz kod opcije ogranicen
void unesiElementUNiz1 (char noviElement[]) {

	if((rep+1==glava || (rep==kapacitet-1 && glava==0)) && kapacitet!=0) { // ukoliko je red pun
		printf("Red u nizu1 je pun.\n\n");
	}
	else {

		if(prazan==0) { // ukoliko je prazan
			strcpy(red[glava], noviElement);
			prazan=1;
		}
		else { // ukoliko nije prazan
			// ako je rep stigao do poslednjeg indeksa sledeci je 0, u suprotnom ++
			(rep==kapacitet-1 && kapacitet!=0) ? rep=0 : rep++;
			strcpy(red[rep], noviElement);
		}

	}

}

// izbacuje element iz niza kod opcije ogranicen
void izbaciElementNiz1() {
	int i=0;
	int signal=0;

	if(glava==rep) { // ako su glava i rep na istom indeksu red je prazan
		printf("Red u nizu1 je prazan!\n");
		prazan=0;
	}
	if(prazan!=0) {

			glava==kapacitet-1 ? glava=0 : glava++;	
		
	}

}

// prikazuje red u nizu kod opcije ogranicen
void prikaziRedNiz1() {
	int i;

	printf("Red u nizu1: ");

	if(prazan==0) printf("Red u nizu1 je prazan!\n\n");
	else {
		// ************************
		// prolazi kroz ceo red i ispisuje ga
		for(i=glava; rep+1==glava ? i!=rep : i!=rep+1; i++) {
			if(i>kapacitet-1) i=0;
			if(i==glava) printf("|");
			printf("%s,", red[i]);
		}

		if(rep+1==glava) {
			printf("%d,", red[i]);
		}
		putchar('\b');
		putchar(NULL);
		printf("\n\n");
		// ************************
	}
}
// ************************************************************************************************