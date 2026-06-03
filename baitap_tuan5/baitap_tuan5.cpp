#include <iostream>
#include <string>
using namespace std;

// dinh nghia cau truc sinh vien
struct SinhVien {
    string hoTen;
    string ngaySinh;
    string lop;
    float gpa;
};

// dịnh nghia 1 node
struct Node {
    SinhVien data; 
    Node* next;    
};

// ham tao ra 1 node
Node* taoNode(SinhVien sv) {
    Node* nutMoi = new Node(); 
    nutMoi->data = sv;         
    nutMoi->next = NULL;       
    return nutMoi;
}
// Ham them mot sinh vien vao cuoi danh sach
void themSinhVien(Node*& head, SinhVien sv) {
    Node* nutMoi = taoNode(sv);

    // Th1:  Danh sach dang rong, nut moi se thanh nut dau tien (head) luon
    if (head == NULL) {
        head = nutMoi;
        return;
    }

    // Th2: Danh sach da co nguoi. Ta phai duyet den cuoi cung de noi vao.
    Node* nutHientai = head;
    while (nutHientai->next != NULL) {
        nutHientai = nutHientai->next;
    }

    // Noi nut moi vao sau nut cuoi cung
    nutHientai->next = nutMoi;
}
