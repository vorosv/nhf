#include "gtest_lite.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "string.h"
#include "operatorok.h"
#include "gtest_lite.h"
#include "classes.h"

#include "menu.h"
#include "memtrace.h"





int udvozles_login() {
    std::cout << "*************Udvozoljuk a Meseorszagi Villamos Muvek online ugyintezo feluleten***************" << std::endl;
    std::cout << "Kerjuk valasszon az alabbi opciok kozul a megfelelo sorszam beutesevel!" << std::endl;
    std::cout << "1. Belepes a feluletre ugyfelkent" << std::endl;
    std::cout << "2. Belepes a feluletre ugyintezokent" << std::endl;
    std::cout << "3. Felulet bezarasa" << std::endl;
    int sorszm;
    std::cin >> sorszm;
    return sorszm;

}

void aut(String& azon, unsigned long& pin) {
    //system("CLS");
    std::cout << "Kerjuk adja meg 6-jegyu azonositojat es 4-jegyu PIN-kodjat!" << std::endl;
    std::cout << "Felhasznalo-azonosito: ";
    std::cin >> azon;
    std::cout << "PIN-kod: " ;
    std::cin >> pin;
}


void szerzodesbekeres(unsigned long& azon) {
    //system("CLS");
    std::cout << "Kerjuk adja meg a szerzodesehez tartozo 9-jegyu azonositot!" << std::endl;
    std::cout << "Szerzodes-azonosito: ";
    std::cin >> azon;
}

//void szamlakiir(std::ofstream& os, Szerzodes kiirando);
/**
*   Uj ugyfelhez random 6-jegyu azonositot general
*/

int teszteset_valasztas() {
    int sorszam;
    std::cout << "Valassz az alabbi muveletek kozul" << std::endl;
    std::cout << "1. autentikacio tesztelese" << std::endl;
    std::cout << "2. egyenleglekerdezes tesztelese" << std::endl;
    std::cout << "3. szamlcim modositas tesztelese" << std::endl;
    std::cout << "4. dijbefizetes tesztelese" << std::endl;
    std::cout << "5. fogyasztas bejelentes tesztelese" << std::endl;
    std::cout << "6. szamlakiallitas tesztelese" << std::endl;
    std::cout << "7. szerzodeskotes tesztelese" << std::endl;
    std::cout << "8. szerzodesfelmondas tesztelese" << std::endl;
    std::cout << "9. ugyfelfelvetel tesztelese" << std::endl;
    std::cout << "10. nyilvantartas fajlba mentesenek tesztelese" << std::endl;
    std::cin >> sorszam;
    return sorszam;

}

int ugyfel_todolist() {
    int sorszam;
    std::cout << "Kerjuk valasszon az alabbi tevekenysegek kozul a megfelelo sorszam beutesevel!" << std::endl;
    std::cout << "1. Egyenleglekerdezes" << std::endl;
    std::cout << "2. Szamlazasi cim modositasa" << std::endl;
    std::cout << "3. Uj fogyasztas bejelentese" << std::endl;
    std::cout << "4. Szolgaltatasi dij befizetese" << std::endl;
    std::cin >> sorszam;
    return sorszam;

}

int ugyintezo_todolist() {
    int sorszam;
    std::cout << "Kerjuk valasszon az alabbi tevekenysegek kozul a megfelelo sorszam beutesevel!" << std::endl;
    std::cout << "1. Uj ugyfel felvetele a nyilvantartasba" << std::endl;
    std::cout << "2. Szamlakiallitas" << std::endl;
    std::cout << "3. Uj szerzodes kotese" << std::endl;
    std::cout << "4. Meglevo szerzodes felbontasa" << std::endl;
    std::cin >> sorszam;
    return sorszam;

}

/*void szamlakiir(std::ofstream& os, Szerzodes kiirando) {


}*/

 void ugyfeladatok_beker(unsigned long& pin, String& nev,String& email, Datum& szulido,Cim& szamlcim) {
    String kernev, veznev;
    std::cout << "Kerjuk adja meg a felvenni kivant ugyfel adatait!" << std::endl;
    std::cout << "4-jegyu PIN-kod: " ;
    std::cin >> pin;
    std::cout << "Nev: ";
    std::cin >> veznev >> kernev;
    std::cout << "Email-cim: " ;
    std::cin >> email;
    std::cout << "Szuletesi ido: " ;
    std::cin >> szulido;
    std::cout << "Szamlazasi cim: " ;
    std::cin >> szamlcim;
    nev = veznev + ' ';
    nev = nev + kernev;
 }


 int biztosbenne() {
    int sorsz;
    std::cout << "Biztos benne, hogy fel akarja mondani a szerzodeset?" << std::endl;
    std::cout << "1. Igen, felmondom a jelenlegi szerzodesem." << std::endl;
    std::cout << "2. Megse." << std::endl;
    std::cin >> sorsz;
    return sorsz;
}




void kartyaadatok_be(unsigned long& kartyaszam, String& nev, Datum& lejarat, int& CVC, double& osszeg) {
    String kernev, veznev;
    std::cout << "Kerjuk adja meg a bankartyaja adatait!" << std::endl;
    std::cout << "A kartyatulajdonos neve: " ;
    std::cin >> veznev >> kernev;
    std::cout << "Lejarati datum: ";
    std::cin >> lejarat;
    std::cout << "CVC/CVV kod: " ;
    std::cin >> CVC;
    std::cout << "A befizetendo osszeg: " ;
    std::cin >> osszeg;
    nev = veznev + ' ';
    nev = nev + kernev;
 }


 int tovabbhasznal() {
     std::cout << std::endl << "--------------------------------------------------------------------" << std::endl << std::endl;
     std::cout << "Kerjuk valasszon az alabbi opciok kozul a megfelelo sorszam beutesevel!" << std::endl;
     std::cout << "1. Ugyintezes folytatasa" << std::endl;
     std::cout << "2. Kijelentkezes" << std::endl;
     int sorszm;
     std::cin >> sorszm;
     return sorszm;

 }

 int kikapcsole() {
    std::cout << std::endl << "--------------------------------------------------------------------" << std::endl << std::endl;
     std::cout << "Kerjuk valasszon az alabbi opciok kozul a megfelelo sorszam beutesevel!" << std::endl;
     std::cout << "1. Bejelentkezes a felhasznaloi feluletre " << std::endl;
     std::cout << "2. Felhasznaloi felulet bezarasa" << std::endl;
     int sorszm;
     std::cin >> sorszm;
     return sorszm;

 }


