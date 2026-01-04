#include <iostream> 
using namespace std; 
int main() { 
    string students[50]; 
    int n = 0, choice, pos; 
    string name; 
    do { 
        cout << "\n--- Student Array Operations ---"; 
        cout << "\n1. Insert Student"; 
        cout << "\n2. Delete Student"; 
        cout << "\n3. Display Students"; 
        cout << "\n4. Exit"; 
        cout << "\nEnter your choice: "; 
        cin >> choice; 
        switch (choice) { 
        case 1: 
            cout << "Enter student name: "; 
            cin >> name; 
            students[n] = name; 
            n++; 
            cout << "Student inserted successfully."; 
            break; 
        case 2: 
            if (n == 0) { 
                cout << "No students to delete."; 
 
            } else { 
                cout << "Enter position to delete (1 to " << n << "): "; 
                cin >> pos; 
                if (pos < 1 || pos > n) { 
                    cout << "Invalid position."; 
                } else { 
                    for (int i = pos - 1; i < n - 1; i++) { 
                        students[i] = students[i + 1]; 
                    } 
                    n--; 
                    cout << "Student deleted successfully."; 
                } 
            } 
            break; 
        case 3: 
            if (n == 0) { 
                cout << "No students to display."; 
            } else { 
                cout << "\nStudent List:"; 
                for (int i = 0; i < n; i++) { 
                    cout << "\n" << i + 1 << ". " << students[i]; 
                } 
            } 
            break; 
        case 4: 
            cout << "Exiting program."; 
            break; 
        default: 
            cout << "Invalid choice."; 
        } 
    } while (choice != 4); 
    return 0; 
 
} 