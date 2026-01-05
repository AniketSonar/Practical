#include <iostream> 
using namespace std; 
#define SIZE 5 
class CircularQueue { 
    int queue[SIZE]; 
    int front, rear; 
public: 
    CircularQueue() { 
        front = -1; 
        rear = -1; 
    } 
    void enqueue(int job) { 
        if ((rear + 1) % SIZE == front) { 
            cout << "Printer Queue is Full.\n"; 
            return; 
        } 
        if (front == -1) 
            front = 0; 
        rear = (rear + 1) % SIZE; 
        queue[rear] = job; 
        cout << "Print job added successfully.\n"; 
    } 
    void dequeue() { 
        if (front == -1) { 
 
            cout << "Printer Queue is Empty.\n"; 
            return; 
        } 
        cout << "Print job " << queue[front] << " completed.\n"; 
        if (front == rear) { 
            front = rear = -1; 
        } else { 
            front = (front + 1) % SIZE; 
        } 
    } 
    void display() { 
        if (front == -1) { 
            cout << "Printer Queue is Empty.\n"; 
            return; 
        } 
        cout << "Printer Queue: "; 
        int i = front; 
        while (true) { 
            cout << queue[i] << " "; 
            if (i == rear) 
                break; 
            i = (i + 1) % SIZE; 
        } 
        cout << endl; 
    } 
}; 
int main() { 
    CircularQueue cq; 
    int choice, job; 
 
 
    do { 
        cout << "\n--- Printer Queue Management ---"; 
        cout << "\n1. Add Print Job"; 
        cout << "\n2. Process Print Job"; 
        cout << "\n3. Display Queue"; 
        cout << "\n4. Exit"; 
        cout << "\nEnter your choice: "; 
        cin >> choice; 
        switch (choice) { 
        case 1: 
            cout << "Enter print job ID: "; 
            cin >> job; 
            cq.enqueue(job); 
            break; 
        case 2: 
            cq.dequeue(); 
            break; 
        case 3: 
            cq.display(); 
            break; 
        case 4: 
            cout << "Exiting program.\n"; 
            break; 
        default: 
            cout << "Invalid choice.\n"; 
        } 
    } while (choice != 4); 
    return 0; 
} 

