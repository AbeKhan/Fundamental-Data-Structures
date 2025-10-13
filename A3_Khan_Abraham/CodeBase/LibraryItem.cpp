#include "LibraryItem.h"

void LibraryItem::borrowItem(const std::string& memberID, const std::string& due) {

    borrowedBy = memberID;
    dueDate = due;
    isAvailable = false;
}

void LibraryItem::returnItem() {
    borrowedBy = "";
    dueDate = "";
    isAvailable = true;
}
