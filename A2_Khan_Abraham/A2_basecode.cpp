#include <iostream>
#include <algorithm>
#include <cctype>
#include <limits>
#include <string>
#include <cstdlib> // for rand()
#include <ctime>   // for time()
#include <fstream>
#include <sstream>

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

void Song::display() const
{
    cout << "\"" << title << "\" by " << artist << " | "
         << formatDuration() << " | "
         << genre << " | Rating: " << rating << endl;
}

string Song::formatDuration() const
{
    int minutes = duration / 60;
    int seconds = duration % 60;
    return to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + to_string(seconds);
}

class PlaylistManager
{
private: // define the necessary data members
private:
    Song *head;       // Pointer to first song in playlist
    int totalSongs;   // Track number of songs in playlist
    bool shuffleMode; // Track if playlist is in shuffle mode
                      // Song *currentSong; // Pointer to currently playing song
public:
    // Constructor and Destructor
    PlaylistManager();
    ~PlaylistManager();

    // Main interface functions
    void displayMainMenu();
    void handleMenuChoice(int choice);

    // File I/O
    void loadFromFile(const std::string &filename);

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
    manager.loadFromFile("songlist.txt");

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

PlaylistManager::PlaylistManager() : head(nullptr), totalSongs(0), shuffleMode(false)
{
    srand(static_cast<unsigned>(time(nullptr))); // Initialize random seed for shuffle functionality
}

PlaylistManager::~PlaylistManager()
{
    clearPlaylist();
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
        std::cout << "Invalid choice! Please enter a number between 0-6." << std::endl;
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

    string title, artist, genre;
    int duration, rating;

    // Ensure any leftover newline is removed before reading lines
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Please enter the song title: ";
    getline(cin, title);

    cout << "Please enter the artist: ";
    getline(cin, artist);

    cout << "Please enter the genre: ";
    getline(cin, genre);

    cout << "Please enter the duration (in seconds): ";
    while (!(cin >> duration) || duration <= 0)
    {
        cout << "Invalid duration. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Please enter the rating (1-5): ";
    while (!(cin >> rating) || rating < 1 || rating > 5)
    {
        cout << "Invalid rating. Please enter a number between 1 and 5: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // After reading numbers, remove the trailing newline so next getline works elsewhere
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    addSong(title, artist, duration, genre, rating);
}

void PlaylistManager::addSong(const std::string &title, const std::string &artist,
                              int duration, const std::string &genre, int rating)
{
    // cout << "TODO: Implement linked list insertion" << endl;
    // cout << "Hint: Create new Song, link to list, update totalSongs" << endl;
    Song *temp = new Song(title, artist, duration, genre, rating);

    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        Song *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }

    totalSongs++;
}

void PlaylistManager::removeSongMenu()
{
    cout << " REMOVE SONG" << endl;
    cout << string(30, '-') << endl;
    string title;

    // Remove any leftover newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Please enter the title of the song you want to remove: ";
    std::getline(cin, title);

    removeSongByTitle(title);
}

void PlaylistManager::removeSongByTitle(const std::string &title)
{
    // cout << "TODO: Implement linked list deletion" << endl;
    // cout << "Hint: Search for song, handle head/middle/tail cases" << endl;

    if (head == nullptr)
    {
        cout << "Playlist is empty. There is nothing to remove." << endl;
    }

    Song *prev = nullptr;
    Song *curr = head;

    while (curr != nullptr)
    {
        if (curr->title == title)
        {
            if (prev == nullptr)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            delete curr;
            totalSongs--;
            cout << "Removed song: " << title << endl;
            return;
        }

        prev = curr;
        curr = curr->next;
    }
    cout << "Song not found: " << title << endl;
}

void PlaylistManager::displayPlaylist() const
{
    cout << " CURRENT PLAYLIST" << endl;
    cout << string(80, '-') << endl;
    // cout << "TODO: Implement playlist display" << endl;
    // cout << "Hint: Traverse linked list, call display() on each song" << endl;

    if (head == nullptr)
    {
        cout << "Playlist is empty." << endl;
        return;
    }

    const Song *curr = head;
    int index = 1;
    while (curr != nullptr)
    {
        cout << index++ << ". ";
        curr->display(); // ensure Song::display() is implemented
        curr = curr->next;
    }
}

void PlaylistManager::searchSongsMenu()
{
    cout << " SEARCH SONGS" << endl;
    cout << string(30, '-') << endl;

    string title;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Please enter the title of the song you are looking for: ";
    getline(cin, title);
    searchSongByTitle(title);
}

Song *PlaylistManager::searchSongByTitle(const std::string &title) const
{
    Song *curr = head;
    string searchTitle = title;
    transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::tolower);

    while (curr != nullptr)
    {
        string currTitle = curr->title;
        transform(currTitle.begin(), currTitle.end(), currTitle.begin(), ::tolower);

        if (currTitle == searchTitle)
        {
            cout << "Found: " << curr->title << " by " << curr->artist << endl;
            return curr;
        }
        curr = curr->next;
    }

    cout << "Song not found: " << title << endl;
    return nullptr;
}

void PlaylistManager::clearPlaylist()
{
    // cout << "TODO: Implement playlist clearing" << endl;
    // cout << "Hint: Delete all nodes, reset head/currentSong/totalSongs" << endl;
    Song *curr = head;
    while (curr != nullptr)
    {
        Song *next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    // currentSong = nullptr;
    totalSongs = 0;
    shuffleMode = false;
}

void PlaylistManager::toggleShuffleMode()
{
    if (totalSongs <= 1)
    {
        cout << "Not enough songs to shuffle." << endl;
        return;
    }

    try
    {
        Song **songArray = new Song *[totalSongs];
        shuffleMode = !shuffleMode;

        if (!shuffleMode)
        {
            delete[] songArray;
            cout << "Shuffle mode disabled." << endl;
            return;
        }

        Song *current = head;
        int index = 0;

        while (current != nullptr)
        {
            songArray[index++] = current;
            current = current->next;
        }

        for (int i = totalSongs - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);
            swap(songArray[i], songArray[j]);
        }

        head = songArray[0];
        current = head;
        for (int i = 1; i < totalSongs; i++)
        {
            current->next = songArray[i];
            current = current->next;
        }
        current->next = nullptr;

        delete[] songArray;
        cout << "Playlist shuffled! New order:" << endl;
        displayPlaylist();
    }
    catch (const std::bad_alloc &)
    {
        cout << "Memory allocation failed for shuffle operation." << endl;
        shuffleMode = false;
    }
}

void PlaylistManager::loadFromFile(const std::string &filename)
{
    std::ifstream in(filename);
    if (!in) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    int lineNo = 0;
    while (std::getline(in, line))
    {
        ++lineNo;
        if (line.empty()) continue;
        if (!line.empty() && line.back() == '\r') line.pop_back(); // handle CRLF

        std::istringstream ss(line);
        string title, artist, durationStr, genre, ratingStr;

        if (!std::getline(ss, title, '|') ||
            !std::getline(ss, artist, '|') ||
            !std::getline(ss, durationStr, '|') ||
            !std::getline(ss, genre, '|') ||
            !std::getline(ss, ratingStr))
        {
            cout << "Malformed line " << lineNo << ": " << line << endl;
            continue;
        }

        auto trim = [](string &s) {
            size_t a = s.find_first_not_of(" \t");
            size_t b = s.find_last_not_of(" \t");
            if (a == string::npos) { s.clear(); return; }
            s = s.substr(a, b - a + 1);
        };

        trim(title); trim(artist); trim(durationStr); trim(genre); trim(ratingStr);

        int duration = 0;
        int rating = 0;
        try {
            duration = std::stoi(durationStr);
            rating = std::stoi(ratingStr);
        } catch (...) {
            cout << "Invalid number on line " << lineNo << ": " << line << endl;
            continue;
        }

        addSong(title, artist, duration, genre, rating);
    }

    cout << "Loaded songs from " << filename << endl;
}

void PlaylistManager::exitProgram()
{
    cout << "\n Thank you for using Music Playlist Manager!" << endl;
    cout << " Keep the music playing! " << endl;
}
