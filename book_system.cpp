#include "book_system.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
//book class and adds vector filled with books
Book::Book(std::string t, std::string a, std::string i, int y) : title(t), author(a), isbn(i), year(y) {}
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
        if (line.empty()) continue; // Skip empty lines

        std::stringstream ss(line);
        std::string title, author, isbn, yearStr;

        // Extract each component from the line
        std::getline(ss, title, ',');
        std::getline(ss, author, ',');
        std::getline(ss, isbn, ',');
        std::getline(ss, yearStr, ',');

        int year = yearStr.empty() ? 0 : std::stoi(yearStr); // Handle empty year field


        Book newbook(title, author, isbn, year);
        library.push_back(newbook);
    }
}

void searchByTitle(const std::vector<Book>& library, const std::string& searchTitle) {
    bool found = false;
    for (const auto& book : library) {
        if (book.title == searchTitle) {
            std::cout << "Found: " << book.title << " by " << book.author << '\n';
            found = true;
        }
    }
    if (!found) {
        std::cout << "Book not found \n";
    }
}


int main() {
    loadBooks();
    searchByTitle(library, "Moby Dick");

    return 0;
}
