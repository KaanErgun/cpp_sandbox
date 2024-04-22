/**
 * Library Management System
 *
 * This program is a simple console-based library management system designed to help manage 
 * the lending and returning of books within a small library or personal collection. It allows 
 * library staff or users to add books to the inventory, loan books to members, return loaned books, 
 * and display all the books currently available in the library.
 *
 * Key Features:
 * 1. Add Book: Allows the user to add new books to the library inventory with details such as 
 *    title, author, and the number of copies.
 * 2. Loan Book: Enables the user to loan out a book to a library member. It checks for the 
 *    availability of the book and decreases the count of available copies.
 * 3. Return Book: Allows for the return of loaned books and increases the available count of the 
 *    returned book.
 * 4. Display Books: Lists all the books currently available in the library, showing their titles, 
 *    authors, and the number of available copies.
 * 5. Exit: Exits the program.
 *
 * Usage:
 * The system prompts the user with a menu of actions corresponding to the features listed above. 
 * The user can select an action by entering the appropriate number associated with each feature. 
 * The program will then ask for the necessary information to perform the selected action, such as 
 * the book title or author name.
 *
 * This application is particularly useful for small libraries looking to digitize their book 
 * management processes without the complexity of larger commercial systems.
 */


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Book {
    string title;
    string author;
    int copies;

    Book(string t, string a, int c) : title(move(t)), author(move(a)), copies(c) {}
};

class Library {
private:
    vector<Book> books;
    unordered_map<string, int> loanedBooks; // Key: book title, Value: loaned copies

public:
    void addBook(const string& title, const string& author, int copies) {
        books.emplace_back(title, author, copies);
        cout << "Book added successfully." << endl;
    }

    void loanBook(const string& title) {
        for (auto& book : books) {
            if (book.title == title && book.copies > 0) {
                book.copies--;
                loanedBooks[title]++;
                cout << "Book loaned successfully." << endl;
                return;
            }
        }
        cout << "Book not available or not found." << endl;
    }

    void returnBook(const string& title) {
        if (loanedBooks.find(title) != loanedBooks.end() && loanedBooks[title] > 0) {
            loanedBooks[title]--;
            for (auto& book : books) {
                if (book.title == title) {
                    book.copies++;
                    cout << "Book returned successfully." << endl;
                    return;
                }
            }
        }
        cout << "Error in returning book." << endl;
    }

    void displayBooks() const {
        cout << "Available Books:" << endl;
        for (const auto& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", Available Copies: " << book.copies << endl;
        }
    }
};

int main() {
    Library library;
    string title, author;
    int copies, choice;

    cout << "Library Management System" << endl;

    while (true) {
        cout << "1. Add Book" << endl;
        cout << "2. Loan Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Display Books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin >> ws;  // to consume any leading whitespace
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter number of copies: ";
                cin >> copies;
                library.addBook(title, author, copies);
                break;
            case 2:
                cout << "Enter book title to loan: ";
                cin >> ws;
                getline(cin, title);
                library.loanBook(title);
                break;
            case 3:
                cout << "Enter book title to return: ";
                cin >> ws;
                getline(cin, title);
                library.returnBook(title);
                break;
            case 4:
                library.displayBooks();
                break;
            case 5:
                cout << "Exiting application." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
