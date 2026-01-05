#include <iostream> 
using namespace std; 
#define SIZE 10 
struct Book { 
    long long isbn; 
    string title; 
}; 
Book table[SIZE]; 
void init() { 
    for (int i = 0; i < SIZE; i++) { 
        table[i].isbn = -1; 
    } 
} 
int hashFunction(long long isbn) { 
    return isbn % SIZE; 
} 
void insertBook(long long isbn, string title) { 
    int index = hashFunction(isbn); 
 
    while (table[index].isbn != -1) { 
        index = (index + 1) % SIZE; 
    } 
 
    table[index].isbn = isbn; 
    table[index].title = title; 
 
    cout << "Book inserted successfully.\n"; 
} 
void searchBook(long long isbn) { 
    int index = hashFunction(isbn); 
    int start = index; 
    while (table[index].isbn != -1) { 
        if (table[index].isbn == isbn) { 
            cout << "Book Found!\n"; 
            cout << "ISBN: " << table[index].isbn << endl; 
            cout << "Title: " << table[index].title << endl; 
            return; 
        } 
        index = (index + 1) % SIZE; 
        if (index == start) 
            break; 
    } 
    cout << "Book not found.\n"; 
} 
void display() { 
    cout << "\nHash Table:\n"; 
    for (int i = 0; i < SIZE; i++) { 
        if (table[i].isbn != -1) 
            cout << i << " -> " << table[i].isbn << " (" << table[i].title << ")\n"; 
        else 
            cout << i << " -> Empty\n"; 
    } 
} 
 
int main() { 
    init(); 
    int choice; 
    long long isbn; 
    string title; 
    do { 
        cout << "\n--- Library Hashing Menu ---"; 
        cout << "\n1. Insert Book"; 
        cout << "\n2. Search Book"; 
        cout << "\n3. Display Hash Table"; 
        cout << "\n4. Exit"; 
        cout << "\nEnter your choice: "; 
        cin >> choice; 
        switch (choice) { 
        case 1: 
            cout << "Enter ISBN: "; 
            cin >> isbn; 
            cout << "Enter Book Title: "; 
            cin >> title; 
            insertBook(isbn, title); 
            break; 
        case 2: 
            cout << "Enter ISBN to search: "; 
            cin >> isbn; 
            searchBook(isbn); 
            break; 
        case 3: 
            display(); 
            break; 
        case 4: 
 
            cout << "Exiting program.\n"; 
            break; 
        default: 
            cout << "Invalid choice.\n"; 
        } 
    } while (choice != 4); 
    return 0; 
}
