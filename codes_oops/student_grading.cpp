#include <iostream> 
#include <string> 
using namespace std; 
const int MAX_STUDENTS = 50;  
struct Student { 
    string name; 
    double score; 
}; 
char getGrade(double score) { 
    if (score >= 90) return 'A'; 
    if (score >= 80) return 'B'; 
    if (score >= 70) return 'C'; 
    if (score >= 60) return 'D'; 
    return 'F'; 
} 
int main() { 
    Student students[MAX_STUDENTS];  
    int count = 0;                   
    int choice; 
    do { 
        cout << "\n--- Grading System ---\n"; 
        cout << "1. Add Student\n"; 
        cout << "2. Show All Grades\n"; 
        cout << "3. Calculate Class Average\n"; 
 
        cout << "4. Exit\n"; 
        cout << "Enter choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: { 
                if (count >= MAX_STUDENTS) { 
                    cout << "Error: Class is full (Max " << MAX_STUDENTS << ").\n"; 
                } else { 
                    cout << "Enter Name: "; 
                    cin >> students[count].name; 
                    cout << "Enter Score: "; 
                    cin >> students[count].score; 
                    count++;  
                    cout << "Student added.\n"; 
                }break; 
            } 
            case 2: { 
                cout << "\n--- Student Records ---\n"; 
                if (count == 0) { 
                    cout << "No records found.\n"; 
                } else { 
                    for (int i = 0; i < count; i++) { 
                        cout << students[i].name << " \t| Score: " << students[i].score  
                             << " \t| Grade: " << getGrade(students[i].score) << endl; 
                    } 
                } 
                break; 
            } 
            case 3: { 
                if (count == 0) { 
 
                    cout << "No records to calculate average.\n"; 
                } else { 
                    double total = 0; 
                    for (int i = 0; i < count; i++) { 
                        total += students[i].score; 
                    } 
                    cout << "Class Average: " << (total / count) << endl; 
                } 
                break; 
            } 
            case 4: 
                cout << "Exiting...\n"; 
                break; 
            default: 
                cout << "Invalid choice, please try again.\n"; 
        } 
    } while (choice != 4); 
    return 0; 
} 