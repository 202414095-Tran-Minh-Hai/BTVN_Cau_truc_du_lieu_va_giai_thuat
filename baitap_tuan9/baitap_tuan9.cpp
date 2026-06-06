#include <iostream>
#include <cstring>
using namespace std;

// khai báo cấu trúc
struct Ngay {
    int ngay, thang, nam;
};

struct SinhVien {
    char MSSV[8];
    char hoten[50];
    int gioitinh; // nũ - 0 nam -1
    Ngay ngaysinh;
    char diachi[100];
    char lop[12];
    char khoa[7];
};

struct Node {
    SinhVien data;
    Node* link;
};

struct List {
    Node* sv_dau;
    Node* sv_cuoi;
};

// khởi tạo danh sách rỗng
void Init(List& l) {
    l.sv_dau = l.sv_cuoi = NULL;
}

// Hàm tạo 1 Node mới
Node* Newnode(SinhVien sv) {
    Node* p = new Node;
    if (p == NULL) return NULL;
    p->data = sv;
    p->link = NULL;
    return p;
}

int main() {
  
    return 0;
}