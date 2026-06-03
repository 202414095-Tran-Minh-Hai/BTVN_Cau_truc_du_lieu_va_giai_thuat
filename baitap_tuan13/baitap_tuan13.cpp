#include <iostream>
using namespace std;

// Dinh nghia cau truc mot nut tren cay
struct Node {
    int data; 
    Node* left;
    Node* right;

    // tao Node moi
    Node(int namsinh) {
        data = namsinh;
        left = NULL;
        right = NULL;
    }
};

// Ham chen nam sinh vao cay
Node* chenNamsinh(Node* nutHientai, int namsinh) {
    if (nutHientai == NULL) {
        return new Node(namsinh);
    }
    // Nho hon -> re trai
    if (namsinh < nutHientai->data) {
        nutHientai->left = chenNamsinh(nutHientai->left, namsinh);
    }
    // Lon hon hoac bang -> re phai 
    else {
        nutHientai->right = chenNamsinh(nutHientai->right, namsinh);
    }
    return nutHientai;
}
// hàm duyệt cây   
void duyetGiua(Node* nutHientai) {
    if (nutHientai != NULL) {
        duyetGiua(nutHientai->left);
        cout << nutHientai->data << " ";
        duyetGiua(nutHientai->right);
    }
}
// hàm tìm sinh viên 
void timnamsinh(Node* nutHientai, int namCanTim) {
    if (nutHientai == NULL) {
        return;
    }

    if (nutHientai->data == namCanTim) {
        cout << "Da tim thay sinh vien sinh nam " << namCanTim << "!" << endl;
        // Vi co the co nhieu ban cung sinh nam 2004 (nam ben nhanh phai), phai tim tiep
        timnamsinh(nutHientai->right, namCanTim);
        return; }

    // nhỉ hơn rẽ trái tìm
    if (namCanTim < nutHientai->data) {
        timnamsinh(nutHientai->left, namCanTim);  }
    // lớn thù rẽ phải tìm
    else {
        timnamsinh(nutHientai->right, namCanTim);
   }
}


int main() {
    int mangNamsinh[] = { 2001, 2002, 2006, 2007, 2003, 2004, 2005, 2001, 1999, 2004 };
    int soLuong = sizeof(mangNamsinh) / sizeof(mangNamsinh[0]);
    Node* goc = NULL;
    for (int i = 0; i < soLuong; i++) {
        goc = chenNamsinh(goc, mangNamsinh[i]);
    }
    cout << "Danh sach nam sinh (Duyet giua): ";
    duyetGiua(goc);
    cout << endl;
    cout << "\n--- Ket qua tim kiem ---" << endl;
    timnamsinh(goc, 2004); 

    return 0;
}