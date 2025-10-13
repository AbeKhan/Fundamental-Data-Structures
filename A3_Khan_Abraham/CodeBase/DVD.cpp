#include "DVD.h"

DVD::DVD(std::string id, std::string title, std::string author, int year,
         int dur, std::string gen)
    : LibraryItem(id, title, author, year), duration(dur), genre(gen), director(author) {}

void DVD::displayInfo() const
{
    std::cout << *this << std::endl; // Uses overloaded operator<<
}

double DVD::calculateLateFee(int daysLate) const
{
    const double ratePerDay = 0.25;
    return ratePerDay * daysLate;
}

std::string DVD::getItemType() const
{
    return "DVD: " + getTitle() + " by " + getAuthor();
}

LibraryItem *DVD::clone() const
{
    return new DVD(getItemID(), getTitle(), getAuthor(), getPublicationYear(),
                   duration, genre);
}

std::ostream& operator<<(std::ostream& os, const DVD& d) {
    os << "DVD Info:\n"
       << "ID: " << d.getItemID() << "\n"
       << "Title: " << d.getTitle() << "\n"
       << "Author: " << d.getAuthor() << "\n"
       << "Year: " << d.getPublicationYear() << "\n"
       << "Director: " << d.director << "\n"
       << "Genre: " << d.genre << "\n"
       << "Duration: " << d.duration << " mins\n"
       << "Available: " << (d.getIsAvailable() ? "Yes" : "No") << "\n";
    if (!d.getIsAvailable()) {
        os << "Borrowed By: " << d.getBorrowedBy() << "\n"
           << "Due Date: " << d.getDueDate() << "\n";
    }
    return os;
}


bool operator==(const DVD& lhs, const DVD& rhs) {
    return lhs.getItemID() == rhs.getItemID() &&
           lhs.getTitle() == rhs.getTitle() &&
           lhs.getAuthor() == rhs.getAuthor() &&
           lhs.getPublicationYear() == rhs.getPublicationYear() &&
           lhs.duration == rhs.duration &&
           lhs.genre == rhs.genre &&
           lhs.director == rhs.director;
}
