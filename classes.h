#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include <iostream>
#include "string.h"
#include "memtrace.h"

/**
* \class Datum
* \brief Egy dátum könnyebb tárolására szolgáló osztály
*Dátumok formátumát modellezi
*Tagjai: év, hónap, nap
*/
class Datum {
    int ev, ho, nap;        /*!< év, hónap, nap integerben*/
public:
    Datum() {}
    Datum(int e, int h, int n) :ev(e), ho(h), nap(n) {}
    int getEv() const {return ev;}
    int getHo() const {return ho;}
    int getNap() const {return nap;}
    Datum& operator=(Datum const& rhs);
   // bool& operator==(Datum const& rhs);        //mihez kellett?

};

/**
* \class Fogyasztas
* \brief Áramhasználat/fogyasztás bejelntését modellezi
*Tagjai: fogyasztás mértéke(kWh), leolvasás napja
*/
class Fogyasztas {
    double ertek;
    Datum leolvasasnapja;
public:
    Fogyasztas() {}
    Fogyasztas(double e, Datum d) :ertek(e), leolvasasnapja(d) {}
    double getErtek() const {return ertek;}
    void setErtek(double e) {ertek = e;}
    Datum getNap() const {return leolvasasnapja;}
    void setNap(Datum d) {leolvasasnapja = d;}
    Fogyasztas& operator=(Fogyasztas const& rhs);
    //bool operator!= (Fogyasztas const& rhs);

};


/**
*\class Cim
*\brief Cím könnyebb tárolására szolgáló osztály
* Cím formátumát/összetételét modellezi
*Tagjai: irányítoszám, város, utca, házszám
*/
class Cim {
    int iranyitoszam;
    String varos;
    String utcanev;
    int hazszam;
public:
    Cim() {}
    Cim(int i, String v, String u, int h) :iranyitoszam(i), varos(v), utcanev(u), hazszam(h) {}
    int getIranyszam() const  {return iranyitoszam;}
    String getVaros() const {return varos;}
    String getUtca() const {return utcanev;}
    int getHaz() const {return hazszam;}
    Cim& operator=(Cim const& rhs);
    bool operator!=(Cim const& rhs);
};

/**
* \class Felhasznalo
* \brief A felületet hasznaló személy leírása/modellje
*A felhasználói felületet használók modellezése a felületen. Az osztály segítségével azonosítjuk, tároljuk, más objektumokhoz rendeljük a user-t
*Tagjai: azonosító, PIN-kód, Név(Vezeték+kereszt)
*/
class Felhasznalo {
protected:
    String azon;
    unsigned long pin;
    String nev;
public:
    Felhasznalo() {}
   // Felhasznalo(const Felhasznalo& rhs); eleg az implicit
    Felhasznalo(String a, unsigned long p, String n) :azon(a), pin(p), nev(n) {}
    String getAzon() const {return azon;}
    unsigned long getPin() const {return pin;}
    String getNev() const {return nev;}

};

/**
* \class Ugyfel
* \brief A szolgáltató ügyfeleit modellezi
*Felhasznalo osztály leszármazottja, a szolgáltató ügyfeleink adatait tartalmazzza/kezeli
*Tagjai: Email-cím, Születési idõ, Számlázási cím
*/
class Ugyfel :public Felhasznalo {
    String email;
    Datum szulido;
    Cim szamlcim;
public:
    Ugyfel(){}
    Ugyfel(String a, unsigned long p, String n, String email, Datum d, Cim sz) :Felhasznalo(a, p, n), email(email), szulido(d), szamlcim(sz) {}
    Ugyfel(const Ugyfel& rhs);
    Cim getSzamlcim() const {return szamlcim;}
    void setSzamlcim(Cim uj) {szamlcim = uj;}
    String getEmail() const {return email;}
    Datum getSzulido() const {return szulido;}
    Ugyfel& operator=(Ugyfel const& rhs);
};


