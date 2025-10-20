#include "Book.h"
#include <iostream>

Book::Book(std::string id, std::string title, std::string author, int year,
           std::string isbn, std::string gen, int pc)
    : LibraryItem(id, title, author, year), ISBN(isbn),
      genre(gen), pageCount(pc) {}

void Book::displayInfo() const {
    std::cout << *this << std::endl; // Uses overloaded operator<<
}

double Book::calculateLateFee(int daysLate) const
{
    const double ratePerDay = 0.50;
    return ratePerDay * daysLate;
}

std::string Book::getItemType() const
{
    return "Book: " + getTitle() + " by " + getAuthor() + " (" + ISBN + ")";
}

LibraryItem *Book::clone() const
{
    return new Book(getItemID(), getTitle(), getAuthor(), getPublicationYear(),
                    ISBN, genre, pageCount);
}

std::ostream& operator<<(std::ostream& os, const Book& b) {
    os << "Type: Book\n"
       << "ID: " << b.getItemID() << "\n"
       << "Title: " << b.getTitle() << "\n"
       << "Author: " << b.getAuthor() << "\n"
       << "ISBN: " << b.ISBN << "\n"
       << "Genre: " << b.genre << "\n"
       << "Pages: " << b.pageCount << "\n"
       << "Publication Year: " << b.getPublicationYear() << "\n"
       << "Status: " << (b.getIsAvailable() ? "Available" : "Not Available") << "\n";
    if (!b.getIsAvailable()) {
        os << "Borrowed By: " << b.getBorrowedBy() << "\n"
           << "Due Date: " << b.getDueDate() << "\n";
    }
    return os;
}

bool operator==(const Book& lhs, const Book& rhs) {
    return lhs.ISBN == rhs.ISBN;
}
