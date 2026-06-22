#include <iostream>
#include <string>
using namespace std;

const int chua_xay_duong = 15062006;

string tenthanhpho[11] = {
    "Ha Noi", "Hai Duong", "Hung Yen", "Phu Ly",
    "Hoa Binh", "Son Tay", "Thai Nguyen", "Bac Ninh",
    "Bac Giang", "Uong Bi", "Hai Phong"
};

int dothi[11][11];

// Ham khoi tao do thi ban dau
void khoitaoDothi() {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (i == j) dothi[i][j] = 0;
            else dothi[i][j] = chua_xay_duong; 
        }
    }
}

// Ham them tuyen duong
void themcanh(int u, int v, int khoangcach) {
    dothi[u][v] = khoangcach;
    dothi[v][u] = khoangcach;
}