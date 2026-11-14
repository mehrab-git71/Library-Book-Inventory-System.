// INDIVIDUAL CONTRIBUTION EXTRACT
// This file shows the section assigned to Member 2.
// It is an excerpt from ../src/main.cpp and is not intended to compile alone.

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
