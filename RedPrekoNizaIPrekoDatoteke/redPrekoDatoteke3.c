
#include "redHeaderDatoteka.h"

// DATOTEKA 3. NACIN
/* Glava prati element koji je najduze u redu, a rep koji je poslednji usao.
Primenjen je kada je kapacitet reda ogranicen.
*/

int glavaDat=0, repDat=0, prazanDat=0;

// *************************DATOTEKA 3. NACIN******************************************************
// kreira datoteku3 kada je red ogranicen
void kreirajDatoteku3 () {

	if((dat=fopen("red3.bin", "rb"))==NULL) {
		dat=fopen("red3.bin", "wb");
		fclose(dat);
	}

	if( (dat=fopen("red3podaci.bin", "rb"))!=NULL) {
		preskUnosKap=1;

		fread(&glavaDat, sizeof(int), 1, dat);
		fread(&repDat, sizeof(int), 1, dat);
		fread(&prazanDat, sizeof(int), 1, dat);
		fread(&kapacitet, sizeof(int), 1, dat);
		fclose(dat);
	}

}

void sacuvajPodatkeDatoteka3 () {

	dat=fopen("red3podaci.bin", "wb");
	
	fwrite(&glavaDat, sizeof(int), 1, dat);
	fwrite(&repDat, sizeof(int), 1, dat);
	fwrite(&prazanDat, sizeof(int), 1, dat);
	fwrite(&kapacitet, sizeof(int), 1, dat);
	fclose(dat);
}
// unosi element u datoteku3 kada je red ogranicen
void unesiElementUDatoteku3(char noviElement[]) {
	FILE *dat;

		if(repDat+1==glavaDat || (repDat==kapacitet-1 && glavaDat==0)) {
			printf("Red u datoteci3 je pun!\n");
		}
		else {
			dat=fopen("red3.bin", "rb+");

			if(prazanDat==0) {
				fseek(dat, sizeof(char)*50*glavaDat, SEEK_SET);
				prazanDat=1;
			}
			else {
				repDat==kapacitet-1 ? repDat=0 : repDat++;
				fseek(dat, sizeof(char)*50*repDat, SEEK_SET);
			}

			fwrite(noviElement, sizeof(char)*50, 1, dat);

			fclose(dat);
	}
	
}

// izbacuje element iz reda u datoteci3 kada je red ogranicen
void izbaciElementDatoteka3() {
	if(glavaDat==repDat) {
		printf("Red u datoteci3 je prazan!\n");
		prazanDat=0;
	}
	if(prazanDat!=0) {
		glavaDat==kapacitet-1 ? glavaDat=0 : glavaDat++;
	}
}

// prikazuje elemente reda u datoteci3 kada je red ogranicen
void prikaziRedDatoteka3() {
	FILE *dat;
	char podatak[50];
	int i;

	printf("Red u datoteci3: ");

	if(prazanDat==0) printf("Red u datoteci3 je prazan!\n\n");
	else {
		dat=fopen("red3.bin", "rb");

		// ************************
		// prolazi kroz ceo red i ispisuje ga
		for(i=glavaDat; repDat+1==glavaDat ? i!=repDat : i!=repDat+1; i++) {
			if(i>kapacitet-1) i=0;
			if(i==glavaDat) printf("|");
			fseek(dat, sizeof(char)*50*i, SEEK_SET);
			fread(podatak, sizeof(char)*50, 1, dat); 
			printf("%s,", podatak);
		}

		if(repDat+1==glavaDat) {
			fseek(dat, sizeof(char)*50*i, SEEK_SET);
			fread(podatak, sizeof(char)*50, 1, dat); 
			printf("%s,", podatak);
		}

		putchar('\b');
		putchar(NULL);
		printf("\n\n");
		// ************************
		fclose(dat);
	}

}
// ************************************************************************************************