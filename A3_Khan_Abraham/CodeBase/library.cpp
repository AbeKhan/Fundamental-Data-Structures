#include "Library.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

// Constructor
Library::Library(std::string name) : libraryName(std::move(name)) {}

// Destructor
Library::~Library() {
    for (auto item : items) delete item;
    for (auto member : members) delete member;
    for (auto txn : transactions) delete txn;
}

// Item Management
void Library::addItem(LibraryItem* item) {
    items.push_back(item);
    itemCountByType[item->getItemType()]++;
}

void Library::removeItem(const std::string& itemID) {
    auto it = std::find_if(items.begin(), items.end(),
        [&itemID](LibraryItem* item) {
            return item->getItemID() == itemID;
        });

    if (it != items.end()) {
        itemCountByType[(*it)->getItemType()]--;
        delete *it;
        items.erase(it);
        std::cout << itemID << " has been removed!" << std::endl;
    } else {
        std::cout << "Item not found." << std::endl;
    }
}

// Member Management
void Library::addMember(Member* member) {
    members.push_back(member);
}

void Library::removeMember(const std::string& memberID) {
    auto it = std::find_if(members.begin(), members.end(),
        [&memberID](Member* member) {
            return member->getMemberID() == memberID;
        });

    if (it != members.end()) {
        delete *it;
        members.erase(it);
        std::cout << memberID << " has been removed!" << std::endl;
    } else {
        std::cout << "Member not found." << std::endl;
    }
}

// Search
LibraryItem* Library::searchByID(const std::string& itemID) const {
    for (auto item : items) {
        if (item->getItemID() == itemID) return item;
    }
    return nullptr;
}

Member* Library::findMember(const std::string& memberID) const {
    for (auto member : members) {
        if (member->getMemberID() == memberID) return member;
    }
    return nullptr;
}

// Borrow/Return
void Library::borrowItem(const std::string& memberID, const std::string& itemID,
                         const std::string& dueDate, const std::string& dateStamp) {
    Member* member = findMember(memberID);
    LibraryItem* item = searchByID(itemID);

    if (!member || !item) {
        std::cout << "Invalid member or item ID." << std::endl;
        return;
    }

    if (!item->getIsAvailable()) {
        std::cout << "Item is already borrowed." << std::endl;
        return;
    }

    item->borrowItem(memberID, dueDate);
    member->borrowItem(itemID);

    transactions.push_back(new Transaction(memberID, itemID, "Borrow", dateStamp));
}

void Library::returnItem(const std::string& memberID, const std::string& itemID,
                         int daysLate, const std::string& dateStamp) {
    Member* member = findMember(memberID);
    LibraryItem* item = searchByID(itemID);

    if (!member || !item) {
        std::cout << "Invalid member or item ID." << std::endl;
        return;
    }

    item->returnItem();
    member->returnItem(itemID);

    double fee = item->calculateLateFee(daysLate);
    if (fee > 0) {
        std::cout << std::fixed << std::setprecision(2);
        *member += fee;
        std::cout << "Late fee of $" << fee << " applied to " << memberID << std::endl;
    }

    transactions.push_back(new Transaction(memberID, itemID, "Return", dateStamp));
}

// Display
void Library::displayAvailableItems() const {
    std::cout << "Available Items:\n";
    for (auto item : items) {
        if (item->getIsAvailable()) {
            std::cout << *item << "\n";
        }
    }
}

void Library::displayMemberInfo(const std::string& memberID) const {
    Member* member = findMember(memberID);
    if (member) {
        std::cout << *member << std::endl;
    } else {
        std::cout << "Member not found." << std::endl;
    }
}

// Getter
std::string Library::getLibraryName() const {
    return libraryName;
}
