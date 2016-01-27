#include "redHeaderZajednicke.h"

// promenljive za rad sa datotekom
FILE *dat;
int brojNebrojivihDatoteka;

int glavaRbr, repRbr, mestoRbr; // datoteka 1. nacin
int brojElemenataDat; // datoteka 2. nacin
int glavaDat, repDat, prazanDat; // datoteka 3. nacin

// struktura za rad sa datotekom 1. nacin
struct element1 {
	char podatak[50];
	int rbr;
	int izbacen;
};

// DATOTEKA 1. NACIN
/* Svakom novom elementu dodeljuje se odredjeni redni broj. Promenljiva glavaRbr
predstavlja redni broj elementa koji je najduze u redu, a repRbr poslednjeg elementa.
Ako je rec o ogranicenom redu, kada je njihova razlika jednaka kapacitetu reda, red je pun.
Kada se god neki element izbaci obelezava se da je izbacen i u sledecem ubacivanju
preko njega se upisuje novi element.
*/
void kreirajDatoteku1();
void sacuvajPodatkeDatoteka1();
void unesiElementUDatoteku1 (char noviElement[]);
void izbaciElementDatoteka1 ();
void prikaziRedDatoteka1 ();
//**************************************************
// DATOTEKA 2. NACIN
/* Svaki put kada se izbacuje neki element svi ostali se pomeraju jedno mesto ulevo.
Isti princip kao kod reda preko niza 2. nacin, samo sa datotekom.
*/
void kreirajDatoteku2 ();
void sacuvajPodatkeDatoteka2 ();
void unesiElementUDatoteku2 (char noviElement[]);
void izbaciElementDatoteka2 ();
int pomeriSveDatoteka2 (int i);
void prikaziRedDatoteka2 ();
void sumaSvihElemenataDatoteka2 ();
//**************************************************
// DATOTEKA 3. NACIN
/* Glava prati element koji je najduze u redu, a rep koji je poslednji usao.
Primenjen je kada je kapacitet reda ogranicen.
*/
void kreirajDatoteku3 ();
void sacuvajPodatkeDatoteka3 ();
void unesiElementUDatoteku3(char noviElement[]);
void izbaciElementDatoteka3();
void prikaziRedDatoteka3();
//**************************************************