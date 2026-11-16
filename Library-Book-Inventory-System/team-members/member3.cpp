// INDIVIDUAL CONTRIBUTION EXTRACT
// This file shows the section assigned to Member 3.
// It is an excerpt from ../src/main.cpp and is not intended to compile alone.

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
