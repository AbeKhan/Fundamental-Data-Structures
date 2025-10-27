#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Create a map: string keys -> int values
    map<string, int> studentGrades;
    
    // === ADDING ELEMENTS ===
    cout << "=== Adding Elements ===\n";
    
    // Method 1: Using []
    studentGrades["Alice"] = 95;
    studentGrades["Bob"] = 87;
    studentGrades["Charlie"] = 92;
    
    // Method 2: Using insert
    studentGrades.insert({"David", 88});
    studentGrades.insert({"Eve", 91});
    
    cout << "Added 5 students\n\n";
    
    
    // === ACCESSING ELEMENTS ===
    cout << "=== Accessing Elements ===\n";
    
    cout << "Alice's grade: " << studentGrades["Alice"] << "\n";
    cout << "Bob's grade: " << studentGrades["Bob"] << "\n\n";
    
    
    // === ITERATING THROUGH MAP ===
    cout << "=== All Students (sorted by name) ===\n";
    
    //map class must provide public member functions, begin(), end()
    //auto: compiler gussess the type of it --> iterator of the map class
    //      --> map<string, int>::Iterator Iterator itself is a class, which is contained in map
    //      --> Iterator of map is a nested class
    //++it  ==> result: go to the next element
    //      ==> it: an object of Iterator
    //      ==> ++object --> operator++ defined within the Iterator class
    for (auto it = studentGrades.begin(); it != studentGrades.end(); ++it) {
        cout << it->first << ": " << it->second << "\n";
    }
    cout << "\n";
    
    // Or using range-based for loop (cleaner!)
    cout << "=== Using Range-Based For Loop ===\n";
    for (auto pair : studentGrades) {
        cout << pair.first << ": " << pair.second << "\n";
    }
    cout << "\n";
    
    // Or with structured bindings (C++17)
    cout << "=== Using Structured Bindings (C++17) ===\n";
    for (auto [name, grade] : studentGrades) {
        cout << name << ": " << grade << "\n";
    }
    cout << "\n";
    
    
    // === CHECKING IF KEY EXISTS ===
    cout << "=== Checking if Key Exists ===\n";
    
    string searchName = "Alice";
    if (studentGrades.find(searchName) != studentGrades.end()) {
        cout << searchName << " found! Grade: " << studentGrades[searchName] << "\n";
    } else {
        cout << searchName << " not found\n";
    }
    
    searchName = "Frank";
    if (studentGrades.find(searchName) != studentGrades.end()) {
        cout << searchName << " found! Grade: " << studentGrades[searchName] << "\n";
    } else {
        cout << searchName << " not found\n";
    }
    cout << "\n";
    
    
    // === UPDATING VALUES ===
    cout << "=== Updating Values ===\n";
    
    cout << "Charlie's old grade: " << studentGrades["Charlie"] << "\n";
    studentGrades["Charlie"] = 96;  // Update
    cout << "Charlie's new grade: " << studentGrades["Charlie"] << "\n\n";
    
    
    // === REMOVING ELEMENTS ===
    cout << "=== Removing Elements ===\n";
    
    cout << "Size before: " << studentGrades.size() << "\n";
    studentGrades.erase("Bob");  // Remove Bob
    cout << "Size after removing Bob: " << studentGrades.size() << "\n\n";
    
    
    // === OTHER USEFUL OPERATIONS ===
    cout << "=== Other Operations ===\n";
    
    cout << "Number of students: " << studentGrades.size() << "\n";
    cout << "Is map empty? " << (studentGrades.empty() ? "Yes" : "No") << "\n";
    
    // count() returns 1 if key exists, 0 otherwise
    cout << "Does Alice exist? " << (studentGrades.count("Alice") ? "Yes" : "No") << "\n";
    cout << "Does Bob exist? " << (studentGrades.count("Bob") ? "Yes" : "No") << "\n\n";
    
    
    // === PRACTICAL EXAMPLE: Word Counter ===
    cout << "=== Practical Example: Word Counter ===\n";
    
    string text = "hello world hello C++ world hello";
    map<string, int> wordCount;
    
    // Simple word counting (split by spaces)
    string word = "";
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                wordCount[word]++;  // Increment count
                word = "";
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        wordCount[word]++;  // Don't forget last word
    }
    
    cout << "Word frequencies:\n";
    for (auto [w, count] : wordCount) {
        cout << w << ": " << count << " times\n";
    }
    cout << "\n";
    
    
    // === CLEAR ALL ELEMENTS ===
    cout << "=== Clearing Map ===\n";
    studentGrades.clear();
    cout << "Size after clear: " << studentGrades.size() << "\n";
    cout << "Is map empty? " << (studentGrades.empty() ? "Yes" : "No") << "\n";
    
    return 0;
}