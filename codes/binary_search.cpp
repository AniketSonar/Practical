#include <iostream>
using namespace std;

int main() {
    int n, key;
    cout << "Enter number of students: ";
    cin >> n;

    int a[n];
    cout << "Enter sorted roll numbers:\n";
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "Enter roll to search: ";
    cin >> key;

    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == key) {
            cout << "Found at position " << m + 1;
            return 0;
        }
        if (a[m] < key) l = m + 1;
        else r = m - 1;
    }
    cout << "Not found";
}
