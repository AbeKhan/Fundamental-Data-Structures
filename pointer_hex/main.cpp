/*
    1. Generate a decimal: int for decimal in main()
    2. convert it to deciamal to hex: hex in string,
    3. display a decimal to the user
    4. get an answer from the user: string for the user answer
    5. verify the answer: bool by comparing the two strings
    6. Record the user's history: answer/right/ or wrong
       -text file
       -points, how many correct answers
    7. Display the current points
        - 1 point
    8. give an obtion to play again or exit
        - bool: 1 for try, 0 for quit



*/

#include <iostream>
#include <ctime>   //time(0) for random number generation
#include <cstdlib> //srand() for seeding the random number generator
#include <string>
#include <fstream> //file handling
#include <cassert> //assert()

using namespace std;

int genDec();
string decToHex(int);
char getHexDigit(int);
int *getArray(int);
void storeDecimal(int *, int &, const int, int);

// store the generate decimal into the array, decimals for game history
// how to deal with the case when the array is full: flush out
//       so that the dicmals stores the most recent 20 decimals
//   flush method1: the oldest on only --> shifting --> inefficient when the array size is large and the user contuines
//         method2: all elements --> no shifting

bool repeat;
unsigned int points = 0;
const int SIZE = 20;
int *decimals = getArray(SIZE);
int count = 0; // number of problems

int main()
{
    srand(time(0)); // 0:null value
    do
    {
        int decimal = genDec();
        string answer = decToHex(decimal);
        storeDecimal(decimals, count, SIZE, decimal);

        cout << "Convert " << decimal << " to a hex: " << endl;
        string guess;
        cin >> guess;

        if (guess == answer)
        {
            points++;
            cout << "Excellent!" << endl;
        }
        else
        {
            cout << "Practice!" << endl;
        }

        cout << "Want to continue, 1 for yes, 0 for no : ";
        cin >> repeat;

    } while (repeat); // non-zero value : true in C++
}

int genDec()
{
    return rand() % 16;
}

string decToHex(int decimal)
{
    int quotient = decimal;
    string answer;
    while (quotient != 0)
    {
        int remainder = quotient % 16;
        char hexDigit = getHexDigit(remainder);
        answer = hexDigit + answer; // Prepend the hex digit to the answer string
        quotient = quotient / 16;
    }

    return answer; // need to address
}

char getHexDigit(int number)
{
    char hexDigit;
    if (number < 10)
        hexDigit = (char)('0' + number); // Convert to character '0' to '9'
    else

    {
        hexDigit = (char)('a' + (number - 10)); // Convert to character 'A' to 'F'
    }

    return hexDigit;
}

int *getArray(const int size)
{
    return new int[size]; // new returns the address of the allocated memory
}

void storeDecimal(int *decimals, int &count, const int SIZE, int decimal)
{
    if (SIZE > count) // count = 20
    {
        decimals[count] = decimal;
        count++;
    }
    else // flush method2: fluch a decimal to a file
    {
        string outDecimalFile = "decimalHistory.txt";
        ofstream outDecimals(outDecimalFile, ios::app); // append mode
        if (!outDecimals.is_open())
        {
            cout << outDecimalFile << " is not open" << endl;
            cout << "scores not saved" << endl;
        }
        else // flush decimals to the file
        {
            for (int i = 0; i < SIZE; i++)
            {
                outDecimals << decimals[i] << " ";
            }
            outDecimals << endl;
            outDecimals.close();
        }

        // flush decimals from the RAM
        // method1: reset every element to 01, an invalid --> inefficient
        // method2: reset count to 0, the next decimal will overwrite the oldest one
        decimals[0] = decimal; // the first element is the new decimal
        count = 1;
    }
}