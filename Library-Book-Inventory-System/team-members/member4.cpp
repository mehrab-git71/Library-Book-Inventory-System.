// INDIVIDUAL CONTRIBUTION EXTRACT
// This file shows the section assigned to Member 4.
// It is an excerpt from ../src/main.cpp and is not intended to compile alone.

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
