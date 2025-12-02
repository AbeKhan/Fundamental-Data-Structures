#include <iostream>
#include <stdexcept>
using namespace std;

int main() {

    try {
        cout << "Inside try block...\n";

        int option;
        cout << "Enter an option (1, 2, 3, or 4): ";
        cin >> option;

        if (option == 1) {
            throw 42;  // throw an int
        }
        else if (option == 2) {
            throw runtime_error("A runtime error occurred!");
        }
        else if (option == 3) {
            throw string("Custom string exception!");
        }
        else {
           // cout << "No exception thrown.\n";
		   throw 3.14;
        }
    }
    // Catch an integer exception
    catch (const int value) {
        cout << "Caught an int exception. Value = " << value << endl;
    }
    // Catch a standard library exception
    catch (const runtime_error& err) {
        cout << "Caught a runtime_error. Message = " << err.what() << endl;
    }
    // Catch a string exception
    catch (const string& message) {
        cout << "Caught a string exception. Message = " << message << endl;
    }
    // Default fallback (catch anything)
    catch (...) {
        cout << "Caught an unknown exception type!" << endl;
    }

    cout << "Program continues after catch blocks.\n";

    return 0;
}
