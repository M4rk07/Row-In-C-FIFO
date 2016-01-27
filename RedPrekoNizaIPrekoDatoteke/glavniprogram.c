#include "redHeaderNiz.h"
#include "redHeaderDatoteka.h"

// ****************************************************************************
void glavniMeni() {
	int izbor;
	char prioritetIzbor[5];

	do {
		// meni za odabir opcije ogranicen ili neogranicen red
		printf("Izaberite kakav red zelite da kreirate: \n");
		printf("1-Ogranicen\n");
		printf("2-Neogranicen\n");
		printf("Vas izbor: ");
		scanf("%d", &izbor);
		fflush(stdin);
		// ukoliko je nepoznata opcija poruka o gresci
		if(izbor!=1 && izbor!=2) printf("Nepoznata opcija!\n");

	} while(izbor!=1 && izbor!=2);

	podesavanjaZaOgranicenostReda(izbor);
	
	printf("Podesavanja uspesno zavrsena!\n");

	// glavni meni koji se vrti dok se ne odabere izlaz iz programa
	do {
		printf("\n----GLAVNI MENI----");
		printf("\n\nIzaberite opciju: \n");
		printf("1-Unesi element\n");
		printf("2-Obrisi element\n");
		printf("3-Prikazi red\n");
		if(kapacitet==0) printf("4-Suma svih elemenata u redu\n");
		printf("0-Izlaz\n");
		printf("Vas izbor: ");
		scanf("%d", &izbor);
		fflush(stdin);

		if(izbor==1) pozoviUnosElementa();

		else if(izbor==2) pozoviIzbacivanjeElementa();

		else if(izbor==3) pozoviPrikazivanjeReda();


		else if(kapacitet==0 && izbor==4) {
			sumaSvihElemenataNiz2 (); 
			sumaSvihElemenataDatoteka2();
			pressEnter();
		}

		else if(izbor==0) pozoviIzlazIzPrograma();

		else printf("Nepoznata opcija!\n");

	} while(izbor!=0);

}
// ****************************************************************************

int main(void) {

	glavniMeni();

	return 1;
}