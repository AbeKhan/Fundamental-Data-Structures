#include <iostream>
#include <iomanip>
#include "Song.h"

using namespace std;

int main()
{

    // how to call a static memeber function:
    // DataType::function();
    // only once, never put in the constuctor to avoid repeatition
    Song::addGenres("Rock");
    Song::addGenres("Classical");

    // Song s1("Hello", "Pop"); //"Hello" --> C-string literal --> constant
    string title = "Pigstep";
    string genre = "Minecraft";

    cout << "addr of title = " << &title << endl;
    cout << "addr of genre = " << &genre << endl;

    Song s2(title, genre);

    // s1.addGenres("Blues"); // instance1.staticMemeber-->fine
    s2.addGenres("Jazz"); // instance2.staticMemeber

    //s1.printGenres();
    s2.printGenres();

    return 0;
}