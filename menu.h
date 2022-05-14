#ifndef MENU_H
#define MENU_h
#include "classes.h"
#include "operatorok.h"
#include "memtrace.h"
/**
*Kiírja a bejelntkezés elõtti menüt, bekéri a user típusát(Ugyfel vagy Ugyintezo
*@return kiválasztott menü sorszáma
*/
int udvozles_login();
/**
*   Bekéri a user azonosítóját és PIN-ját, majd átírja vele a paraméterként kapott referenciákat
*@param azon a user (inicializálatlan) azonosítója
*@param pin a user pin-je
*/
void aut(String& azon, unsigned long& pin);

/**
*   Beeolvas egy szerzõdés azonosítót
*@param azon  a keresett szerzodes (inicializálatlan) azonosítója
*/
void szerzodesbekeres(unsigned long& azon);

/**
*Kiírja a különbözõ teszteseteket tartalmazó menüt
*@return kiválasztott menü sorszáma
*/
int teszteset_valasztas();

/**
*Kilistázza, milyen mûveleteket végezhet a bejelntkezett ügyfél
*@return a kiválasztott menü sorszáma
*/
int ugyfel_todolist();

/**
*Kilistázza, milyen mûveleteket végezhet a bejelntkezett ügyfél
*@return a kiválasztott menü sorszáma
*/
int ugyintezo_todolist();




/**
*Kiírja a szerzõdés törlése elõtti megerõsítõ üzenetet/kérdést
*@return a kiválasztott menü sorszáma
*/
int biztosbenne();

/**
*Belolvassa a user kártya adatait, módoítja a paraméterként kapott változókat
*@param kártyaszám, név, kártya érvényessége, CVC/CVV kód, kifizetni kívánt összeg
*/
void kartyaadatok_be(unsigned long& kartyaszam, String& nev, Datum& lejarat, int& CVC, double& osszeg);

/**
*Bekéri/beolvassa az új ügyfél személyes adatait, módoítja a paraméterként kapott változókat
*@param PIN-kód, név, emial-cím, születési idõ, számlázási cím
*/
void ugyfeladatok_beker(unsigned long& pin, String& nev,String& email, Datum& szulido,Cim& szamlcim);
/**
*Kiírja a user opcióit egy mûvelet befejezése után
*@return a kiválasztott menü sorszáma
*/
int tovabbhasznal();

int kikapcsole();

#endif // MENU_H
