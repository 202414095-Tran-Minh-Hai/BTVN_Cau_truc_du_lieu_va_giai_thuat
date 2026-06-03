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