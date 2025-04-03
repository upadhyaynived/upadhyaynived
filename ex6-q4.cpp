#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char str[20];

public:
    // Constructor
    String() { str[0] = '\0'; }
    
    // Function to input data
    void getData() {
        cout << "Enter string: ";
        cin >> str;
    }
    
    // Function to display data
    void display() {
        cout << str << endl;
    }
    
    // Overloading > operator
    bool operator>(const String &s) {
        return strcmp(str, s.str) > 0;
    }
    
    // Overloading < operator
    bool operator<(const String &s) {
        return strcmp(str, s.str) < 0;
    }
    
    // Overloading == operator
    bool operator==(const String &s) {
        return strcmp(str, s.str) == 0;
    }
    
    // Overloading != operator
    bool operator!=(const String &s) {
        return strcmp(str, s.str) != 0;
    }
};

int main() {
    String s1, s2;
    
    cout << "Enter first string:" << endl;
    s1.getData();
    
    cout << "Enter second string:" << endl;
    s2.getData();
    
    if (s1 > s2)
        cout << "First string is greater." << endl;
    else if (s1 < s2)
        cout << "Second string is greater." << endl;
    else if (s1 == s2)
        cout << "Strings are equal." << endl;
    else if (s1 != s2)
        cout << "Strings are not equal." << endl;
    
    return 0;
}
