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
// in ra lo trinh
void inDuongdi(int batdau, int ketThuc) {
    if (khoangcachmin[ketThuc] == chua_xay_duong) {
        cout << "X Khong co duong di tu " << tenthanhpho[batdau] << " den " << tenthanhpho[ketThuc] << endl;
        return;
    }

    cout << "=> Tong chieu dai ngan nhat: " << khoangcachmin[ketThuc] << " km" << endl;
    cout << "=> Lo trinh di chuyen: ";

    int duongDi[11];
    int sodinhdiqua = 0;
    int tam = ketThuc;

    // Lan nguoc tu ket thuc ve bat dau
    while (tam != -1) {
        duongDi[sodinhdiqua] = tam;
        sodinhdiqua++;
        tam = truoc[tam];
    }

    // In chieu thuan
    for (int i = sodinhdiqua - 1; i >= 0; i--) {
        cout << tenthanhpho[duongDi[i]];
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}
int main() {
    khoitaoDothi();

    // Nap cac tuyen duong mo phong theo ban do
    themcanh(0, 1, 60);  // HN - HD
    themcanh(0, 3, 55);  // HN - PL
    themcanh(0, 4, 75);  // HN - HB
    themcanh(0, 5, 40);  // HN - ST
    themcanh(0, 6, 80);  // HN - TN
    themcanh(0, 7, 30);  // HN - BN

    themcanh(1, 2, 45);  // HD - HY
    themcanh(1, 10, 45); // HD - HP

    themcanh(2, 3, 35);  // HY - PL

    themcanh(7, 8, 20);  // BN - BG
    themcanh(7, 9, 85);  // BN - UB

    themcanh(8, 9, 70);  // BG - UB

    themcanh(9, 10, 40); // UB - HP

    cout << "DUONG DI NGAN NHAT=" << endl;

    int diemXp1 = 0; // Ha Noi
    int diemden = 10;     // Hai Phong

    // Tinh toan khoang cach tu Ha Noi den moi noi
    dijkstra(diemXp1);

    cout << "\nTim duong tu [" << tenthanhpho[diemXp1] << "] den [" << tenthanhpho[diemden] << "]:" << endl;
    inDuongdi(diemXp1, diemden);

    cout << " " << endl;

    int diemXp2 = 4; // Hoa Binh
    int diemden2 = 9;      // Uong Bi

    // Tinh toan lai khoang cach xuat phat tu Hoa Binh
    dijkstra(diemXp2);

    cout << "Tim duong tu [" << tenthanhpho[diemXp2] << "] den [" << tenthanhpho[diemden2   ] << "]:" << endl;
    inDuongdi(diemXp2, diemden2);

    return 0;
}