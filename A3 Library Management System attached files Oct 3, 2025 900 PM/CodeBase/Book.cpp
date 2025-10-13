#include "Book.h"
#include <string>

Book::Book(std::string id, std::string ti, std::string auth, int y, std::string isbn, std::string gen, int pageC) 
{
    ID = id;
    title = ti;
    author = auth;
    year = y;
    ISBN = isbn;
    pageCount = pageC;
}