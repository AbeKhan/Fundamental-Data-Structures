#ifndef DVD_H
#define DVD_H

#include "LibraryItem.h"
#include <string>

class DVD : public LibraryItem
{
    int duration; // minutes
    std::string genre;
    std::string director;

public:
    DVD(std::string id, std::string title, std::string author, int year,
        int dur, std::string gen);

    void displayInfo() const override;
    double calculateLateFee(int daysLate) const override;
    std::string getItemType() const override;
    LibraryItem *clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const DVD &b);
    friend bool operator==(const DVD &lhs, const DVD &rhs);
};

#endif
