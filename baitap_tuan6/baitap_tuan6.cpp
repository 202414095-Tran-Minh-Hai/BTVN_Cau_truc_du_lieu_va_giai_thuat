#include <iostream>
#include <string>
using namespace std;

// Dn thuoc tinh cua 1 File
struct dacdiemFile {
    string TenFile;
    int thoigianTao; // Dung so Z mo phong (vd 1, 2, 3..  tang dan)
    float kichThuoc; // Don vi la GB
};

// Dn node
struct Node {
    dacdiemFile data;
    Node* next;
};

// Ham tao Node moi
Node* taoNode(dacdiemFile file) {
    Node* nutMoi = new Node();
    nutMoi->data = file;
    nutMoi->next = NULL;
    return nutMoi;
}

// Ham in danh sach 
void indanhsach(Node* head) {
    cout << "\nTHU MUC D:\\Document" << endl;
    if (head == NULL) {
        cout << "Thu muc trong!" << endl;
        return;
    }
    Node* nutHientai = head;
    while (nutHientai != NULL) {
        cout << "[" << nutHientai->data.thoigianTao << "] "
            << nutHientai->data.TenFile << " - "
            << nutHientai->data.kichThuoc << " GB" << endl;
        nutHientai = nutHientai->next;
    }
}

// Ham chen file sao cho luon giu dung trat tu thoi gian tang dan
void chenFileTheoThoiGian(Node*& head, dacdiemFile fileMoi) {
    Node* nutMoi = taoNode(fileMoi);

    // Thu muc rong hoac file moi co thoi gian cu hon ca file dau tien
    if (head == NULL || head->data.thoigianTao >= nutMoi->data.thoigianTao) {
        nutMoi->next = head;
        head = nutMoi;
        return;
    }

    // Duyet tim vi tri thich hop o giua hoac cuoi
    Node* nuthientai = head;
    while (nuthientai->next != NULL && nuthientai->next->data.thoigianTao < nutMoi->data.thoigianTao) {
        nuthientai = nuthientai->next;
    }

    // Chen nut moi vao sau nut hien tai
    nutMoi->next = nuthientai->next;
    nuthientai->next = nutMoi;
}

int main() {



    return 0;
}