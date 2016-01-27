#include "redHeaderZajednicke.h"

// promenljive za rad sa nizom
char red[100][50];
int brojNebrojivihNiz;

int glava, rep, prazan; // niz 1. nacin
int brojElemenata; // niz 2. nacin

//**************************************************
// NIZ 1. NACIN
/* Ilustruje rad sa redom po principu glava-rep, pri tome red je ogranicenog kapaciteta.
Glava prati element koji je najduze u redu, rep prati poslednji ubacen.
*/
void unesiElementUNiz1 (char noviElement[]);
void izbaciElementNiz1();
void prikaziRedNiz1();
//**************************************************
// NIZ 2. NACIN
/* Funkcionisanje reda tako sto se svi elementi pomeraju jedno mesto ulevo
svaki put kada se element izbaci. Elementi se unose redom po indeksima.
Tako se uvek zna da je element sa indeksom 0 najduze u redu, a element sa najvecim
indeksom poslednji u redu.
*/
void unesiElementUNiz2 (char noviElement[]);
void izbaciElementNiz2 ();
void prikaziRedNiz2();
void sumaSvihElemenataNiz2 ();
//**************************************************