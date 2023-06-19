#ifndef SKLEP_KLIENT_H
#define SKLEP_KLIENT_H

#include <iostream>
#include <string>

using namespace std;

class klient {

private:
    string imie;
    string nazwisko;
    string adres;
    string plec;

public:
    klient(string &imie, string &nazwisko, string &adres, string &plec);

    string getImie() const;

    string getNazwisko() const;

    string getAdres() const;

    string getPlec() const;


};


#endif //SKLEP_KLIENT_H
