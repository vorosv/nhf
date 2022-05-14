#ifndef MENU_H
#define MENU_h
#include "classes.h"
#include "operatorok.h"
#include "memtrace.h"
/**
*Ki�rja a bejelntkez�s el�tti men�t, bek�ri a user t�pus�t(Ugyfel vagy Ugyintezo
*@return kiv�lasztott men� sorsz�ma
*/
int udvozles_login();
/**
*   Bek�ri a user azonos�t�j�t �s PIN-j�t, majd �t�rja vele a param�terk�nt kapott referenci�kat
*@param azon a user (inicializ�latlan) azonos�t�ja
*@param pin a user pin-je
*/
void aut(String& azon, unsigned long& pin);

/**
*   Beeolvas egy szerz�d�s azonos�t�t
*@param azon  a keresett szerzodes (inicializ�latlan) azonos�t�ja
*/
void szerzodesbekeres(unsigned long& azon);

/**
*Ki�rja a k�l�nb�z� teszteseteket tartalmaz� men�t
*@return kiv�lasztott men� sorsz�ma
*/
int teszteset_valasztas();

/**
*Kilist�zza, milyen m�veleteket v�gezhet a bejelntkezett �gyf�l
*@return a kiv�lasztott men� sorsz�ma
*/
int ugyfel_todolist();

/**
*Kilist�zza, milyen m�veleteket v�gezhet a bejelntkezett �gyf�l
*@return a kiv�lasztott men� sorsz�ma
*/
int ugyintezo_todolist();




/**
*Ki�rja a szerz�d�s t�rl�se el�tti meger�s�t� �zenetet/k�rd�st
*@return a kiv�lasztott men� sorsz�ma
*/
int biztosbenne();

/**
*Belolvassa a user k�rtya adatait, m�do�tja a param�terk�nt kapott v�ltoz�kat
*@param k�rtyasz�m, n�v, k�rtya �rv�nyess�ge, CVC/CVV k�d, kifizetni k�v�nt �sszeg
*/
void kartyaadatok_be(unsigned long& kartyaszam, String& nev, Datum& lejarat, int& CVC, double& osszeg);

/**
*Bek�ri/beolvassa az �j �gyf�l szem�lyes adatait, m�do�tja a param�terk�nt kapott v�ltoz�kat
*@param PIN-k�d, n�v, emial-c�m, sz�let�si id�, sz�ml�z�si c�m
*/
void ugyfeladatok_beker(unsigned long& pin, String& nev,String& email, Datum& szulido,Cim& szamlcim);
/**
*Ki�rja a user opci�it egy m�velet befejez�se ut�n
*@return a kiv�lasztott men� sorsz�ma
*/
int tovabbhasznal();

int kikapcsole();

#endif // MENU_H
