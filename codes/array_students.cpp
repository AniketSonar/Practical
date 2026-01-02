#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    string names[n];
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    for (int i = 0; i < n; i++)
        cout << names[i] << endl;
}
