#include <iostream>
#include <stdexcept>

void process() {
    int* p = new int(10);  // (1) memory allocated

    std::cout << "Allocated p\n";

    // (2) Something throws an exception before we can delete p
    throw std::runtime_error("Something went wrong!");

    delete p;              // (3) This is never reached -> memory leak!
}

int main() {
    try {
        process();
    } catch (const std::runtime_error& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
		//delete e;
    }
}
