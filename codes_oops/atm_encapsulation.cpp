#include <iostream> 
using namespace std; 
class ATM { 
private: 
    double balance;   
public: 
    ATM(double initialBalance = 0.0) { 
        balance = initialBalance; 
    } 
    double getBalance() { 
        return balance; 
    } 
    void deposit(double amount) { 
        if (amount > 0) { 
            balance += amount; 
            cout << "Amount Deposited Successfully.\n"; 
        } else { 
            cout << "Invalid Deposit Amount!\n"; 
        } 
    } 
    void withdraw(double amount) { 
        if (amount > balance) { 
            cout << "Insufficient Balance!\n"; 
        } else if (amount <= 0) { 
            cout << "Invalid Withdrawal Amount!\n"; 
 
        } else { 
            balance -= amount; 
            cout << "Withdrawal Successful.\n"; 
        } 
    } 
}; 
int main() { 
    ATM atm(1000);  
    int choice; 
    double amount; 
    do { 
        cout << "\n------ ATM MENU ------\n"; 
        cout << "1. Balance Inquiry\n"; 
        cout << "2. Deposit Money\n"; 
        cout << "3. Withdraw Money\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
        switch (choice) { 
        case 1: 
            cout << "Current Balance: Rs. " << atm.getBalance() << "\n"; 
            break; 
 
        case 2: 
            cout << "Enter Deposit Amount: "; 
            cin >> amount; 
            atm.deposit(amount); 
            break; 
        case 3: 
            cout << "Enter Withdrawal Amount: "; 
            cin >> amount; 
            atm.withdraw(amount); 
 
            cout << "Remaining Balance: Rs. " << atm.getBalance() << "\n"; 
            break; 
        case 4: 
            cout << "Thank you for using the ATM.\n"; 
            break; 
        default: 
            cout << "Invalid Choice! Please try again.\n"; 
        } 
    } while (choice != 4); 
    return 0; 
}