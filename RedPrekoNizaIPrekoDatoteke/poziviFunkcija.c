#include "redHeaderDatoteka.h"
#include "redHeaderNiz.h"

void pozoviUnosElementa () {
	printf("Unesite element: ");
	gets(podatak);
	fflush(stdin);
				
	// ukoliko je red neogranicen
	if(kapacitet==0) {
		unesiElementUNiz2(podatak);
		unesiElementUDatoteku2(podatak);
	}
	// ukoliko je red ogranicen
	else {
		unesiElementUNiz1(podatak);
		unesiElementUDatoteku1(podatak);
		unesiElementUDatoteku3(podatak);
	}

	printf("Element je uspesno ubacen u red!\n\n");
	pressEnter();
}

void pozoviIzbacivanjeElementa () {
	//ukoliko je red neogranicen
	if(kapacitet==0) {
		izbaciElementNiz2();
		izbaciElementDatoteka2();
	}
	// ukoliko je red ogranicen
	else {
		izbaciElementNiz1();
		izbaciElementDatoteka1();
		izbaciElementDatoteka3();
	}

	printf("Element je uspesno izbacen iz reda!\n\n");
	pressEnter();
}

void pozoviPrikazivanjeReda() {
	//ukoliko je red neogranicen
	if(kapacitet==0) {
		prikaziRedNiz2();
		prikaziRedDatoteka2();
	}
	// ukoliko je red ogranicen
	else {
		prikaziRedNiz1();
		prikaziRedDatoteka1();
		prikaziRedDatoteka3();
	}

	pressEnter();
}

void pozoviIzlazIzPrograma() {
	//ukoliko je red neogranicen
	if(kapacitet==0) {
		sacuvajPodatkeDatoteka2();
	}
	// ukoliko je red ogranicen
	else {
		sacuvajPodatkeDatoteka1();
		sacuvajPodatkeDatoteka3();
	}
}

void podesavanjaZaOgranicenostReda(int izbor) {
	brojNebrojivihNiz=0; // postavi za nizove na 0, jer nema nijednog elementa
	brojNebrojivihDatoteka=0; // postavi za datoteke na 0 podrazumevano

	if(izbor==1) {
		kreirajDatoteku1();
		kreirajDatoteku3();

		if(preskUnosKap!=1) {
			do{
			printf("Unesite kapacitet reda: ");
			scanf("%d", &kapacitet);
			fflush(stdin);

			if(kapacitet==0) printf("Kapacitet mora biti veci od 0.\n");

			} while(kapacitet==0);
		}

	}
	else if(izbor==2) {
		kreirajDatoteku2();
	}
}

void pressEnter() {
	char enter;
	printf("\nPritisnite ENTER za nastavak...\n");
	scanf("%c", &enter);
	fflush(stdin);
}