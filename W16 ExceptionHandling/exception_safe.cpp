#include <iostream>
#include <memory>
#include <stdexcept>

void process() {
    auto p = std::make_unique<int>(10);  // RAII, make_quiqur<T>: utility function

    std::cout << "Allocated p safely\n";

    throw std::runtime_error("Something went wrong!");

}   // p goes out of scope here → destructor calls delete automatically

int main() {
    try {
        process();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }
}