/**
* \class Ugyintezo
* \brief A szolgáltató munkatársait modellezi
*Felhasznalo osztály leszármazottja, a szolgáltató munkatársainak jellemzõit/adatait tartalmazza
*Tagjai:a dolgozó beosztása
*/
class Ugyintezo :public Felhasznalo {
    String beosztas;
public:
    Ugyintezo() {}
    Ugyintezo(String a, unsigned long p, String n, String beo) :Felhasznalo(a,p,n), beosztas(beo) {}
    String getBeosztas() const {return beosztas;}
    Ugyintezo& operator=(Ugyintezo const& rhs);
};

/**
* \class Szerzodes
* \brief A szolgáltató ügyfeleinek szerzõdéseit modellezi
*Az áramszolgáltató által megkötött lakossági szerzõdések jellemzõit/adatait tartalmazza
*Tagjai:a egyedi azonosító, ügyfél azonosítója, fogyasztás helye, aktuális egyenleg/tartozás, az utolsó fogyasztás(leolvasott érték), fizetés módja
*/
class Szerzodes{
    unsigned long azon;
    String ugyfelazon;
    Cim fogyasztashelye;
    unsigned long egyenleg;
    Fogyasztas utolsofogy;
    String fizetesmod;
    //szerzodes op= valamiert itt volt
public:
    Szerzodes() {}
    Szerzodes(unsigned long a, String ugyaz, Cim f, unsigned long egy, Fogyasztas utso, String fizmod) :azon(a), ugyfelazon(ugyaz), fogyasztashelye(f), egyenleg(egy), utolsofogy(utso), fizetesmod(fizmod) {}
    unsigned long getEgyenleg() const {return egyenleg;}
    void setEgyenleg(unsigned long uj) {egyenleg = uj;}
    Fogyasztas getUtolsofogy() const {return utolsofogy;}
    void setUtolsofogy(Fogyasztas uj) {utolsofogy = uj;}
    unsigned long getAzon() const {return azon;}
    String getUgyfelazon() const {return ugyfelazon;}
    Cim getFogyhelye() const {return fogyasztashelye;}
    String getFizetesmod() const {return fizetesmod;}
    Szerzodes& operator=(Szerzodes const& rhs);

};

/**
* \class Szerzodesek
* \brief Tömbosztály a szerzõdések tárolására
*Dinamikusan nyújtózkodó tömb a Szerzodes osztály példányainak
*Tagjai: a tömb elejére mutató pointer, tömb elemszáma
*/
class Szerzodesek {
    Szerzodes* t;
    int n;
public:
    Szerzodesek(int db = 0) :n(db) {t = new Szerzodes[db];}
     Szerzodesek(const Szerzodesek& mas);
    int getN() const {return n;}
    void add(Szerzodes& uj);
    int search(unsigned long azon);
    void del(int idx);
    Szerzodes& operator[](int idx);
    Szerzodes operator[](int idx) const;
    void fajlbair(std::ofstream& os);
    ~Szerzodesek() {delete [] t;}
};

/**
* \class tomb
* \brief Osztalysablon a két típusú felhasználóknak
*Dinamikusan nyújtózkodó tömb, mely sablonparaméterként kapja a tárolandó elemek típusát
*@param T felhasználók típusa(Ugyfel vagy Ugyintezo)
*Tagjai: a tömb elejére mutató pointer, tömb elemszáma
*/
template <typename T>
class tomb {
    T* t;
    int n;
public:
    tomb(int db = 0) :n(db) {t = new T[db];}

    int getN() const {return n;}
    inline void add(T& uj) {
        T* temp = new T[n+1];
        for (int i = 0; i < n; ++i) {
            temp[i] = t[i];
        }
        temp[n++] = uj;
        delete[] t;
        t = temp;
    };





    inline int search(String azon) {
        for (int i = 0 ; i <n; ++i){
            if (azon == t[i].getAzon()) return i;
        }
        return -1;
    }




    inline T& operator[](int idx) {return t[idx];}
    inline T operator[](int idx) const {return t[idx];}
    inline void fajlbair(std::ofstream& os) {
        for(int i = 0; i < n; ++i) {
            if (i < n-1)
                os << t[i] << std::endl;
            else
                os << t[i];
        }
    }
    tomb(tomb const& mas) {
        n = mas.getN();
        t = new T[n];
        for (int i = 0; i < n; ++i)
            t[i] = mas[i];
    }
    ~tomb() {delete [] t;}
};













#endif // CLASSES_H
