#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int kocoduongdi = 1000000000;

string tentp[11] = {  "Ha Noi", "Hai Duong", "Hung Yen", "Phu Ly", "Hoa Binh", "Son Tay", "Thai Nguyen", "Bac Ninh", "Bac Giang", "Uong Bi", "Hai Phong"};

int matran[11][11];

// Khoi tao do thi
void taodothi() {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (i == j) matran[i][j] = 0;
            else matran[i][j] = kocoduongdi;
        }
    }
}

void themcanh(int u, int v, int trongSo) {
    matran[u][v] = trongSo;
    matran[v][u] = trongSo;
}

// Ham in Ma tran dinh ke 
void inmatran(int maTran[11][11]) {
    for (int i = 0; i < 11; i++) cout << i << "\t";
    cout << "\n";
    for (int i = 0; i < 11; i++) {
        cout << " " << i << " | ";
        for (int j = 0; j < 11; j++) {
            if (maTran[i][j] == kocoduongdi || i == j) cout << "0\t"; // In 0 neu khong co canh noi
            else cout << maTran[i][j] << "\t";                   // In ra trong so
        }
        cout << "\n";
    }
}