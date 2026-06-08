#include <iostream>
using namespace std;

// dn cau truc Node cay AVL
struct Node {
    int data;
    Node* left;
    Node* right;
    int chieucao;
};

// lay chieu cao cua mot node
int chieuCao(Node* cc) {
    if (cc == NULL)
        return 0;
    return cc->chieucao;
}

// xem so nao lơn hơn
int max(int a, int b) {
    return (a > b) ? a : b;
}

//tao Node moi
Node* taonode(int data) {
    Node* nutMoi = new Node();
    nutMoi->data = data;
    nutMoi->left = NULL;
    nutMoi->right = NULL;
    nutMoi->chieucao = 1; // do node moi duojc them o leaf nen chieu cao = 1
    return nutMoi;
}

//tinh su can bang cua mot node
int canbang(Node* N) {
    if (N == NULL)
        return 0;
    return chieuCao(N->left) - chieuCao(N->right);
}

