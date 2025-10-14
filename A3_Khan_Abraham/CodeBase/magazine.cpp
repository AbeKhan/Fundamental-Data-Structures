#include "Magazine.h"

Magazine::Magazine(std::string id, std::string title, std::string author, int year, int in, std::string m) 
: LibraryItem(id, title, author, year),  issueNumber(in), month(m) {}

void Magazine::displayInfo() const {
    std::cout << *this << std::endl; // Uses overloaded operator<<
}

double Magazine::calculateLateFee(int daysLate) const
{
    const double ratePerDay = 0.25;
    return ratePerDay * daysLate;
}

std::string Magazine::getItemType() const
{
    return "Magazine: " + getTitle() + " by " + getAuthor();
}

LibraryItem *Magazine::clone() const
{
    return new Magazine(getItemID(), getTitle(), getAuthor(), getPublicationYear(),
                    issueNumber, month);
}

std::ostream& operator<<(std::ostream& os, const Magazine& b) {
    os << "Magazine Info:\n"
       << "ID: " << b.getItemID() << "\n"
       << "Title: " << b.getTitle() << "\n"
       << "Author: " << b.getAuthor() << "\n"
       << "Year: " << b.getPublicationYear() << "\n"
       << "Issue Number: " << b.issueNumber << "\n"
       << "Month: " << b.month<< "\n"
       << "Available: " << (b.getIsAvailable() ? "Yes" : "No") << "\n";
    if (!b.getIsAvailable()) {
        os << "Borrowed By: " << b.getBorrowedBy() << "\n"
           << "Due Date: " << b.getDueDate() << "\n";
    }
    return os;
}

bool operator==(const Magazine& lhs, const Magazine& rhs) {

    if(lhs.itemID == rhs.itemID && lhs.title == rhs.title && lhs.author == rhs.author && lhs.publicationYear == rhs.publicationYear && lhs.issueNumber == rhs.issueNumber && lhs.month == rhs.month)
        return true;
    return false;
}