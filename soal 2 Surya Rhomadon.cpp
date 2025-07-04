#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* createNode(char data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
    if (root->data != 'A') cout << ", ";
}

int main() {
    Node* A = createNode('A');
    Node* B = createNode('B');
    Node* C = createNode('C');
    Node* D = createNode('D');
    Node* E = createNode('E');

    // Struktur Tree
    A->left = B;
    A->right = D;
    B->left = C;
    B->right = E;

    cout << "Postorder Traversal:\n";
    postorder(A);  // Output: C, E, B, D, A

    return 0;
}
