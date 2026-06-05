#include <iostream>
using namespace std;

// dn don thuc 
struct donthuc {
    float heso;
    int somu;
};

// dn node
struct Node {
    donthuc data;
    Node* next;
};

// ham tạo node mới
Node* taonode(float hs, int sm) {
    Node* nutmoi = new Node();
    nutmoi->data.heso = hs;
    nutmoi->data.somu = sm;
    nutmoi->next = NULL;
    return nutmoi;
}

// ham them 1 don thuc
void themDonthuc(Node*& head, float hs, int sm) {
    Node* nutMoi = taonode(hs, sm);

    // neu ds rong
    if (head == NULL) {
        head = nutMoi;
        return;
    }

    // neu da co phan tu, duyet den cuoi ds
    Node* nutHientai = head;
    while (nutHientai->next != NULL) {
        nutHientai = nutHientai->next;
    }

    // Noi vao duoi
    nutHientai->next = nutMoi;
}

// ham in da thuc
void inDathuc(Node* head) {
    if (head == NULL) {
        cout << "0" << endl;
        return;
    }

    Node* nutHientai = head;
    bool dau = true; //bien danh dau de khong in dau '+' o don thuc dau tien

    while (nutHientai != NULL) {
        // In dau cong cho cac don thuc phia sau neu he so duong
        if (!dau && nutHientai->data.heso > 0) cout << " + ";

        // In he so
        cout << nutHientai->data.heso;

        // In so mu (x^...)
        if (nutHientai->data.somu > 0) {
            cout << "x^" << nutHientai->data.somu;
        }

        dau = false;
        nutHientai = nutHientai->next;
    }
    cout << endl;
}

int main() {
    Node* daThuc = NULL;
    int soLuong;

    cout << "Ban dung muon nhap bao nhieu don thuc: ";
    cin >> soLuong;

    for (int i = 1; i <= soLuong; i++) {
        float hs;
        int sm;

        cout << "\n-Nhap don thuc thu " << i << endl;

        cout << "Nhap he so: ";
        cin >> hs;

        cout << "Nhap so mu: ";
        cin >> sm;

        themDonthuc(daThuc, hs, sm);
    }


    cout << endl;
    cout << "- Da thuc ban vua nhap la: ";
    inDathuc(daThuc);
    cout << endl;

    return 0;
}