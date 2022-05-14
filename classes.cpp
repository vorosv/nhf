#include "classes.h"
#include <iostream>
#include <fstream>
#include "operatorok.h"
#include "gtest_lite.h"
#include "classes.h"
#include "operatorok.h"
#include "menu.h"
#include "string.h"
#include "memtrace.h"


/**
*   Ertekado operator a Datum osztalyhoz
*@param rhs a lemasolando Datum peldany, aminek az erteket masoljuk
*@return referencia a megvaltozatott erteku objektumra
*/
Datum& Datum::operator=(Datum const& rhs) {
    ev = rhs.getEv();
    ho = rhs.getHo();
    nap = rhs.getNap();
    return *this;
}



/**
*   Ertekado operator a Fogyasztas osztalyhoz
*@param rhs a lemasolando Fogyasztas peldany, aminek az erteket masoljuk
*@return referencia a megvaltozott erteku objektumra
*/
Fogyasztas& Fogyasztas::operator=(Fogyasztas const& rhs) {
    ertek = rhs.getErtek();
    leolvasasnapja = rhs.getNap();
    return *this;

}

/**
*   Nem-egyenlo/osszehasonlito operator a Fogyasztas osztalyhoz
*@param rhs a relacio jobb oldalan allo fogyasztas peldany
*@return a "nem-"egyenloseg erteke
*/
/*bool Fogyasztas::operator!=(Fogyasztas const& rhs) {
    return (ertek == rhs.getErtek() && leolvasasnapja == rhs.getNap());
}*/

/**
*   Ertekado operator Cim osztalyhoz
*@param rhs a lemasolando Cim peldany, aminek az erteket masoljuk
*@return referencia a megvaltozott erteku objektumra
*/
Cim& Cim::operator=(Cim const& rhs) {
    iranyitoszam = rhs.getIranyszam();
    varos = rhs.getVaros();
    utcanev  = rhs.getUtca();
    hazszam = rhs.getHaz();
    return *this;

}

/**
*   !=operator Cim osztalyhoz
*@param rhs a relacio jobb oldalan allo Cim peldany
*@return a relacio logikai erteke
*/
bool Cim::operator!=(Cim const& rhs) {
    return (iranyitoszam == rhs.getIranyszam() && varos == rhs.getVaros() && utcanev == rhs.getUtca() && hazszam == rhs.getHaz());
}


/**
*   Ugyfel osztaly copy konstruktora
*@param konstans referencia a lemasolando objektumra
*/
Ugyfel::Ugyfel(const Ugyfel& rhs) {
    azon = rhs.getAzon();
    pin = rhs.getPin();
    nev = rhs.getNev();
    szamlcim = rhs.getSzamlcim();
    email = rhs.getEmail();
    szulido = rhs.getSzulido();
}

/**
*   Ertekado operator az Ugyfel osztalynak
*@param rhs referencia az ertekul adando objektumra
*@return referencia a megvaltoztatott erteku objektumra
*/
Ugyfel& Ugyfel::operator=(Ugyfel const& rhs) {
    azon=rhs.getAzon();
    pin=rhs.getPin();
    nev= rhs.getNev();
    email = rhs.getEmail();
    szulido = rhs.getSzulido();
    szamlcim = rhs.getSzamlcim();
    return *this;
}
/**
*      Ertekado operator az Ugyintezo osztalynak
*@param rhs referencia az ertekul adando objektumra
*@return referencia a megvaltoztatott erteku objektumra
*/
Ugyintezo& Ugyintezo::operator=(Ugyintezo const& rhs) {
    azon=rhs.getAzon();
    pin=rhs.getPin();
    nev= rhs.getNev();
    beosztas = rhs.getBeosztas();
    return *this;
}

/**
*   A Szerzodesek tombosztaly copy konstruktora
*@param lemasolando tomb konstans referenciaja
*/
Szerzodesek::Szerzodesek(const Szerzodesek& mas) {
     n = mas.getN();
     t = new Szerzodes[n];
     for (int i = 0; i < n; ++i)
        t[i] = mas[i];
}

