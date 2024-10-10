#include <future>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double GBP_Bendras = 0.8593;
    double GBP_Pirkti = 0.8450;
    double GBP_Parduoti = 0.9060;
    double USD_Bendras = 1.0713;
    double USD_Pirkti = 1.0547;
    double USD_Parduoti = 1.1309;
    double INR_Bendras = 88.8260;
    double INR_Pirkti = 85.2614;
    double INR_Parduoti = 92.8334;

    int pasirinkimas;
    int Antras_pasirinkimas;

    double pirk_valiuta;
    double pard_valiuta;
    string kokia_valiuta;
    string Pirmas_kokia_valiuta;
    string Antras_kokia_valiuta;
    double skaicius;
    double Pirmas_palyginimas;
    double Antras_palyginimas;
    int Trecias_pasirinkimas;
    int Ketvirtas_pasirinkimas;

    printf("Meniu:\n");
    printf("1. Palyginimas\n");
    printf("2. Pirkimas\n");
    printf("3. Pardavimas\n");
    printf("iveskite savo pasirinkima: ");
    scanf("%d", &pasirinkimas);

    switch (pasirinkimas) {
        case 1:
            printf("Jus pasirinkote palyginima.\n");
        break;

        case 2:
            printf("Jus pasirinkote pirkima\n");
        break;
        case 3:
            printf("Jus pasirinkote pardavima \n");
        break;
        default:
            printf("Tokio pasirinkimo nera");
    }
        if (pasirinkimas == 1) {
            printf("Meniu:\n");
            printf("1. GBP\n");
            printf("2. USD\n");
            printf("3. INR\n");
            printf("iveskite savo pasirinkima: ");
            scanf("%d", &Trecias_pasirinkimas);

            switch (Trecias_pasirinkimas) {
                case 1:
                    printf("Jus pasirinkote GBP.\n");
                Pirmas_palyginimas=GBP_Bendras;
                Pirmas_kokia_valiuta="GBP";
                break;

                case 2:
                    printf("Jus pasirinkote USD\n");
                Pirmas_palyginimas=USD_Bendras;
                Pirmas_kokia_valiuta="USD";
                break;
                case 3:
                    printf("Jus pasirinkote INR \n");
                Pirmas_palyginimas=INR_Bendras;
                Pirmas_kokia_valiuta="INR";
                break;
                default:
                    printf("Tokio pasirinkimo nera");
            }
            cout << "Su kokia valiuta lyginsit:" << endl;
            printf("1. GBP\n");
            printf("2. USD\n");
            printf("3. INR\n");
            printf("iveskite savo pasirinkima: ");
            scanf("%d", &Ketvirtas_pasirinkimas);

            switch (Ketvirtas_pasirinkimas) {
                case 1:
                    printf("Jus pasirinkote GBP.\n");
                Antras_palyginimas=GBP_Bendras;
                Antras_kokia_valiuta="GBP";
                break;

                case 2:
                    printf("Jus pasirinkote USD\n");
                Antras_palyginimas=USD_Bendras;
                Antras_kokia_valiuta="USD";
                break;
                case 3:
                    printf("Jus pasirinkote INR \n");
                Antras_palyginimas=INR_Bendras;
                Antras_kokia_valiuta="INR";
                break;
                default:
                    printf("Tokio pasirinkimo nera");
            }
cout << Pirmas_kokia_valiuta << " bendras kursas yra " << Pirmas_palyginimas << endl;
            cout << Antras_kokia_valiuta << " bendras kursa kursa yra " << Antras_palyginimas << endl;

        }


    if (pasirinkimas == 2 || pasirinkimas == 3) {
            printf("Meniu:\n");
            printf("1. GBP\n");
            printf("2. USD\n");
            printf("3. INR\n");
            printf("iveskite savo pasirinkima: ");
            scanf("%d", &Antras_pasirinkimas);

            switch (Antras_pasirinkimas) {
                case 1:
                    printf("Jus pasirinkote GBP.\n");
                pirk_valiuta=GBP_Parduoti;
                pard_valiuta=GBP_Pirkti;
                kokia_valiuta="GBP";
                break;

                case 2:
                    printf("Jus pasirinkote USD\n");
                pirk_valiuta=USD_Parduoti;
                pard_valiuta=USD_Pirkti;
                kokia_valiuta="USD";
                break;
                case 3:
                    printf("Jus pasirinkote INR \n");
                pirk_valiuta=INR_Parduoti;
                pard_valiuta=INR_Pirkti;
                kokia_valiuta="INR";
                break;
                default:
                    printf("Tokio pasirinkimo nera");
            }
            if (pasirinkimas == 2) {
                cout << "Kiek norite nusipirkti: ";
                cin >> skaicius;
            } else if (pasirinkimas == 3) {
                cout << "Kiek norite parduoti: ";
                cin >> skaicius;
            }
            if (pasirinkimas == 2) {
                cout << " Nusipirkote " << fixed << setprecision(2) << skaicius << " " << kokia_valiuta  <<" uz " << fixed << setprecision(2) << skaicius / pard_valiuta  << " eur" <<  endl;
                system("pause");
            } else if (pasirinkimas == 3) {
                cout << " Pardavete " << fixed << setprecision(2) << skaicius << " " << kokia_valiuta  <<" uz " << fixed << setprecision(2) << skaicius / pirk_valiuta  << " eur" <<  endl;
                system("pause");
            }
        }
    return 0;
        }