#include <iostream>
#include <fstream>
#include "string.h"
#include "operatorok.h"
#include "gtest_lite.h"
#include "classes.h"
#include "menu.h"
#include "memtrace.h"
#include "muveletek.h"
#include "test.h"




int main()          //meg nincs a main-ben normal mukodes, csak a tesztprogram
{
    if (false) {
        tomb<Ugyfel> kliensek;
        tomb<Ugyintezo> dolgozok;
        Szerzodesek nyilvantartas;
        teszt_fajlokbeolvasasa(kliensek, dolgozok, nyilvantartas);      //ahhoz, hogy a kulonbozo muveleteket tesztelni tudjuk, be kell olvasni az adatokat/tomboket, hogy legyen min muveletet vegrehajtani
        //konzol torlese, ha a beolvasas teszt eredmenye meg ki  van irva
        Ugyfel user = kliensek[0];                                      //ha nem az autentikaciot teszteljuk, ezzel a ket probafelhasznaloval vegzunk muveletet
        Ugyintezo staff = dolgozok[0];
        int sorszam = teszteset_valasztas();                            //kiirja a teszteseteket sorszamozva, kozuluk valaszthatunk a sorszam beirasaval
        switch(sorszam) {
        case 1:
            teszt_autentikacio(kliensek, dolgozok);
            break;
        case 2:
            teszt_egyenleglekerdezes(nyilvantartas, user);
            break;
        case 3:
            teszt_szamlcimmodositas(user);
            break;
        case 4:
            teszt_dijbefizetes(nyilvantartas, user);
            break;
        case 5:
            teszt_fogyasztasbejelentes(nyilvantartas, user);
            break;
        case 6:
            teszt_szamlakiallitas(nyilvantartas, staff);
            break;
        case 7:
            teszt_szerzodeskotes(nyilvantartas, staff);
            break;
        case 8:
            teszt_szerzodesfelmondas(nyilvantartas, staff);
            break;
        case 9:
            teszt_ugyfelfelvetele(kliensek, staff);
            break;
        case 10:
            teszt_faljokbairas(kliensek, dolgozok, nyilvantartas);
            break;
        }
    }

    else {

        tomb<Ugyfel> kliensek;
        tomb<Ugyintezo> dolgozok;
        Szerzodesek nyilvantartas;
        tombok_fajlbol(kliensek, dolgozok, nyilvantartas);


        while(true) {
        int mod = udvozles_login();             //bekeri, hogy ugyfel vagy ugyintezo hasznalja-e a feluletet
        bool tovabb = true;                     //egy muvelet elvegzese utan folytatni akarja-e a felhasz

        //system("CLS");
        switch(mod)
        {





            case 1:
                //Ugyfel hasznalja a feluletet
                {
                    String azon; //a bejelntkezo ugyfel azonositoja
                    unsigned long pin; //beolvasando pin kod
                    int user_idx;       //aktiv felhasznalo idx-e a tombon belul
                    bool sikereslogin = false;
                    while(!sikereslogin) {
                        aut(azon, pin);
                                                //bekéri az azonosítot, jelszot
                        user_idx = kliensek.search(azon);
                        if (user_idx == -1) {
                            sikereslogin = false;
                            std::cout << "Hibas azonosito!" << std::endl;             //kiirast egybol torli az aut fv
                        }
                        else {
                            if (pin == kliensek[user_idx].getPin()) sikereslogin = true;
                            else std::cout << "Helytelen jelszo!" << std::endl;
                        }
                    }

                    while (tovabb) {                                            //amig a user hasznalni akarja a feluletet - minden muvelet vege megkerezzuk
                    //system("CLS");
                    int tevekenyseg = ugyfel_todolist();
                   // system("CLS");
                    switch(tevekenyseg)
                    {
                        case 1:
                            //Egyenleglekerdezes
                            {
                            int szerzodes_idx = ugyfel_szerzodese(nyilvantartas, azon);        //szerzodes megkeresese+ugyfel ellenorzese(ugyfel azonositoja alapjan

                            std::cout << "Az On egyenlege a megadott szerzodes keretebe: " << nyilvantartas[szerzodes_idx].getEgyenleg() << " HUF" << std::endl;
                            }
                            break;
                        case 2:
                            //SzamlCim modositasa
                            {
                                Cim ujcim;
                                //system("CLS");
                                std::cout << "Az On jelenlegi szamlazasi cime: " << kliensek[user_idx].getSzamlcim() << std::endl;
                                std::cout << "Adja meg az uj szamlazasi cimet!" << std::endl;
                                std::cin >> ujcim;
                                kliensek[user_idx].setSzamlcim(ujcim);
                            }
                            break;
                        case 3:
                            //Fogyasztas bejelentese
                            {
                                //system("CLS");
                                Fogyasztas ujfogy;
                                //szerzodes megker esese+ugyfel ellenorzese(ugyfel azonositoja alapjan)
                                int szerzodes_idx = ugyfel_szerzodese(nyilvantartas, azon);

                                std::cout << "Adja meg a leolvasott fogyasztas erteket es a leolvasas napjat!" << std::endl;
                                std::cin >> ujfogy;
                                double kulonbseg = ujfogy.getErtek() - nyilvantartas[szerzodes_idx].getUtolsofogy().getErtek();
                                double energiaara = 35.33;
                                //az uj és a regi leolvasott ertek kulonbsege, egyenleg novelese a kulonbseg aranyaban, fix dijjal szamolva
                                unsigned long regebbi = nyilvantartas[szerzodes_idx].getEgyenleg();
                                nyilvantartas[szerzodes_idx].setEgyenleg(regebbi + kulonbseg*energiaara);
                                nyilvantartas[szerzodes_idx].setUtolsofogy(ujfogy);
                            }
                            break;
                        case 4:
                            //Szolgaltatsi dij befizetes
                            {
                                //szerzodes megkeresese+ugyfel ellenorzese
                                int szerzodes_idx = ugyfel_szerzodese(nyilvantartas, azon);


                               // system("CLS");
                                std::cout << "Az On egyenlege a megadott szerzodes keretebe: " << nyilvantartas[szerzodes_idx].getEgyenleg() << " HUF" << std::endl;
                                std::cout << "Az On preferalt fizetesi mod: " << nyilvantartas[szerzodes_idx].getFizetesmod() << std::endl;
                                if (nyilvantartas[szerzodes_idx].getFizetesmod() == "kartya") {
                                    unsigned long kartyaszam;
                                    Datum lejarat;
                                    String nev;
                                    int CVC;
                                    double osszeg;
                                    kartyaadatok_be(kartyaszam, nev, lejarat, CVC, osszeg);
                                    double regiegyenleg = nyilvantartas[szerzodes_idx].getEgyenleg();
                                    nyilvantartas[szerzodes_idx].setEgyenleg(regiegyenleg - osszeg);
                                    std::cout << "A tranzakcio sikeres, az On szerzodesenek uj egyenlege: " << nyilvantartas[szerzodes_idx].getEgyenleg() << " HUF" << std::endl;

                                }
                                else {
                                    std::cout << "Napokon belul kiallitjuk az On egyenlegerol szolo csekket es megkuldjuk az On altal megadott szamlazasi cimre!" << std::endl;
                                    nyilvantartas[szerzodes_idx].setEgyenleg(0);
                                }

                            }
                            break;


                    }
                    int sorszam = tovabbhasznal();                  //megkerdezi, hogy hasznalja-e a user tovabb hasznalni a  feluletet
                    if (sorszam == 2) tovabb = false;
                    }
                }
                break;





            case 2:
                //Ugyintezo hasznalja
                {
                    String azon; //a bejelntkezo ugyinteo azonositoja
                    unsigned long pin; //ugyfel pin-kodja
                    bool sikereslogin = false;
                    while(!sikereslogin) {
                        aut(azon, pin);                     //bekéri az azonosítot, jelszot
                        int idx = dolgozok.search(azon);
                        if (idx == -1) {
                            sikereslogin = false;
                            std::cout << "Hibas azonosito!" << std::endl;             //kiirast egybol torli az aut fv
                        }
                        else {
                            if (pin == dolgozok[idx].getPin()) sikereslogin = true;
                            else std::cout << "Helytelen jelszo!" << std::endl;
                        }
                    }

                    while (tovabb) {                                            //amig a user hasznalni akarja a feluletet - minden muvelet vege megkerezzuk
                   // system("CLS");
                    int  tevekenyseg = ugyintezo_todolist();
                    //system("CLS");
                    switch(tevekenyseg)
                    {
                        case 1:
                            //Uj ugyfel felvetele a rendszerbe/nyilvantartasba
                            {
                                String azon = azon_sorsol();
                                String nev, email;
                                unsigned long pin;
                                Datum szulido;
                                Cim szamlcim;
                                ugyfeladatok_beker(pin, nev, email, szulido, szamlcim);
                                Ugyfel uj(azon, pin, nev, email, szulido, szamlcim);

                                kliensek.add(uj);
                            }

                            break;
                        case 2:
                            //Szamlakiallitas
                            {

                            //megkeresi az uygintezo a megadott szerzodest az azon alapjan, majd ellenorzi, hogy a jo ugyfelhez tartozikk-e
                            bool sikeresazon = false;
                            int szerzodes_idx;
                            while(!sikeresazon) {
                                    unsigned long azon;
                                    String ugyfelazon;
                                    szerzodesbekeres(azon);
                                    std::cout << "Adja meg az egyedi ugyfelazonositojat!" << std::endl;
                                    std::cin >> ugyfelazon;
                                    szerzodes_idx = nyilvantartas.search(azon);
                                    if (nyilvantartas[szerzodes_idx].getUgyfelazon() == ugyfelazon && szerzodes_idx>-1) sikeresazon = true;
                                    else std::cout << "Hibas szerzodesazonosito vagy ugyfelazonosito!" << std::endl;
                            }


                            szamlakiallit(kliensek,dolgozok, nyilvantartas, szerzodes_idx, azon);
                            }
                            break;
                        case 3:
                            //Uj szerzodes kotese
                            {
                                bool ugyfelmegtalalva = false;
                                String ugyfelazon;
                                while (!ugyfelmegtalalva) {
                                    std::cout << "Kerjuk adja meg a szerzodni kivano ugyfel 6-jegyu azonositojat: ";
                                    std::cin >> ugyfelazon;
                                    int idx = kliensek.search(ugyfelazon);
                                    if (idx <0) std::cout << "Hibas azonosito! A keresett ugyfel nem talahato!" << std::endl;
                                    else {
                                    ugyfelmegtalalva = true;
                                    }
                                }
                                unsigned long szer_azon = szerzazon_sorsol();
                                Cim fogycim;
                                String fizmod;
                                std::cout << "Kerjuk adja meg a fogyasztas helyet!" << std::endl;
                                std::cin >> fogycim;
                                std::cout << "Kerjuk adja meg a preferalt fizetesi modot!" << std::endl;
                                std::cin >> fizmod;
                                Datum leolvasnap(0,0,0);                //ervenytelen datum, hiszen meg nem volt fogyasztas
                                Fogyasztas utolsofogy(0, leolvasnap);
                                Szerzodes uj(szer_azon, ugyfelazon, fogycim, 0, utolsofogy, fizmod);
                                nyilvantartas.add(uj);
                            }
                            break;
                        case 4:
                            //Szerzodes felmondasa
                            {
                                bool sikeresazon = false;
                                int szerzodes_idx;
                                while(!sikeresazon) {
                                    unsigned long azon;
                                    String ugyfelazon;
                                    szerzodesbekeres(azon);
                                    std::cout << "Adja meg az egyedi ugyfelazonositojat!" << std::endl;
                                    std::cin >> ugyfelazon;
                                    szerzodes_idx = nyilvantartas.search(azon);
                                    if (nyilvantartas[szerzodes_idx].getUgyfelazon() == ugyfelazon && szerzodes_idx>-1) sikeresazon = true;
                                    else std::cout << "Hibas szerzodesazonosito vagy ugyfelazonosito!" << std::endl;
                                }

                                if(biztosbenne() == 1) {
                                    nyilvantartas.del(szerzodes_idx);
                                }
                            }
                            break;


                    }

                    int sorszam = tovabbhasznal();
                    if (sorszam == 2) tovabb = false;
                    }
                    break;
                }
             case 3:
                 tombok_fajlba(kliensek, dolgozok, nyilvantartas);
                    return 0;
                    break;



        }

        }



    }



    return 0;
}
