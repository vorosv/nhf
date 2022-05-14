#include <iostream>
#include <fstream>
#include "operatorok.h"
#include "gtest_lite.h"
#include "classes.h"
#include "test.h"
#include "menu.h"
#include "string.h"
#include "memtrace.h"

void teszt_fajlokbeolvasasa(tomb<Ugyfel>& kliensek, tomb<Ugyintezo>& dolgozok, Szerzodesek& nyilvantartas) { //it megkapja a tesztfuggveny, milyen objektumokba olvasson be/tombot toltson fel
    TEST(FAJLKEZELES, ugyfel_beolvasas) {

      std::ifstream file("ugyfelek.txt");
      EXPECT_EQ(true, file.is_open()) << "fajl megnyitasa sikertelen";
      Ugyfel uj;
      int db = 0;
      while (!file.eof()) {
        file >> uj  ;                                              //egy sor=ugyfel beolvasas; lehetne file.good()??
        kliensek.add(uj);
        EXPECT_EQ(++db, kliensek.getN()) << "Sikertelen ugyfelfelvetel - Ugyfelek::add() fv nem mukodik";          //HIBA, ha nem novekedett a tömb mérete
      }
      file.close();

    } END

    TEST(FAJLKEZELES, ugyintezo_beolvasas) {

      std::ifstream file("ugyintezok.txt");
      EXPECT_EQ(true, file.is_open()) << "fajl megnyitasa sikertelen";
      Ugyintezo uj;
      int db = 0;
     while (!file.eof()) {
        file >> uj;        //while (file != EOF())??????????????
        dolgozok.add(uj);
        EXPECT_EQ(++db, dolgozok.getN()) << "Sikertelen ugyintezofelvetel - Ugyintezok::add() fv nem mukodik";
      }
      file.close();

    } END

   TEST(FAJLKEZELES, szerzodes_beolvasas) {

      std::ifstream file("szerzodesek.txt");
      EXPECT_EQ(true, file.is_open()) << "fajl megnyitasa sikertelen";
      Szerzodes uj;
      int db = 0;
      while (file >> uj) {
        nyilvantartas.add(uj);
        EXPECT_EQ(++db, nyilvantartas.getN()) << "Sikertelen szerzodesfelvetel - Szerzodesek::add() fv nem mukodik";
      }
      file.close();

    } END
}


void teszt_faljokbairas(tomb<Ugyfel>& kliensek, tomb<Ugyintezo>& dolgozok, Szerzodesek& nyilvantartas) { // a tesztfuggveny megkapja, hogy milyen objektumokat kell kirnia; ezzel elkeruljuk a globalis valtozok hasznalatat

    TEST(FAJLKEZELES, ugyfel_kiiras) {

        std::ofstream file("ugyfelek.txt");
        EXPECT_EQ(true, file.is_open()) << "fajl megnyitasa sikertelen";
        int meret = kliensek.getN();
        int i = 0;
        while(i != meret) {
            file << kliensek[i++] << std::endl;
        }
        file.close();

    } END

    TEST(FAJLKEZELES, ugyintezo_kiiras) {

        std::ofstream file("ugyintezok.txt");
        EXPECT_EQ(true, file.is_open()) << "fajl megnyitasa sikertelen";
        int meret = dolgozok.getN();
        int i = 0;
        while(i != meret) {
            file << dolgozok[i++] << std::endl;
        }
        file.close();

    } END

    TEST(FAJLKEZELES, szerzodes_kiiras) {

        std::ofstream file("szerzodesek.txt");
        EXPECT_EQ(true, file.is_open()) << "fajl megnyitasa sikertelen";
        int meret = nyilvantartas.getN();
        int i = 0;
        while(i != meret) {
            file << nyilvantartas[i++] <<std::endl;
        }
        file.close();

    } END

}


void teszt_autentikacio(tomb<Ugyfel>& kliensek, tomb<Ugyintezo>& dolgozok) {

        TEST (KEZDES, udv&aut) {
        int sorsz = udvozles_login();           //menu.cpp-beli fuggveny, ami kiirja az udvozloszoveget, es visszater a felhasznalo altal valasztott menupont sorszamaval(1- ugyfel; 2 - ugyintezo
        EXPECT_LT(sorsz, 3) << "Ervenytelen sorszam";
        String azon;
        unsigned long pin;
        bool benne = false;
        EXPECT_EQ(true, false);
        int idx;
        while (!benne) {
            aut(azon, pin);  //bekéri a felhasználótól az azonosítót, majd pin-t, és felülírja velük a paraméterként kapott változókat
            switch(sorsz) {
                case 1:                                 //1-es opcio, hogy az ugyfelek tombjeben keresi a bejelentkezo adatai
                    idx = kliensek.search(azon);
                    if (idx>=0) {
                        ///EXPECT_EQ(azon, kliensek[idx].getAzon()) << "Ugyfelek::search() fv nem mukodik!";
                        benne = (pin == dolgozok[idx].getPin());
                     }
                    else benne =false;                          //Ha negatív az index, akkor a megadott azon nincs benne->HIBA
                break;
                case 2:                                                  //2-es opcio, hogy az ugyintezok tombjeben kereri
                    idx = dolgozok.search(azon);                        //valahogy ezt az indexet meg kene jegyezni; a foprogramban a bejelentkezo fv egy idx-el fog visszatérni
                    if (idx>=0) {
                       /// EXPECT_EQ(azon, kliensek[idx].getAzon()) << "Ugyfelek::search() fv nem mukodik!";
                        benne = (pin == dolgozok[idx].getPin());
                    }
                    else benne =false;
                break;
            }
            if (benne) std::cout << "Sikeres belepes!" << std::endl;
            else std::cout << "Helytelen azonosito vagy PIN-kod! Probalja ujra!" << std::endl;

        }
    } END



}

