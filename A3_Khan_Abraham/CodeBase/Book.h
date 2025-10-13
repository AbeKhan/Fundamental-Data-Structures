#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include <iostream>

class Book : public LibraryItem
{
    std::string ISBN;
    std::string genre;
    int pageCount;

public:
    Book(std::string id, std::string title, std::string author, int year,
         std::string isbn, std::string gen, int pc);

    void displayInfo() const override;
    double calculateLateFee(int daysLate) const override;
    std::string getItemType() const override;
    LibraryItem *clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const Book &b);
    friend bool operator==(const Book &lhs, const Book &rhs);
};
#endif