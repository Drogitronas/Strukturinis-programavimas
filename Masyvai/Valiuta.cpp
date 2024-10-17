#include <future>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
int A[100];
    int suma=0, maziausias=9999, didziausias=0;
    for (int i = 0; i < 5; i++) {
        cin >> A[i];

    }
    for (int i = 0; i < 5; i++) {
        suma = suma + A[i];
if (maziausias > A[i]) {
    maziausias = A[i];
}
        if (didziausias < A[i]) {
            didziausias = A[i];
        }
    }
    cout << "suma: " << suma << endl;
    cout << "maziausias: " << maziausias << endl;
    cout << "didziausias: " << didziausias << endl;
    return 0;
        }