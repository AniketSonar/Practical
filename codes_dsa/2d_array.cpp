#include <iostream>
using namespace std;

int main() {
    int s, sub;
    cin >> s >> sub;

    int m[s][sub];
    for (int i = 0; i < s; i++)
        for (int j = 0; j < sub; j++)
            cin >> m[i][j];

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < sub; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}
