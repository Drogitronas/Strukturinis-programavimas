
#include <iomanip>
#include <iostream>
#include <cstdlib>

using namespace std;

void Raides (int &pasirinkimas, char raide);
void Euklidas (int skaicius1, int skaicius2, int &pasirinkimas, int dbd );
void Skaiciaus_spejimas (int &pasirinkimas);
void fizzbuzz (int &pasirinkimas, int n);
int main() {
    int skaicius1, skaicius2, pasirinkimas, dbd, n;
    char raide;
    string pabaiga;
cout << "Galite sustabdyti programa, parasydami 5 ." << endl;
    cout << endl;
    cout << endl;

while (true) {
    printf("Meniu:\n");
    printf("1. Raides\n");
    printf("2. Euklidas\n");
    printf("3. Skaiciaus spejimas\n");
    printf("4. Fizzbuzz\n");
    printf("5. iseiti\n");
    printf("iveskite savo pasirinkima: ");
    scanf("%d", &pasirinkimas);

    cout << endl;
    switch (pasirinkimas) {
        case 1:
            printf("Jus pasirinkote raidziu zaidima.\n");
        break;

        case 2:
            printf("Jus pasirinkote euklido zaidima\n");
        break;
        case 3:
            printf("Jus pasirinkote spejimo zaidima \n");
        break;
        case 4:
            printf("Jus pasirinkote fizzbuzz zaidima \n");
        break;
        case 5:
            printf("Jus isejote is programos\n");
        break;
        default:
            printf("Tokio pasirinkimo nera");
    }
cout << endl;
    Raides(pasirinkimas,raide);
    Euklidas(skaicius1,skaicius2,pasirinkimas,dbd);
    Skaiciaus_spejimas(pasirinkimas);
    fizzbuzz(pasirinkimas,n);

    if (pasirinkimas == 5) {
        break;
    }
}

return 0;
    }
    void Raides (int &pasirinkimas, char raide) {
    if (pasirinkimas ==1) {
        cout << pasirinkimas << endl;
        cout << "Iveskite raide:" << endl;
        cin >> raide;
        if (raide == 'A' || raide == 'a' || raide == 'Ą' || raide == 'ą' ||
                raide == 'E' || raide == 'e' || raide == 'Ę' || raide == 'ę' ||
                raide == 'Ė' || raide == 'ė' || raide == 'I' || raide == 'i' ||
                raide == 'Į' || raide == 'į' || raide == 'Y' || raide == 'y' ||
                raide == 'O' || raide == 'o' || raide == 'U' || raide == 'u' ||
                raide == 'Ų' || raide == 'ų' || raide == 'Ū' || raide == 'ū'){
            cout << "True" << endl;
                }else cout << "False" << endl;
    }
}
void Euklidas (int skaicius1, int skaicius2, int &pasirinkimas, int dbd ) {
if (pasirinkimas ==2) {
cout << "Yveskite pirmus skaicius"  << endl;
    cin >> skaicius1;
    cout << "Yveskite antrus skacius" << endl;
    cin >> skaicius2;
    while (abs(skaicius1) != 0 && abs(skaicius2) != 0) {
        if (abs(skaicius1) > abs(skaicius2)) {
            skaicius1 %= skaicius2;
        } else {
            skaicius2 %= skaicius1;
        }
    }
    dbd = skaicius1 + skaicius2;
cout << dbd << endl;
}
}
void Skaiciaus_spejimas (int &pasirinkimas) {
    if (pasirinkimas == 3) {
        int Spejimas=0;
        srand(time(nullptr));
        int r = rand() % 100 ;

        while (Spejimas != r) {
            cin >> Spejimas;
            if (Spejimas>r) {
                cout << "Jusu spejimas per didelis" << endl;
            }
            if (Spejimas<r) {
                cout << "Jusu spejimas per mazas" << endl;
            }
            if (Spejimas==r){
                cout << "Jusu spejimas teisingas!" << endl;
            }
        }
    }
}
void fizzbuzz (int &pasirinkimas, int n) {
    if (pasirinkimas == 4) {
        int Skaicius=0;
        cout << "Yveskite teigiama kintamajy skaiciu: ";
        cin >> Skaicius;
        for (int i = 1; i <= Skaicius; i++) {
            if (i % 3 ==0 && i % 5 ==0) {
                cout << "Fizzbuzz" << endl;

            }if (i % 3 ==0) {cout << "Fizz" << endl;
        }if (i % 5 ==0) {cout << "Buzz" << endl;}else cout << i << endl;
        }

    }
}