#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

class Transaction {
    std::string transactionID;
    std::string memberID;
    std::string itemID;
    std::string transactionType; // "BORROW" or "RETURN"
    std::string date;
    double feesPaid;

public:
    Transaction(std::string tid, std::string mid, std::string iid, std::string type,
                std::string date, double feesPaid = 0.0)
        : transactionID(std::move(tid)), memberID(std::move(mid)), itemID(std::move(iid)),
          transactionType(std::move(type)), date(std::move(date)), feesPaid(feesPaid) {}

    void displayTransaction() const;
    const std::string& getMemberID() const { return memberID; }
    const std::string& getItemID() const { return itemID; }
    const std::string& getType() const { return transactionType; }
    const std::string& getDate() const { return date; }
    double getFeesPaid() const { return feesPaid; }

    friend std::ostream& operator<<(std::ostream& os, const Transaction& t);
};

#endif
