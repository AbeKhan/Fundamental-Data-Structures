/* Game Stat with Linked List for Decimals*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//=============================================================================
// GAME STATE STRUCTURE - PROVIDED
//=============================================================================
struct Node
{
    int decimal;
    Node *next; // address of the next node  next belong to an instance of Nodes
    //function overload(ing)
    // : In a complation unit, define multiple functions with the same name as long as their signatures are different
    // function signature: must be unqiue to each function in a complation unit
    // What determines the signature of a faction?
    // 1. function name
    // 2. the order of the data types (not names) of the parameters
    // 3. const int  is the same as int? -> No, const kkeyword matters
    // 4. reference variable ot non-reference variable --> matter--> &
    // 5. return type: not part of a function signature  in C++ standard
    //    but modern day compilers such as g++ will use return type as part of F.S.

    Node() : decimal(-1), next(nullptr) {}
    Node(int newDecimal, Node *next)
    { // next: variable local to the function
        decimal = newDecimal;
        // next on the left : data memeber of Node's instance
        // next on the right : local variable
        this->next = next; // this->next: next that belongs to the instance of Node
        /*
        ~Node(): no need to define because an instance of Node does not reserve any dynamic memory
             GameState does --> responsible for resource cleanup
        */
    }
};

struct GameState
{
    string username; // string class' construcor initializes username to ""
    unsigned int points;
    int totalQuestions;
    int correctAnswers;
    Node *head; // the head of the linked list composed of nodes in the heap

    // Constructor

    GameState() : points(0), totalQuestions(0), correctAnswers(0), head(nullptr)

    {
        cout << "GameState(): " << this << endl;
    }

    // Destructor
    ~GameState()
    {
        cout << "GameState(): " << this << endl;
        // resource cleanup because GameState is the one who creates nodes in the heap

        while (head != nullptr)
        {
            Node *curNodePtr = head->next;
            delete curNodePtr;
            head = curNodePtr;
        }
    }
    void addDecimal(int newDecimal)
    {
        cout << "addDecimal(" << newDecimal << ") " << this << endl;
        // A node must be created regardless of head being nullptr or not
        Node *newNodePtr = new Node(newDecimal, nullptr);
        // newNodePtr->decimal = newDecimal;
        // newNodePtr->next = nullptr;
        if (head == nullptr)
        {
            head = newNodePtr;
        }
        else
        {
            // traverse the linked list until hitting the nullptr (reaching the end of LL)
            // currentNodePtr: the pointer of a node where you are at
            Node *currentNodePtr = head;
            while (currentNodePtr->next != nullptr)
            {
                // if there is another node, let currentNodePtr point to that node
                currentNodePtr = currentNodePtr->next;
            }
            currentNodePtr->next = newNodePtr;
        }
    }

    void printDecimals()
    {
        cout << "printDecimals() " << this << endl;
    }
};

int main()
{
    GameState gs; // Stack
    srand(time(0));
    for (int i = 0; i < 3; i++)
    {
        gs.addDecimal(rand() % 101);
    }

    // print the decimals
    gs.printDecimals();
    return 0;
}
