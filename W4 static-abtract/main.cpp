#include <iostream>
#include <iomanip>
#include "Song.h"

using namespace std;

int main()
{

    // how to call a static memeber function:
    // DataType::function();
    //only once, never put in the constuctor to avoid repeatition
    Song::addGenres("Rock");
    Song::addGenres("Classical");

    Song s1("Hello", "Pop");
    Song s2("Pigstep", "Minecraft");

    s1.addGenres("Blues"); //instance1.staticMemeber-->fine
    s2.addGenres("Jazz");  //instance2.staticMemeber

    return 0;
}