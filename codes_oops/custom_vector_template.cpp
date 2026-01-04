#include <iostream>
#include <vector>
using namespace std;

template <class T>
class CustomVector {
private:
    vector<T> v;

public:
    void insertElement(T value) {
        v.push_back(value);
        cout << "Element inserted successfully.\n";
    }

    void deleteElement(T value) {
        for (auto it = v.begin(); it != v.end(); ++it) {
            if (*it == value) {
                v.erase(it);
                cout << "Element deleted successfully.\n";
                return;
            }
        }
        cout << "Element not found.\n";
    }

    void searchElement(T value) {
        for (T x : v) {
            if (x == value) {
                cout << "Element found.\n";
                return;
            }
        }
        cout << "Element not found.\n";
    }

    void display() {
        cout << "Vector elements: ";
        for (T x : v)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    CustomVector<int> cv;
    int choice, value;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cv.insertElement(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                cv.deleteElement(value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                cv.searchElement(value);
                break;

            case 4:
                cv.display();
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
