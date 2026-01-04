#include <iostream>
using namespace std;

int main() {
    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of subjects: ";
    cin >> subjects;

    int marks[students][subjects];

    // Input marks
    cout << "Enter marks:\n";
    for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << ":\n";
        for (int j = 0; j < subjects; j++) {
            cin >> marks[i][j];
        }
    }

    // Display marks
    cout << "\nMarks of Students:\n";
    for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < subjects; j++) {
            cout << marks[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
