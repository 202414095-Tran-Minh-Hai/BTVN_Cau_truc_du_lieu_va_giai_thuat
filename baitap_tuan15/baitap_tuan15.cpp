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

int main() {
    cout << "-TEST HANG DOI:" << endl;
    Hangdoi q;

    // cho Ha Noi (0) va Hai Duong (1) vao hang
    q.them(0);
    q.them(1);

    cout << "Tp dung dau hang la: " << tenThanhPho[q.xemdau()] << endl;

    q.xoa(); //kick Ha Noi
    cout << "Sau khi xoa, tp dung dau la: " << tenThanhPho[q.xemdau()] << endl;

    return 0;
}