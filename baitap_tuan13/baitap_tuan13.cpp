#include <iostream>
using namespace std;

// Dinh nghia cau truc mot nut tren cay
struct Node {
    int data; 
    Node* left;
    Node* right;

    // tao Node moi
    Node(int namsinh) {
        data = namsinh;
        left = NULL;
        right = NULL;
    }
};

// Ham chen nam sinh vao cay
Node* chenNamsinh(Node* nutHientai, int namsinh) {
    if (nutHientai == NULL) {
        return new Node(namsinh);
    }
    // Nho hon -> re trai
    if (namsinh < nutHientai->data) {
        nutHientai->left = chenNamsinh(nutHientai->left, namsinh);
    }
    // Lon hon hoac bang -> re phai (xu ly trung lap nam sinh)
    else {
        nutHientai->right = chenNamsinh(nutHientai->right, namsinh);
    }
    return nutHientai;
}

int main() {
  
    return 0;
}