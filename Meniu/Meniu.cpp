#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

void getData(menuItemType menu[]) {
    menu[0] = {"Kiausiniene", 1.45};
    menu[1] = {"Kiaulienos sonine su keptu kiausiniu", 2.45};
    menu[2] = {"Keksiukas su vysnia", 0.99};
    menu[3] = {"Prancuziskas skrebutis", 1.99};
    menu[4] = {"Vaisiu salotos", 2.49};
    menu[5] = {"Pusryciu dribsniai", 0.69};
    menu[6] = {"Kava", 0.50};
    menu[7] = {"Arbata", 0.75};
}

void ShowMenu(menuItemType menu[], int parinktas_Patiekalas[], int Kartu[]) {
    int j = 0;
    cout << "Sveiki atvyke y restorana Bouzaidi!" << endl;

    while (true) {
        for (int i = 0; i < 8; i++) {
            cout << i << " " << menu[i].menuItem << " - "
                    << fixed << setprecision(2) << menu[i].menuPrice << " EUR" << endl;
        }
        cout << "Pasirinkite patiekalo skaiciu, arba jei norite baikti uzsakyma parasykite 8:" << endl;

        int Parinktas;
        cin >> Parinktas;

        int Kartus;
        if (Parinktas != 8) {
            cout << "Kiek norite sito patiekalo porciju: " << endl;
            cin >> Kartus;
        }
        if (Parinktas == 8) {
            break;
        } else if (Parinktas >= 0 && Parinktas < 8) {
            parinktas_Patiekalas[j++] = Parinktas;
            Kartu[j] = Kartus;
        } else {
            cout << "Neteisingas pasirinkimas, bandykite dar karta." << endl;
        }
    }
    parinktas_Patiekalas[j] = -1;
}

void printCheck(menuItemType menu[], int parinktas_Patiekalas[], int Kartu[]) {
    ofstream out("Saskaita.txt");
    cout << "\nJusu uzsakymas:\n";
    out << "\nJusu uzsakymas:\n";
    double total = 0.0;
    int Kartu_pirktas[8] = {0};

    for (int i = 0; parinktas_Patiekalas[i] != -1; i++) {
        int index = parinktas_Patiekalas[i];
        Kartu_pirktas[index] =Kartu[index];
    }

    for (int i = 0; i < 8; i++) {
        if (Kartu_pirktas[i] > 0) {
            cout  << Kartu_pirktas[i] << " "  << setw(40) << menu[i].menuItem << " - " << fixed << setprecision(2) << menu[i].menuPrice * Kartu_pirktas[i] << " EUR" << endl;
            out   << Kartu_pirktas[i] << " " <<right << setw(40) <<menu[i].menuItem << " - " << fixed << setprecision(2) << menu[i].menuPrice * Kartu_pirktas[i] << " EUR" << endl;
            total += menu[i].menuPrice * Kartu_pirktas[i];
        }
    }

    double tax = total * 0.21;
    cout  <<  "Mokesciai: "  << fixed << setprecision(2) << tax << " EUR" << endl;
    cout << "Galutine suma: "  << fixed << setprecision(2) << (total + tax) << " EUR" << endl;
    out  <<  "Mokesciai: "  << fixed << setprecision(2) << tax << " EUR" << endl;
    out << "Galutine suma: "  << fixed << setprecision(2) << (total + tax) << " EUR" << endl;
    out.close();
}

int main() {
    int parinktas_Patiekalas[100], Kartu[100];
    menuItemType menu[8];
    getData(menu);
    ShowMenu(menu, parinktas_Patiekalas, Kartu);
    printCheck(menu, parinktas_Patiekalas, Kartu);
    return 0;
}
