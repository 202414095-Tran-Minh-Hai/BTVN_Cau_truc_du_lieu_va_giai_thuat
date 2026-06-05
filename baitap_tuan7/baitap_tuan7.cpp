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

int main() {
    Node* daThuc = NULL;
    Node* nuttest = taonode(5, 3);

    cout << "tao don thuc voi he so: "
        << nuttest->data.heso << " va so mu: " << nuttest->data.somu    << endl;

    return 0;
}