#include "string.h"
#include <iostream>
#include <cstring>
#include "gtest_lite.h"
#include "classes.h"
#include "operatorok.h"
#include "menu.h"
#include "memtrace.h"

#ifdef _MSC_VER
// MSC ne adjon figyelmeztetĹ Ăźzenetet a stringkezelĹ fĂźggvĂŠnyekre.
  #define _CRT_SECURE_NO_WARNINGS
#endif

    String::String() :pData(0), len(0) {}



    String::~String() {delete [] pData;}

    String::String(const char c) {
        len = 1;
        pData = new char[2];
        pData[0] = c;
        pData[1] = '\0';
    }

    String::String(const char *s) {
        len = strlen(s);
        pData = new char[len+1];
        strcpy(pData, s);
    }

    String::String(String const& s) {
        // MeghatĂĄrozzuk a hosszĂĄt
        len = s.len;
        // Helyet foglalunk, ha kell
        if ((pData = s.pData) == NULL) return; // Ăźres sztring
        pData = new char[len+1];
        // BemĂĄsoljuk a stringet, ami le van zĂĄrva 0-val Ă­gy hasznĂĄlhatĂł az strcpy is
        strcpy(pData, s.pData);
    }

    String& String::operator=(String const& rhs) {
       if (this != &rhs) {
        delete[] pData;
        len = rhs.len;
        pData = new char [len+1];
        strcpy(pData, rhs.pData);
    }
    return *this;
    }


    bool String::operator==(String const& rhs) {
        const char*masik = rhs.c_str();
        for (unsigned int i = 0; i < len; ++i) {
            if (masik[i] != pData[i]) return false;
        }
        return len == rhs.size();
    }



    String String::operator+(String const& rhs) const {
        String temp;		// ide kerĂźl az eredmĂŠny
        // MeghatĂĄrozza az Ăşj string hosszĂĄt
        temp.len = len + rhs.len;
        // FelszabadĂ­tja a temp adattaerĂźletĂŠt
        delete []temp.pData;
        // lefoglalja a memĂłriĂĄt az Ăşj stringnek.
        if (temp.len == 0) { // ha kĂŠt Ăźres stringet adunk Ăśssze.
            temp.pData = NULL;
            return temp;
        }
        temp.pData = new char[temp.len+1];
        // Az elejĂŠre bemĂĄsolja az elsĹ stringet
        if (pData == NULL)
            temp.pData[0] = '\0';  // ha Ăźres sztring a bal oldal
        else
            strcpy(temp.pData, pData);
    // BemĂĄsolja a mĂĄsodik stringet.
        if (rhs.pData != NULL)   // ha nem Ăźres a jobb oldal
            strcat(temp.pData, rhs.pData);

        return temp;		// visszatĂŠr
    }

    String String::operator+(char const c) const {
        return *this + String(c);
    }

    char& String::operator[](size_t idx) {
        if (idx < 0 || idx>len) throw std::out_of_range("Hibas index");
        return pData[idx];
    }


    char String::operator[] (size_t idx) const {
        if (idx < 0 || idx>len) throw std::out_of_range("Hibas index");
        return pData[idx];
    }



