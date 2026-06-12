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

int main() {
    cout << "TEST DANH SACH LIEN KET- " << endl;
    
    // Thu them tuyen duong: Ha Noi (0) - Hai Duong (1) va Ha Noi (0) - Phu Ly (3)
    themcanh(0, 1);
    themcanh(0, 3);
    
    cout << "Cac thanh pho ke voi " << tenThanhPho[0] << " la: ";
    
    // Duyet danh sach lien ket cua Ha Noi de in ra
    Node* tam = danhSachKe[0];
    while (tam != NULL) {
        cout << tenThanhPho[tam->iddinh] << " - ";
        tam = tam->next;
    }
    cout << "\n=> ds oke" << endl;
    
    return 0;
}