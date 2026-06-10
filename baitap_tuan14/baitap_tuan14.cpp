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

// ham chen them mot node vao cay AVL
Node* chennode(Node* node, int data) {
    // chen 
    if (node == NULL)
        return taonode(data);

    if (data < node->data)
        node->left = chennode(node->left, data);
    else if (data > node->data)
        node->right = chennode(node->right, data);
    else // Khong cho phep gia tri trung lap tren cay AVL
        return node;

    // them chieu cao cua node cha hien tai
    node->chieucao = 1 + max(chieuCao(node->left), chieuCao(node->right));

    // kiem tra su can bang cua node 
    int cb = canbang(node);

    //4 truong hop lech va xoay

    // traaia trai
    if (cb > 1 && data < node->left->data)
        return xoayphai(node);

    // p p
    if (cb < -1 && data > node->right->data)
        return xoaytrai(node);

    // t p
    if (cb > 1 && data > node->left->data) {
        node->left = xoaytrai(node->left);
        return xoayphai(node);
    }

    // p t
    if (cb < -1 && data < node->right->data) {
        node->right = xoayphai(node->right);
        return xoaytrai(node);
    }

    // Tra ve con tro node hien tai (neu van can bang)
    return node;
}

//ham duyệt giua de in ra danh sach tang dan
void duyetgiua(Node* goc) {
    if (goc != NULL) {
        duyetgiua(goc->left);
        cout << goc->data << " ";
        duyetgiua(goc->right);
    }
}

// ham duyet truoc in theo thu tu root -trai -phai
void duyettruoc(Node* goc) {
    if (goc != NULL) {
        cout << goc->data << " ";
        duyettruoc(goc->left);
        duyettruoc(goc->right);
    }
}