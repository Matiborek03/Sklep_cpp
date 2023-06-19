#ifndef SKLEP_ZAMOWIENIE_H
#define SKLEP_ZAMOWIENIE_H

#include <string>
#include <iostream>

using namespace std;

class zamowienie {
private:

public:
    zamowienie();

    string nazwaProduktu;
    float ilosc;
    float stawkaVAT;
    float cena;
    string dataZamowienia;
    float wartosc;
    string metodaPlatnosci;
    int iloscProduktu;

    zamowienie(string &nazwaProduktu, float ilosc, float stawkaVAT, float cena, string &
    dataZamowienia, float wartosc, string &metodaPlatnosci, int iloscProduktu);

    string getnazwaProduktu() const;

    float getIlosc() const;

    float getstawkaVAT() const;

    float getCena() const;

    string getDataZamowienia() const;

    float getWartosc() const;

    string getMetodaPlatnosci() const;

    int getIloscProduktu() const;

    void setNazwaProduktu(const string &nazwa);

    void setIlosc(float il);

    void setStawkaVAT(float vat);

    void setCena(float c);

    void setDataZamowienia(const string &data);

    void setWartoscZamowienia(float wartosc);

    void setMetodaPlatnosci(const string &metoda);

    void setIloscProduktu(int ilosc);
};


#endif //SKLEP_ZAMOWIENIE_H
