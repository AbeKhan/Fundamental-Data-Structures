#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Member {
    std::string memberID;
    std::string name;
    std::string email;
    std::string phoneNumber;
    std::vector<std::string> borrowedItems;
    double outstandingFees = 0.0;
    std::string membershipType; // "Student", "Faculty", "Public"

public:

};

#endif
