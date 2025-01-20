#ifndef BOOK_SYSTEM_H
#define BOOK_SYSTEM_H
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;
    int year;
    bool isCheckedOut;

    Book(std::string t, std::string a, std::string i, int y);
};

#endif //BOOK_SYSTEM_H