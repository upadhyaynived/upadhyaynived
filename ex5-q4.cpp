#include <iostream>
using namespace std;

class Student {
private:
    int rollno;
    string name;
    float marks[6];
    float percentage;
    string student_class;

public:
    // Constructor
    Student() {
        rollno = 0;
        name = "";
        percentage = 0.0;
        student_class = "";
    }

    // Function to get data
    void getData() {
        cout << "Enter Roll No: ";
        cin >> rollno;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks for 6 Subjects: ";
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
        calculatePercentage();
        calculateClass();
    }

    // Function to display data
    void displayData() {
        cout << "Roll No: " << rollno << ", Name: " << name << ", Percentage: " << percentage << "%, Class: " << student_class << endl;
    }

    // Function to calculate percentage
    void calculatePercentage() {
        float total = 0;
        for (int i = 0; i < 6; i++) {
            total += marks[i];
        }
        percentage = total / 6;
    }

    // Function to calculate class based on percentage
    void calculateClass() {
        if (percentage >= 75)
            student_class = "Distinction";
        else if (percentage >= 60)
            student_class = "First Class";
        else if (percentage >= 50)
            student_class = "Second Class";
        else if (percentage >= 35)
            student_class = "Pass";
        else
            student_class = "Fail";
    }

    // Get percentage (for sorting)
    float getPercentage() {
        return percentage;
    }
};

// Function to sort students by percentage
void sortByPercentage(Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (students[i].getPercentage() < students[j].getPercentage()) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    Student students[5];

    // Input 5 students
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        students[i].getData();
    }

    // Sorting by percentage
    sortByPercentage(students, 5);
    cout << "\nStudents sorted by percentage:\n";
    for (int i = 0; i < 5; i++) {
        students[i].displayData();
    }

    return 0;
}