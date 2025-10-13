#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"
#include <string>

class Magazine : public LibraryItem
{
    std::string month;
    int issueNumber;

public:
    Magazine(std::string id, std::string title, std::string author, int year,
             int in, std::string m);

    void displayInfo() const override;
    double calculateLateFee(int daysLate) const override;
    std::string getItemType() const override;
    LibraryItem *clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const Magazine &b);
    friend bool operator==(const Magazine &lhs, const Magazine &rhs);
};

#endif
