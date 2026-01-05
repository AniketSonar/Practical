#include <iostream> 
#include <stack> 
using namespace std; 
int main() { 
    stack<string> undoStack, redoStack; 
    string text = ""; 
    int choice; 
    string input; 
    do { 
        cout << "\n--- Stack Based Text Editor ---"; 
        cout << "\n1. Write Text"; 
        cout << "\n2. Undo"; 
        cout << "\n3. Redo"; 
        cout << "\n4. Display Text"; 
        cout << "\n5. Exit"; 
        cout << "\nEnter your choice: "; 
        cin >> choice; 
        switch (choice) { 
        case 1: 
            cout << "Enter text to add: "; 
            cin >> input; 
            undoStack.push(text); 
            text += input; 
            while (!redoStack.empty()) 
 
                redoStack.pop(); 
            cout << "Text added successfully."; 
            break; 
        case 2: 
            if (!undoStack.empty()) { 
                redoStack.push(text); 
                text = undoStack.top(); 
                undoStack.pop(); 
                cout << "Undo operation performed."; 
            } else { 
                cout << "Nothing to undo."; 
            } 
            break; 
        case 3: 
            if (!redoStack.empty()) { 
                undoStack.push(text); 
                text = redoStack.top(); 
                redoStack.pop(); 
                cout << "Redo operation performed."; 
            } else { 
                cout << "Nothing to redo."; 
            } 
            break; 
        case 4: 
            cout << "Current Text: " << text; 
            break; 
        case 5: 
            cout << "Exiting program."; 
            break; 
        default: 
 
            cout << "Invalid choice."; 
        } 
    } while (choice != 5); 
    return 0; 
}
