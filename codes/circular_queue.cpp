#include <iostream>
using namespace std;

#define SIZE 5
int q[SIZE], f = -1, r = -1;

void enqueue(int x) {
    if ((r + 1) % SIZE == f) {
        cout << "Queue Full\n";
        return;
    }
    if (f == -1) f = 0;
    r = (r + 1) % SIZE;
    q[r] = x;
}

void display() {
    int i = f;
    while (i != r) {
        cout << q[i] << " ";
        i = (i + 1) % SIZE;
    }
    cout << q[i];
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
}
