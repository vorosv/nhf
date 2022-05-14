#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include <iostream>
#include "string.h"
#include "memtrace.h"

/**
* \class Datum
* \brief Egy d�tum k�nnyebb t�rol�s�ra szolg�l� oszt�ly
*D�tumok form�tum�t modellezi
*Tagjai: �v, h�nap, nap
*/
class Datum {
    int ev, ho, nap;        /*!< �v, h�nap, nap integerben*/
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
* \brief �ramhaszn�lat/fogyaszt�s bejelnt�s�t modellezi
*Tagjai: fogyaszt�s m�rt�ke(kWh), leolvas�s napja
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
*\brief C�m k�nnyebb t�rol�s�ra szolg�l� oszt�ly
* C�m form�tum�t/�sszet�tel�t modellezi
*Tagjai: ir�ny�tosz�m, v�ros, utca, h�zsz�m
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
* \brief A fel�letet hasznal� szem�ly le�r�sa/modellje
*A felhaszn�l�i fel�letet haszn�l�k modellez�se a fel�leten. Az oszt�ly seg�ts�g�vel azonos�tjuk, t�roljuk, m�s objektumokhoz rendelj�k a user-t
*Tagjai: azonos�t�, PIN-k�d, N�v(Vezet�k+kereszt)
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
* \brief A szolg�ltat� �gyfeleit modellezi
*Felhasznalo oszt�ly lesz�rmazottja, a szolg�ltat� �gyfeleink adatait tartalmazzza/kezeli
*Tagjai: Email-c�m, Sz�let�si id�, Sz�ml�z�si c�m
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
* \brief A szolg�ltat� munkat�rsait modellezi
*Felhasznalo oszt�ly lesz�rmazottja, a szolg�ltat� munkat�rsainak jellemz�it/adatait tartalmazza
*Tagjai:a dolgoz� beoszt�sa
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
* \brief A szolg�ltat� �gyfeleinek szerz�d�seit modellezi
*Az �ramszolg�ltat� �ltal megk�t�tt lakoss�gi szerz�d�sek jellemz�it/adatait tartalmazza
*Tagjai:a egyedi azonos�t�, �gyf�l azonos�t�ja, fogyaszt�s helye, aktu�lis egyenleg/tartoz�s, az utols� fogyaszt�s(leolvasott �rt�k), fizet�s m�dja
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
* \brief T�mboszt�ly a szerz�d�sek t�rol�s�ra
*Dinamikusan ny�jt�zkod� t�mb a Szerzodes oszt�ly p�ld�nyainak
*Tagjai: a t�mb elej�re mutat� pointer, t�mb elemsz�ma
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
* \brief Osztalysablon a k�t t�pus� felhaszn�l�knak
*Dinamikusan ny�jt�zkod� t�mb, mely sablonparam�terk�nt kapja a t�roland� elemek t�pus�t
*@param T felhaszn�l�k t�pusa(Ugyfel vagy Ugyintezo)
*Tagjai: a t�mb elej�re mutat� pointer, t�mb elemsz�ma
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
