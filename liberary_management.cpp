#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

class library {
private:
    int book_Id[MAX_BOOKS]; // array for id
    string book_Titles[MAX_BOOKS]; // array for titles
    string book_Authors[MAX_BOOKS]; // array to store book authors
    string book_Locations[MAX_BOOKS]; // Array for new locations
    int bookCount;  // current number

public:
    library() : bookCount(0) {} // constructor to initialize

    void addbook(int id, const string& title, const string& author, const string& location) {
        if (bookCount < MAX_BOOKS) {
            book_Id[bookCount] = id;
            book_Titles[bookCount] = title;
            book_Authors[bookCount] = author;
            book_Locations[bookCount] = location; // Location stored
            bookCount++;
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Library is full" << endl;
        }
    }

    void removeBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (book_Id[i] == id) { // Use '==' for comparison
                for (int j = i; j < bookCount - 1; j++) {
                    book_Id[j] = book_Id[j + 1];
                    book_Titles[j] = book_Titles[j + 1];
                    book_Authors[j] = book_Authors[j + 1];
                    book_Locations[j] = book_Locations[j + 1]; 
                }
                bookCount--;
                cout << "Book removed successfully!" << endl;
                return;
            }
        }
        cout << "Book is not found!" << endl;
    }

    void searchbook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (book_Id[i] == id) { 
                cout << "Book found: " << book_Titles[i] << " by " << book_Authors[i] << ", Location: " << book_Locations[i] << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void viewallbooks() {
        cout << "\nLibrary Books:" << endl;
        for (int i = 0; i < bookCount; i++) {
            cout << "ID: " << book_Id[i] << ", Title: " << book_Titles[i] << ", Author: " << book_Authors[i] << ", Location: " << book_Locations[i] << endl;
        }
    }

    void showlocation(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (book_Id[i] == id) { // Use '==' for comparison
                cout << "Location of book ID " << id << ": " << book_Locations[i] << endl;
                return;
            }
        }
        cout << "Book not found!" << endl; 
    }
};

int main() {
    library lib;
    int choice, id;
    string title, author, location;

    while (true) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Remove book" << endl;
        cout << "3. Search book" << endl;
        cout << "4. View all books" << endl;
        cout << "5. Location of book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the book ID: ";
                cin >> id;
                cout << "Enter the book title: ";
                cin.ignore(); 
                getline(cin, title);
                cout << "Enter the author: ";
                getline(cin, author);
                cout << "Enter the Location: ";
                getline(cin, location);
                lib.addbook(id, title, author, location);
                break;
            case 2:
                cout << "Enter the book ID to remove: ";
                cin >> id;
                lib.removeBook(id);
                break;
            case 3:
                cout << "Enter the Book ID to search: ";
                cin >> id;
                lib.searchbook(id);
                break;
            case 4:
                lib.viewallbooks();
                break;
            case 5:
                cout << "Enter the book ID to check the location: ";
                cin >> id;
                lib.showlocation(id);
                break;
            case 6:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}