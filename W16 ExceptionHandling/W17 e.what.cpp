#include <iostream>
#include <stdexcept>
#include <string>

class DivisionByZero : public std::runtime_error {
public:
    // Constructor passes a custom message to std::runtime_error
    
    /* "Error: Division by zero" is never displayed.
    DivisionByZero() 
        : std::runtime_error("Error: Division by zero") {}
    */
    // To properly initialize the base object, C++ requires passing a null-terminated string to the base class.
    DivisionByZero() : std::runtime_error("") {}

    // Override what()
    //std::exception defines:
    //virtual const char* what() const noexcept;
    //      ==> const char: The caller cannot change the error message; it must be a null-terminated character array
    //      ==> Exception messages should be read-only because of data integrity and thread safety when multiple threads attempt to read or modify the message simultaneously.
    //const noexcept override: const for a const memeber function that does not modify the object
    //noexcept: This function guarantees it will not throw exceptions
    //      ==> Throwing an exception while handling another exception would terminate the program.
    //      ==> The C++ standard requires std::exception::what() to be noexcept.
    //override: This function is intended to override a virtual method from the base class.
    //      ==> to help compiler catches mismatches
    //
    const char* what() const noexcept override {					//noexcpect: this function will not throw an exception
        return "DivisionByZero exception: cannot divide by zero."; 
    }
};

// Example function that throws the exception
double divide(double a, double b) {
    if (b == 0) {
        throw DivisionByZero();
    }
    return a / b;
}

int main() {
    try {
        double result = divide(10, 0);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const DivisionByZero& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
