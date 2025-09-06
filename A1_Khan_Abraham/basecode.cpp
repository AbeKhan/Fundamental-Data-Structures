/*
A1 - Hex Quiz Game Refactoring Project
BASE CODE TEMPLATE - complete the missing functions

PROVIDED: Core architecture structure, GameState struct, utility functions
TODO: Implement Frontend, Business Logic, and Backend functions as marked

5-Day Timeline:
Day 1-2: Understand structure, implement Frontend functions
Day 3: Implement Business Logic functions
Day 4: Implement Backend functions
Day 5: Testing, debugging, documentation
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

//=============================================================================
// GAME STATE STRUCTURE - PROVIDED
//=============================================================================
struct GameState
{
    string username; // string class' construcor initializes username to ""
    unsigned int points;
    int totalQuestions;
    int correctAnswers;
    int *decimals;
    int decimalCount;
    const int ARRAY_SIZE;

    // Constructor

    GameState() : points(0), totalQuestions(0), correctAnswers(0),
                  decimalCount(0), ARRAY_SIZE(3)
    {
        decimals = new int[ARRAY_SIZE]; // resources allocation
    }

    // Destructor
    ~GameState()
    {
        delete[] decimals; // clean up the resources--> no (heap) memory leak
    }
};

//=============================================================================
// FUNCTION DECLARATIONS - PROVIDED
//=============================================================================

// FRONTEND FUNCTIONS: handles all user interaction - getting input, displaying output, and managing the user experience flow.
string getUsernameInput();
bool validateUsername(const string &username);
int getValidatedChoice();
string getValidatedHexAnswer();
void displayWelcome(const string &username);
void displayGameStats(int points, int totalQuestions, int correctAnswers);
void displayQuestion(int questionNumber, int decimal);
void displayResult(bool isCorrect, const string &correctAnswer);
void displayFinalSummary(const GameState &game);

// BUSINESS LOGIC FUNCTIONS: contains game rules, scoring, and hex conversion.
void initializeGame(GameState &game);
bool playGameRound(GameState &game);
void finalizeGame(GameState &game);
int generateDecimal();
string convertDecToHex(int decimal);
char getHexDigit(int number);
bool checkAnswer(const string &userAnswer, const string &correctAnswer);
void updateScore(GameState &game, bool isCorrect);

// BACKEND FUNCTIONS: manages data persistence through file operations and dynamic memory management
void saveQuestionHistory(int decimal, const string &userAnswer,
                         const string &correctAnswer, bool isCorrect,
                         const string &username);
void saveSessionInfo(const GameState &game);
void storeDecimal(GameState &game, int decimal);
void flushDecimalsToFile(const GameState &game);

// UTILITY FUNCTIONS - PROVIDED
string trim(const string &str);
string getCurrentDateTime();

//=============================================================================
// MAIN FUNCTION - acts as a controller that orchestrates all three layer
//=============================================================================
int main()
{
    srand(time(0));

    GameState game;

    initializeGame(game);

    bool continueGame;
    do
    {
        continueGame = playGameRound(game);
    } while (continueGame);

    finalizeGame(game);
    return 0;
}

//=============================================================================
// UTILITY FUNCTIONS - PROVIDED (Complete implementations)
//=============================================================================
// trim(): remove whitespaces from the beginning and end of a string:
// Examples of what trim() does:
// trim("  hello  ")     → "hello"
// trim("\t\nworld\r")   → "world"
// trim("  ")            → ""
// trim("")              → ""
// trim("no spaces")     → "no spaces"
string trim(const string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == string::npos) // npos: means not found or no position
        return "";

    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

string getCurrentDateTime()
{
    time_t now = time(0);
    char *dt = ctime(&now);
    string dateTime(dt);
    if (!dateTime.empty() && dateTime.back() == '\n')
    {
        dateTime.pop_back();
    }
    return dateTime;
}

//=============================================================================
// TODO: Implement all the functions declared above
//=============================================================================

//-----------------------------------------------------------------------------
// FRONTEND FUNCTIONS - TODO: Implement these 9 functions
//-----------------------------------------------------------------------------

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

    string userName;
    bool valid = false;

    cout << "=== Hex Conversion Game ==" << endl;
    cout << "Please enter your user name (3-20 characters): ";
    while (!valid)
    {
        getline(cin, userName);
        userName = trim(userName);
        valid = validateUsername(userName);
        if (!valid)
        {
            cout << endl;
            cout << "Please enter a valid username: ";
        }
    }

    return userName;
}

bool validateUsername(const string &username)
{
    // TODO: Implement username validation
    // Requirements:
    // - Length must be 3-20 characters
    // - Only alphanumeric characters and spaces allowed
    // - Cannot be only spaces (use trim() to check)
    // - Return true if valid, false if invalid
    string usernameTrim = trim(username);
    bool alphanumeric = true;
    bool validLength = !(usernameTrim.length() < 3 || usernameTrim.length() > 20);
    bool notOnlySpace = !(usernameTrim == "");

    for (char c : username)
    {
        alphanumeric = (c >= 'A' && c <= 'Z') ||
                       (c >= 'a' && c <= 'z') ||
                       (c >= '0' && c <= '9') ||
                       (c == ' ');
    }

    return alphanumeric && notOnlySpace && validLength;
}

int getValidatedChoice()
{
    // TODO: Implement choice validation for continue/quit
    // - Get input as string (to handle invalid input)
    // - Accept only "0" (quit) or "1" (continue)
    // - Loop until valid choice provided
    // - Return 0 or 1 as integer

    string choice;
    cout << "Enter 0 to quit, 1 to contuine " << endl;
    do
    {
        cin >> choice;
        stoi(choice);
        if (stoi(choice) != 0 || stoi(choice) != 1)
            cout << "Invalid input. Please enter 0 to quit or 1 to continue: ";
    } while (stoi(choice) != 1 || stoi(choice) != 0);
    return stoi(choice);
}

string getValidatedHexAnswer()
{
    // TODO: Implement hex answer validation
    // - Get answer as string
    // - Convert to lowercase using transform()
    // - Validate only 0-9 and a-f characters allowed
    // - Loop until valid hex string provided
    // - Return valid hex string
    string hexAnswer;
    bool validHex = false;
    do
    {

        cout << "Enter your answer: ";
        cin >> hexAnswer;
        transform(hexAnswer.begin(), hexAnswer.end(), hexAnswer.begin(), ::tolower);
        for (char c : hexAnswer)
        {
            if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')))
            {
                cout << "Invalid input. Please enter a valid hexadecimal number (0-9, a-f). " << endl;
                validHex = false;
                break;
            }
            else
                validHex = true;
        }

    } while (validHex);
    return hexAnswer;
}

void displayWelcome(const string &username)
{
    cout << "\nWelcome, " << username << "!" << endl;
    cout << "Let's practice converting decimal numbers to hexadecimal." << endl;
    cout << "You'll earn 1 point for each correct answer." << endl;
    cout << "Use lowercase letters (a-f) for hex digits 10-15." << endl;
}

void displayGameStats(int points, int totalQuestions, int correctAnswers)
{
    // TODO: Display current game statistics
    // Show current score (points)
    // Calculate and show accuracy percentage if totalQuestions > 0
    // Format: "Current Score: X points | Accuracy: XX.X%"

    if (totalQuestions < 1)
    {
        cout << "Current Score: " << points << "  points | Accuracy: 00.0%" << endl;
    }
    else
        cout << "Current Score: " << points << "  points | Accuracy: " << correctAnswers / double(totalQuestions) << setprecision(1) << "%" << endl;
}

void displayQuestion(int questionNumber, int decimal)
{
    cout << "\n--- Question " << questionNumber << " ---" << endl;
    cout << "Convert " << decimal << " to hex: ";
}

void displayResult(bool isCorrect, const string &correctAnswer)
{
    if (isCorrect)
    {
        cout << "Excellent! ";
    }
    else
    {
        cout << "Practice! The correct answer was: " << correctAnswer << ". ";
    }
}

void displayFinalSummary(const GameState &game)
{
    // TODO: Display final game summary
    // Show: Player name, total questions, correct answers, final score
    // Calculate and show final accuracy percentage
    // Thank the player

    cout << "Name: " << game.username
         << " Total Questions: " << game.totalQuestions
         << " Answered Correclty: " << game.correctAnswers
         << " Final Score: " << game.points << endl;

    cout << "Thank you for playing! Come back soon " << game.username << "!" << endl;
}

//-----------------------------------------------------------------------------
// BUSINESS LOGIC FUNCTIONS - TODO: Implement these 8 functions
//-----------------------------------------------------------------------------

void initializeGame(GameState &game)
{
    game.username = getUsernameInput();
    displayWelcome(game.username);
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

    int randomInt = generateDecimal();
    string userAnswer;
    string correctAnswer = convertDecToHex(randomInt);
    game.totalQuestions++;

    cout << "Convert " << randomInt << " to a hex value. ";
    userAnswer = getValidatedHexAnswer();
    checkAnswer(userAnswer, correctAnswer);
    // displayGameStats();

    // updateScore();

    return false; // PLACEHOLDER - Remove this line
}

void finalizeGame(GameState &game)
{
    // TODO: Finalize the game
    // - Flush any remaining decimals to file
    // - Save session information
    // - Display final summary
}

int generateDecimal()
{
    return rand() % 256;
}

string convertDecToHex(int decimal)
{
    if (decimal == 0)
        return "0";

    int quotient = decimal;
    string answer;

    while (quotient != 0)
    {
        int remainder = quotient % 16;
        char hexDigit = getHexDigit(remainder);
        answer = hexDigit + answer;
        quotient = quotient / 16;
    }

    return answer;
}

char getHexDigit(int number)
{
    if (number < 10)
    {
        return (char)(number + '0');
    }
    else
    {
        return (char)(number % 10 + 'a');
    }
}

bool checkAnswer(const string &userAnswer, const string &correctAnswer)
{
    // TODO: Compare user answer with correct answer
    // Return true if they match exactly, false otherwise

    if (userAnswer == correctAnswer)
        return true;

    return false; // PLACEHOLDER - Remove this line
}

void updateScore(GameState &game, bool isCorrect)
{
    // TODO: Update game score
    // If correct: increment points and correctAnswers
    // This function modifies the GameState
    if (isCorrect)
    {
        game.points++;
        game.correctAnswers++;
    }
}

//-----------------------------------------------------------------------------
// BACKEND FUNCTIONS - TODO: Implement these 4 functions
//-----------------------------------------------------------------------------

void saveQuestionHistory(int decimal, const string &userAnswer,
                         const string &correctAnswer, bool isCorrect,
                         const string &username)
{
    // TODO: Save individual question to questions_history.txt
    // Open file in append mode
    // Write line with: timestamp | user | question | user answer | correct answer | result
    // Use getCurrentDateTime() for timestamp
    // Handle file open errors gracefully
    // Close file when done

    fstream file;

    file.open("questions_history.txt", ios::out | ios::app);

    if (file.is_open())
    {
        file << "timestamp " << getCurrentDateTime()
             << " | user " << username
             << " | question " << decimal
             << " | user answer " << userAnswer
             << " | correct answer " << correctAnswer
             << " | result " << isCorrect << endl;
        file.close();
    }
    else
        cerr << "Failed to open file." << endl;
}

void saveSessionInfo(const GameState &game)
{
    // TODO: Save session summary to session_history.txt
    // Open file in append mode
    // Write session header with timestamp, player, stats
    // Calculate accuracy percentage
    // Format nicely with proper spacing
    // Handle file open errors gracefully
    // Close file when done

    fstream file;

    file.open("session_history.txt", ios::out | ios::app);

    if (file.is_open())
    {
        file << "timestamp " << getCurrentDateTime()
             << " | player " << game.username
             << " | points " << game.points << endl;
        file.close();
    }
    else
        cerr << "Failed to open file." << endl;
}

void storeDecimal(GameState &game, int decimal)
{
    // TODO: Store decimal in memory array
    // If array not full (count < ARRAY_SIZE):
    //   - Add decimal to array at index count
    //   - Increment count
    // If array is full:
    //   - Call flushDecimalsToFile() to save current array
    //   - Put new decimal at index 0
    //   - Set count to 1
    if (game.decimalCount < game.ARRAY_SIZE)
    {
        game.decimals[game.decimalCount - 1] = decimal;
    }
    else
    {
        flushDecimalsToFile(game);
        game.decimals[0] = decimal;
        game.decimalCount = 1;
    }
}

void flushDecimalsToFile(const GameState &game)
{
    // TODO: Write decimal array to decimalHistory.txt
    // Open file in append mode
    // Write "Decimal batch: " followed by all decimals in array
    // Use game.decimalCount to know how many decimals to write
    // Handle file open errors gracefully
    // Close file when done

    fstream file;

    file.open("decimalHistory.txt", ios::out | ios::app);
    file << "Decimal batch: ";
    if (file.is_open())
    {
        for (int i = 0; i < game.decimalCount; i++)
        {
            file << game.decimals[i] << " ";
        }
        file << endl;
    }
    else
        cerr << "Failed to open file." << endl;
}

//=============================================================================
// IMPLEMENTATION HINTS AND REMINDERS
//=============================================================================

/*
IMPLEMENTATION TIPS:

Frontend Functions:
- Use getline() for username (allows spaces)
- Use cin >> for single-word inputs (choice, hex answer)
- Remember to validate ALL user input
- Use loops for validation (do-while or while)

Business Logic Functions:
- playGameRound() is the most complex - break it into steps
- Remember to update ALL game state fields
- convertDecToHex() - use while loop with division/remainder
- Don't forget special case: decimal 0 should return "0"

Backend Functions:
- Always check if file opened successfully
- Use ios::app for append mode
- Remember to close files
- Use getCurrentDateTime() for timestamps

Common Issues to Avoid:
- Not validating input properly
- Forgetting to update game state
- Memory leaks (destructor handles this)
- Not handling file errors
- Off-by-one errors in arrays

Testing Strategy:
- Test each function individually
- Test with valid and invalid inputs
- Test file operations (check output files)
- Test memory management (run multiple games)
*/