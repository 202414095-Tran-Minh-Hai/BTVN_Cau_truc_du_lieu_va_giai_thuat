#include <iostream>
#include <string>
using namespace std;

// luu ten cac thanh pho 
string tenThanhPho[11] = { "Ha Noi", "Hai Duong", "Hung Yen", "Phu Ly", "Hoa Binh", "Son Tay", "Thai Nguyen", "Bac Ninh","Bac Giang", "Uong Bi", "Hai Phong"};

// cau truc hang doi su dung mang de luu tru du lieu
struct Hangdoi {
    int mangluutru[100];
    int dau = 0;
    int cuoi = 0;

    bool rong() {
        return dau == cuoi;
    }

    void them(int giaTri) {
        mangluutru[cuoi] = giaTri;
        cuoi++;
    }

    void xoa() {
        if (!rong()) {
            dau++;
        }
    }

    int xemdau() {
        return mangluutru[dau];
    }
};


//DANH SACH LIEN KET TP

struct Node {
    int iddinh; 
    Node* next;
};

// Mang chua 11 con tro, moi con tro quan ly danh sach cac diem kề cua 1 thanh pho
Node* danhsachke[11] = {NULL};

// Ham tao mat xich moi
Node* taonode(int v) {
    Node* nutmoi = new Node();
    nutmoi->iddinh = v;
    nutmoi->next = NULL;
    return nutmoi;
}

// Ham them 1 tuyen duong 2 chieu vao do thi
void themcanh(int u, int v) {
    // Them v vao danh sach cua u (Them vao dau danh sach)
    Node* nutV = taonode(v);
    nutV->next = danhsachke[u];
    danhsachke[u] = nutV;

    // Them u vao danh sach cua v
    Node* nutU = taonode(u);
    nutU->next = danhsachke[v];
    danhsachke[v] = nutU;
}


// THUAT TOAN DUYET THEO CHIEU RONG (BFS)

void bfsDanhsach(int dinhBatDau) {
    bool datham[11] = { false };
    Hangdoi hanghoi;

    // Cho dinh xuat phat vao hang doi va danh dau
    hanghoi.them(dinhBatDau);
    datham[dinhBatDau] = true;

    cout << "Lo trinh BFS: ";

    // Lap den khi nao hang doi rong
    while (!hanghoi.rong()) {
        int u = hanghoi.xemdau();
        hanghoi.xoa();

        cout << tenThanhPho[u];
        if (!hanghoi.rong() || u == dinhBatDau) cout << " -> ";

        // Quet tat ca cac tuyen duong noi tu thanh pho u
        Node* tam = danhsachke[u];
        while (tam != NULL) {
            int v = tam->iddinh;
            // Neu thanh pho v nay chua den bao gio
            if (!datham[v]) {
                datham[v] = true;   // Danh dau da den
                hanghoi.them(v);    // Xep vao hang doi de quet tiep
            }
            tam = tam->next; // Nhay sang node tiep theo
        }
    }
    cout << "\n xong" << endl;
}

int main() {
    // Khoi tao lai mang 
    for (int i = 0; i < 11; i++) {
        danhsachke[i] = NULL;
    }

    //13 TUYEN DUONG
    // D1, D4, D5, D6, D7, D8 (Tu Ha Noi)
    themcanh(0, 1); // HN - HD
    themcanh(0, 3); // HN - PL
    themcanh(0, 4); // HN - HB
    themcanh(0, 5); // HN - ST
    themcanh(0, 6); // HN - TN
    themcanh(0, 7); // HN - BN

    // D2, D13 (Tu Hai Duong)
    themcanh(1, 2);  // HD - HY
    themcanh(1, 10); // HD - HP

    // D3 (Tu Hung Yen)
    themcanh(2, 3);  // HY - PL

    // D9, D11 (Tu Bac Ninh)
    themcanh(7, 8);  // BN - BG
    themcanh(7, 9);  // BN - UB

    // D10 (Tu Bac Giang)
    themcanh(8, 9);  // BG - UB

    // D12 (Tu Uong Bi)
    themcanh(9, 10); // UB - HP

    cout << "\n KET QUAT DUYET DO THI GIAO THONG:" << endl;

    // Chay thuat toan tu Ha Noi (index = 0)
    bfsDanhsach(0);

    return 0;
}
