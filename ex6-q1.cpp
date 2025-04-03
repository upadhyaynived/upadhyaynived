#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    // Constructor
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    // Overloading + operator
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overloading - operator
    Complex operator-(const Complex &c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // Overloading * operator
    Complex operator*(const Complex &c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    // Overloading / operator
    Complex operator/(const Complex &c) {
        float denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
    }

    // Function to input data
    void getData() {
        cout << "Enter real and imaginary parts: ";
        cin >> real >> imag;
    }

    // Function to display data
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1, c2, result;
    
    cout << "Enter first complex number:" << endl;
    c1.getData();
    
    cout << "Enter second complex number:" << endl;
    c2.getData();
    
    result = c1 + c2;
    cout << "Addition: ";
    result.display();
    
    result = c1 - c2;
    cout << "Subtraction: ";
    result.display();
    
    result = c1 * c2;
    cout << "Multiplication: ";
    result.display();
    
    result = c1 / c2;
    cout << "Division: ";
    result.display();
    
    return 0;
}
