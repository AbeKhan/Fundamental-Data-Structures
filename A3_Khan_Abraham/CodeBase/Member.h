#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Member {
private:
    std::string memberID;
    std::string name;
    std::string email;
    std::string phoneNumber;
    std::vector<std::string> borrowedItems;
    double outstandingFees = 0.0;
    std::string membershipType; // "Student", "Faculty", "Public"

public:
    Member(std::string ID, std::string nam, std::string em, std::string phoneN,
            std::string memberType);

    void borrowItem(std::string itemID);
    void returnItem(std::string itemID);
    void payFee(double amount);
    void displayMemberInfo() const;

    std::string getMemberID();

    Member& operator+=(double amount);  // Add to fees
    Member& operator-=(double amount);  // Subtract from fees

    
    friend std::ostream& operator<<(std::ostream& os, const Member& m);
};

#endif
