
#ifndef OPERATOROK_H_INCLUDED
#define OPERATOROK_H_INCLUDED

#include "classes.h"
#include <iostream>
#include <fstream>
#include "operatorok.h"
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
std::ostream& operator<<(std::ostream& os, String const& rhs);

std::ofstream& operator<<(std::ofstream& os, String const& rhs);
/**
*   Extraktor operator sztringhez
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando sztring referenciaja
*@return kimeneti adatfolyam, hogy tobbszorozni lehessen
*/

std::ifstream& operator>>(std::ifstream& is, String& rhs);

std::istream& operator>>(std::istream& is, String& rhs);




/**
*   Inserter operator Datum osztalyhoz
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando Datum referenciaja
*@return kimeneti adatfolyamra, hogy tobbszorozni lehessen
*/
std::ostream& operator<<(std::ostream& os, Datum const& rhs);

std::ofstream& operator<<(std::ofstream& os, Datum const& rhs);

/**
*   Inserter operator Cim osztalyhoz
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando cimhez referenciaja
*@return kimeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::ostream& operator<<(std::ostream& os, Cim const& rhs);

std::ofstream& operator<<(std::ofstream& os, Cim const& rhs);

/**
*   Inserter operator Fogyasztas osztalyhoz
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando fogyasztas referenciaja
*@return kimeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::ostream& operator<<(std::ostream& os, Fogyasztas const& rhs);

std::ofstream& operator<<(std::ofstream& os, Fogyasztas const& rhs) ;
/**
*   Inserter operator Ugyfel osztalyhoz
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando ugyfel referenciaja
*@return kimeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::ostream& operator<<(std::ostream& os, Ugyfel const& rhs) ;

std::ofstream& operator<<(std::ofstream& os, Ugyfel const& rhs) ;

/**
*   Inserter operator Ugyintezo osztalyhoz
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando ugyintezo referenciaja
*@return kimeneti adatfolyam, hogy tobbszorozni lehessen
*/

std::ostream& operator<<(std::ostream& os, Ugyintezo const& rhs) ;

std::ofstream& operator<<(std::ofstream& os, Ugyintezo const& rhs);
/**
*   Inserter operator Szerzodes osztalyhoz
*@param os referencia egy kimeneti adatfolyamra
*@param rhs kiirando szerzodes referenciaja
*@return kimeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::ostream& operator<<(std::ostream& os, Szerzodes const& rhs) ;

std::ofstream& operator<<(std::ofstream& os, Szerzodes const& rhs) ;

/**
*   Extraktor operator Datum osztalyhoz
*@param os referencia egy bemeneti adatfolyamra
*@param rhs beolvasando datum referenciaja
*@return bemeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::istream& operator>>(std::istream& is, Datum& rhs) ;

std::ifstream& operator>>(std::ifstream& is, Datum& rhs) ;

/**
*   Extraktor operator Cim osztalyhoz
*@param os referencia egy bemeneti adatfolyamra
*@param rhs beolvasando cim referenciaja
*@return bemeneti adatfolyam, hogy tobbszorozni lehessen
*/

std::istream& operator>>(std::istream& is, Cim& rhs);

std::ifstream& operator>>(std::ifstream& is, Cim& rhs);

/**
*   Extraktor operator Fogyasztas osztalyhoz
*@param os referencia egy bemeneti adatfolyamra
*@param rhs beolvasando fogyasztas referenciaja
*@return bemeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::istream& operator>>(std::istream& is, Fogyasztas& rhs);

std::ifstream& operator>>(std::ifstream& is, Fogyasztas& rhs);
/**
*   Extraktor operator Ugyfel osztalyhoz
*@param os referencia egy bemeneti adatfolyamra
*@param rhs beolvasando ugyfel referenciaja
*@return bemeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::istream& operator>>(std::istream& is, Ugyfel & rhs);

std::ifstream& operator>>(std::ifstream& is, Ugyfel & rhs);

/**
*   Extraktor operator Ugyintezo osztalyhoz
*@param os referencia egy bemeneti adatfolyamra
*@param rhs beolvasando ugyintezo referenciaja
*@return bemeneti adatfolyam, hogy tobbszorozni lehessen
*/

std::istream& operator>>(std::istream& is, Ugyintezo& rhs) ;

std::ifstream& operator>>(std::ifstream& is, Ugyintezo& rhs) ;

/**
*   Extraktor operator Szerzodes osztalyhoz
*@param os referencia egy bemeneti adatfolyamra
*@param rhs beolvasando szerzodes referenciaja
*@return bemeneti adatfolyam, hogy tobbszorozni lehessen
*/
std::istream& operator>>(std::istream& is, Szerzodes& rhs) ;


std::ifstream& operator>>(std::ifstream& is, Szerzodes& rhs);


#endif // OPERATOROK_H_INCLUDED
