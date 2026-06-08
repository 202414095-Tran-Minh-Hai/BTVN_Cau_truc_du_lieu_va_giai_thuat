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

// xoay cay
// xoay phai
Node* xoayphai(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;

    //chieu cao sau khi xoay
    y->chieucao = max(chieuCao(y->left), chieuCao(y->right)) + 1;
    x->chieucao = max(chieuCao(x->left), chieuCao(x->right)) + 1;

    // tra ve goc moi
    return x;
}

// xoay sang trái
Node* xoaytrai(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    //chieu cao sau khi xoay
    x->chieucao = max(chieuCao(x->left), chieuCao(x->right)) + 1;
    y->chieucao = max(chieuCao(y->left), chieuCao(y->right)) + 1;
    return y;
}
