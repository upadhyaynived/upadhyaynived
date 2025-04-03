#include <iostream>
using namespace std;

class Matrix {
private:
    int mat[2][2];

public:
    // Constructor
    Matrix() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                mat[i][j] = 0;
            }
        }
    }

    // Function to input data
    void getData() {
        cout << "Enter 2x2 matrix elements:" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> mat[i][j];
            }
        }
    }

    // Function to display data
    void display() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Overloading + operator
    Matrix operator+(const Matrix &m) {
        Matrix temp;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                temp.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return temp;
    }

    // Overloading - operator
    Matrix operator-(const Matrix &m) {
        Matrix temp;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                temp.mat[i][j] = mat[i][j] - m.mat[i][j];
            }
        }
        return temp;
    }
};

int main() {
    Matrix m1, m2, result;

    cout << "Enter first matrix:" << endl;
    m1.getData();
    
    cout << "Enter second matrix:" << endl;
    m2.getData();
    
    result = m1 + m2;
    cout << "Addition Result:" << endl;
    result.display();
    
    result = m1 - m2;
    cout << "Subtraction Result:" << endl;
    result.display();
    
    return 0;
}
