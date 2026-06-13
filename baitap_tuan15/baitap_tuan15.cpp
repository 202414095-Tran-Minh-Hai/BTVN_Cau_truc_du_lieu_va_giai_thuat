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
    cout << "-TEST THUAT TOAN BFS (MINI DO THI) : " << endl;

    themcanh(0, 1); // HN(0) - HD(1)
    themcanh(0, 3); // HN(0) - PL(3)
    themcanh(1, 2); // HD(1) - HY(2)

    // Ha Noi -> Phu Ly -> Hai Duong -> Hung Yen
    bfsDanhsach(0);

    return 0;
}
