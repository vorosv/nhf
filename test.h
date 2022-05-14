#ifndef TEST_H
#define TEST_H




#include "menu.h"
#include "string.h"

#include <iostream>
#include <fstream>
#include "operatorok.h"
#include "gtest_lite.h"
#include "classes.h"
#include "memtrace.h"
#include "menu.h"
#include "string.h"


void teszt_fajlokbeolvasasa(tomb<Ugyfel>& kliensek, tomb<Ugyintezo>& dolgozok, Szerzodesek& nyilvantartas) ;


void teszt_faljokbairas(tomb<Ugyfel>& kliensek, tomb<Ugyintezo>& dolgozok, Szerzodesek& nyilvantartas) ;

void teszt_autentikacio(tomb<Ugyfel>& kliensek, tomb<Ugyintezo>& dolgozok) ;

//a kovetkezo tesztfuggvenyek parameterkent az aktualisan bejelentkezett felhasznalot/ugyintezot es minden adatat megkapjak+a nyilvantartast, ha azt kell modositani a muvelet soran

void teszt_egyenleglekerdezes(Szerzodesek& nyilvantartas, Ugyfel& user) ;

void teszt_fogyasztasbejelentes(Szerzodesek& nyilvantartas, Ugyfel& user) ;

void teszt_szamlcimmodositas(Ugyfel& user);


void teszt_dijbefizetes(Szerzodesek& nyilvantartas, Ugyfel& user);


void teszt_szamlakiallitas(Szerzodesek& nyilvantartas, Ugyintezo& user) ;

void teszt_szerzodeskotes(Szerzodesek& nyilvantartas, Ugyintezo& user);

void teszt_szerzodesfelmondas(Szerzodesek& nyilvantartas, Ugyintezo& user);


void teszt_ugyfelfelvetele(tomb<Ugyfel>& kliensek, Ugyintezo& user);

#endif // TEST_H
