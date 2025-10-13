#include "Member.h"

Member::Member(const std::string ID, const std::string nam, const std::string em,
               const std::string phoneN, const std::vector<std::string> bItems,
               double oFee, const std::string membership)
    : memberID(ID), name(nam), email(em), phoneNumber(phoneN),
      borrowedItems(bItems), outstandingFees(oFee), membershipType(membership) {}

    std::string Member::getMemberID()
    {
        return memberID;
    }

void Member::borrowItem(std::string itemID) {
    borrowedItems.push_back(itemID);
}

void Member::returnItem(std::string itemID) {
    auto it = std::find(borrowedItems.begin(), borrowedItems.end(), itemID);
    if (it != borrowedItems.end()) {
        borrowedItems.erase(it);
    }
}

void Member::payFee(double amount) {
    *this -= amount;  // Uses operator-=
}

void Member::displayMemberInfo() const {
    std::cout << *this << std::endl;  // Uses operator<<
}

Member& Member::operator+=(double amount) {
    outstandingFees += amount;
    return *this;
}

Member& Member::operator-=(double amount) {
    outstandingFees -= amount;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Member& m) {
    os << "Member Info:\n"
       << "ID: " << m.memberID << "\n"
       << "Name: " << m.name << "\n"
       << "Email: " << m.email << "\n"
       << "Phone: " << m.phoneNumber << "\n"
       << "Membership Type: " << m.membershipType << "\n"
       << "Outstanding Fees: $" << m.outstandingFees << "\n"
       << "Borrowed Items:\n";
    for (const auto& item : m.borrowedItems) {
        os << "  - " << item << "\n";
    }
    return os;
}
