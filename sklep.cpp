#include "sklep.h"


void sklep::dodajKlienta(klient &Klient) {
    klienci.push_back(Klient);
}

void sklep::wyswietlKlientow() {
    for (size_t i = 0; i < klienci.size(); i++) {
        const klient &klient = klienci[i];
        cout << "Indeks: " << i << endl;
        cout << "Imie: " << klient.getImie() << endl;
        cout << "Nazwisko: " << klient.getNazwisko() << endl;
        cout << "Adres: " << klient.getAdres() << endl;
        cout << "Plec: " << klient.getPlec() << endl;
        cout << endl;
    }
}

void sklep::usunKlienta(int indeks) {
    if (indeks >= 0 && indeks < klienci.size()) {
        klienci.erase(klienci.begin() + indeks);
        std::cout << "Klient o indeksie " << indeks << " został usuniety." << std::endl;
    } else {
        std::cout << "Nieprawidłowy indeks klienta." << std::endl;
    }
}

void sklep::zapiszDoPlikuTekstowego() {
    ofstream plik("klienci.txt");

    if (plik.is_open()) {
        for (const auto &klient: klienci) {
            plik << klient.getImie() << ";" << klient.getNazwisko() << ";" << klient.getAdres() << ";"
                 << klient.getPlec() << "\n";
        }

        plik.close();
        cout << "Dane klientow zostaly zapisane do pliku " << endl;
    } else {
        cout << "Nie mozna otworzyc pliku do zapisu." << endl;
    }
}

void sklep::zapiszDoPlikuBinarnego() {
    ofstream plik("klienci.bin", ios::binary);

    if (plik.is_open()) {
        for (const auto &klient: klienci) {
            plik << klient.getImie() << ";" << klient.getNazwisko() << ";" << klient.getAdres() << ";"
                 << klient.getPlec() << "\n";
        }

        plik.close();
        cout << "Dane klientow zostaly zapisane do pliku " << endl;
    } else {
        cout << "Nie mozna otworzyc pliku do zapisu." << endl;
    }
}

void sklep::wczytajZPlikuTekstowego() {
    ifstream plik("klienci.txt");

    if (plik.is_open()) {
        string linia;

        while (getline(plik, linia)) {
            istringstream iss(linia);
            string imie, nazwisko, adres, plec;

            if (getline(iss, imie, ';') &&
                getline(iss, nazwisko, ';') &&
                getline(iss, adres, ';') &&
                getline(iss, plec, ';')) {
                klient Klient(imie, nazwisko, adres, plec);
                dodajKlienta(Klient);
            }
        }

        plik.close();
        cout << "Dane klientow zostaly wczytane z pliku " << endl;
    } else {
        cout << "Nie mozna otworzyc pliku do odczytu." << endl;
    }
}

void sklep::dodajZamowienie(zamowienie &Zamowienie) {
    zamowienia.push_back(Zamowienie);
}

void sklep::wyswietlZamowienia() {
    for (size_t i = 0; i < zamowienia.size(); i++) {
        const zamowienie &zam = zamowienia[i];
        cout << "Indeks: " << i << endl;
        cout << "Nazwa produktu: " << zam.getnazwaProduktu() << endl;
        cout << "Data zamowienia: " << zam.getDataZamowienia() << endl;
        cout << "Metoda platnosci: " << zam.getMetodaPlatnosci() << endl;
        cout << "Ilosc: " << zam.getIlosc() << endl;
        cout << "Cena: " << zam.getCena() << endl;
        cout << "Wartosc: " << zam.getWartosc() << endl;
        cout << "Stawka VAT: " << zam.getstawkaVAT() << endl;
        cout << "Ilosc produktu: " << zam.getIloscProduktu() << endl;
        cout << endl;
    }
}

