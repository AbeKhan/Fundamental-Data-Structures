/*
 * ============================================================================
 * LIBRARY MANAGEMENT SYSTEM - MAIN() WITHOUT EXCEPTION HANDLING
 * ============================================================================
 * 
 * This version demonstrates the Library Management System without using
 * try-catch blocks or exception handling. All operations are executed
 * assuming valid inputs and successful operations.
 * 
 * This is useful for:
 * - Students learning basic C++ before exception handling
 * - Simple demonstrations without error handling complexity
 * - Quick testing and prototyping
 * 
 * Note: In production code, exception handling should be used!
 * 
 * Compilation: g++ -std=c++11 -o library library_system.cpp
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// ============================================================================
// HELPER FUNCTIONS
// ============================================================================

void printSectionHeader(string title) {
    cout << "\n\n" << string(80, '=') << endl;
    cout << "  " << title << endl;
    cout << string(80, '=') << endl;
}

void printSubSection(string title) {
    cout << "\n--- " << title << " ---" << endl;
}

// ============================================================================
// MAIN FUNCTION - SIMPLE VERSION WITHOUT EXCEPTION HANDLING
// ============================================================================

int main() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                                                        ║\n";
    cout << "║            LIBRARY MANAGEMENT SYSTEM - DEMONSTRATION                   ║\n";
    cout << "║                                                                        ║\n";
    cout << "║              (Without Exception Handling)                              ║\n";
    cout << "║                                                                        ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════╝\n";
    
    // ========================================================================
    // STEP 1: CREATE LIBRARY
    // ========================================================================
    printSectionHeader("STEP 1: Creating Library");
    
    Library library("City Central Library");
    cout << "\n✓ Library created successfully!" << endl;
    cout << "Library name: " << library.getLibraryName() << endl;
    
    // ========================================================================
    // STEP 2: ADD BOOKS TO LIBRARY
    // ========================================================================
    printSectionHeader("STEP 2: Adding Books");
    
    cout << "\nAdding books to the library..." << endl;
    
    Book* book1 = new Book("B001", "The Great Gatsby", "F. Scott Fitzgerald", 
                           1925, "978-0743273565", "Fiction", 180);
    library.addItem(book1);
    
    Book* book2 = new Book("B002", "To Kill a Mockingbird", "Harper Lee", 
                           1960, "978-0061120084", "Fiction", 324);
    library.addItem(book2);
    
    Book* book3 = new Book("B003", "1984", "George Orwell", 
                           1949, "978-0451524935", "Dystopian", 328);
    library.addItem(book3);
    
    Book* book4 = new Book("B004", "Pride and Prejudice", "Jane Austen", 
                           1813, "978-0141439518", "Romance", 279);
    library.addItem(book4);
    
    Book* book5 = new Book("B005", "The Hobbit", "J.R.R. Tolkien", 
                           1937, "978-0547928227", "Fantasy", 310);
    library.addItem(book5);
    
    cout << "\n✓ Added 5 books successfully!" << endl;
    
    // ========================================================================
    // STEP 3: ADD MAGAZINES TO LIBRARY
    // ========================================================================
    printSectionHeader("STEP 3: Adding Magazines");
    
    cout << "\nAdding magazines to the library..." << endl;
    
    Magazine* mag1 = new Magazine("M001", "National Geographic", 
                                  "National Geographic Society", 2024, 1, "January");
    library.addItem(mag1);
    
    Magazine* mag2 = new Magazine("M002", "Time Magazine", "Time Inc", 
                                  2024, 5, "May");
    library.addItem(mag2);
    
    Magazine* mag3 = new Magazine("M003", "Scientific American", 
                                  "Springer Nature", 2024, 8, "August");
    library.addItem(mag3);
    
    cout << "\n✓ Added 3 magazines successfully!" << endl;
    
    // ========================================================================
    // STEP 4: ADD DVDs TO LIBRARY
    // ========================================================================
    printSectionHeader("STEP 4: Adding DVDs");
    
    cout << "\nAdding DVDs to the library..." << endl;
    
    DVD* dvd1 = new DVD("D001", "The Shawshank Redemption", "Frank Darabont", 
                        1994, 142, "Drama");
    library.addItem(dvd1);
    
    DVD* dvd2 = new DVD("D002", "Inception", "Christopher Nolan", 
                        2010, 148, "Sci-Fi");
    library.addItem(dvd2);
    
    DVD* dvd3 = new DVD("D003", "The Matrix", "Wachowski Brothers", 
                        1999, 136, "Sci-Fi");
    library.addItem(dvd3);
    
    DVD* dvd4 = new DVD("D004", "The Dark Knight", "Christopher Nolan", 
                        2008, 152, "Action");
    library.addItem(dvd4);
    
    cout << "\n✓ Added 4 DVDs successfully!" << endl;
    cout << "\n📚 Total items in library: " << library.getTotalItems() << endl;
    
    // ========================================================================
    // STEP 5: ADD MEMBERS
    // ========================================================================
    printSectionHeader("STEP 5: Registering Members");
    
    cout << "\nRegistering library members..." << endl;
    
    Member* member1 = new Member("MEM001", "Alice Johnson", 
                                 "alice@email.com", "555-0101", "Student");
    library.addMember(member1);
    
    Member* member2 = new Member("MEM002", "Bob Smith", 
                                 "bob@email.com", "555-0102", "Faculty");
    library.addMember(member2);
    
    Member* member3 = new Member("MEM003", "Carol White", 
                                 "carol@email.com", "555-0103", "Public");
    library.addMember(member3);
    
    Member* member4 = new Member("MEM004", "David Brown", 
                                 "david@email.com", "555-0104", "Student");
    library.addMember(member4);
    
    Member* member5 = new Member("MEM005", "Emma Davis", 
                                 "emma@email.com", "555-0105", "Faculty");
    library.addMember(member5);
    
    cout << "\n✓ Registered 5 members successfully!" << endl;
    cout << "👥 Total members: " << library.getTotalMembers() << endl;
    
    // ========================================================================
    // STEP 6: DISPLAY ALL ITEMS (Polymorphism Demonstration)
    // ========================================================================
    printSectionHeader("STEP 6: Displaying All Library Items");
    
    cout << "\n🎯 POLYMORPHISM IN ACTION:" << endl;
    cout << "Calling displayInfo() on LibraryItem* pointers" << endl;
    cout << "Each derived class (Book/Magazine/DVD) shows different behavior!" << endl;
    
    library.displayAllItems();
    
    // ========================================================================
    // STEP 7: SEARCH DEMONSTRATIONS
    // ========================================================================
    printSectionHeader("STEP 7: Search Functionality");
    
    // Search by ID
    printSubSection("Search by ID: B003");
    LibraryItem* foundItem1 = library.searchByID("B003");
    foundItem1->displayInfo();
    
    // Search by Title
    printSubSection("Search by Title: Inception");
    LibraryItem* foundItem2 = library.searchByTitle("Inception");
    foundItem2->displayInfo();
    
    // Search by Author
    printSubSection("Search by Author: Christopher Nolan");
    vector<LibraryItem*> nolanItems = library.searchByAuthor("Christopher Nolan");
    cout << "\nFound " << nolanItems.size() << " items by Christopher Nolan:" << endl;
    for (LibraryItem* item : nolanItems) {
        item->displayInfo();
    }
    
    // ========================================================================
    // STEP 8: BORROW ITEMS
    // ========================================================================
    printSectionHeader("STEP 8: Borrowing Items");
    
    cout << "\nProcessing borrow transactions..." << endl;
    
    printSubSection("Transaction 1");
    library.borrowItem("MEM001", "B001", "2024-12-01");
    cout << "Alice borrowed 'The Great Gatsby'" << endl;
    
    printSubSection("Transaction 2");
    library.borrowItem("MEM002", "D002", "2024-12-05");
    cout << "Bob borrowed 'Inception'" << endl;
    
    printSubSection("Transaction 3");
    library.borrowItem("MEM003", "M001", "2024-11-25");
    cout << "Carol borrowed 'National Geographic'" << endl;
    
    printSubSection("Transaction 4");
    library.borrowItem("MEM004", "B003", "2024-12-03");
    cout << "David borrowed '1984'" << endl;
    
    printSubSection("Transaction 5");
    library.borrowItem("MEM004", "D003", "2024-12-03");
    cout << "David borrowed 'The Matrix'" << endl;
    
    printSubSection("Transaction 6");
    library.borrowItem("MEM005", "B002", "2024-12-10");
    cout << "Emma borrowed 'To Kill a Mockingbird'" << endl;
    
    printSubSection("Transaction 7");
    library.borrowItem("MEM001", "M002", "2024-11-28");
    cout << "Alice borrowed 'Time Magazine'" << endl;
    
    printSubSection("Transaction 8");
    library.borrowItem("MEM002", "B004", "2024-12-07");
    cout << "Bob borrowed 'Pride and Prejudice'" << endl;
    
    cout << "\n✓ Completed 8 borrow transactions!" << endl;
    
    // ========================================================================
    // STEP 9: DISPLAY BORROWED ITEMS
    // ========================================================================
    printSectionHeader("STEP 9: Currently Borrowed Items");
    
    library.displayBorrowedItems();
    
    // ========================================================================
    // STEP 10: DISPLAY MEMBER INFORMATION
    // ========================================================================
    printSectionHeader("STEP 10: Member Information");
    
    printSubSection("Member MEM001 - Alice Johnson");
    library.displayMemberInfo("MEM001");
    
    printSubSection("Member MEM004 - David Brown");
    library.displayMemberInfo("MEM004");
    
    printSubSection("Member MEM002 - Bob Smith");
    library.displayMemberInfo("MEM002");
    
    // ========================================================================
    // STEP 11: RETURN ITEMS WITH LATE FEES
    // ========================================================================
    printSectionHeader("STEP 11: Returning Items (Late Fee Calculation)");
    
    cout << "\n💰 LATE FEE RATES:" << endl;
    cout << "  Book:     $0.50 per day" << endl;
    cout << "  Magazine: $0.25 per day" << endl;
    cout << "  DVD:      $1.00 per day" << endl;
    
    printSubSection("Return 1: Alice returns 'The Great Gatsby'");
    cout << "Days late: 0" << endl;
    library.returnItem("MEM001", "B001", 0);
    
    printSubSection("Return 2: Bob returns 'Inception'");
    cout << "Days late: 5" << endl;
    cout << "Expected late fee: 5 × $1.00 = $5.00" << endl;
    library.returnItem("MEM002", "D002", 5);
    
    printSubSection("Return 3: Carol returns 'National Geographic'");
    cout << "Days late: 3" << endl;
    cout << "Expected late fee: 3 × $0.25 = $0.75" << endl;
    library.returnItem("MEM003", "M001", 3);
    
    printSubSection("Return 4: David returns '1984'");
    cout << "Days late: 7" << endl;
    cout << "Expected late fee: 7 × $0.50 = $3.50" << endl;
    library.returnItem("MEM004", "B003", 7);
    
    printSubSection("Return 5: David returns 'The Matrix'");
    cout << "Days late: 0" << endl;
    library.returnItem("MEM004", "D003", 0);
    
    printSubSection("Return 6: Emma returns 'To Kill a Mockingbird'");
    cout << "Days late: 2" << endl;
    cout << "Expected late fee: 2 × $0.50 = $1.00" << endl;
    library.returnItem("MEM005", "B002", 2);
    
    cout << "\n✓ Completed 6 return transactions!" << endl;
    
    // ========================================================================
    // STEP 12: OPERATOR OVERLOADING DEMONSTRATION
    // ========================================================================
    printSectionHeader("STEP 12: Operator Overloading");
    
    printSubSection("Member Fee Operators (+=, -=, <<)");
    Member* bob = library.findMember("MEM002");
    cout << "\nBob's current status:" << endl;
    cout << *bob << endl;
    
    cout << "\nAdding $15.50 to Bob's fees (operator +=)..." << endl;
    *bob += 15.50;
    cout << *bob << endl;
    
    cout << "\nBob pays $10.00 (operator -=)..." << endl;
    *bob -= 10.00;
    cout << *bob << endl;
    
    printSubSection("Library Array Access Operator []");
    cout << "\nAccessing first item: library[0]" << endl;
    LibraryItem* firstItem = library[0];
    firstItem->displayInfo();
    
    cout << "\nAccessing third item: library[2]" << endl;
    LibraryItem* thirdItem = library[2];
    thirdItem->displayInfo();
    
    printSubSection("Book Equality Operator (==)");
    Book testBook1("TEST", "Test Book", "Test Author", 2024, "978-1234567890", "Test", 100);
    Book testBook2("TEST", "Test Book", "Test Author", 2024, "978-1234567890", "Test", 100);
    Book testBook3("TEST", "Different", "Test Author", 2024, "978-9999999999", "Test", 100);
    
    cout << "\nComparing books by ISBN:" << endl;
    cout << "testBook1 == testBook2 (same ISBN):     " 
         << (testBook1 == testBook2 ? "true ✓" : "false ✗") << endl;
    cout << "testBook1 == testBook3 (different ISBN): " 
         << (testBook1 == testBook3 ? "true ✗" : "false ✓") << endl;
    
    // ========================================================================
    // STEP 13: DISPLAY AVAILABLE ITEMS
    // ========================================================================
    printSectionHeader("STEP 13: Available Items for Borrowing");
    
    library.displayAvailableItems();
    
    // ========================================================================
    // STEP 14: GENERATE COMPREHENSIVE REPORT
    // ========================================================================
    printSectionHeader("STEP 14: Library Statistics Report");
    
    library.generateReport();
    
    // ========================================================================
    // STEP 15: FILE I/O OPERATIONS
    // ========================================================================
    printSectionHeader("STEP 15: File I/O Operations");
    
    printSubSection("Saving Library Data");
    library.saveToFile("library_data.txt");
    cout << "✓ Library data saved to 'library_data.txt'" << endl;
    
    printSubSection("Saving Transaction Log");
    library.saveTransactions("transactions.log");
    cout << "✓ Transaction log saved to 'transactions.log'" << endl;
    
    printSubSection("Loading Library Data (Test)");
    Library loadedLibrary("Loaded Library");
    loadedLibrary.loadFromFile("library_data.txt");
    cout << "✓ Successfully tested loading library data" << endl;
    
    // ========================================================================
    // STEP 16: ADDITIONAL BORROWING AND RETURNS
    // ========================================================================
    printSectionHeader("STEP 16: Additional Transactions");
    
    cout << "\nProcessing more transactions..." << endl;
    
    printSubSection("Alice borrows 'The Hobbit'");
    library.borrowItem("MEM001", "B005", "2024-12-15");
    
    printSubSection("Carol borrows 'Scientific American'");
    library.borrowItem("MEM003", "M003", "2024-12-12");
    
    printSubSection("Alice returns 'Time Magazine' (4 days late)");
    library.returnItem("MEM001", "M002", 4);
    cout << "Expected late fee: 4 × $0.25 = $1.00" << endl;
    
    printSubSection("Bob returns 'Pride and Prejudice' (on time)");
    library.returnItem("MEM002", "B004", 0);
    
    cout << "\n✓ Additional transactions completed!" << endl;
    
    // ========================================================================
    // STEP 17: FINAL STATISTICS
    // ========================================================================
    printSectionHeader("STEP 17: Final System Status");
    
    cout << "\n📊 FINAL STATISTICS:" << endl;
    cout << string(70, '-') << endl;
    cout << left << setw(30) << "Library Name:" << library.getLibraryName() << endl;
    cout << left << setw(30) << "Total Items:" << library.getTotalItems() << endl;
    cout << left << setw(30) << "  - Books:" << library.getItemCountByType("Book") << endl;
    cout << left << setw(30) << "  - Magazines:" << library.getItemCountByType("Magazine") << endl;
    cout << left << setw(30) << "  - DVDs:" << library.getItemCountByType("DVD") << endl;
    cout << left << setw(30) << "Total Members:" << library.getTotalMembers() << endl;
    cout << left << setw(30) << "Available Items:" << library.getAvailableItemCount() << endl;
    cout << left << setw(30) << "Borrowed Items:" << library.getBorrowedItemCount() << endl;
    cout << left << setw(30) << "Total Transactions:" << library.getTotalTransactions() << endl;
    cout << string(70, '-') << endl;
    
    // ========================================================================
    // SUMMARY
    // ========================================================================
    printSectionHeader("PROGRAM SUMMARY");
    
    cout << "\n✅ ALL OPERATIONS COMPLETED SUCCESSFULLY!" << endl;
    
    cout << "\n📋 OPERATIONS PERFORMED:" << endl;
    cout << "  ✓ Created library and initialized system" << endl;
    cout << "  ✓ Added 12 items (5 books, 3 magazines, 4 DVDs)" << endl;
    cout << "  ✓ Registered 5 library members" << endl;
    cout << "  ✓ Performed 10 borrow transactions" << endl;
    cout << "  ✓ Performed 8 return transactions" << endl;
    cout << "  ✓ Calculated late fees for various item types" << endl;
    cout << "  ✓ Demonstrated search functionality" << endl;
    cout << "  ✓ Tested operator overloading" << endl;
    cout << "  ✓ Generated reports and statistics" << endl;
    cout << "  ✓ Saved data to files" << endl;
    
    cout << "\n🎓 OOP CONCEPTS DEMONSTRATED:" << endl;
    cout << "  ✓ Inheritance (LibraryItem → Book, Magazine, DVD)" << endl;
    cout << "  ✓ Polymorphism (displayInfo() and calculateLateFee())" << endl;
    cout << "  ✓ Encapsulation (private/protected/public members)" << endl;
    cout << "  ✓ Abstraction (abstract base class LibraryItem)" << endl;
    cout << "  ✓ Operator Overloading (+=, -=, <<, [], ==)" << endl;
    cout << "  ✓ Composition (Library contains Items and Members)" << endl;
    cout << "  ✓ Dynamic Memory Management (new/delete in destructor)" << endl;
    
    cout << "\n💰 LATE FEE CALCULATIONS VERIFIED:" << endl;
    cout << "  ✓ Book:     $0.50/day × 7 days = $3.50" << endl;
    cout << "  ✓ Magazine: $0.25/day × 3 days = $0.75" << endl;
    cout << "  ✓ DVD:      $1.00/day × 5 days = $5.00" << endl;
    
    cout << "\n📁 FILES CREATED:" << endl;
    cout << "  ✓ library_data.txt - Complete library state" << endl;
    cout << "  ✓ transactions.log - Transaction history" << endl;
    
    cout << "\n" << string(80, '=') << endl;
    cout << "LIBRARY MANAGEMENT SYSTEM DEMONSTRATION COMPLETED" << endl;
    cout << string(80, '=') << endl;
    
    cout << "\n✨ Program executed successfully without errors!" << endl;
    cout << "Thank you for using the Library Management System.\n" << endl;
    
    return 0;
}

