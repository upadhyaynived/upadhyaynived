#include <iostream>
using namespace std;

class Catalog {
private:
    string title;
    string author;
    int year_of_publication;
    int no_of_copies;

public:
    // Constructor
    Catalog() {
        title = "";
        author = "";
        year_of_publication = 0;
        no_of_copies = 0;
    }

    // Function to get data
    void getData() {
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
        cout << "Enter Year of Publication: ";
        cin >> year_of_publication;
        cout << "Enter Number of Copies: ";
        cin >> no_of_copies;
    }

    // Function to display data
    void displayData() {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year_of_publication << ", Copies: " << no_of_copies << endl;
    }

    // Function to check if title matches
    bool searchTitle(string search_title) {
        return title == search_title;
    }
};

int main() {
    Catalog books[15];
    string search_title;
    bool found = false;

    // Input 15 books
    for (int i = 0; i < 15; i++) {
        cout << "\nEnter details for Book " << i + 1 << ":\n";
        books[i].getData();
    }

    // Display all books
    cout << "\nCatalog of Books:\n";
    for (int i = 0; i < 15; i++) {
        books[i].displayData();
    }

    // Search for a particular title
    cout << "\nEnter title to search: ";
    cin >> search_title;
    for (int i = 0; i < 15; i++) {
        if (books[i].searchTitle(search_title)) {
            cout << "\nBook Found:\n";
            books[i].displayData();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nBook not found in catalog." << endl;

    return 0;
}
