#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "LibraryItem.h"
#include "Member.h"
#include "Transaction.h"


class Library {
    std::vector<LibraryItem*> items;    // owns pointers
    std::vector<Member*> members;       // owns pointers
    std::string libraryName;
    std::vector<Transaction*> transactions; // owns pointers
    std::map<std::string, int> itemCountByType;

public:
    explicit Library(std::string name) : libraryName(std::move(name)) {}
    ~Library();

    // Item Management
    void addItem(LibraryItem* item);
    void removeItem(const std::string& itemID);

    // Member Management
    void addMember(Member* member);
    void removeMember(const std::string& memberID);

    // Search
    LibraryItem* searchByID(const std::string& itemID) const;
    LibraryItem* searchByTitle(const std::string& title) const; // optional
    std::vector<LibraryItem*> searchByAuthor(const std::string& author) const; // optional
    Member* findMember(const std::string& memberID) const;

    // Borrow/Return
    void borrowItem(const std::string& memberID, const std::string& itemID, const std::string& dueDate, const std::string& dateStamp);
    void returnItem(const std::string& memberID, const std::string& itemID, int daysLate, const std::string& dateStamp);

    // Display
    void displayAllItems() const;       // optional
    void displayAvailableItems() const;
    void displayBorrowedItems() const;  // optional
    void displayMemberInfo(const std::string& memberID) const;

    // Reporting
    void generateReport() const; //optonal

    // Operators
    Library operator+(const Library& rhs) const; // deep-merge (items/members cloned)
    LibraryItem* operator[](size_t index) const { return items.at(index); }
    friend std::ostream& operator<<(std::ostream& os, const Library& lib);

    /* File I/O (optional)
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename); // destroys current and loads
    void saveTransactions(const std::string& filename) const;
    */
   
    //getter
    string getLibraryName() const;
};

#endif
