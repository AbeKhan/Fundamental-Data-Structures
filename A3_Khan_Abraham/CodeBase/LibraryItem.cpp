#include "LibraryItem.h"

void LibraryItem::borrowItem(const std::string &memberID, const std::string &due)
{

    borrowedBy = memberID;
    dueDate = due;
    isAvailable = false;
}

void LibraryItem::returnItem()
{
    borrowedBy = "";
    dueDate = "";
    isAvailable = true;
}

std::ostream &operator<<(std::ostream &os, const LibraryItem &item)
{
    os << "Item ID: " << item.getItemID() << "\n"
       << "Title: " << item.getTitle() << "\n"
       << "Author: " << item.getAuthor() << "\n"
       << "Type: " << item.getItemType() << "\n"
       << "Available: " << (item.getIsAvailable() ? "Yes" : "No") << "\n";
    return os;
}
