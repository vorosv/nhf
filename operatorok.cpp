#include "classes.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include "operatorok.h"
#include "gtest_lite.h"
#include "classes.h"
#include "operatorok.h"
#include "menu.h"
#include "string.h"
#include "memtrace.h"


/**
*   Inserter operator sztringhez
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando sztring referenciaja
*@return kimeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::ostream& operator<<(std::ostream& os, const String& rhs) {
    os << rhs.c_str();
    return os;
}

std::ofstream& operator<<(std::ofstream& os, String const& rhs) {
    os << rhs.c_str();
    return os;
}
/**
*   Extraktor operator sztringhez
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando sztring referenciaja
*@return kimeneti adatfolyam, hogy tobbszorozni lehessen
*/

std::ifstream& operator>>(std::ifstream& is, String& rhs) {
   unsigned char ch;
    rhs = String("");            // ßres string, ehhez fŹzßnk hozzå
	std::ios_base::fmtflags fl = is.flags(); // eltesszßk a rÊgi flag-eket
	is.setf(std::ios_base::skipws);			// az elejÊn eldobjuk a ws-t
    while (is >> ch) {
	    is.unsetf(std::ios_base::skipws);	// utåna pedig mår nem
        if (isspace(ch)) {
            is.putback(ch);             // na ezt nem kÊrjßk
            break;
        } else {
            rhs = rhs + ch;               // vÊgÊre fŹzzßk a karaktert
        }
    }
	is.setf(fl);						// visszaållítjuk a flag-eket
    return is;

}

std::istream& operator>>(std::istream& is, String& rhs) {
   unsigned char ch;
    rhs = String("");            // ßres string, ehhez fŹzßnk hozzå
	std::ios_base::fmtflags fl = is.flags(); // eltesszßk a rÊgi flag-eket
	is.setf(std::ios_base::skipws);			// az elejÊn eldobjuk a ws-t
    while (is >> ch) {
	    is.unsetf(std::ios_base::skipws);	// utåna pedig mår nem
        if (isspace(ch)) {
            is.putback(ch);             // na ezt nem kÊrjßk
            break;
        } else {
            rhs = rhs + ch;               // vÊgÊre fŹzzßk a karaktert
        }
    }
	is.setf(fl);						// visszaållítjuk a flag-eket
    return is;

}


/**
*   Inserter operator Datum osztalyhoz
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando Datum referenciaja
*@return kimeneti adatfolyamra, hogy tobbszorozni lehessen
*/
std::ostream& operator<<(std::ostream& os, Datum const& rhs) {
    int ev = rhs.getEv();
    int ho = rhs.getHo();
    int nap = rhs.getNap();
    String dot('.');
    os << ev;
    os << dot  <<ho ;
    os << dot << nap << dot;
    return os;
}

std::ofstream& operator<<(std::ofstream& os, Datum const& rhs) {
    int ev = rhs.getEv();
    int ho = rhs.getHo();
    int nap = rhs.getNap();
    String dot('.');
    os << (int)ev;
    os << dot  <<ho ;
    os << dot << nap << dot;
    return os;
}


/**
*   Inserter operator Cim osztalyhoz
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando cimhez referenciaja
*@return kimeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::ostream& operator<<(std::ostream& os, Cim const& rhs) {
    String sp(' ');
    os << rhs.getIranyszam() << sp << rhs.getVaros() << sp << rhs.getUtca() << " utca " << rhs.getHaz() << '.';
    return os;

}

std::ofstream& operator<<(std::ofstream& os, Cim const& rhs) {
    String sp(' ');
    os << rhs.getIranyszam() << sp;
    os << rhs.getVaros() << sp ;
    os<< rhs.getUtca() << " utca " ;
    os << rhs.getHaz() << '.';
    return os;

}

/**
*   Inserter operator Fogyasztas osztalyhoz
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando fogyasztas referenciaja
*@return kimeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::ostream& operator<<(std::ostream& os, Fogyasztas const& rhs) {
    String sp(' ');
    os << rhs.getErtek() << sp<< rhs.getNap();
    return os;
}

std::ofstream& operator<<(std::ofstream& os, Fogyasztas const& rhs) {
    String sp(' ');
    os << rhs.getErtek() << sp;
    os << rhs.getNap();
    return os;
}
/**
*   Inserter operator Ugyfel osztalyhoz
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando ugyfel referenciaja
*@return kimeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::ostream& operator<<(std::ostream& os, Ugyfel const& rhs) {
    String sp(' ');
    os << rhs.getAzon() << sp ;
    os << rhs.getPin() << sp ;
    os << rhs.getNev() << sp;
    os << rhs.getSzulido() << sp ;
    os << rhs.getEmail() << sp ;
    os << rhs.getSzamlcim();
    return os;
}

std::ofstream& operator<<(std::ofstream& os, Ugyfel const& rhs) {
    String sp(' ');
    os << rhs.getAzon() << sp;
    os << rhs.getPin() << sp;
    os  << rhs.getNev() << sp ;
    os << rhs.getSzulido() << sp ;
    os << rhs.getEmail() << sp;
    os << rhs.getSzamlcim();
    return os;
}

/**
*   Inserter operator Ugyintezo osztalyhoz
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando ugyintezo referenciaja
*@return kimeneti adatfolyam, hogy tobbszorozni lehessen
*/

