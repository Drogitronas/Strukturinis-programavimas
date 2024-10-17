#include <future>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 1, 3, 4, 5, 6, 7, 8, 9, 10,1, 1, 3, 4, 5, 6, 7, 8, 9, 10, 1, 6, 3, 4, 5, 6, 7, 8, 9, 10};
    int vienas=0, du=0 , trys=0, keturi=0, penki=0, sesi=0, septyni=0, astuoni=0, devyni=0, desimt=0;
    for (int i = 0; i < 40; i++) {
        if (A[i] == 1) vienas++;
        if (A[i] == 2) du++;
        if (A[i] == 3) trys++;
        if (A[i] == 4) keturi++;
        if (A[i] == 5) penki++;
        if (A[i] == 6) sesi++;
        if (A[i] == 7) septyni++;
        if (A[i] == 8) astuoni++;
        if (A[i] == 9) devyni++;
        if (A[i] == 10) desimt++;

    }
    cout << vienas << " vienas" << endl;
    cout << du << " du" << endl;
    cout << trys << " trys" << endl;
    cout << keturi << " keturi" << endl;
    cout << penki << " penki" << endl;
    cout << sesi << " sesi" << endl;
    cout << septyni << " septyni" << endl;
    cout << astuoni << " astuoni" << endl;
    cout << devyni << " devyni" << endl;
    cout << desimt << " desimt" << endl;
    return 0;
        }