#include "transaction.h"

void Transaction::displayTransaction() const
{
    std::cout << transactionType << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Transaction& t) {
    os << "transactionID " << t.transactionID
       << "memberID" << t.memberID
       << "Item: " << t.itemID
       << " " << (t.transactionType == "BORROW" ? "BORROW" : "RETURN")
       << " Date: " << t.date;
    return os;
}