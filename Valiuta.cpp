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
    string Procesas;
    string Pirkti_valiuta;
    string Parduoti_valiuta;
    string Naudojant_valiuta;
    string Pirmas_palyginimas;
    string Antras_palyginimas;
    double Pirmas_lyginimas;
    double Antras_lyginimas;
    double Parduoti;
    double Pirkimas;
    double Pardavimas;
    double Pirmas_Skaicius;
    double Antras_Skaicius;
cout << "Palyginti kursa ar pirkti arba parduoti valiuta" << endl;
    cin >> Procesas;
    if (Procesas == "Pirkti" || Procesas == "pirkti") {
        cout << "Pirkti kuria valiuta " << endl;
        cin >> Pirkti_valiuta;
        cout << "Kokia valiuta pirksite " << Pirkti_valiuta << " -us" <<  endl;
        cin >> Naudojant_valiuta;
    }  else if (Procesas == "Parduoti" || Procesas == "parduoti") {
        cout << "Kokia valiuta parduoti " << endl;
        cin >> Parduoti_valiuta;
        cout << "Uz kokia valiuta parduosite " << Parduoti_valiuta << " -us"<< endl;
        cin >> Naudojant_valiuta;
    } else if (Procesas == "Palyginti kursa" || Procesas == "Palyginti kursa" || Procesas == "Palyginti" || Procesas == "palyginti") {
        cout << "Kiek ir kokiu valiutu kursus palyginti?" << endl;
        cin >> Pirmas_Skaicius >> Pirmas_palyginimas;
        cin >> Antras_Skaicius >> Antras_palyginimas;
        if (Pirmas_palyginimas == "USD" || Pirmas_palyginimas == "Usd" || Pirmas_palyginimas == "usd") {
            Pirmas_lyginimas = USD_Bendras;
        }
        if (Pirmas_palyginimas == "GBP" || Pirmas_palyginimas == "Gbp" || Pirmas_palyginimas == "gbp") {
            Pirmas_lyginimas = GBP_Bendras;
        }
        if (Pirmas_palyginimas == "INR" || Pirmas_palyginimas == "Inr" || Pirmas_palyginimas == "inr") {
            Pirmas_lyginimas = INR_Bendras;
        }
        if (Antras_palyginimas == "USD" || Antras_palyginimas == "Usd" || Antras_palyginimas == "usd") {
            Antras_lyginimas = USD_Bendras;
        }
        if (Antras_palyginimas == "GBP" || Antras_palyginimas == "Gbp" || Antras_palyginimas == "gbp") {
            Antras_lyginimas = GBP_Bendras;
        }
        if (Antras_palyginimas == "INR" || Antras_palyginimas == "Inr" || Antras_palyginimas == "inr") {
            Antras_lyginimas = INR_Bendras;
        }
        double VienasLyginti =  Pirmas_Skaicius / Pirmas_lyginimas ;
        double DuLyginti =  Antras_Skaicius / Antras_lyginimas ;
        cout << "Uz " << Pirmas_Skaicius << " " << Pirmas_palyginimas << " gaunat " << fixed << setprecision(2) << VienasLyginti << " EUR" << endl;
        cout << "O uz " << Antras_Skaicius << " " << Antras_palyginimas << " gaunat " << fixed << setprecision(2) << DuLyginti << " Eur" << endl;
    }

    //-------------------------------valiutos suradimas
    if (Pirkti_valiuta == "GBP" || Pirkti_valiuta == "gbp" || Pirkti_valiuta == "Gbp" && Procesas == "Pirkti" ) {
        Pirkimas = GBP_Pirkti;
    }
    if (Pirkti_valiuta == "USD" ||Pirkti_valiuta == "usd" ||Pirkti_valiuta == "Usd" && Procesas == "Pirkti" ) {
        Pirkimas = USD_Pirkti;
    }
    if (Pirkti_valiuta == "INR" ||Pirkti_valiuta == "inr" ||Pirkti_valiuta == "Inr" && Procesas == "Pirkti" ) {
        Pirkimas = INR_Pirkti;
    }


    if (Parduoti_valiuta == "GBP" || Parduoti_valiuta == "gbp" || Parduoti_valiuta == "Gbp" && Procesas == "Parduoti" ) {
        Parduoti = GBP_Parduoti;
    }
    if (Parduoti_valiuta == "USD" || Parduoti_valiuta == "usd" || Parduoti_valiuta == "Usd" && Procesas == "Parduoti" ) {
        Parduoti = USD_Parduoti;
    }
    if (Parduoti_valiuta == "INR" || Parduoti_valiuta == "inr" || Parduoti_valiuta == "Inr" && Procesas == "Parduoti" ) {
        Parduoti = INR_Parduoti;
    }


    return 0;
}