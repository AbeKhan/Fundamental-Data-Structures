#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Custom exception class
class DivisionByZeroError : public runtime_error {
public:
    DivisionByZeroError() : runtime_error("Division by zero is not allowed!") {}
};

// Function that throws different types of exceptions
double divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw DivisionByZeroError();
    }
    return static_cast<double>(numerator) / denominator;
}

int accessArray(int index) {
    int arr[5] = {10, 20, 30, 40, 50};
    
    if (index < 0 || index >= 5) {
        throw out_of_range("Array index out of bounds!");
    }
    
    return arr[index];
}

void validateAge(int age) {
    if (age < 0 || age > 150) {
        throw invalid_argument("Age must be between 0 and 150");
    }
    cout << "Valid age: " << age << endl;
}

int main() {
    cout << "=== Multiple Catch Blocks Demo ===" << endl;
    
    // Example 1: Catching DivisionByZeroError
    cout << "\n--- Test 1: Division by Zero ---" << endl;
    try {
        double result = divide(10, 2);
        cout << "Result: " << result << endl;
        
        result = divide(10, 0);  // This will throw DivisionByZeroError
        cout << "This line won't execute" << endl;
    }
    catch (const DivisionByZeroError& e) {
        cout << "Caught DivisionByZeroError: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Caught general exception: " << e.what() << endl;
    }
    
    // Example 2: Catching out_of_range
    cout << "\n--- Test 2: Array Index Out of Range ---" << endl;
    try {
        cout << "Accessing index 2: " << accessArray(2) << endl;
        cout << "Accessing index 10: " << accessArray(10) << endl;  // Throws out_of_range
        cout << "This line won't execute" << endl;
    }
    catch (const out_of_range& e) {
        cout << "Caught out_of_range: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Caught general exception: " << e.what() << endl;
    }
    
    // Example 3: Catching invalid_argument
    cout << "\n--- Test 3: Invalid Argument ---" << endl;
    try {
        validateAge(25);
        validateAge(200);  // This will throw invalid_argument
        cout << "This line won't execute" << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Caught invalid_argument: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Caught general exception: " << e.what() << endl;
    }
    
    // Example 4: Multiple different exceptions in one try block
    cout << "\n--- Test 4: Multiple Possible Exceptions ---" << endl;
    
    int testCase = 2;  // Change this to test different cases (0, 1, 2, 3)
    
    try {
        switch (testCase) {
            case 0:
                cout << "Normal execution" << endl;
                break;
            case 1:
                divide(5, 0);  // Throws DivisionByZeroError
                break;
            case 2:
                accessArray(100);  // Throws out_of_range
                break;
            case 3:
                validateAge(-5);  // Throws invalid_argument
                break;
        }
        cout << "Operation completed successfully" << endl;
    }
    catch (const DivisionByZeroError& e) {
        cout << "Caught DivisionByZeroError: " << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cout << "Caught out_of_range: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Caught invalid_argument: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Caught general exception: " << e.what() << endl;
    }
    catch (...) {
        cout << "Caught unknown exception (catch-all)" << endl;
    }
    
    // Example 5: Order matters! Specific before general
    cout << "\n--- Test 5: Catch Order Matters ---" << endl;
    try {
        throw out_of_range("Index error");
    }
    // Specific exceptions MUST come before general ones
    catch (const out_of_range& e) {
        cout << "Caught specific out_of_range: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "This won't execute (more specific catch above)" << endl;
    }
    
    cout << "\n=== Program continues after exceptions ===" << endl;
    
    return 0;
}