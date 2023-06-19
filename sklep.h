#ifndef SKLEP_SKLEP_H
#define SKLEP_SKLEP_H

#include <string>
#include <iostream>
#include <vector>
#include "klient.h"
#include "zamowienie.h"
#include <fstream>
#include <sstream>
#include "produkt.h"

class sklep {
private:
    vector<klient> klienci;
    vector<produkt> produkty;


public:
    void dodajKlienta(klient &Klient);

    void wyswietlKlientow();

    void usunKlienta(int indeks);

    void zapiszDoPlikuTekstowego();

    void zapiszDoPlikuBinarnego();

    void wczytajZPlikuTekstowego();

    void dodajZamowienie(zamowienie &Zamowienie);

    void wyswietlZamowienia();

    void zapiszDoPlikuTekstowegoZamowienia();

    void zapiszDoPlikuBinarnegoZamowienia();

    void wczytajZPlikuTekstowegoZamowienia();

    void wczytajProdukty();

    void wyswietlProdukty();

    void dodajProdukt(const produkt &Produkt);

    vector<zamowienie> zamowienia;
};

#endif //SKLEP_SKLEP_H
