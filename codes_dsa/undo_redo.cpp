#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> undo, redo;

    undo.push("Text1");
    undo.push("Text2");

    redo.push(undo.top());
    undo.pop();

    cout << "Current text: " << undo.top();
}
