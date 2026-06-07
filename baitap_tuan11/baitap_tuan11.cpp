#include <iostream>
using namespace std;

#define MAX_SIZE 50

void khoitaocay(int cay[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        cay[i] = -1; 
    }
}

// Ham in ra cac vi tri co du lieu tren mang
void caytuantu(int cay[], string tenCay) {
    cout << "-" << tenCay << " " << endl;
    for (int i = 1; i < MAX_SIZE; i++) {
        if (cay[i] != -1) {
            cout << "Vi tri mang [" << i << "] = " << cay[i] << endl;
        }
    }
    cout << endl;
}


// CAU TRUC MOC NOI 

struct Node {
    int data;
    Node* left;
    Node* right;

    // Ham tao Node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Ham duyet cay theo thu tu truoc sau
void duyettruoc(Node* goc) {
    if (goc != NULL) {
        cout << goc->data << " ";
        duyettruoc(goc->left);
        duyettruoc  (goc->right);
    }
}

int main() {
    // DUNG CAY LECH TRAI
    Node* goctrai = new Node(1);
    goctrai->left = new Node(2);
    goctrai->left->left = new Node(3);
    goctrai->left->left->left = new Node(4);
    goctrai->left->left->left->left = new Node(5);

    // DUNG CAY LECH PHAI
    Node* gocphai = new Node(1);
    gocphai->right = new Node(2);
    gocphai->right->right = new Node(3);
    gocphai->right->right->right = new Node(4);
    gocphai->right->right->right->right = new Node(5);

    //DUNG CAY dic dac 
    Node* gocdicdac = new Node(1);
    gocdicdac->left = new Node(2);
    gocdicdac->left->right = new Node(3);
    gocdicdac->left->right->left = new Node(4);
    gocdicdac->left->right->left->right = new Node(5);

    // In ket qua kiem tra (Duyet tu goc xuong la)
    cout << "KET QUA DUYET CAY MOC NOI" << endl;
    cout << "Lech trai: "; duyettruoc(goctrai); cout << endl;
    cout << "Lech phai: "; duyettruoc(gocphai); cout << endl;
    cout << "Dic dac   : "; duyettruoc(gocdicdac); cout << endl;

    return 0;
}


/*
int main() {
    int caylechtrai[MAX_SIZE];
    int caylechphai[MAX_SIZE];
    int caydicdac[MAX_SIZE];

    khoitaocay(caylechtrai);
    khoitaocay(caylechphai);
    khoitaocay(caydicdac);

    caylechtrai[1] = 1;
    caylechtrai[2] = 2;
    caylechtrai[4] = 3;
    caylechtrai[8] = 4;
    caylechtrai[16] = 5;


    caylechphai[1] = 1;
    caylechphai[3] = 2;
    caylechphai[7] = 3;
    caylechphai[15] = 4;
    caylechphai[31] = 5;

    caydicdac[1] = 1;
    caydicdac[2] = 2;
    caydicdac[5] = 3;
    caydicdac[10] = 4;
    caydicdac[21] = 5;

  
    caytuantu(caylechtrai, "CAY LECH TRAI (TUAN TU)");
    caytuantu(caylechphai, "CAY LECH PHAI (TUAN TU)");
    caytuantu(caydicdac, "CAY DICDAC (TUAN TU)");

    return 0;
}
*/