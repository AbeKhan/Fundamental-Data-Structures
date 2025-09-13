#include <iostream>
#include <string>

using namespace std;

struct Song
{
    std::string title;
    std::string artist;
    int duration;
    std::string genre;
    int rating;
    Song *next;

    Song(std::string t, std::string a, int d, std::string g, int r)
        : title(t), artist(a), duration(d), genre(g), rating(r), next(nullptr) {}
    void display() const;
    std::string formatDuration() const;
};

class PlaylistManager
{
private: // define the necessary data members
public:
    // Constructor and Destructor
    PlaylistManager();
    ~PlaylistManager();

    // Main interface functions
    void displayMainMenu();
    void handleMenuChoice(int choice);

private:
    // Menu functions (UI + validation)
    void addSongMenu();
    void removeSongMenu();
    void searchSongsMenu();

    // Core business logic functions
    void addSong(const std::string &title, const std::string &artist,
                 int duration, const std::string &genre, int rating);
    void removeSongByTitle(const std::string &title);
    Song *searchSongByTitle(const std::string &title) const;
    void displayPlaylist() const; // Business logic only due to minimal UI
    void clearPlaylist();         // Business logic only due to minimal UI
    void toggleShuffleMode();     // Business logic only because it is a toggle

    // Utility functions
    bool isEmpty() const;
    int getTotalSongs() const;
    void exitProgram();
};

// Main program loop example
int main()
{
    PlaylistManager manager;
    int choice;

    std::cout << " Welcome to Music Playlist Manager! " << std::endl;

    do
    {
        manager.displayMainMenu();
        std::cin >> choice;
        manager.handleMenuChoice(choice);
    } while (choice != 0);

    return 0;
}

void PlaylistManager::displayMainMenu()
{
    std::cout << "\n"
              << std::string(50, '=') << std::endl;
    std::cout << "         MUSIC PLAYLIST MANAGER " << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    std::cout << "  1. Add Song" << std::endl;
    std::cout << "  2. Display Playlist" << std::endl;
    std::cout << "  3. Remove Song" << std::endl;
    std::cout << "  4. Search Songs" << std::endl;
    std::cout << "  5. Toggle Shuffle Mode" << std::endl;
    std::cout << "  6. Clear Playlist" << std::endl;
    std::cout << "\n 0. Exit Program" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    std::cout << "Enter your choice (0-6): ";
}
void PlaylistManager::handleMenuChoice(int choice)
{
    std::cout << std::endl;

    switch (choice)
    {
    case 1:
        addSongMenu();
        break;
    case 2:
        displayPlaylist();
        break;
    case 3:
        removeSongMenu();
        break;
    case 4:
        searchSongsMenu();
        break;
    case 5:
        toggleShuffleMode();
        break;
    case 6:
        clearPlaylist();
        break;
    case 0:
        exitProgram();
        break;
    default:
        std::cout << "Invalid choice! Please enter a number between 0-16." << std::endl;
    }

    if (choice != 0)
    {
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(); //
        // discard only the next single character from the input buffer. Commonly used to remove the trailing newline character using cin >> to read a numeric value, which leaves the newline in the buffer.
        // Check out cin.ignore(count), ignore(count, delimiter)
        // cin.clear() : to reset the error flags and discard the invalid characters, allowing for subsequent input
        std::cin.get(); // read one character and return an int
    }
}
// Song TODO: Students need to implement undefined functions listed in Song

// PlaylistManager TODO: Students need to implement these functions
void PlaylistManager::addSongMenu()
{
    cout << " ADD NEW SONG" << endl;
    cout << string(30, '-') << endl;
    cout << "TODO: Implement this function" << endl;
    cout << "Hint: Get user input for title, artist, duration, genre, rating" << endl;
    cout << "Then call addSong() with the collected data" << endl;
}

void PlaylistManager::addSong(const std::string &title, const std::string &artist,
                              int duration, const std::string &genre, int rating)
{
    cout << "TODO: Implement linked list insertion" << endl;
    cout << "Hint: Create new Song, link to list, update totalSongs" << endl;
}

void PlaylistManager::removeSongMenu()
{
    cout << " REMOVE SONG" << endl;
    cout << string(30, '-') << endl;
    cout << "TODO: Implement this function" << endl;
    cout << "Hint: Get song title from user, call removeSongByTitle()" << endl;
}

void PlaylistManager::removeSongByTitle(const std::string &title)
{
    cout << "TODO: Implement linked list deletion" << endl;
    cout << "Hint: Search for song, handle head/middle/tail cases" << endl;
}

void PlaylistManager::displayPlaylist() const
{
    cout << " CURRENT PLAYLIST" << endl;
    cout << string(80, '-') << endl;
    cout << "TODO: Implement playlist display" << endl;
    cout << "Hint: Traverse linked list, call display() on each song" << endl;
}

void PlaylistManager::searchSongsMenu()
{
    cout << " SEARCH SONGS" << endl;
    cout << string(30, '-') << endl;
    cout << "TODO: Implement search interface" << endl;
    cout << "Hint: Get search term, call searchSongByTitle()" << endl;
}

Song *PlaylistManager::searchSongByTitle(const std::string &title) const
{
    cout << "TODO: Implement search algorithm" << endl;
    cout << "Hint: Traverse list, compare titles (case-insensitive?)" << endl;
    return nullptr;
}

void PlaylistManager::clearPlaylist()
{
    cout << "TODO: Implement playlist clearing" << endl;
    cout << "Hint: Delete all nodes, reset head/currentSong/totalSongs" << endl;
}

void PlaylistManager::toggleShuffleMode()
{
    cout << "TODO: Implement shuffle toggle" << endl;
    cout << "Hint: Change shuffleMode boolean, apply Fisher-Yates Shuffle, and display the resulting list of titles" << endl;
}

void PlaylistManager::exitProgram()
{
    cout << "\n Thank you for using Music Playlist Manager!" << endl;
    cout << " Keep the music playing! " << endl;
}
