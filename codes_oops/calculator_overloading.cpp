#include <iostream> 
using namespace std; 
class Calculator{ 
public:  
 inline double add(double a, double b){  
  return a + b;  
 } 
 inline double subtract(double a, double b){ 
  return a - b; 
 } 
 inline double multiply(double a, double b){  
  return a * b;  
 } 
 inline double divide(double a, double b){ 
  return a / b; 
 } 
 double calculate(double a, double b, char op){ 
     switch(op) { 
         case '+': return add(a, b); 
         case '-': return subtract(a, b); 
         case '*': return multiply(a, b); 
         case '/':  
             if (b == 0) { 
                 cout << "Error: Division by zero!\n"; 
 
                 return 0; 
               } 
             return divide(a, b); 
         default: 
             cout << "Invalid operator!\n"; 
             return 0; 
     } 
 } 
 double calculate() { 
     double x, y; 
     char op; 
     cout << "Enter expression (example: 3 + 5): "; 
     cin >> x >> op >> y; 
     return calculate(x, y, op); 
 } 
}; 
int main() { 
 Calculator cal; 
 while(true){ 
  int ch; 
  cout<<"\n=== Enter the Choice ===\n"<<endl; 
  cout<<"1.Calculator"<<endl; 
  cout<<"2.Exit"<<endl; 
  cout<<"Enter Your Choice = "; 
  cin >> ch; 
  if(ch == 1){ 
   cout << "\n=== Basic Calculator ===\n"; 
   double result = cal.calculate();   
      cout << "Result = " << result << endl; 
  }else if(ch == 2){ 
 
   cout << "Exiting..." << endl; 
   break; 
  } 
  else { 
            cout << "Invalid choice, try again." << endl; 
        } 
 } 
    return 0; 
} 