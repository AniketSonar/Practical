#include <iostream>
using namespace std;

struct Node {
    int roll;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int r) {
    if (root == NULL)
        return new Node{r, NULL, NULL};

    if (r < root->roll)
        root->left = insert(root->left, r);
    else
        root->right = insert(root->right, r);

    return root;
}

bool search(Node* root, int r) {
    if (root == NULL)
        return false;

    if (root->roll == r)
        return true;

    if (r < root->roll)
        return search(root->left, r);
    else
        return search(root->right, r);
}

int main() {
    Node* root = NULL;
    int n, roll, key;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter roll numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> roll;
        root = insert(root, roll);
    }

    cout << "Enter roll number to search: ";
    cin >> key;

    if (search(root, key))
        cout << "Student record found";
    else
        cout << "Student record not found";

    return 0;
}
