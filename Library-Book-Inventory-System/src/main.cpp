// ============================================================
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
// MEMBER 2: SEARCHING + AVAILABILITY
// Paste this section after Member 1.
// ============================================================

// Search for a book using its ID
void searchByID() {
    if (bookCount == 0) {
        cout << "\nNo books are registered.\n";
        return;
    }

    int id = readInt("\nEnter Book ID to search: ");
    int index = findBookByID(id);

    if (index == -1) {
        cout << "\nBook not found in the library records.\n";
    } else {
        cout << "\nBook found!\n";
        displayBook(index);
    }
}

// Convert a string to lowercase for case-insensitive matching
string toLowerCase(string text) {
    transform(text.begin(), text.end(), text.begin(),
        [](unsigned char ch) {
            return static_cast<char>(tolower(ch));
        });
    return text;
}

// Search by full name or part of a book name
void searchByName() {
    if (bookCount == 0) {
        cout << "\nNo books are registered.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string searchName;

    cout << "\nEnter all or part of the Book Name: ";
    getline(cin, searchName);

    if (searchName.empty()) {
        cout << "Search text cannot be empty.\n";
        return;
    }

    string target = toLowerCase(searchName);
    bool found = false;

    for (int i = 0; i < bookCount; i++) {
        string currentName = toLowerCase(books[i].name);

        if (currentName.find(target) != string::npos) {
            displayBook(i);
            found = true;
        }
    }

    if (!found) {
        cout << "\nNo matching book was found.\n";
    }
}

// Check whether a registered book has copies available
void checkAvailability() {
    if (bookCount == 0) {
        cout << "\nNo books are registered.\n";
        return;
    }

    int id = readInt("\nEnter Book ID: ");
    int index = findBookByID(id);

    if (index == -1) {
        cout << "\nBook not found in the library records.\n";
    } else if (books[index].quantity > 0) {
        cout << "\nSTATUS: AVAILABLE\n";
        cout << "Copies available: " << books[index].quantity << '\n';
    } else {
        cout << "\nSTATUS: OUT OF STOCK\n";
        cout << "The book is registered, but no copies are available.\n";
    }
}


// ============================================================
// MEMBER 3: SORTING ALGORITHMS
// Paste this section after Member 2.
// ============================================================

// Bubble Sort: arrange books from lowest price to highest price
void sortByPrice() {
    if (bookCount < 2) {
        cout << "\nAt least two books are needed for sorting.\n";
        return;
    }

    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = 0; j < bookCount - i - 1; j++) {
            if (books[j].price > books[j + 1].price) {
                swap(books[j], books[j + 1]);
            }
        }
    }

    cout << "\nBooks sorted by price (lowest to highest).\n";
    displayAllBooks();
}

// Bubble Sort: arrange books by ascending Book ID
void sortByID() {
    if (bookCount < 2) {
        cout << "\nAt least two books are needed for sorting.\n";
        return;
    }

    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = 0; j < bookCount - i - 1; j++) {
            if (books[j].id > books[j + 1].id) {
                swap(books[j], books[j + 1]);
            }
        }
    }

    cout << "\nBooks sorted by ID (lowest to highest).\n";
    displayAllBooks();
}


// ============================================================
// MEMBER 4: INVENTORY + QUANTITY UPDATE + MAIN MENU
// Paste this section after Member 3. Keep main() at the end.
// ============================================================

// Calculate the total value of all copies in the library
void calculateInventoryValue() {
    double totalValue = 0;

    for (int i = 0; i < bookCount; i++) {
        totalValue += books[i].price * books[i].quantity;
    }

    cout << "\n========== INVENTORY SUMMARY ==========\n";
    cout << "Number of book titles: " << bookCount << '\n';
    cout << "Total copies: ";

    int totalCopies = 0;
    for (int i = 0; i < bookCount; i++) {
        totalCopies += books[i].quantity;
    }

    cout << totalCopies << '\n';
    cout << "Total inventory value: ৳"
         << fixed << setprecision(2) << totalValue << '\n';
}

// Display only books whose quantity is zero
void displayUnavailableBooks() {
    bool found = false;

    cout << "\n========== OUT-OF-STOCK BOOKS ==========\n";

    for (int i = 0; i < bookCount; i++) {
        if (books[i].quantity == 0) {
            displayBook(i);
            found = true;
        }
    }

    if (!found) {
        cout << "There are no out-of-stock books.\n";
    }
}

// Replace a book's recorded quantity with a new total quantity
void updateQuantity() {
    if (bookCount == 0) {
        cout << "\nNo books are registered.\n";
        return;
    }

    int id = readInt("\nEnter Book ID: ");
    int index = findBookByID(id);

    if (index == -1) {
        cout << "\nBook not found.\n";
        return;
    }

    cout << "Current quantity: " << books[index].quantity << '\n';

    int newQuantity = readInt("Enter the new total quantity: ");
    while (newQuantity < 0) {
        newQuantity = readInt("Quantity cannot be negative. Enter again: ");
    }

    books[index].quantity = newQuantity;
    cout << "\nQuantity updated successfully!\n";
}

// Main function connects all members' functions
int main() {
    loadSampleBooks();

    int choice;

    do {
        cout << "\n\n";
        cout << "============================================\n";
        cout << "       LIBRARY BOOK INVENTORY SYSTEM        \n";
        cout << "============================================\n";
        cout << "1.  Add New Book\n";
        cout << "2.  Display All Books\n";
        cout << "3.  Search Book by ID\n";
        cout << "4.  Search Book by Name\n";
        cout << "5.  Check Book Availability\n";
        cout << "6.  Sort Books by Price\n";
        cout << "7.  Sort Books by ID\n";
        cout << "8.  Calculate Inventory Value\n";
        cout << "9.  Display Out-of-Stock Books\n";
        cout << "10. Update Book Quantity\n";
        cout << "0.  Exit\n";
        cout << "============================================\n";

        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayAllBooks();
                break;
            case 3:
                searchByID();
                break;
            case 4:
                searchByName();
                break;
            case 5:
                checkAvailability();
                break;
            case 6:
                sortByPrice();
                break;
            case 7:
                sortByID();
                break;
            case 8:
                calculateInventoryValue();
                break;
            case 9:
                displayUnavailableBooks();
                break;
            case 10:
                updateQuantity();
                break;
            case 0:
                cout << "\nThank you for using the Library System!\n";
                break;
            default:
                cout << "\nInvalid menu choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