std::ostream& operator<<(std::ostream& os, Ugyintezo const& rhs) {
    String sp(' ');
    os << rhs.getAzon() << sp;
    os  << rhs.getPin() << sp ;
    os << rhs.getNev() << sp ;
    os << rhs.getBeosztas();
    return os;
}

std::ofstream& operator<<(std::ofstream& os, Ugyintezo const& rhs) {
    String sp(' ');
    os << rhs.getAzon() << sp ;
    os<< rhs.getPin() << sp ;
    os << rhs.getNev() << sp;
    os << rhs.getBeosztas();
    return os;

}
/**
*   Inserter operator Szerzodes osztalyhoz
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando szerzodes referenciaja
*@return kimeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::ostream& operator<<(std::ostream& os, Szerzodes const& rhs) {
        String sp(' ');
        String dot('.');
        os << rhs.getAzon() ;
        os << sp << rhs.getUgyfelazon();
        os << sp << rhs.getFogyhelye();
        os << sp <<rhs.getEgyenleg();
        os << sp << rhs.getUtolsofogy() ;
        os<< sp << rhs.getFizetesmod();
        return os;
}

std::ofstream& operator<<(std::ofstream& os, Szerzodes const& rhs) {
        String sp(' ');
        String dot('.');
        os << rhs.getAzon() ;
        os << sp << rhs.getUgyfelazon();
        os << sp << rhs.getFogyhelye();
        os << sp << rhs.getEgyenleg() ;
        os << sp << rhs.getUtolsofogy() ;
        os << sp << rhs.getFizetesmod();
        return os;
}

/**
*   Extraktor operator Datum osztalyhoz
*@param os referencia egy bemeneti adatfolyamra
*@param rhs beolvasando datum referenciaja
*@return bemeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::istream& operator>>(std::istream& is, Datum& rhs) {
    int ev, ho, nap;
    (is >> ev).ignore(1);
    (is >> ho).ignore(1);
    (is >> nap).ignore(1);
    rhs = Datum(ev, ho, nap);
    return is;
}

std::ifstream& operator>>(std::ifstream& is, Datum& rhs) {
    int ev, ho, nap;
    (is >> ev).ignore(1);
    (is >> ho).ignore(1);
    (is >> nap).ignore(1);
    rhs = Datum(ev, ho, nap);
    return is;

}

/**
*   Extraktor operator Cim osztalyhoz
*@param os referencia egy bemeneti adatfolyamra
*@param rhs beolvasando cim referenciaja
*@return bemeneti adatfolyam, hogy tobbszorozni lehessen
*/

std::istream& operator>>(std::istream& is, Cim& rhs) {
    int iranyto, hazszam;
    String varos, utcanev, utcaszo;
    (is >> iranyto >> varos >> utcanev>> utcaszo >> hazszam).ignore(1);
    rhs = Cim(iranyto, varos, utcanev, hazszam);
    return is;
}

std::ifstream& operator>>(std::ifstream& is, Cim& rhs) {
    int iranyto, hazszam;
    String varos, utcanev, utcaszo;
    (is >> iranyto >> varos >> utcanev>> utcaszo >> hazszam).ignore(1);
    rhs = Cim(iranyto, varos, utcanev, hazszam);
    return is;
}