//a kovetkezo tesztfuggvenyek parameterkent az aktualisan bejelentkezett felhasznalot/ugyintezot es minden adatat megkapjak+a nyilvantartast, ha azt kell modositani a muvelet soran

void teszt_egyenleglekerdezes(Szerzodesek& nyilvantartas, Ugyfel& user) {

    TEST(Muveletek, egyenleglekerdezes) {
        unsigned long szer_azon;                //szerzodes azonosito
        szerzodesbekeres(szer_azon);            //a fv bekéri a felhasznalo altal megadott szerzodes-azonositot, és felulirja vele a szer_azon paramétert
        //int idx = nyilvantartas.search(szer_azon);
       /// EXPECT_EQ(szer_azon, nyilvantartas[idx].getAzon()) << "Szerzodesek::search() fv nem mukodik!";

    //TOVABBI ALGORITMUS: ha megegyezik a szerzodeshez tartozo ugyfelazon az aktualis user azonositojaval, a szerzodes egyenleg adattagja kiirodik
    }END

}


void teszt_fogyasztasbejelentes(Szerzodesek& nyilvantartas, Ugyfel& user) {

    TEST(Muveletek, ujabbfogyasztas) {
        unsigned long szer_azon;                //szerzodes azonosito
        szerzodesbekeres(szer_azon);            //a fv bekéri a felhasznalo altal megadott szerzodes-azonositot, és felulirja vele a szer_azon paramétert
        int idx = nyilvantartas.search(szer_azon);
        ///if (idx>=0) EXPECT_EQ(szer_azon, nyilvantartas[idx].getAzon()) << "Szerzodesek::search() fv nem mukodik!";
        //else a keresett szerzodes nincs benne a tombben, probalja ujra

        Fogyasztas ujabb;
        //Felhasznalo megadja az ujabb fogyasztast az eloirt formatumban
        Fogyasztas regi = nyilvantartas[idx].getUtolsofogy();
        nyilvantartas[idx].setUtolsofogy(ujabb);
       /// EXPECT_NE(regi, nyilvantartas[idx].getUtolsofogy()) <<"Szerzodes::setUtolsofogy() tagfv nem mukodik!";

        double kulonbseg = nyilvantartas[idx].getUtolsofogy().getErtek() - regi.getErtek();
        double energiaara = 35.33;
        //az uj és a regi leolvasott ertek kulonbsege, egyenleg novelese a kulonbseg aranyaban, fix dijjal szamolva
        unsigned long regebbi = nyilvantartas[idx].getEgyenleg();
        nyilvantartas[idx].setEgyenleg(regebbi + kulonbseg*energiaara);
        EXPECT_GT(nyilvantartas[idx].getEgyenleg(), regebbi) << "egyenleg nem novekedett - Szerzodes::setEgyenleg() fv nem mukodik";
    }END

}


void teszt_szamlcimmodositas(Ugyfel& user) {

    TEST(Muveletek, szamlcimmodositas) {
        Cim ujcim;
        //uj szamlazasi cim beolvasas a konzolrol/felhasznalotol ,legyen ez most az ujcim valtozo
        Cim regi = user.getSzamlcim();
        user.setSzamlcim(ujcim);
       /// EXPECT_NE(regi, user.getSzamlcim()) << "Szamlazasi cim modositasa sikertelen: nem jol mukodik a setSzamlcim() tagfv";
        //ha nem egyenlo, uzenet a sikeres modositasrol
    }END


}


void teszt_dijbefizetes(Szerzodesek& nyilvantartas, Ugyfel& user) {

    TEST(Muveletek, dijbefizetes) {
        unsigned long szer_azon;                //szerzodes azonosito
        szerzodesbekeres(szer_azon);            //a fv bekéri a felhasznalo altal megadott szerzodes-azonositot, és felulirja vele a szer_azon paramétert
        int idx = nyilvantartas.search(szer_azon);
       /// if (idx>=0) EXPECT_EQ(szer_azon, nyilvantartas[idx].getAzon()) << "Szerzodesek::search() fv nem mukodik!";
        //else a keresett szerzodes nincs benne a tombben, probalja ujra

        //felhasznalo megadja a fizetesi modnak megfelelo adatai(pl kartyaszam) -- lenyeges muvelet, adattarolas nics, csak a kartyas fizetes imitalasa
        unsigned long befizetes=10000;;
        //user megadja mennyit fizet be
        unsigned long aktual = nyilvantartas[idx].getEgyenleg();
        nyilvantartas[idx].setEgyenleg(aktual-befizetes);
        EXPECT_LT(nyilvantartas[idx].getEgyenleg(), aktual) << "egyenleg nem csokkent - Szerzodes::setEgyenleg() fv nem mukodik";

    }END
}


