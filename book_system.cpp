#include "book_system.h"
Book::Book(std::string t, std::string a, std::string i, int y) : title(t), author(a), isbn(i), year(y) {}

#include <vector>
#include <iostream>
#include <fstream>
std::vector<Book> library;

void addBook(std::vector<Book>& library, const Book& book) {
    library.push_back(book);
}

// add plans to get books added from csv file and add ways to look up, check out online books

void loadBooks() {
    std::ifstream booksFile("books.csv");

    if (!booksFile.is_open()) {
        std::cerr << "Books file not found" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(booksFile, line)) {
        // Assuming the format of each line is title,author,isbn,year
        std::string title, author, isbn;
        int year;

        size_t startPos = 0;
        size_t endPos = line.find(',');

        // Extract title
        title = line.substr(startPos, endPos - startPos);

        // Extract author
        startPos = endPos + 1;
        endPos = line.find(',', startPos);
        author = line.substr(startPos, endPos - startPos);

        // Extract ISBN
        startPos = endPos + 1;
        endPos = line.find(',', startPos);
        isbn = line.substr(startPos, endPos - startPos);

        // Extract year
        startPos = endPos + 1;
        year = std::stoi(line.substr(startPos));
    }
}


int main() {
    loadBooks();



    Book book1("1984", "George Orwell", "9780451524935", 1949);
    addBook(library, book1);

    // Display the book details
    for (const auto& book : library) {
        std::cout << "Title: " << book.title << "\n"
                  << "Author: " << book.author << "\n"
                  << "ISBN: " << book.isbn << "\n"
                  << "Year: " << book.year << "\n";
    }

    return 0;
}
