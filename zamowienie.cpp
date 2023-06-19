#include "zamowienie.h"

zamowienie::zamowienie(std::string &nazwaProduktu, float ilosc, float stawkaVAT, float cena,
                       std::string &dataZamowienia, float wartosc, std::string &metodaPlatnosci, int iloscProduktu) {
    this->nazwaProduktu=nazwaProduktu;
    this->ilosc=ilosc;
    this->stawkaVAT=stawkaVAT;
    this->cena=cena;
    this->dataZamowienia=dataZamowienia;
    this->wartosc=ilosc*cena+((ilosc*cena)*stawkaVAT);
    this->metodaPlatnosci=metodaPlatnosci;
    this->iloscProduktu=iloscProduktu;
}


string zamowienie::getnazwaProduktu() const {
    return nazwaProduktu;
}
string zamowienie::getDataZamowienia() const {
    return dataZamowienia;
}
string zamowienie::getMetodaPlatnosci() const{
    return metodaPlatnosci;
}
float zamowienie::getIlosc() const {
    return ilosc;
}
float zamowienie::getCena() const {
    return cena;
}
float zamowienie::getWartosc() const {
    return wartosc;
}
float zamowienie::getstawkaVAT() const {
    return stawkaVAT;
}
int zamowienie::getIloscProduktu() const{
    return iloscProduktu;
}

void zamowienie::setNazwaProduktu(const string &nazwa) {
    nazwaProduktu = nazwa;
}

void zamowienie::setIlosc(float il) {
    ilosc = il;
}

void zamowienie::setStawkaVAT(float vat) {
    stawkaVAT = vat;
}

void zamowienie::setCena(float c) {
    cena = c;
}

void zamowienie::setDataZamowienia(const string &data) {
    dataZamowienia = data;
}

void zamowienie::setWartoscZamowienia(float wartosc) {
    wartosc = wartosc;
}

void zamowienie::setMetodaPlatnosci(const string &metoda) {
    metodaPlatnosci = metoda;
}

void zamowienie::setIloscProduktu(int ilosc) {
    iloscProduktu = ilosc;
}

zamowienie::zamowienie() {

}
