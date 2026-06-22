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
// Cac mang ho tro
int truoc[11];
int khoangcachmin[11];

void dijkstra(int dinhBatDau) {
    bool daDuyet[11] = { false };

    for (int i = 0; i < 11; i++) {
        khoangcachmin[i] = chua_xay_duong;
        truoc[i] = -1;
    }
    khoangcachmin[dinhBatDau] = 0;

    // Vong lap quet cac dinh
    for (int i = 0; i < 10; i++) {
        int min = chua_xay_duong;
        int u = -1;

        for (int v = 0; v < 11; v++) {
            if (!daDuyet[v] && khoangcachmin[v] <= min) {
                min = khoangcachmin[v];
                u = v;
            }
        }

        if (u == -1)
            break;

        daDuyet[u] = true;

        // Cap nhat lai khoang cach cho cac láng giềng
        for (int v = 0; v < 11; v++) {
            if (!daDuyet[v] && dothi[u][v] != chua_xay_duong &&
                khoangcachmin[u] + dothi[u][v] < khoangcachmin[v]) {

                khoangcachmin[v] = khoangcachmin[u] + dothi[u][v];
                truoc[v] = u;
            }
        }
    }
}