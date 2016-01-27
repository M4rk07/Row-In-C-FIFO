
#include "redHeaderDatoteka.h"

// DATOTEKA 2. NACIN
/* Svaki put kada se izbacuje neki element svi ostali se pomeraju jedno mesto ulevo.
Isti princip kao kod reda preko niza 2. nacin, samo sa datotekom.
*/

int brojElemenataDat=0;

// ****************************DATOTEKA 2. NACIN***************************************************
// kreira datoteku2 kod opcije neogranicen
void kreirajDatoteku2 () {

	if((dat=fopen("red2.bin", "rb"))==NULL) {
		dat=fopen("red2.bin", "wb");
		fclose(dat);
	}

	if( (dat=fopen("red2podaci.bin", "rb"))!=NULL) {
		fread(&brojElemenataDat, sizeof(int), 1, dat);
		fread(&brojNebrojivihDatoteka, sizeof(int), 1, dat);
		fclose(dat);
	}

}

void sacuvajPodatkeDatoteka2 () {

	dat=fopen("red2podaci.bin", "wb");
	
	fwrite(&brojElemenataDat, sizeof(int), 1, dat);
	fwrite(&brojNebrojivihDatoteka, sizeof(int), 1, dat);
	fclose(dat);
}

// unosi element u datoteku2 kada je neogranicen
void unesiElementUDatoteku2 (char noviElement[]) {
	char c;
	int i=0;

	if((dat=fopen("red2.bin", "r+b"))==NULL) printf("Neuspesno otvaranje datoteke!\n");
	else {

		// ************************************
		// provera da li je ubacen element koji nije broj
		do {
			c=noviElement[i++];
			
			if((c<'0' || c>'9') && c!='\0') {
				brojNebrojivihDatoteka++;
				printf("%d\n", brojNebrojivihDatoteka);
				break;
			}

		} while(c!='\0');
		// ************************************

		fseek(dat, sizeof(char)*50*brojElemenataDat, SEEK_SET);
		fwrite(noviElement, sizeof(char)*50, 1, dat);
		fclose(dat);
		brojElemenataDat++;
	}

}

// izbacuje element iz datoteke2 kada je red neogranicen
void izbaciElementDatoteka2 () {
	char c;
	char podatak[50];
	int i=0;

	if(brojElemenataDat==0) printf("Red u datoteci2 je prazan! \n");
	else {

		dat=fopen("red2.bin", "r+b");

		// ******************************************
		// provera da li izbacuje element koji nije broj
		if(brojNebrojivihDatoteka>0) {
			fread(podatak, sizeof(char)*50, 1, dat);
			do {
				c=podatak[i++];
				if((c<'0' || c>'9') && c!='\0') {
					break;
				}
				if(c=='\0') brojNebrojivihDatoteka--;
			} while (c!='\0');
		}
		// ******************************************

		pomeriSveDatoteka2(1);

		fclose(dat);
		brojElemenataDat--;
	}
}
// funkcija za pomeranje svih elemenata kod rada sa datotekom2 kada je red neogranicen
int pomeriSveDatoteka2 (int i) {
	char podatak[50];
	fseek(dat, sizeof(char)*50*i, SEEK_SET);
	if(fread(podatak, sizeof(char)*50, 1, dat)==NULL) {
		return 1;
	}
	fseek(dat, sizeof(char)*50*(i-1), SEEK_SET);
	fwrite(podatak, sizeof(char)*50, 1, dat);

	pomeriSveDatoteka2(i+1);

	return 1;
}

void prikaziRedDatoteka2 () {
	int i;

	printf("Red u datoteci2: ");

	if(brojElemenataDat==0) printf("Red u datoteci2 je prazan!\n\n");
	else {
		if((dat=fopen("red2.bin", "rb"))==NULL) printf("Neuspesno otvarnje datoteke!\n");
		else {

			for(i=0; i<brojElemenataDat; i++) {
				if(i==0) printf("|");
				fread(podatak, sizeof(char)*50, 1, dat);
				printf("%s,", podatak);
			}

			putchar('\b');
			putchar(NULL);
			printf("\n\n");
			fclose(dat);
		}
	}
}

void sumaSvihElemenataDatoteka2 () {

	if(brojNebrojivihDatoteka>0) printf("Nije moguce izracunati sumu svih elemenata u datoteci2.\nNeki elementi nisu brojevi.\n\n");
	else {
		int i, suma=0;
		dat=fopen("red2.bin", "rb");

		for(i=0; i<brojElemenataDat; i++) {
			fread(podatak, sizeof(char)*50, 1, dat);
			suma+=atoi(podatak);
		}

		fclose(dat);

		printf("Suma svih elemenata u datoteci2 je: %d\n\n", suma);
	}

}
// ************************************************************************************************