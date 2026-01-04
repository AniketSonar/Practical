#include <iostream> 
using namespace std; 
class Complex { 
private: 
    double* real; 
    double* imag; 
public: 
    Complex(double r = 0.0, double i = 0.0) { 
        real = new double(r); 
        imag = new double(i); 
    } 
    ~Complex() { 
        delete real; 
        delete imag; 
    } 
    Complex(const Complex& other) { 
        real = new double(*(other.real)); 
        imag = new double(*(other.imag)); 
    } 
    Complex& operator=(const Complex& other) { 
        if (this != &other) { 
            delete real; 
            delete imag; 
            real = new double(*(other.real)); 
 
            imag = new double(*(other.imag)); 
        } 
        return *this; 
    } 
    Complex operator+(const Complex& other) const { 
        return Complex(*real + *(other.real), *imag + *(other.imag)); 
    } 
    Complex operator-(const Complex& other) const { 
        return Complex(*real - *(other.real), *imag - *(other.imag)); 
    } 
    Complex operator*(const Complex& other) const { 
        double r = (*real * *(other.real)) - (*imag * *(other.imag)); 
        double i = (*real * *(other.imag)) + (*imag * *(other.real)); 
        return Complex(r, i); 
    } 
    void display() const { 
        cout << *real; 
        if (*imag >= 0) cout << " + " << *imag << "i"; 
        else cout << " - " << -(*imag) << "i"; // Handle negative imaginary part 
        cout << endl; 
    } 
}; 
int main() { 
    double r1, i1, r2, i2; 
    cout << "--- Complex Number Operations ---\n";  
    cout << "Enter real and imaginary parts for first number (e.g., 3 4): "; 
    cin >> r1 >> i1; 
    Complex c1(r1, i1); 
    cout << "Enter real and imaginary parts for second number (e.g., 1 2): "; 
    cin >> r2 >> i2; 
 
    Complex c2(r2, i2); 
    cout << "\nFirst Number: "; c1.display(); 
    cout << "Second Number: "; c2.display(); 
    Complex sum = c1 + c2; 
    Complex diff = c1 - c2; 
    Complex prod = c1 * c2; 
    cout << "\nResults:\n"; 
    cout << "Sum (+): "; sum.display(); 
    cout << "Difference (-): "; diff.display(); 
    cout << "Product (*): "; prod.display(); 
    return 0; 
}