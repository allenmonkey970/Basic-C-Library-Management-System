#ifndef BOOK_SYSTEM_H
#define BOOK_SYSTEM_H
#include <string>


class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;
    int year;

    Book(std::string title, std::string author, std::string isbn, int year);
};

#endif //BOOK_SYSTEM_H
