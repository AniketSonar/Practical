#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    Student* next;
};

Student* head = NULL;

void insert() {
    Student* s = new Student();
    cout << "Enter roll: ";
    cin >> s->roll;
    cout << "Enter name: ";
    cin >> s->name;
    s->next = head;
    head = s;
}

void display() {
    Student* temp = head;
    while (temp) {
        cout << temp->roll << " " << temp->name << endl;
        temp = temp->next;
    }
}

void del() {
    int r;
    cout << "Enter roll to delete: ";
    cin >> r;

    Student *temp = head, *prev = NULL;
    while (temp && temp->roll != r) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        cout << "Not found\n";
        return;
    }
    if (!prev) head = temp->next;
    else prev->next = temp->next;
    delete temp;
}

int main() {
    int ch;
    do {
        cout << "1.Insert 2.Delete 3.Display 0.Exit\n";
        cout << "Enter the Choice: ";
        cin >> ch;
        if (ch == 1) insert();
        else if (ch == 2) del();
        else if (ch == 3) display();
    } while (ch != 0);
}
