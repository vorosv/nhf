#ifndef MUVELETEK_H
#define MUVELETEK_H
#include "classes.h"
#include "operatorok.h"
#include "memtrace.h"



String azon_sorsol();


void tombok_fajlba(tomb<Ugyfel>& kliensek, tomb<Ugyintezo>& dolgozok, Szerzodesek& nyilvantartas);
void tombok_fajlbol(tomb<Ugyfel>& kliensek, tomb<Ugyintezo>& dolgozok, Szerzodesek& nyilvantartas);

unsigned long szerzazon_sorsol();

void szamlakiallit(tomb<Ugyfel>& kliensek, tomb<Ugyintezo> dolgozok, Szerzodesek& nyilvantartas, unsigned long szerzodes_idx, String ugyintezo_azon);

int ugyfel_szerzodese(Szerzodesek& nyilvantartas, String ugyfelazon);

#endif // MUVELETEK_H
