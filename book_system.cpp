#include "book_system.h"
Book::Book(std::string t, std::string a, std::string i, int y) : title(t), author(a), isbn(i), year(y) {}

#include <vector>
#include <iostream>

std::vector<Book> library;

void addBook(std::vector<Book>& library, const Book& book) {
    library.push_back(book);
}

int main() {
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
