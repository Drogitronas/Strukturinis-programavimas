#include <iostream>
#include <iomanip>
#include <string>

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

void ShowMenu(menuItemType menu[], int parinktas_Patiekalas[]) {
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

        if (Parinktas == 8) {
            break;
        } else if (Parinktas >= 0 && Parinktas < 8) {
            parinktas_Patiekalas[j++] = Parinktas;
        } else {
            cout << "Neteisingas pasirinkimas, bandykite dar karta." << endl;
        }
    }
    parinktas_Patiekalas[j] = -1;
}

void printCheck(menuItemType menu[], int parinktas_Patiekalas[]) {
    cout << "\nJusu uzsakymas:\n";
    double total = 0.0;
    int Kartu_pirktas[8] = {0};

    for (int i = 0; parinktas_Patiekalas[i] != -1; i++) {
        int index = parinktas_Patiekalas[i];
        Kartu_pirktas[index]++;
    }

    for (int i = 0; i < 8; i++) {
        if (Kartu_pirktas[i] > 0) {
            cout << Kartu_pirktas[i] << " " << menu[i].menuItem << " - "
                    << fixed << setprecision(2) << menu[i].menuPrice * Kartu_pirktas[i] << " EUR" << endl;
            total += menu[i].menuPrice * Kartu_pirktas[i];
        }
    }

    double tax = total * 0.21;
    cout << "Mokesciai: " << fixed << setprecision(2) << tax << " EUR" << endl;
    cout << "Galutine suma: " << fixed << setprecision(2) << (total + tax) << " EUR" << endl;
}

int main() {
    int parinktas_Patiekalas[100];
    menuItemType menu[8];

    getData(menu);
    ShowMenu(menu, parinktas_Patiekalas);
    printCheck(menu, parinktas_Patiekalas);

    return 0;
}
