#include <iostream> 
using namespace std; 
class Employee { 
public: 
    virtual void showRole() { 
        cout << "I am an Employee." << endl; 
    } 
}; 
class Manager : public Employee { 
public: 
    void showRole() override { 
        cout << "I am a Manager." << endl; 
    } 
}; 
class Director : public Manager { 
public: 
    void showRole() override { 
        cout << "I am a Director." << endl; 
    } 
}; 
int main() { 
    Employee emp; 
    Manager mgr; 
    Director dir; 
 
    Employee* ptr; 
    cout << "--- Runtime Polymorphism ---\n"; 
    ptr = &emp; 
    ptr->showRole(); 
    ptr = &mgr; 
    ptr->showRole(); 
    ptr = &dir; 
    ptr->showRole(); 
    return 0; 
}