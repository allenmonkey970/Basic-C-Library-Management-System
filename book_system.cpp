#include "book_system.h"
Book::Book(std::string t, std::string a, std::string i, int y) : title(t), author(a), isbn(i), year(y) {}

#include <vector>
#include <iostream>
#include <fstream>
std::vector<Book> library;

void addBook(std::vector<Book>& library, const Book& book) {
    library.push_back(book);
}



void loadBooks() {
    std::ifstream booksFile("books.csv");

    if (!booksFile.is_open()) {
        std::cerr << "Books file not found" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(booksFile, line)) {
        size_t startPos = 0;
        size_t endPos = line.find(',');

        // Extract title
        std::string title = line.substr(startPos, endPos - startPos);

        // Extract author
        startPos = endPos + 1;
        endPos = line.find(',', startPos);
        std::string author = line.substr(startPos, endPos - startPos);

        // Extract ISBN
        startPos = endPos + 1;
        endPos = line.find(',', startPos);
        std::string isbn = line.substr(startPos, endPos - startPos);

        // Extract year
        startPos = endPos + 1;
        int year = std::stoi(line.substr(startPos));

        Book newBook(title, author, isbn, year);
        library.push_back(newBook);
    }
}


int main() {
    loadBooks();
    std::cout << "Number of books loaded: " << library.size() << std::endl;
    for (const auto& book : library) {
        std::cout << "Title: " << book.title << "\n"
                  << "Author: " << book.author << "\n"
                  << "ISBN: " << book.isbn << "\n"
                  << "Year: " << book.year << "\n";
    }


    return 0;
}
