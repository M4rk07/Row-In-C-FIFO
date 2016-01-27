
#include "redHeaderDatoteka.h"

// DATOTEKA 1. NACIN
/* Svakom novom elementu dodeljuje se odredjeni redni broj. Promenljiva glavaRbr
predstavlja redni broj elementa koji je najduze u redu, a repRbr poslednjeg elementa.
Ako je rec o ogranicenom redu, kada je njihova razlika jednaka kapacitetu reda, red je pun.
Kada se god neki element izbaci obelezava se da je izbacen i u sledecem ubacivanju
preko njega se upisuje novi element.
*/

int glavaRbr=0, repRbr=0, mestoRbr=0;

// ****************************DATOTEKA 1. NACIN***************************************************
// kreira datoteku1 kod opcije ogranicen
void kreirajDatoteku1() {
	int pomKapacitet;

	if( (dat=fopen("red1.bin", "rb"))==NULL) {
		dat=fopen("red1.bin", "wb");
	}

	fclose(dat);

	if( (dat=fopen("red1podaci.bin", "rb"))!=NULL) {
		preskUnosKap=1;

		fread(&glavaRbr, sizeof(int), 1, dat);
		fread(&repRbr, sizeof(int), 1, dat);
		fread(&mestoRbr, sizeof(int), 1, dat);
		fread(&kapacitet, sizeof(int), 1, dat);
		fclose(dat);
	}
}

// cuva podatke pre zatvaranja programa u datoteci1 kada je red ogranicen
void sacuvajPodatkeDatoteka1() {
	
	dat=fopen("red1podaci.bin", "wb");
	
	fwrite(&glavaRbr, sizeof(int), 1, dat);
	fwrite(&repRbr, sizeof(int), 1, dat);
	fwrite(&mestoRbr, sizeof(int), 1, dat);
	fwrite(&kapacitet, sizeof(int), 1, dat);
	fclose(dat);
}

// unosi element u datoteku kada je ogranicen
void unesiElementUDatoteku1 (char noviElement[]) {
	struct element1 s, m;
	int ubacen=0;

	if(repRbr-glavaRbr==kapacitet) printf("Red u datoteci1 je pun!\n");

	else {
		// unos podataka
		strcpy(s.podatak, noviElement);
		s.rbr=repRbr;
		s.izbacen=0;

		dat=fopen("red1.bin", "r+b");
		while(fread(&m, sizeof(struct element1), 1, dat)!=NULL) {
			if(m.izbacen==1) {
				fseek(dat, sizeof(struct element1)*(-1), SEEK_CUR);
				fwrite(&s, sizeof(struct element1), 1, dat);
				ubacen=1;
				break;
			}
		}
		if(ubacen==0) {
			fseek(dat, sizeof(struct element1)*mestoRbr, SEEK_SET);
			fwrite(&s, sizeof(struct element1), 1, dat);
			mestoRbr++;
		}
		fclose(dat);
		repRbr++;
	}

}

// izbacuje element iz datoteke kod opcije ogranicen
void izbaciElementDatoteka1 () {
	struct element1 s;
	if(glavaRbr==repRbr) printf("Red u datoteci1 je prazan!\n");
	else {
		if( (dat=fopen("red1.bin", "r+b")) ==NULL) printf("Doslo je do greske pri otvaranju datoteke!\n");
		else {
			while(fread(&s, sizeof(struct element1), 1, dat)!=NULL) {
				if(s.rbr==glavaRbr) {
					s.izbacen=1;
					fseek(dat, sizeof(struct element1)*(-1), SEEK_CUR);
					fwrite(&s, sizeof(struct element1), 1, dat);
					glavaRbr++;
					break;
				}
			}
			fclose(dat);
		}
	}
}

// prikazuje red u datoteci kod opcije ogranicen
void prikaziRedDatoteka1 () {
	struct element1 s;
	int i;

	printf("Red u datoteci1: ");

	if(glavaRbr==repRbr) printf("Red u datoteci1 je prazan!\n\n");
	else {
		if((dat=fopen("red1.bin", "rb"))==NULL) printf("Neuspesno otvaranje datoteke!\n");
		else {

			while(fread(&s, sizeof(struct element1), 1, dat)!=NULL) {
				if(s.rbr==glavaRbr) printf("|");
				if(s.izbacen==0) printf("%s,", s.podatak);
			}

				putchar('\b');
				putchar(NULL);
				printf("\n\n");

			fclose(dat);
		}
	}
}
// ************************************************************************************************