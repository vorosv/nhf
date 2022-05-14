#include "muveletek.h"
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


String azon_sorsol() {
    srand(time(0));
    char t[] = {'1', '2', '3', '4','5', '6', '7', '8','9', 'A', 'B', 'C','D', 'E', 'F', 'G','H', 'I', 'J', 'K','L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S','T','U', 'V', 'W', 'X', 'Y', 'Z'};
    String azon;
    char c;
    int idx;
    for(int i = 0; i < 6; i++) {
        idx = rand()%35;
        c =  t[idx];
        azon = azon +c;

    }
    return azon;
}

unsigned long szerzazon_sorsol() {
    srand(time(0));
    unsigned long azon = 0;
    int szamjegy;
    for (int i = 0; i < 9; ++i) {
        szamjegy = rand()%10;
        azon*=10;
        azon+=szamjegy;
    }
    return azon;


}

int ugyfel_szerzodese(Szerzodesek& nyilvantartas, String ugyfelazon) {
    bool sikeresszamlaazon = false;
    int szerzodes_idx;
    unsigned long szamlaazon;
    while(!sikeresszamlaazon) {
            szerzodesbekeres(szamlaazon);
            szerzodes_idx = nyilvantartas.search(szamlaazon);
            if (szerzodes_idx < 0) {
                    std::cout << "Hibas szerzodes azonosito!" << std::endl;
            }
            else {
                if (ugyfelazon == nyilvantartas[szerzodes_idx].getUgyfelazon()) sikeresszamlaazon = true;
                else std::cout << "Hibas szerzodes azonosito" << std::endl;
            }

    }
    return szerzodes_idx;
}



void tombok_fajlba(tomb<Ugyfel>& kliensek, tomb<Ugyintezo>& dolgozok, Szerzodesek& nyilvantartas) {
        std::ofstream f;
        f.open("ugyfelek.txt");
        kliensek.fajlbair(f);
        f.close();

        f.open("ugyintezok.txt");
        dolgozok.fajlbair(f);
        f.close();

         f.open("szerzodesek.txt");
        nyilvantartas.fajlbair(f);
        f.close();
}

void tombok_fajlbol(tomb<Ugyfel>& kliensek, tomb<Ugyintezo>& dolgozok, Szerzodesek& nyilvantartas){
    //Ugyfelek beolvasas
        Ugyfel uj1;
        std::ifstream file("ugyfelek.txt");
        (file >> uj1).ignore(1);
        kliensek.add(uj1);
        while (!file.eof()) {
            (file >> uj1).ignore(1);
              kliensek.add(uj1);
        }
        file.close();
        //Ugyintezok beolvasas
        Ugyintezo uj2;
        file.open("ugyintezok.txt");
        (file >> uj2).ignore(1);
        //std::cout << uj2 << std::endl;
        dolgozok.add(uj2);
        while (!file.eof()) {
            (file >> uj2).ignore(1);
            //std::cout << uj2 << std::endl;
            dolgozok.add(uj2);

        }
        file.close();
        //Szerzodesek beolvasas
        Szerzodes uj3;
        file.open("szerzodesek.txt");
        (file >> uj3).ignore(1);
        nyilvantartas.add(uj3);
        //std::cout << uj3 << std::endl;
        while (!file.eof()) {
            (file >> uj3).ignore(1);
            nyilvantartas.add(uj3);
            //std::cout << uj3 << std::endl;
        }

        file.close();
}

void szamlakiallit(tomb<Ugyfel>& kliensek, tomb<Ugyintezo> dolgozok, Szerzodesek& nyilvantartas, unsigned long szerzodes_idx, String ugyintezo_azon) {
    String filename("szamla_");
    filename = filename + nyilvantartas[szerzodes_idx].getUgyfelazon();
    filename = filename + String(".txt");
    int ugyfel_idx = kliensek.search(nyilvantartas[szerzodes_idx].getUgyfelazon());
    int ugyintezo_idx = dolgozok.search(ugyintezo_azon);
    std::ofstream file(filename.c_str());
    file << "*******************************Szamla*******************************" << std::endl << std::endl;
    file << "Ertekesito:            Meseorszagi Villamos Muvek" << std::endl;
    file << "Vevo neve:             " << kliensek[ugyfel_idx].getNev() << std::endl;
    file << "Szamlazasi cim:        " << kliensek[ugyfel_idx].getSzamlcim() << std::endl;
    file << "Fizetendo tetel:       Aramfogyasztas: " << nyilvantartas[szerzodes_idx].getUtolsofogy().getErtek() << " kWh" << std::endl;
    file << "Fogyasztas helye:      " << nyilvantartas[szerzodes_idx].getFogyhelye() << std::endl;
    file << "Datum:                 " << nyilvantartas[szerzodes_idx].getUtolsofogy().getNap() << std::endl;
    file << "Osszeg:                " << nyilvantartas[szerzodes_idx].getEgyenleg() << " HUF" <<std::endl;
    file << "Fizetes modja:         " << nyilvantartas[szerzodes_idx].getFizetesmod() << std::endl;
    file << "Kiallito:              " << dolgozok[ugyintezo_idx].getNev() << " " << dolgozok[ugyintezo_idx].getBeosztas() << std::endl << std::endl;
    file << "********************************************************************";
    file.close();


 }



