// INDIVIDUAL CONTRIBUTION EXTRACT
// This file shows the section assigned to Member 1.
// It is an excerpt from ../src/main.cpp and is not intended to compile alone.

// MEMBER 1: BOOK DATA + INPUT + ADD/DISPLAY BOOKS
// ============================================================
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <cctype>
using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    int id;
    string name;
    string author;
    double price;
    int quantity;
};

Book books[MAX_BOOKS];
int bookCount = 0;

// Read an integer safely
int readInt(string message) {
    int value;
    cout << message;

    while (!(cin >> value)) {
        cout << "Invalid input! Enter a whole number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

// Read a non-negative price
double readPrice(string message) {
    double value;
    cout << message;

    while (!(cin >> value) || value < 0) {
        cout << "Invalid price! Enter zero or a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

// Find a book by ID (used by Members 2 and 4 as well)
int findBookByID(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Display one book's complete information
void displayBook(int index) {
    cout << "\n----------------------------------------\n";
    cout << "Book ID      : " << books[index].id << '\n';
    cout << "Book Name    : " << books[index].name << '\n';
    cout << "Author       : " << books[index].author << '\n';
    cout << "Price        : " << fixed << setprecision(2)
         << books[index].price << '\n';
    cout << "Quantity     : " << books[index].quantity << '\n';

    if (books[index].quantity > 0) {
        cout << "Availability : Available\n";
    } else {
        cout << "Availability : Out of stock\n";
    }
    cout << "----------------------------------------\n";
}

// Add one new book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "\nLibrary storage is full!\n";
        return;
    }

    int id = readInt("\nEnter Book ID: ");

    if (id <= 0) {
        cout << "Book ID must be positive.\n";
        return;
    }

    if (findBookByID(id) != -1) {
        cout << "This Book ID already exists!\n";
        return;
    }

    books[bookCount].id = id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Book Name: ";
    getline(cin, books[bookCount].name);

    cout << "Enter Author Name: ";
    getline(cin, books[bookCount].author);

    if (books[bookCount].name.empty() ||
        books[bookCount].author.empty()) {
        cout << "Book name and author cannot be empty.\n";
        return;
    }

    books[bookCount].price = readPrice("Enter Book Price: ");

    int quantity = readInt("Enter Book Quantity: ");
    while (quantity < 0) {
        quantity = readInt("Quantity cannot be negative. Enter again: ");
    }

    books[bookCount].quantity = quantity;
    bookCount++;

    cout << "\nBook added successfully!\n";
}

// Display every book currently stored
void displayAllBooks() {
    if (bookCount == 0) {
        cout << "\nNo books are registered in the library.\n";
        return;
    }

    cout << "\n==================== LIBRARY BOOKS ====================\n";
    cout << left
         << setw(8)  << "ID"
         << setw(26) << "Book Name"
         << setw(22) << "Author"
         << setw(12) << "Price"
         << setw(9)  << "Qty" << '\n';
    cout << string(77, '-') << '\n';

    for (int i = 0; i < bookCount; i++) {
        cout << left
             << setw(8)  << books[i].id
             << setw(26) << books[i].name.substr(0, 24)
             << setw(22) << books[i].author.substr(0, 20)
             << setw(12) << fixed << setprecision(2) << books[i].price
             << setw(9)  << books[i].quantity << '\n';
    }
}

// Add sample records so the project can be demonstrated immediately.
// Users can still add more books through menu option 1.
void loadSampleBooks() {
    books[0] = {101, "C++ Programming", "Bjarne Stroustrup", 450.00, 5};
    books[1] = {102, "Data Structures", "Mark Allen Weiss", 550.00, 3};
    books[2] = {103, "Algorithms", "Thomas H. Cormen", 600.00, 0};
    books[3] = {104, "Database Systems", "Ramez Elmasri", 500.00, 7};
    books[4] = {105, "Computer Networks", "Andrew Tanenbaum", 650.00, 2};
    bookCount = 5;
}


// ============================================================
