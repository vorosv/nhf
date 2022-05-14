
#ifndef STRING_H
#define STRING_H
#include <iostream>
#include "memtrace.h"

class String {
    char *pData;
    size_t len;
public:

/// Az elsĹ kĂŠt feladatot elĹre megoldottuk, de lehet, hogy nem jĂłl.
/// Az Ăźres sztring reprezentĂĄciĂłja nem szerencsĂŠs, mert Ă­gy NULL pointerrĂŠ
/// konvertĂĄl a c_str(), ami kĂźlĂśn kezelĂŠst igĂŠnyel a kĂŠsĹbbiekben.
/// Ezt a teszt program sem fogadja el.
/// Gondolja vĂŠgig, ĂŠs vĂĄltoztassa meg!
/// KĂŠt lehetĹsĂŠg van:
///     a) nem NULL pointert tĂĄrol, hanem tĂŠnylegesen Ăźres sztringet.
///     b) NULL-t tĂĄrol, de a c_str() Ăźres sztringet ad vissza helyette
///        Ebben az esetben Ăźgyelnie kell a mĂĄsolĂĄsokra (mĂĄsolĂł kostruktor op=) is,
///        nehogy NULL pointert kapjon az strcpy!
/// BĂĄrmelyik megoldĂĄs jĂł, mert ez az osztĂĄly belĂźgye.


    /**
    *
    *Parameter nelkuli konstruktor
    */
    String();

    /**
    * Visszadja a sztring hosszat
    *@return string tenyleges, lezaro nelkuli hossza
    */
    size_t size() const { return len; }

    /**
    * C-sztringet ad vissza
    * @return pointer arra a memoriateruletre, ahol a sztring/nullaval lezart karaktersorozat kezdodik
    */
    char* c_str() const { return pData;}

    /**
    * Destruktor
    *
    */
    ~String();
    /**
    *  Karakterbol sztringet letrehozo konstruktor
    *@param c egy konstanst karakter
    */
    String(const char c);

    /**
    *  Nullaval lezart karaktersorozatol sztringet letrehozo konstruktor
    *@param s pointer a karaktersorozat elso elemere
    */
    String(const char *s);

    /**
    *  Masolo konstruktor
    *@param s konstanst sztring referencia a lemasolni kivant sztringre
    */
    String(String const& s);

    /**
    *  Ertekado operator
    *@param rhs konstanst sztring referencia az ertekadas jobb oldalan allo sztringre
    *@return a modositott sztring referenciajaval ter vissza
    */
    String& operator=(String const& rhs);


    /**
    *  Egyenloseg operator
    *@param rhs konstanst sztring referencia az egyenloseg jobb oldalan allo sztringre
    *@return az egyenloseg logikai erteke
    */
    bool operator==(String const& rhs);


    /**
    *  Osszeado operator: a sztring vegehet fuzi a parameterkent kapott sztring tartalmat
    *@param rhs konstanst sztring referencia a hozzafuzendo sztringre
    *@return az osszefuzott sztring ertekevel ter vissza
    */
    String operator+(String const& rhs) const;

    /**
    *  Osszeado operator: a sztring vegehet fuzi a parameterkent kapott karaktert
    *@param c a sztringhez hozzafuzendo konstanst karakter
    *@return az osszefuzott sztring ertekevel ter vissza
    */
    String operator+(char const c) const;

    /**
    *  Indexelo operator
    *@param idx a sztringben keresett karakter indexe
    *@return a keresett karakter referenciaja
    */
    char& operator[](size_t idx);

    /**
    *  Indexelo operator
    *@param idx a sztringben keresett karakter indexe
    *@return a keresett karakter erteke
    */
    char operator[] (size_t idx) const;

};





#endif // STRING_H
