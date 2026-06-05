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
 
    
    return 0;
}