void teszt_szamlakiallitas(Szerzodesek& nyilvantartas, Ugyintezo& user) {

    TEST(Muveletek, szamlakiallitas) {
        unsigned long szer_azon;                //szerzodes azonosito
        szerzodesbekeres(szer_azon);            //a fv bekéri a felhasznalo altal megadott szerzodes-azonositot, és felulirja vele a szer_azon paramétert
        int idx = nyilvantartas.search(szer_azon);
        if (idx>=0) EXPECT_EQ(szer_azon, nyilvantartas[idx].getAzon()) << "Szerzodesek::search() fv nem mukodik!";
        //else a keresett szerzodes nincs benne a tombben, probalja ujra

        String ugyfelazon;                      //ugyintezo bekeri az ugyfeltol az azonositojat, majd osszehasonlitja a megtalalt szerzodes ugyfelazonositjaval
        //if (ugyfelazon == nyilvantartas[idx].getUgyfelazon() meghivja a szamlakiir() fv-t
        std::ofstream file("teszt.txt");
        //szamlakiir(file, nyilvantartas[idx]);     //lényegében kiirja egy fájlba a megtalalt szerzodes allapotat
        //itt nem tudom, mit lehetne tesztelni meg -- talan a sikeres fajlmegnyitast?
        file.close();
    } END


}


void teszt_szerzodeskotes(Szerzodesek& nyilvantartas, Ugyintezo& user) {

    TEST(Muveletek, szerzodeskotes) {
        unsigned long azon= 123456789;         //a felulet random 9-jegyu azonositoval latja el a szerzodest
        String ugyfelazon;          //az ugyintezo hozzarendeli az ugyfelet az uj szerzodeshez, es "felveszi"/beallitja a szerzodes egyeb jellemzoit
        Cim fogyasztashelye;
        String fizetesmod;
        Fogyasztas utolsofogy;
        Szerzodes uj(azon, ugyfelazon, fogyasztashelye, 0, utolsofogy, fizetesmod);
        int aktualmeret = nyilvantartas.getN();
        nyilvantartas.add(uj);
        EXPECT_EQ(aktualmeret+1, nyilvantartas.getN()) << "Sikertelen felvetel a nyilvantartasba - Szerzodesek::add() fv nem mukodik";
    }END


}


void teszt_szerzodesfelmondas(Szerzodesek& nyilvantartas, Ugyintezo& user) {

    TEST(Muveletek, szerzodesfelmondas) {
        unsigned long szer_azon;                //szerzodes azonosito
        szerzodesbekeres(szer_azon);            //a fv bekéri a felhasznalo altal megadott szerzodes-azonositot, és felulirja vele a szer_azon paramétert
        int idx = nyilvantartas.search(szer_azon);
        if (idx>=0) EXPECT_EQ(szer_azon, nyilvantartas[idx].getAzon()) << "Szerzodesek::search() fv nem mukodik!";
        //else a keresett szerzodes nincs benne a tombben, probalja ujra

        String ugyfelazon;                      //ugyintezo bekeri az ugyfeltol az azonositojat, majd osszehasonlitja a megtalalt szerzodes ugyfelazonositjaval
        //if (ugyfelazon == nyilvantartas[idx].getUgyfelazon()) szerzodes torlese
        int aktualmeret = nyilvantartas.getN();
        nyilvantartas.del(idx);
        EXPECT_EQ(aktualmeret-1, nyilvantartas.getN()) << "megtalalt szerzodes nem torlodott - Szerzodesek::del() tagfv nem mukodik";

    }END

}


void teszt_ugyfelfelvetele(tomb<Ugyfel>& kliensek, Ugyintezo& user) {

    TEST(Muveletek, ugyfelfelvetele) {
        String nev, email;      //az ugyintezo "felveszi"/megkerdezi a felhasznalotol a szemelyes adatait
        Datum szulido;
        Cim szamlcim;
        unsigned long pin = 1234;
        String azon;            //utana sorsol neki egy random generalt azonosito
        Ugyfel uj(azon, pin, nev, email, szulido, szamlcim);

        int aktualmeret = kliensek.getN();
        kliensek.add(uj);
        EXPECT_EQ(aktualmeret+1, kliensek.getN()) << "ugyfel hozzaadasa a nyilvantartashoz sikertelen - Ugyfelek::add() fv nem mukodik";


    }END


}
