# Library Book Inventory & Search System

A menu-driven, console-based Library Book Inventory & Search System developed in C++ for our CAC Algorithm course project.

## Project Overview

The program stores book records and provides options to add books, display records, search by ID or name, check availability, sort books, calculate inventory value, view out-of-stock books, and update quantities.

## Features

- Add new book records
- Display all registered books
- Search by book ID
- Search by full or partial book name (case-insensitive)
- Check book availability
- Sort books by price
- Sort books by ID
- Calculate total inventory value
- Display out-of-stock books
- Update book quantity

## Concepts and Algorithms

- C++ structures and arrays
- Functions, loops, and conditional statements
- Linear search
- Bubble sort
- String processing

## Repository Structure

```text
Library-Book-Inventory-System/
├── README.md
├── .gitignore
├── src/
│   └── main.cpp
├── member-contributions/
│   ├── member1.cpp
│   ├── member2.cpp
│   ├── member3.cpp
│   └── member4.cpp
└── screenshots/
    └── README.md
```

## Team Contributions

| Team member | Responsibility |
|---|---|
| Member 1 | Book data, input validation, add and display books |
| Member 2 | Searching and availability checking |
| Member 3 | Sorting algorithms |
| Member 4 | Inventory calculations, quantity update, and main menu |

> The four files in `member-contributions/` are contribution extracts from the integrated program. They are provided to document each member's assigned section; they are not separate, standalone programs. The complete runnable program is `src/main.cpp`.

## How to Compile and Run

You need a C++ compiler that supports C++17.

From the repository's root directory, run:

```bash
g++ -std=c++17 src/main.cpp -o library
```

Then run the program:

- Windows: `library.exe`
- Linux/macOS: `./library`

You can also open `src/main.cpp` in Code::Blocks or VS Code and compile/run it there.

## Sample Data

Five sample book records are loaded when the program starts, so the menu can be demonstrated immediately. Additional books can be added during execution.

## Limitations

- Records are stored in memory and are not saved after the program closes.
- The project does not currently use a database or login system.

## Possible Future Improvements

- Persistent storage or database integration
- User login and role management
- Book borrowing and returning
- Saving and loading records from a file

## Course Project

Developed as a group project for the CAC Algorithm course.
