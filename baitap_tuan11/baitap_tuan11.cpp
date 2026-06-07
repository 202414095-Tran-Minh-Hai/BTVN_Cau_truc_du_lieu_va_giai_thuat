#include <iostream>
using namespace std;

#define MAX_SIZE 50

void khoitaocay(int cay[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        cay[i] = -1; 
    }
}

// Ham in ra cac vi tri co du lieu tren mang
void caytuantu(int cay[], string tenCay) {
    cout << "-" << tenCay << " " << endl;
    for (int i = 1; i < MAX_SIZE; i++) {
        if (cay[i] != -1) {
            cout << "Vi tri mang [" << i << "] = " << cay[i] << endl;
        }
    }
    cout << endl;
}

int main() {
    int caylechtrai[MAX_SIZE];
    int caylechphai[MAX_SIZE];
    int caydicdac[MAX_SIZE];

    khoitaocay(caylechtrai);
    khoitaocay(caylechphai);
    khoitaocay(caydicdac);

    caylechtrai[1] = 1;
    caylechtrai[2] = 2;
    caylechtrai[4] = 3;
    caylechtrai[8] = 4;
    caylechtrai[16] = 5;


    caylechphai[1] = 1;
    caylechphai[3] = 2;
    caylechphai[7] = 3;
    caylechphai[15] = 4;
    caylechphai[31] = 5;

    caydicdac[1] = 1;
    caydicdac[2] = 2;
    caydicdac[5] = 3;
    caydicdac[10] = 4;
    caydicdac[21] = 5;

  
    caytuantu(caylechtrai, "CAY LECH TRAI (TUAN TU)");
    caytuantu(caylechphai, "CAY LECH PHAI (TUAN TU)");
    caytuantu(caydicdac, "CAY DICDAC (TUAN TU)");

    return 0;
}