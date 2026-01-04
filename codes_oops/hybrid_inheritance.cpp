#include <iostream> 
using namespace std; 
class Student { 
protected: 
    int roll_number; 
public: 
    void get_number(int a) { 
        roll_number = a; 
    } 
    void put_number() { 
        cout << "Roll No: " << roll_number << endl; 
    } 
}; 
class Test : virtual public Student { 
protected: 
    float part1, part2; 
public: 
    void get_marks(float x, float y) { 
        part1 = x; 
        part2 = y; 
    } 
    void put_marks() { 
        cout << "Marks Obtained:" << endl; 
        cout << "  Part 1: " << part1 << endl; 
 
        cout << "  Part 2: " << part2 << endl; 
    } 
}; 
class Sports : virtual public Student { 
protected: 
    float score; 
public: 
    void get_score(float s) { 
        score = s; 
    } 
    void put_score() { 
        cout << "Sports Score: " << score << endl; 
    } 
}; 
class Result : public Test, public Sports { 
    float total; 
public: 
    void display() { 
        total = part1 + part2 + score; 
        put_number();  
        put_marks(); 
        put_score(); 
         
        cout << "---------------------" << endl; 
        cout << "Total Score: " << total << endl; 
    } 
}; 
int main() { 
    Result student1; 
    student1.get_number(1234); 
 
    student1.get_marks(85.5, 92.0); 
    student1.get_score(75.0); 
    cout << "--- Student Report Card ---\n"; 
    student1.display(); 
    return 0; 
} 