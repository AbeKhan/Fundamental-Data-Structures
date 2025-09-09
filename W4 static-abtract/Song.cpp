#include "Song.h"

Song::Song(string title, string genre)
{
    this->title = title;
    this->genre = genre;  //this: the address of an object that calls this constructor
}

void Song::addGenres(const string genre)
{
    validGenres.push_back(genre);
}