# Library Management System

This is a basic library management system implemented in C++. The system allows you to add books to the library and display their details. The 
include  features such as reading book data from a CSV file and  functionalities for book lookup and online checkout.

## Getting Started

### Prerequisites

Make sure you have the following software installed:
- C++ Compiler (e.g., g++, clang++)
- C++ Standard Library

### Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/allenmonkey970/Basic-C-Library-Management-System.git
    cd library-management-system
    ```

2. Compile the code:

    ```bash
    g++ -o library_management_system main.cpp book_system.cpp
    ```

### Usage

1. Run the compiled executable:

    ```bash
    ./library_management_system
    ```

2. The program will load books from the `books.csv` file, search for a book by title or ISBN, check out a book, and then return it. Here's an example of what the output might look like:

```
Found: Moby Dick by Herman Melville
Found: The Art of War by Sun Tzu
Checked out: The Art of War
Returned: The Art of War
```


### Updated features

1. **Reading Books from a CSV File:**
    - function to read book data from a CSV file and add the books to the library.
    
2. **Book Lookup:**
    - Implemented functions to search for books in the library by title, or ISBN.

3. **Online Checkout:**
    - Add functionality to allow users to check out books online.


### Possible Plans
1. **User Interface/GUI**
   - Using possibly Qt or wxWidgets.

### Contributing

Feel free to contribute to this project by submitting pull requests or reporting issues.

### License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---
