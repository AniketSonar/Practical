#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* head = NULL;

void insert(string s) {
    Node* n = new Node();
    n->name = s;
    n->next = head;
    head = n;
}

void reverse() {
    Node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display() {
    Node* t = head;
    while (t) {
        cout << t->name << " -> ";
        t = t->next;
    }
    cout << "NULL\n";
}

int main() {
    insert("Pune");
    insert("Mumbai");
    insert("Delhi");

    display();
    reverse();
    display();
}
