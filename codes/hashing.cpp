#include <iostream>
using namespace std;

#define SIZE 10
long hashTable[SIZE];

int hashFunc(long key) {
    return key % SIZE;
}

int main() {
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;

    long isbn;
    cout << "Enter ISBN: ";
    cin >> isbn;

    int index = hashFunc(isbn);
    hashTable[index] = isbn;

    cout << "Stored at index " << index;
}
