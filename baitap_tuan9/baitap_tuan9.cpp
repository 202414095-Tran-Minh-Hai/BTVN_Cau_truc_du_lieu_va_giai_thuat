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

// Hàm thêm vào cuối danh sách 
void ThemCuoiDS(List& l, Node* p) {
    if (l.sv_dau == NULL) {
        l.sv_dau = l.sv_cuoi = p;
    }
    else {
        l.sv_cuoi->link = p;
        l.sv_cuoi = p;
    }
}

// Hàm nhập 1 sinh viên 
void Nhap1SV(SinhVien& sv) {
    cout << "Nhap Ma SV: "; cin >> sv.MSSV;
    cin.ignore();
    cout << "Nhap Ho Ten: "; cin.getline(sv.hoten, 50);
    cout << "Nhap ngay thang nam sinh (cach nhau boi dau cach): ";
    cin >> sv.ngaysinh.ngay >> sv.ngaysinh.thang >> sv.ngaysinh.nam;
}

void NhapDS(List& l, int n) {
    for (int i = 0; i < n; i++) {
        SinhVien sv;
        cout << "\n-Nhap SV thu " << i + 1 << " " << endl;
        Nhap1SV(sv);
        ThemCuoiDS(l, Newnode(sv));
    }
}

void Xuat1SV(SinhVien sv) {
    cout << sv.MSSV << " | " << sv.hoten << " | "
        << sv.ngaysinh.ngay << "/" << sv.ngaysinh.thang << "/" << sv.ngaysinh.nam << endl;
}

void XuatDS(List l) {
    cout << "\nDANH SACH SINH VIEN:\n";
    for (Node* p = l.sv_dau; p != NULL; p = p->link) {
        Xuat1SV(p->data);
    }
}

// Sắp xếp danh sách tăng dần theo mã sinh viên
void SapxepSV(List& l) {
    for (Node* p = l.sv_dau; p != NULL; p = p->link) {
        for (Node* q = p->link; q != NULL; q = q->link) 
        {
            if (strcmp(p->data.MSSV, q->data.MSSV) > 0) {
             SinhVien temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

int main() {
    List listSV;
    Init(listSV);
    int n;
    cout << "Nhap so luong SV: "; 
    cin >> n;
    NhapDS(listSV, n);
    SapxepSV(listSV);
    cout << "\nSAU KHI SAP XEP";
    XuatDS(listSV);
    return 0;
}

