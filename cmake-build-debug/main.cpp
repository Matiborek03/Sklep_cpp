#include <iostream>
#include "klient.h"
#include "zamowienie.h"
#include "sklep.h"

int main() {
    sklep sklep_obj;
    sklep_obj.wczytajZPlikuTekstowego();
    sklep_obj.wczytajZPlikuTekstowegoZamowienia();
    sklep_obj.wczytajProdukty();

    int wybor;
    while (true) {
        cout << "Menu" << endl;
        cout << "1. Dodaj klienta" << endl;
        cout << "2. Wyswietl klientow" << endl;
        cout << "3. Usun klienta" << endl;
        cout << "4. Zapisz klientow do pliku tekstowego" << endl;
        cout << "5. Zapisz klientow do pliku binarnego" << endl;
        cout << "6. Dodaj zamowienie" << endl;
        cout << "7. Modyfikuj zamowienie" << endl;
        cout << "8. Wyswietl zamowienia" << endl;
        cout << "9. Zapisz zamowienia do pliku tekstowego" << endl;
        cout << "10. Zapisz zamowienia do pliku binarnego" << endl;
        cout << "11. Wyswietl produkty" << endl;
        cin >> wybor;

        switch (wybor) {
            case 1: {
                string imie, nazwisko, adres, plec;
                cout << "Podaj imie: ";
                cin >> imie;
                cout << "Podaj nazwisko: ";
                cin >> nazwisko;
                cout << "Podaj adres: ";
                cin >> adres;
                cout << "Podaj plec: ";
                cin >> plec;
                klient Klient(imie, nazwisko, adres, plec);
                sklep_obj.dodajKlienta(Klient);
                break;
            }
            case 2: {
                sklep_obj.wyswietlKlientow();
                break;
            }
            case 3: {
                int indeks;
                std::cout << "Podaj indeks klienta do usuniecia: ";
                std::cin >> indeks;
                sklep_obj.usunKlienta(indeks);
                break;
            }
            case 4: {
                sklep_obj.zapiszDoPlikuTekstowego();
                break;
            }
            case 5: {
                sklep_obj.zapiszDoPlikuBinarnego();
                break;
            }
            case 6: {
                sklep_obj.wyswietlProdukty();
                string nazwaProduktu, dataZamowienia, metodaPlatnosci;
                float ilosc, stawkaVAT, cena;
                int iloscProduktu;

                cout << "Podaj nazwe produktu: ";
                cin >> nazwaProduktu;
                cout << "Podaj date zamowienia: ";
                cin >> dataZamowienia;
                cout << "Podaj metode platnosci: ";
                cin >> metodaPlatnosci;
                cout << "Podaj ilosc: ";
                cin >> ilosc;
                cout << "Podaj cene: ";
                cin >> cena;
                cout << "Podaj stawke VAT: ";
                cin >> stawkaVAT;
                cout << "Podaj ilosc produktu: ";
                cin >> iloscProduktu;

                zamowienie Zamowienie(nazwaProduktu, ilosc, stawkaVAT, cena, dataZamowienia, 0.0, metodaPlatnosci,
                                      iloscProduktu);
                sklep_obj.dodajZamowienie(Zamowienie);
                break;
            }
            case 7: {
                int indeks;
                string nazwaProduktu, dataZamowienia, metodaPlatnosci;
                float ilosc, stawkaVAT, cena;
                int iloscProduktu;

                cout << "Podaj indeks zamowienia do modyfikacji: ";
                cin >> indeks;

                if (indeks >= 0 && indeks < sklep_obj.zamowienia.size()) {
                    cout << "Podaj nowe dane zamowienia:" << endl;
                    cout << "Podaj nazwe produktu: ";
                    cin >> nazwaProduktu;
                    cout << "Podaj date zamowienia: ";
                    cin >> dataZamowienia;
                    cout << "Podaj metode platnosci: ";
                    cin >> metodaPlatnosci;
                    cout << "Podaj ilosc: ";
                    cin >> ilosc;
                    cout << "Podaj cene: ";
                    cin >> cena;
                    cout << "Podaj stawke VAT: ";
                    cin >> stawkaVAT;
                    cout << "Podaj ilosc produktu: ";
                    cin >> iloscProduktu;

                    zamowienie &zamowienie = sklep_obj.zamowienia[indeks];
                    zamowienie.setNazwaProduktu(nazwaProduktu);
                    zamowienie.setDataZamowienia(dataZamowienia);
                    zamowienie.setMetodaPlatnosci(metodaPlatnosci);
                    zamowienie.setIlosc(ilosc);
                    zamowienie.setCena(cena);
                    zamowienie.setStawkaVAT(stawkaVAT);
                    zamowienie.setIloscProduktu(iloscProduktu);

                    cout << "Zamowienie o indeksie " << indeks << " zostalo zaktualizowane." << endl;
                } else {
                    cout << "Nieprawidlowy indeks zamowienia." << endl;
                }
                break;
            }
            case 8: {
                sklep_obj.wyswietlZamowienia();
                break;
            }
            case 9: {
                sklep_obj.zapiszDoPlikuTekstowegoZamowienia();
                break;
            }
            case 10: {
                sklep_obj.zapiszDoPlikuBinarnegoZamowienia();
                break;
            }
            case 11: {
                sklep_obj.wyswietlProdukty();
                break;
            }
            default:
                cout << "Niepoprawny wybor" << endl;
                break;
        }
    }

    return 0;

}
