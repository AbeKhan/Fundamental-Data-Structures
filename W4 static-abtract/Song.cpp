#include <iostream>
#include "Song.h"

using namespace std;
// definitione of the static member variable
//  -> reserve memeory, still an empty vector
vector<string> Song::validGenres;

Song::Song(string title, string &genre)
{
    cout << "Song(): " << this << endl;
    cout << "Addr of title: " << &title << endl;
    cout << "value of title: " << title << endl;
    cout << "sizeof (title): " << sizeof(title) << endl;
    cout << "sizeof (string): " << sizeof(string) << endl;
    cout << "Addr of genre: " << &genre << endl;
    cout << "value of genre: " << genre << endl;
    this->title = title;
    this->genre = genre; // this: the address of an object that calls this constructor
}

void Song::addGenres(const string genre)
{
    validGenres.push_back(genre);
}

void Song::printGenres()
{
    for(string& s: validGenres)
    {
        cout << s << " ";
    }
    cout << endl;
}

//Pass By Value: creates a copy of that value and uses the new copy
//Pass By Reference: Does Not Create a copy and uses the value that the variable has