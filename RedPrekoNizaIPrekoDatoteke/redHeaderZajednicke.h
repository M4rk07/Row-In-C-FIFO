#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kapacitet; // promenljiva za cuvanje podatka o kapacitetu reda
int preskUnosKap; // promenljiva za proveru da li je kapacitet ranije unosen
char podatak[50]; // za ucitavanje novog elementa

void glavniMeni(); // glavni meni programa
void pozoviUnosElementa(); // poziva odgovarajuce funkcije za unos elementa
void pozoviIzbacivanjeElementa(); // poziva odgovarajuce funckije za izbacivanje elementa
void pozoviPrikazivanjeReda(); // poziva odgovarajuce funkcije za prikazivanje reda
void pozoviIzlazIzPrograma(); // poziva odgovarajuce funkcije za cuvanje podataka pre izlaza iz programa
void podesavanjaZaOgranicenostReda(int izbor); // podesavanja vezana za ogranicenost reda na pocetku
void pressEnter(); // nakon pritiska entera nastavlja se sa programom