/**
*      Ertekado operator a Szerzodes osztalynak
*@param rhs referencia az ertekul adando objektumra
*@return referencia a megvaltoztatott erteku objektumra
*/
Szerzodes& Szerzodes::operator=(Szerzodes const& rhs) {
    azon=rhs.getAzon();
    ugyfelazon = rhs.getUgyfelazon();
    fogyasztashelye = rhs.getFogyhelye();
    egyenleg = rhs.getEgyenleg();
    utolsofogy = rhs.getUtolsofogy();
   fizetesmod = rhs.getFizetesmod();
    return *this;
}

/**
*   Hozzaado tagfuggveny a Szerzodesek osztalyhoz
*@param referencia tombbhoz hozzadando szerzodesre
*/
void Szerzodesek::add(Szerzodes& uj) {
    Szerzodes* temp = new Szerzodes[n+1];
    for (int i = 0; i < n; ++i) {
        temp[i] = t[i];
    }
    temp[n++] = uj;
    delete[] t;
    t = temp;


}
/**
*   Kereso tagfuggveny a Szerzodesek osztalyhoz
*@param a keresett Szerzodes azonositoja
*@return a keresett Szerzodes tombon beluli indexe, -1, ha nincs a a tombben
*/
int Szerzodesek::search(unsigned long azon) {
    for(int i = 0; i < n; ++i) {
        if (azon == t[i].getAzon()) return i;
    }
    return -1;
}

/**
*   Delete tagfuggveny a Szerzodesek osztalyoz
*@param a tortlendo Szerzodes tombon beluli indexe
*/
void Szerzodesek::del(int idx) {
    Szerzodes* tmp = new Szerzodes[n-1];
    int ujmeret = 0;
    for (int i = 0; i < n; ++i) {
        if (i != idx) tmp[ujmeret++] = t[i];
    }
    n = ujmeret;                //vagy n--;
    delete [] t;
    t = tmp;
}

/**
*   Indexelo operator a Szerzodesek osztalynak
*@param idx a keresett Szerzodes tombbon beluli indexe
*@return a keresett Szerzodes referenciaja
*/
Szerzodes& Szerzodesek::operator[](int idx) {
    return t[idx];
}

/**
*   Indexelo operator a Szerzodesek osztalynak
*@param idx a keresett Szerzodes tombbon beluli indexe
*@return a keresett Szerzodes erteke
*/
Szerzodes Szerzodesek::operator[](int idx) const {
    return t[idx];
}

/**
*   Kiiro fuggveny, mely fajlba irja a Szerzodesek tomb elemeit
*@param kimeneti adatfolyam referenciaja
*/
void Szerzodesek::fajlbair(std::ofstream& os) {
    for(int i = 0; i < n; ++i) {
        if (i < n-1)
            os << t[i] << std::endl;
        else
            os << t[i];
    }
}

/**
*   Hozzaado tagfuggveny az Ugyfelek osztalyhoz
*@param referencia a tombhoz hozzaadando Felhasznalo peldanyra
*/
/*
template <typename T>
void tomb<T>::add(T& uj) {
    T* temp = new T[n+1];
    for (int i = 0; i < n; ++i) {
        temp[i] = t[i];
    }
    temp[n++] = uj;
    delete[] t;
    t = temp;
};*/

/**
*   kereso tagfuggveny a tomb osztalynak
*@param a keresett felhasznalo azonositoja
*@return a keresett felhasznalo indexe, -1 ha nincs a tombben
*/
/*
template <typename T>
int tomb<T>::search(String azon) {
    for (int i = 0 ; i <n; ++i){
        if (azon == t[i].getAzon()) return i;
    }
    return -1;
}
*/


/**
*   Kiiro fuggveny, mely fajlba irja egy tomb elemeit
*@param kimeneti adatfolyam referenciaja
*/
/*
template <typename T>
void tomb<T>::fajlbair(std::ofstream& os) {
    for(int i = 0; i < n; ++i) {
        os << t[i] << '\n';
    }

}*/

/**
*   Indexelo operator a tomb osztalynak
*@param idx a keresett elem tombbon beluli indexe
*@return a keresett tombelem referenciaja
*/
/*
template <typename T>
T& tomb<T>::operator[](int idx) {
    return t[idx];
}
*/
/**
*   Indexelo operator a tomb osztalynak
*@param idx a keresett elem tombbon beluli indexe
*@return a keresett tombelem erteke
*//*
template <typename T>
T tomb<T>::operator[](int idx) const {
    return t[idx];
}

*/

