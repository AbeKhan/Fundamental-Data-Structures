#include "library.h"
#include <iostream>
#include <string>

// using namespace std;

std::string Library::getLibraryName() const
{
    return libraryName;
}

int Library::getTotalItems() const
{
    return items.size();
}

int Library::getTotalMembers() const
{
    return members.size();
}