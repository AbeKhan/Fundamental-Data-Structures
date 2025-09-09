// #pragma once
#ifndef SONG_H
#define SONG_H
#include <string>
#include <vector>
using namespace std;
struct Song
{
private:
    // static dataType variable;
    // static returnType functionName();
    string title; // instance member variable (data memeber)
                  //  Song song: --> instance reservers a memeory to store all the instance memeber variables

    // validGenres does not depend on a single object
    //
    static vector<string> validGenres; // empty vector of strings
    string genre;

public:
    Song(string, string); // title, genre

    static void addGenres(string);// it can access only static members

    // no need for destructor as there is no dynamic memory (heap memory)
};
#endif