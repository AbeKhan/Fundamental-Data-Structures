#include <iostream>
#include <stdexcept> // For deriving from standard exceptions
#include <string>

// Define the maximum size of the queue
const int MAX_SIZE = 5;

// =================================================================
// 1. Custom Exception Classes (Derived from Standard Exceptions)
// =================================================================

/**
 * @brief Exception thrown when attempting to enqueue into a full queue.
 * Derived from std::length_error for semantic clarity (length constraint violation).
 */
class QueueOverflowError : public std::length_error {
public:
    QueueOverflowError(const std::string& msg) 
        : std::length_error(msg) {}
};

/**
 * @brief Exception thrown when attempting to dequeue or peek from an empty queue.
 * Derived from std::out_of_range for semantic clarity (accessing non-existent element).
 */
class QueueUnderflowError : public std::out_of_range {
public:
    QueueUnderflowError(const std::string& msg) 
        : std::out_of_range(msg) {}
};

// =================================================================
// 2. ArrayQueue Class
// =================================================================
class ArrayQueue {
private:
    int arr[MAX_SIZE];
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int count; // Current number of elements in the queue

public:
    // Constructor
    ArrayQueue() : front(0), rear(MAX_SIZE), count(0) {}

    /**
     * @brief Adds an element to the rear of the queue (Enqueue).
     * @param value The element to add.
     * @throws QueueOverflowError if the queue is full.
     */
    void enqueue(int value) {
        if (isFull()) {
            throw QueueOverflowError("Queue Overflow: Cannot enqueue, the queue is full.");
        }

        // Circular array logic
        rear = (rear + 1) % MAX_SIZE; 
        arr[rear] = value;
        count++;

        std::cout << "Enqueued: " << value << std::endl;
    }

    /**
     * @brief Removes and returns the element from the front of the queue (Dequeue).
     * @return The element removed from the front.
     * @throws QueueUnderflowError if the queue is empty.
     */
    int dequeue() {
        if (isEmpty()) {
            throw QueueUnderflowError("Queue Underflow: Cannot dequeue, the queue is empty.");
        }

        int value = arr[front];
        
        // Circular array logic
        front = (front + 1) % MAX_SIZE; 
        count--;

        std::cout << "Dequeued: " << value << std::endl;
        return value;
    }

    /**
     * @brief Returns the element at the front without removing it (Peek).
     * @return The element at the front.
     * @throws QueueUnderflowError if the queue is empty.
     */
    int peek() const {
        if (isEmpty()) {
            throw QueueUnderflowError("Queue is Empty: Cannot peek.");
        }
        return arr[front];
    }

    // --- Helper Methods ---
    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == MAX_SIZE;
    }
};

// =================================================================
// 3. Main Program Demonstration
// =================================================================

int main() {
    ArrayQueue q;

    std::cout << "--- Enqueue and Overflow Demonstration ---" << std::endl;
    
    // Localized try block for Enqueue
    try {
        // Fill the queue
        q.enqueue(11);
        q.enqueue(22);
        q.enqueue(33);
        q.enqueue(44);
        q.enqueue(55);
        
        std::cout << "Peek: " << q.peek() << std::endl;

        // Attempt Overflow (This will throw QueueOverflowError)
        q.enqueue(66); 
    }
    // Catch the specific custom exception first
    catch (const QueueOverflowError& e) {
        std::cerr << "\n[Caught Overflow Exception]: " << e.what() << std::endl;
    }
    // General catch block (will not run here, but is good practice)
    catch (const std::exception& e) {
        std::cerr << "\n[Caught General Exception]: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Dequeue and Underflow Demonstration ---" << std::endl;
    
    // Localized try block for Dequeue
    try {
        // Empty the queue
        q.dequeue(); 
        q.dequeue(); 
        q.dequeue(); 
        q.dequeue(); 
        q.dequeue(); 

        // Attempt Underflow (This will throw QueueUnderflowError)
        q.dequeue();
    }
    // Catch the specific custom exception first
    catch (const QueueUnderflowError& e) {
        std::cerr << "\n[Caught Underflow Exception]: " << e.what() << std::endl;
    }
    // Catch the base std::exception (demonstrates hierarchy)
    catch (const std::exception& e) {
        std::cerr << "\n[Caught General Exception]: " << e.what() << std::endl;
    }
    
    return 0;
}