void sklep::zapiszDoPlikuTekstowegoZamowienia() {
    ofstream plik("zamowienia.txt");

    if (plik.is_open()) {
        for (const auto &zamowienie: zamowienia) {
            plik << zamowienie.getnazwaProduktu() << ";" << zamowienie.getDataZamowienia() << ";"
                 << zamowienie.getMetodaPlatnosci() << ";" << zamowienie.getIlosc() << ";" <<
                 zamowienie.getCena() << ";" << zamowienie.getWartosc() << ";" << zamowienie.getstawkaVAT() << ";"
                 << zamowienie.getIloscProduktu() << "\n";
        }

        plik.close();
        cout << "Dane klientow zostaly zapisane do pliku " << endl;
    } else {
        cout << "Nie mozna otworzyc pliku do zapisu." << endl;
    }
}

void sklep::zapiszDoPlikuBinarnegoZamowienia() {
    ofstream plik("zamowienia.bin", ios::binary);

    if (plik.is_open()) {
        for (const auto &zamowienie: zamowienia) {
            plik << zamowienie.getnazwaProduktu() << ";" << zamowienie.getDataZamowienia() << ";"
                 << zamowienie.getMetodaPlatnosci() << ";" << zamowienie.getIlosc() << ";" <<
                 zamowienie.getCena() << ";" << zamowienie.getWartosc() << ";" << zamowienie.getstawkaVAT() << ";"
                 << zamowienie.getIloscProduktu() << "\n";
        }

        plik.close();
        cout << "Dane klientow zostaly zapisane do pliku " << endl;
    } else {
        cout << "Nie mozna otworzyc pliku do zapisu." << endl;
    }
}

void sklep::wczytajZPlikuTekstowegoZamowienia() {
    ifstream plik("zamowienia.txt");

    if (plik.is_open()) {
        string linia;

        while (getline(plik, linia)) {
            istringstream iss(linia);
            string nazwaProduktu, dataZamowienia, metodaPlatnosci;
            string iloscStr, cenaStr, wartoscStr, stawkaVATStr, iloscProduktuStr;

            if (getline(iss, nazwaProduktu, ';') &&
                getline(iss, dataZamowienia, ';') &&
                getline(iss, metodaPlatnosci, ';') &&
                getline(iss, iloscStr, ';') &&
                getline(iss, cenaStr, ';') &&
                getline(iss, wartoscStr, ';') &&
                getline(iss, stawkaVATStr, ';') &&
                getline(iss, iloscProduktuStr)) {
                float ilosc = stof(iloscStr);
                float cena = stof(cenaStr);
                float wartosc = stof(wartoscStr);
                float stawkaVAT = stof(stawkaVATStr);
                int iloscProduktu = stoi(iloscProduktuStr);

                zamowienie zamowienie(nazwaProduktu, ilosc, stawkaVAT, cena, dataZamowienia, wartosc, metodaPlatnosci,
                                      iloscProduktu);
                dodajZamowienie(zamowienie);
            }
        }

        plik.close();
        cout << "Dane zamowien zostaly wczytane z pliku " << endl;
    } else {
        cout << "Nie mozna otworzyc pliku do odczytu." << endl;
    }
}

void sklep::wczytajProdukty() {
    ifstream plik("produkty.txt");

    if (plik.is_open()) {
        string linia;

        while (getline(plik, linia)) {
            istringstream iss(linia);
            string nazwaProduktu, iloscProduktuStr;
            int iloscProduktu;

            if (getline(iss, nazwaProduktu, ';') && getline(iss, iloscProduktuStr, ';')) {
                try {
                    iloscProduktu = stoi(iloscProduktuStr);
                    produkt Produkt(nazwaProduktu, iloscProduktu);
                    dodajProdukt(Produkt);
                } catch (const exception &e) {
                    cout << "Blad konwersji ilosci produktu: " << e.what() << endl;
                }
            }
        }

        plik.close();
        cout << "Dane produktow zostaly wczytane z pliku " << endl;
    } else {
        cout << "Nie mozna otworzyc pliku do odczytu." << endl;
    }
}


void sklep::wyswietlProdukty() {
    for (const auto &produkt: produkty) {
        cout << "Nazwa produktu: " << produkt.getNazwa() << endl;
        cout << "Ilosc: " << produkt.getIlosc() << endl;
        cout << endl;
    }
}
void sklep::dodajProdukt(const produkt &Produkt) {
    produkty.push_back(Produkt);
}






