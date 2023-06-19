#include "klient.h"
#include <string>

using namespace std;

klient::klient(string &imie, string &nazwisko, string &adres, string &plec)
        : imie(imie), nazwisko(nazwisko), adres(adres), plec(plec) {}

string klient::getImie() const {
    return imie;
}

string klient::getNazwisko() const {
    return nazwisko;
}

string klient::getAdres() const {
    return adres;
}

string klient::getPlec() const {
    return plec;
}