/**
*   Extraktor operator Fogyasztas osztalyhoz
*@param os referencia egy bemeneti adatfolyamra
*@param rhs beolvasando fogyasztas referenciaja
*@return bemeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::istream& operator>>(std::istream& is, Fogyasztas& rhs) {
    double ertek;
    Datum leolvasnap;
    (is >> ertek >> leolvasnap).ignore(1);
    rhs = Fogyasztas(ertek, leolvasnap);
    return is;
}

std::ifstream& operator>>(std::ifstream& is, Fogyasztas& rhs) {
    double ertek;
    Datum leolvasnap;
    (is >> ertek >> leolvasnap).ignore(1);
    rhs = Fogyasztas(ertek, leolvasnap);
    return is;
}
/**
*   Extraktor operator Ugyfel osztalyhoz
*@param os referencia egy bemeneti adatfolyamra
*@param rhs beolvasando ugyfel referenciaja
*@return bemeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::istream& operator>>(std::istream& is, Ugyfel & rhs) {
    String azon, kernev, veznev, email;
    Cim szamlcim;
    Datum szulido;
    unsigned long pin;
    is >> azon >> pin >> veznev >> kernev >> szulido >> email >> szamlcim;
    veznev = veznev + String(' ');                                          //hogy legyen szokoz a vezetek- es keresztnev kozott
    rhs = Ugyfel(azon, pin, veznev+kernev, email, szulido, szamlcim);
    return is;
}

std::ifstream& operator>>(std::ifstream& is, Ugyfel & rhs) {
    String azon, kernev, veznev, email;
    Cim szamlcim;
    Datum szulido;
    unsigned long pin;
    is >> azon >> pin >> veznev >> kernev >> szulido >> email >> szamlcim;
    veznev = veznev + String(' ');                                          //hogy legyen szokoz a vezetek- es keresztnev kozott
    rhs = Ugyfel(azon, pin, veznev+kernev, email, szulido, szamlcim);
    return is;
}

/**
*   Extraktor operator Ugyintezo osztalyhoz
*@param os referencia egy bemeneti adatfolyamra
*@param rhs beolvasando ugyintezo referenciaja
*@return bemeneti adatfolyam, hogy tobbszorozni lehessen
*/

std::istream& operator>>(std::istream& is, Ugyintezo& rhs) {
     String azon, kernev, veznev, beosztas;
    unsigned long pin;
    is >> azon >> pin >> veznev >> kernev >> beosztas;
    veznev = veznev + String(' ');
    rhs = Ugyintezo(azon, pin, veznev+kernev, beosztas);
    return is;
}

std::ifstream& operator>>(std::ifstream& is, Ugyintezo& rhs) {
     String azon, kernev, veznev, beosztas;
    unsigned long pin;
    is >> azon >> pin >> veznev >> kernev >> beosztas;
    veznev = veznev + String(' ');
    rhs = Ugyintezo(azon, pin, veznev+kernev, beosztas);
    return is;
}

/**
*   Extraktor operator Szerzodes osztalyhoz
*@param os referencia egy bemeneti adatfolyamra
*@param rhs beolvasando szerzodes referenciaja
*@return bemeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::istream& operator>>(std::istream& is, Szerzodes& rhs) {
    unsigned long azon, egyenleg;
    String ugyfelazon, fizmod;
    Fogyasztas utolsofogy;
    Cim fogyhelye;
    is >> azon;
    is >> ugyfelazon;
    is>> fogyhelye;
    is >> egyenleg;
    is >> utolsofogy ;
    is>> fizmod;
    rhs = Szerzodes(azon, ugyfelazon, fogyhelye, egyenleg, utolsofogy, fizmod);
    return is;
}


std::ifstream& operator>>(std::ifstream& is, Szerzodes& rhs) {
    unsigned long azon, egyenleg;
    String ugyfelazon, fizmod;
    Fogyasztas utolsofogy;
    Cim fogyhelye;
    is >> azon;
    is >> ugyfelazon;
    is>> fogyhelye;
    is >> egyenleg;
    is >> utolsofogy ;
    is>> fizmod;
    rhs = Szerzodes(azon, ugyfelazon, fogyhelye, egyenleg, utolsofogy, fizmod);
    return is;
}

