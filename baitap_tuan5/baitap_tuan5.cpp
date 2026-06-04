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

// Ham duyet va in danh sach
void inDanhSach(Node* head) {
    if (head == NULL) {
        cout << "Danh sach sinh vien dang trong" << endl;
        return;
    }

    cout << "\nDANH SACH SINH VIEN" << endl;
    Node* nutHientai = head;
    int stt = 1;

    while (nutHientai != NULL) {
        cout << "SV " << stt << ": " << nutHientai->data.hoTen
            << " | Ngay sinh: " << nutHientai->data.ngaySinh
            << " | Lop: " << nutHientai->data.lop
            << " | GPA: " << nutHientai->data.gpa << endl;

        nutHientai = nutHientai->next; 
        stt++;
    }
}

// Ham giai phong bo nho cho danh sach
void giaiphongbonho(Node*& head) {
    Node* nutHientai = head;
    while (nutHientai != NULL) {
        Node* nutCanXoa = nutHientai;   
        nutHientai = nutHientai->next;
        delete nutCanXoa;               
    }
    head = NULL;
}

int main() {
    Node* danhSachSV = NULL;
    int soLuong;

    cout << "Nhap so luong sinh vien: ";
    cin >> soLuong;

    cin.ignore();

    for (int i = 1; i <= soLuong; i++) {
        SinhVien sv;
        cout << "\n Nhap thong tin sinh vien thu " << i << ": " << endl;

        cout << "Nhap ho ten: ";

        getline(cin, sv.hoTen); 

        cout << "Nhap ngay sinh: ";

        getline(cin, sv.ngaySinh);

        cout << "Nhap lop: ";

        getline(cin, sv.lop);

        cout << "Nhap diem GPA: ";
        cin >> sv.gpa;

        cin.ignore();

        themSinhVien(danhSachSV, sv);
    }

    // in ra man hinh de kiem tra
    inDanhSach(danhSachSV);

    giaiphongbonho(danhSachSV); 

    return 0;
}