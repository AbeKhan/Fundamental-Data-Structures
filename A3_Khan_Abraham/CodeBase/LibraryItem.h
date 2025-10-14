#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <string>
#include <iostream>

class LibraryItem
{
protected:
    std::string itemID;
    std::string title;
    std::string author;
    int publicationYear;
    bool isAvailable;
    std::string borrowedBy;
    std::string dueDate;

public:
    LibraryItem(std::string id, std::string t, std::string a, int year)
        : itemID(std::move(id)), title(std::move(t)), author(std::move(a)),
          publicationYear(year), isAvailable(true) {}

    virtual ~LibraryItem() = default;

    // Pure virtuals
    virtual void displayInfo() const = 0;
    virtual double calculateLateFee(int daysLate) const = 0;
    virtual std::string getItemType() const = 0;

    // (Convenience for operator+ deep copy)
    virtual LibraryItem *clone() const = 0;

    // Borrow/Return
    void borrowItem(const std::string &memberID, const std::string &due);
    void returnItem();

    // Getters/Setters
    const std::string &getItemID() const { return itemID; }
    const std::string &getTitle() const { return title; }
    const std::string &getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }
    bool getIsAvailable() const { return isAvailable; }
    const std::string &getBorrowedBy() const { return borrowedBy; }
    const std::string &getDueDate() const { return dueDate; }

    void setTitle(const std::string &t) { title = t; }
    void setAuthor(const std::string &a) { author = a; }
    void setPublicationYear(int y) { publicationYear = y; }

    friend std::ostream &operator<<(std::ostream &os, const LibraryItem &item);
};

#endif