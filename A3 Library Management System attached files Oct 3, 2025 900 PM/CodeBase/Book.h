#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
    std::string ID;
    std::string title;
    std::string author;
    std::string ISBN;
    std::string genre;
    int year;
    int pageCount;

public:
    Book(std::string, std::string, std::string, int, std::string, std::string, int);
};
#endif