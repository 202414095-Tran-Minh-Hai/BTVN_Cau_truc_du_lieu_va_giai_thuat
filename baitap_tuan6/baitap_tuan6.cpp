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

int main() {



    return 0;
}