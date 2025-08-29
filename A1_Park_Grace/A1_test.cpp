#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct GameState
{
//Public:
    string username;
    unsigned int points;
    int totalQuestions;
    int correctAnswers;
    int *decimals;
    int decimalCount;
    const int ARRAY_SIZE;

    // Constructor
    // 1. role: initialization of data members immediately, implicitly after an instance is created
    //          --> not creating an object
    // 2. the function name: same as the struct name
    // 3. return type: none
    // 4. RAII for dynamic, file........
    // 5. a single colon (:) on the function header: memeber initializer
    //          contructor() : var1(initial value), var2(initial value) {}
    //6. function overloading possible
    GameState() : points(0), totalQuestions(0), correctAnswers(0),
                  decimalCount(0), ARRAY_SIZE(3)
    {
        cout << "GameState() called on the instance: " <<  this << endl;
        decimals = new int[ARRAY_SIZE];

        cout << "Address of decimals array: " << &decimals << endl;
    }

    // Destructor
    //1. role: clean up resources
    //2. the function name: ~struct name
    //3. return type: none
    //4. cannot be overloaded --> only one destructor
    //5. Immediately, implicitly called when an instance is out of scope

    ~GameState()
    {
        cout << "GameState() called on the instance: " <<  this << endl;

        delete[] decimals; // clean up the resources--> no (heap) memory leak
    }
};

int main()
{
    srand(time(0));

    //GameState: name of a data type you define
    //game: instance, variable, ibject (for class)
    //game is stored in the stack memory
    GameState game; //--> gameState() called by implicitly passing the address of game

    cout << "sizeof(GameState) = " << sizeof(GameState) << endl;
    cout << "sizeof(game) = " << sizeof(game) << endl;
    cout << "sizeof(string) = " << sizeof(string) << endl;

    //with struct instance, game.var or game.function()
    cout << "decimalCount = " << game.decimalCount << endl;

    GameState* ptr = &game; //ptr's size: 8 bytes
    cout << "decimals[0] = " << ptr->decimals[0] << endl;
    initializeGame(game);

    bool continueGame;
    do
    {
        continueGame = playGameRound(game);
    } while (continueGame);

    finalizeGame(game);
    return 0; //game is out of scope --> GameState() called
}

void initializeGame(GameState &game)
{
    game.username = getUsernameInput();
    // displayWelcome(game.username);
}

bool playGameRound(GameState &game)
{
    // TODO: Execute one game round
    // - Generate random decimal
    // - Convert to hex (correct answer)
    // - Increment totalQuestions
    // - Display question
    // - Get user's hex answer
    // - Check if correct
    // - Update score if correct
    // - Display result and stats
    // - Save question to history
    // - Store decimal in array
    // - Ask if user wants to continue
    // - Return true to continue, false to quit

    return false; // PLACEHOLDER - Remove this line
}

string getUsernameInput()
{
    // TODO: Implement username input with validation loop
    // - Display prompt "=== Hex Conversion Game ==="
    // - Get username from user
    // - Use getline() to allow spaces
    // - Call trim() to clean input
    // - Use validateUsername() to check format
    // - Loop until valid username provided
    // - Return the valid username

    return ""; // PLACEHOLDER - Remove this line
}

void finalizeGame(GameState &game)
{
    // TODO: Finalize the game
    // - Flush any remaining decimals to file
    // - Save session information
    // - Display final summary
}