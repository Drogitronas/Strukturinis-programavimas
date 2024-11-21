#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <cctype>
#include <bits/ranges_algo.h>

using namespace std;

void Pirmas_Budas(int &pasirinkimas);
void Antras_Budas(int &pasirinkimas);

int main() {
    setlocale(LC_ALL, "");

    int pasirinkimas;
    while (true) {
        cout << endl;
        wcout << L"Meniu\n";
        wcout << L"1. Pirmas zaidimas\n";
        wcout << L"2. Antras zaidimas\n";
        wcout << L"3. Iseiti\n";
        wcin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                wcout << L"Pasirinkote pirma zaidima.\n";
                Pirmas_Budas(pasirinkimas);
                break;
            case 2:
                wcout << L"Pasirinkote antra zaidima.\n";
                Antras_Budas(pasirinkimas);
                break;
            case 3:
                wcout << L"Pasirinkote baigti programa\n";
                return 0;
            default:
                wcout << L"Neteisingas pasirinkimas. Bandykite dar kartą.\n";
        }
    }

    return 0;
}

void Pirmas_Budas(int &pasirinkimas) {
    if (pasirinkimas == 1) {
        vector<char> Raide = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        int Pirmas_pasirinkimas;

        wcout << L"1. Šifruoti\n";
        wcout << L"2. Dešifruoti\n";
        wcout << L"3. Grįžti atgal\n";
        wcin >> Pirmas_pasirinkimas;

        switch (Pirmas_pasirinkimas) {
            case 1:
                wcout << L"Pasirinkote šifruoti.\n";
            break;
            case 2:
                wcout << L"Pasirinkote dešifruoti.\n";
            break;
            case 3:
                wcout << L"Grįžot\n\n";
            return;
            default:
                wcout << L"Neteisingas pasirinkimas.\n";
            return;
        }
    if (Pirmas_pasirinkimas == 1 || Pirmas_pasirinkimas == 2) {
            wstring zodis;
            wstring raktas;

            wcout << L"Įveskite žodį:" << endl;
            wcin >> zodis;
            wcout << L"Įveskite raktą:" << endl;
            wcin >> raktas;

            int zodzio_ilgis = zodis.length();
            int raktas_ilgis = raktas.length();

            vector<int> zodzio_skacius(zodzio_ilgis, -1);
            vector<int> raktas_skacius(zodzio_ilgis, -1);
            vector<int> rezultatas_skacius(zodzio_ilgis, -1);

            for (int i = 0; i < zodzio_ilgis; i++) {
                for (int k = 0; k < Raide.size(); k++) {
                    if (Raide[k] == toupper(zodis[i])) {
                        zodzio_skacius[i] = k;
                    }
                    if (Raide[k] == toupper(raktas[i % raktas_ilgis])) {
                        raktas_skacius[i] = k;
                    }
                }
                if (Pirmas_pasirinkimas == 1) {
                    rezultatas_skacius[i] = (zodzio_skacius[i] + raktas_skacius[i]) % Raide.size();
                } else if (Pirmas_pasirinkimas == 2) {
                    rezultatas_skacius[i] = (zodzio_skacius[i] - raktas_skacius[i] + Raide.size()) % Raide.size();
                }

                wcout << Raide[rezultatas_skacius[i]];
            }
            wcout << endl;
        } else if (Pirmas_pasirinkimas == 3) {
            wcout << L"Grįžote atgal.\n";
        } else {
            wcout << L"Neteisingas pasirinkimas.\n";
        }
    }
}
void Antras_Budas(int &pasirinkimas) {
    if (pasirinkimas == 2) {
        int Pirmas_pasirinkimas;

        wcout << L"1. Šifruoti\n";
        wcout << L"2. Dešifruoti\n";
        wcout << L"3. Grįžti atgal\n";
        wcin >> Pirmas_pasirinkimas;

        switch (Pirmas_pasirinkimas) {
            case 1:
                wcout << L"Pasirinkote šifruoti.\n";
            break;
            case 2:
                wcout << L"Pasirinkote dešifruoti.\n";
            break;
            case 3:
                wcout << L"Gryžot\n\n";
            return;
            default:
                wcout << L"Neteisingas pasirinkimas.\n";
            return;
        }
        string zodis;
        string raktas;
        char uzrakintas_zodis;
        string atrakintas_zodis = " ";
        cout << "Yveskite zody " << endl;
        cin >> zodis;
        cout << "Yveskite rakta"<< endl;
        cin >> raktas;

        transform(zodis.begin(), zodis.end(), zodis.begin(), ::toupper);
        transform(raktas.begin(), raktas.end(), raktas.begin(),::toupper);

        if (Pirmas_pasirinkimas == 1) {
            for (int i = 0; i < zodis.length(); i++) {
                uzrakintas_zodis = ((zodis[i] - 32) + (raktas[i % raktas.length()] - 32)) % 95 + 32;
                cout << uzrakintas_zodis;
            }
            cout << endl;
        }

        if (Pirmas_pasirinkimas == 2) {
            for (int i = 0; i < zodis.length(); i++) {
                char atrakintas_zodis = (zodis[i] - (raktas[i % raktas.length()] - 32) + 95) % 95 + 32;
                cout << atrakintas_zodis;
            }
            cout << endl;
        }

        }
    }



