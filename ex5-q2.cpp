#include <iostream>
using namespace std;

class Book {
private:
    string bookName;
    string authorName;
    int quantity;
    float price;

public:
    // Constructor
    Book() {
        bookName = "";
        authorName = "";
        quantity = 0;
        price = 0.0;
    }

    // Function to get data
    void getData() {
        cout << "Enter Book Name: ";
        cin >> bookName;
        cout << "Enter Author Name: ";
        cin >> authorName;
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ";
        cin >> price;
    }

    // Function to display data
    void displayData() {
        cout << "Book: " << bookName << ", Author: " << authorName << ", Quantity: " << quantity << ", Price: " << price << ", Total Price: " << getTotalPrice() << endl;
    }

    // Function to calculate total price
    float getTotalPrice() {
        return quantity * price;
    }
};

// Function to sort books by total price
void sortByTotalPrice(Book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (books[i].getTotalPrice() < books[j].getTotalPrice()) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

int main() {
    Book books[10];

    // Input 10 books
    for (int i = 0; i < 10; i++) {
        cout << "\nEnter details for Book " << i + 1 << ":\n";
        books[i].getData();
    }

    // Sorting by total price
    sortByTotalPrice(books, 10);
    cout << "\nBooks sorted by total price:\n";
    for (int i = 0; i < 10; i++) {
        books[i].displayData();
    }

    return 0;
}