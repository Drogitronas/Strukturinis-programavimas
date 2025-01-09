#include <iostream>
#include <string>
using namespace std;

struct Kontaktas {
    int id;
    string vardas;
    string pavarde;
    string telefonoNumeris;
};

void Pirmas(int pasirinkimas);
void Antras(int pasirinkimas);
void pridetiKontaktą(Kontaktas*& kontaktai, int& kontaktuKiekis);
void spausdintiKontaktus(Kontaktas* kontaktai, int kontaktuKiekis);
void istrintiKontakta(Kontaktas*& kontaktai, int& kontaktuKiekis, int id);
void redaguotiKontakta(Kontaktas* kontaktai, int kontaktuKiekis, int id);
void istrintiVisusKontaktus(Kontaktas*& kontaktai, int& kontaktuKiekis);

int main() {
    int pasirinkimas;
    cout << "Pasirinkite, kuri zaidima norite zaisti (1-2): " << endl;
    cin >> pasirinkimas;

    Pirmas(pasirinkimas);
    Antras(pasirinkimas);

    return 0;
}

void Pirmas(int pasirinkimas) {
    if (pasirinkimas == 1) {
        int x, y;
        cout << "Iveskite lenteles eiluciu skaiciu: " << endl;
        cin >> x;
        cout << "Iveskite lenteles stulpeliu skaiciu: " << endl;
        cin >> y;

        int** lentele = new int*[x];
        for (int i = 0; i < x; i++) {
            lentele[i] = new int[y];
        }

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                cout << "Iveskite reiksme [" << i << "][" << j << "]: " << endl;
                cin >> lentele[i][j];
            }
        }

        for (int i = 0; i < x; i++) {
            int eilutesSuma = 0;
            for (int j = 0; j < y; j++) {
                eilutesSuma += lentele[i][j];
                cout << "[" << lentele[i][j] << "] ";
            }
            cout << " - Eilutes suma: " << eilutesSuma << endl;
        }

        for (int j = 0; j < y; j++) {
            int stulpelioSuma = 0;
            for (int i = 0; i < x; i++) {
                stulpelioSuma += lentele[i][j];
            }
            cout << "Stulpelio " << j << " suma: " << stulpelioSuma << endl;
        }

        int didziausiaReiksme = lentele[0][0];
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (lentele[i][j] > didziausiaReiksme) {
                    didziausiaReiksme = lentele[i][j];
                }
            }
        }
        cout << "Didziausia reiksme lenteleje: " << didziausiaReiksme << endl;

        for (int i = 0; i < x; i++) {
            delete[] lentele[i];
        }
        delete[] lentele;
    }
}

void Antras(int pasirinkimas) {
    if (pasirinkimas == 2) {
        Kontaktas* kontaktai = nullptr;
        int kontaktuKiekis = 0;
        int veiksmas;

        while (1) {
            cout << "\nPasirinkite veiksma:\n";
            cout << "1. Prideti kontakta\n";
            cout << "2. Spaudinti kontaktus\n";
            cout << "3. Redaguoti kontakta pagal ID\n";
            cout << "4. Istrinti kontakta pagal ID\n";
            cout << "5. Istrinti visus kontaktus\n";
            cout << "6. Baigti\n";
            cout << "Jusu pasirinkimas: ";
            cin >> veiksmas;

            if (veiksmas == 1) {
                pridetiKontaktą(kontaktai, kontaktuKiekis);
            } else if (veiksmas == 2) {
                spausdintiKontaktus(kontaktai, kontaktuKiekis);
            } else if (veiksmas == 3) {
                int id;
                cout << "Iveskite kontakto ID, kuri norite redaguoti: ";
                cin >> id;
                redaguotiKontakta(kontaktai, kontaktuKiekis, id);
            } else if (veiksmas == 4) {
                int id;
                cout << "Iveskite kontakto ID, kuri norite istrinti: ";
                cin >> id;
                istrintiKontakta(kontaktai, kontaktuKiekis, id);
            } else if (veiksmas == 5) {
                istrintiVisusKontaktus(kontaktai, kontaktuKiekis);
            } else if (veiksmas == 6) {
                cout << "Programa baigta." << endl;
                delete[] kontaktai;
                return;
            } else {
                cout << "Neteisingas pasirinkimas, bandykite dar karta.\n";
            }
        }
    }
}

