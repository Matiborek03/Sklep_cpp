//
// Created by Mateusz on 19.06.2023.
//

#ifndef SKLEP_PRODUKT_H
#define SKLEP_PRODUKT_H

#include <string>

using namespace std;

class produkt {
private:
    string nazwa;
    int ilosc;

public:
    produkt(const string &nazwa, int ilosc) : nazwa(nazwa), ilosc(ilosc) {}

    string getNazwa() const;

    int getIlosc() const;
};


#endif //SKLEP_PRODUKT_H
