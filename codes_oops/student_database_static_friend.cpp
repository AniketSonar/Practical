#include <iostream> 
#include <string> 
using namespace std; 
const int MAX_SIZE = 100; 
class StudentDatabase { 
private: 
    struct Student { 
        int id; 
        string name; 
    }; 
    Student records[MAX_SIZE];  
    static int recordCount;    
public: 
    StudentDatabase() { 
    } 
    void addStudent(int id, string name) { 
        if (recordCount >= MAX_SIZE) { 
            cout << "Database is full!\n"; 
            return; 
        } 
        records[recordCount].id = id; 
        records[recordCount].name = name; 
        recordCount++;  
        cout << "Student added successfully.\n"; 
 
    } 
    void deleteStudent(int id) { 
        int index = -1; 
        for (int i = 0; i < recordCount; i++) { 
            if (records[i].id == id) { 
                index = i; 
                break; 
            } 
        } 
        if (index != -1) { 
            for (int j = index; j < recordCount - 1; j++) { 
                records[j] = records[j + 1]; 
            } 
            recordCount--;  
            cout << "Student deleted successfully.\n"; 
        } else { 
            cout << "Student with ID " << id << " not found.\n"; 
        } 
    } 
    static void showCount() { 
        cout << "Total Students in Database: " << recordCount << endl; 
    } 
    friend void searchStudent(int id, const StudentDatabase& db); 
}; 
int StudentDatabase::recordCount = 0; 
void searchStudent(int id, const StudentDatabase& db) { 
    bool found = false; 
    for (int i = 0; i < db.recordCount; i++) { 
        if (db.records[i].id == id) { 
            cout << "\n--- Record Found ---\n"; 
 
            cout << "ID: " << db.records[i].id << endl; 
            cout << "Name: " << db.records[i].name << endl; 
            found = true; 
            break; 
        } 
    } 
    if (!found) { 
        cout << "Student with ID " << id << " not found.\n"; 
    } 
} 
int main() { 
    StudentDatabase db; 
    int choice; 
    int id; 
    string name; 
    do { 
        cout << "\n=== Student Database ===\n"; 
        cout << "1. Add Student\n"; 
        cout << "2. Delete Student\n"; 
        cout << "3. Search Student (Friend Func)\n"; 
        cout << "4. Show Total Count (Static)\n"; 
        cout << "5. Exit\n"; 
        cout << "Enter choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: 
                cout << "Enter ID: "; 
                cin >> id; 
                cout << "Enter Name: "; 
                cin >> name;  
 
                db.addStudent(id, name); 
                break; 
            case 2: 
                cout << "Enter ID to delete: "; 
                cin >> id; 
                db.deleteStudent(id); 
                break; 
            case 3: 
                cout << "Enter ID to search: "; 
                cin >> id; 
                searchStudent(id, db);  
                break; 
            case 4: 
                StudentDatabase::showCount();  
                break; 
            case 5: 
                cout << "Exiting...\n"; 
                break; 
            default: 
                cout << "Invalid choice.\n"; 
        } 
    } while (choice != 5); 
    return 0; 
}