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
int main() {
    Node* daThuc = NULL;
    Node* nuttest = taonode(5, 3);

    cout << "tao don thuc voi he so: "
        << nuttest->data.heso << " va so mu: " << nuttest->data.somu    << endl;

    return 0;
}