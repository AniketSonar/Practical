#include <iostream>
using namespace std;

struct Node {
    int roll;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int r) {
    if (!root) return new Node{r, NULL, NULL};
    if (r < root->roll) root->left = insert(root->left, r);
    else root->right = insert(root->right, r);
    return root;
}

bool search(Node* root, int r) {
    if (!root) return false;
    if (root->roll == r) return true;
    if (r < root->roll) return search(root->left, r);
    return search(root->right, r);
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);

    cout << (search(root, 20) ? "Found" : "Not Found");
}