void pridetiKontaktą(Kontaktas*& kontaktai, int& kontaktuKiekis) {
    Kontaktas naujasKontaktas;
    naujasKontaktas.id = kontaktuKiekis + 1;

    cout << "Iveskite varda: ";
    cin >> naujasKontaktas.vardas;
    cout << "Iveskite pavarde: ";
    cin >> naujasKontaktas.pavarde;
    cout << "Iveskite telefono numeri: ";
    cin >> naujasKontaktas.telefonoNumeris;

    Kontaktas* naujiKontaktai = new Kontaktas[kontaktuKiekis + 1];

    for (int i = 0; i < kontaktuKiekis; ++i) {
        naujiKontaktai[i] = kontaktai[i];
    }

    naujiKontaktai[kontaktuKiekis] = naujasKontaktas;

    delete[] kontaktai;
    kontaktai = naujiKontaktai;
    ++kontaktuKiekis;

    cout << "Kontaktas pridetas!\n";
}

void spausdintiKontaktus(Kontaktas* kontaktai, int kontaktuKiekis) {
    if (kontaktuKiekis == 0) {
        cout << "Kontaktu nera." << endl;
        return;
    }
    for (int i = 0; i < kontaktuKiekis; ++i) {
        cout << "ID: " << kontaktai[i].id
             << ", Vardas: " << kontaktai[i].vardas
             << ", Pavarde: " << kontaktai[i].pavarde
             << ", Telefonas: " << kontaktai[i].telefonoNumeris
             << endl;
    }
}

void istrintiKontakta(Kontaktas*& kontaktai, int& kontaktuKiekis, int id) {
    int rastas = 0;
    int istrintiIndex = -1;

    for (int i = 0; i < kontaktuKiekis; ++i) {
        if (kontaktai[i].id == id) {
            istrintiIndex = i;
            rastas = 1;
            break;
        }
    }

    if (rastas == 1) {
        Kontaktas* naujiKontaktai = new Kontaktas[kontaktuKiekis - 1];

        for (int i = 0, j = 0; i < kontaktuKiekis; ++i) {
            if (i != istrintiIndex) {
                naujiKontaktai[j++] = kontaktai[i];
            }
        }

        delete[] kontaktai;
        kontaktai = naujiKontaktai;
        --kontaktuKiekis;

        cout << "Kontaktas istrintas!" << endl;
    } else {
        cout << "Kontaktas su tokiu ID nerastas." << endl;
    }
}

void redaguotiKontakta(Kontaktas* kontaktai, int kontaktuKiekis, int id) {
    int rastas = 0;
    for (int i = 0; i < kontaktuKiekis; ++i) {
        if (kontaktai[i].id == id) {
            cout << "Redaguojamas kontaktas:\n";
            cout << "Iveskite nauja varda: ";
            cin >> kontaktai[i].vardas;
            cout << "Iveskite nauja pavarde: ";
            cin >> kontaktai[i].pavarde;
            cout << "Iveskite nauja telefono numeri: ";
            cin >> kontaktai[i].telefonoNumeris;
            cout << "Kontaktas atnaujintas!" << endl;
            rastas = 1;
            break;
        }
    }
    if (rastas == 0) {
        cout << "Kontaktas su tokiu ID nerastas." << endl;
    }
}

void istrintiVisusKontaktus(Kontaktas*& kontaktai, int& kontaktuKiekis) {
    delete[] kontaktai;
    kontaktai = nullptr;
    kontaktuKiekis = 0;

    cout << "Visi kontaktai istrinti!" << endl;
}
