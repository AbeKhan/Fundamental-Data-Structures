#include <iostream>
#include <stdexcept>
#include <memory>    // For std::unique_ptr
#include <algorithm> // For std::move

// =================================================================
// 1. Custom Exception Classes
// =================================================================

class QueueOverflowError : public std::length_error {
public:
    QueueOverflowError(const std::string& msg) 
        : std::length_error(msg) {}
};

class QueueUnderflowError : public std::out_of_range {
public:
    QueueUnderflowError(const std::string& msg) 
        : std::out_of_range(msg) {}
};

// =================================================================
// 2. Dynamic Array Queue Class
// =================================================================
class DynamicArrayQueue {
private:
    // Use std::unique_ptr to manage the dynamic array (Exception-Safe RAII)
    std::unique_ptr<int[]> arr;
    int capacity; 
    int front; 
    int rear;  
    int count; 

    // Helper function to resize the array when full
    void resize() {
        int new_capacity = capacity * 2;
        std::cout << "\n[Resizing]: Queue full. Increasing capacity to " << new_capacity << std::endl;

        // 1. Acquire new resource (Dynamically allocate new, larger array)
        // This is safe: if new throws std::bad_alloc, the old array remains untouched.
        std::unique_ptr<int[]> new_arr = std::make_unique<int[]>(new_capacity);

        // 2. Transfer elements from the old array to the new array
        for (int i = 0; i < count; ++i) {
            // Calculate the index in the OLD circular buffer
            int old_index = (front + i) % capacity;
            
            // Elements are placed sequentially in the new array starting from index 0
            new_arr[i] = arr[old_index];
        }

        // 3. Commit (The Exchange Step - Exception-Safe)
        // If the copy loop above finished without exceptions, we swap pointers.
        // The old array (arr) is now holding the new memory (new_arr's resource).
        // The temporary smart pointer (new_arr) is now holding the old memory.
        arr.swap(new_arr); 
        
        // Update metadata
        capacity = new_capacity;
        front = 0; // After resizing, the front element is always at index 0
        rear = count - 1; // Rear is now at the last element's index
        
        // 4. Release old resource (Handled automatically)
        // When new_arr goes out of scope, its destructor is called, releasing the OLD memory.
    }

public:
    // Constructor
    explicit DynamicArrayQueue(int initial_capacity = 2) 
        : capacity(initial_capacity > 0 ? initial_capacity : 1), // Ensure capacity is at least 1
          front(0), rear(-1), count(0) 
    {
        // Initial resource acquisition (using RAII)
        arr = std::make_unique<int[]>(capacity);
        std::cout << "Queue initialized with capacity: " << capacity << std::endl;
    }

    /**
     * @brief Adds an element to the rear of the queue (Enqueue).
     * @param value The element to add.
     */
    void enqueue(int value) {
        if (count == capacity) {
            // Resize if full
            resize(); 
        }

        rear = (rear + 1) % capacity; 
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
        
        front = (front + 1) % capacity; 
        count--;

        std::cout << "Dequeued: " << value << std::endl;
        return value;
    }

    // --- Helper Methods ---
    bool isEmpty() const { return count == 0; }
    int size() const { return count; }
    int max_capacity() const { return capacity; }
};

// =================================================================
// 3. Main Program Demonstration
// =================================================================

int main() {
    // Start with a small capacity to easily trigger resizing
    try {
        DynamicArrayQueue q(3); 
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << "\n[Caught Memory Allocation Error]: " << e.what() << std::endl;
    }

    std::cout << "\n--- Enqueue and Resize Demonstration ---" << std::endl;
    
    try {
        // Fill the queue (size 3)
        q.enqueue(10); 
        q.enqueue(20);
        q.enqueue(30);

        // This next enqueue triggers resize (capacity becomes 6)
        q.enqueue(40); 
        
        // Continue filling the resized queue
        q.enqueue(50);
        q.enqueue(60);
        q.enqueue(70); // This next enqueue triggers resize (capacity becomes 12)
        
        // This resize operation is protected by the RAII swap mechanism.
        // Even if std::make_unique throws, no memory is leaked and the queue is in a valid state.
        q.enqueue(80); 
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "\n[Caught Memory Allocation Error]: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "\n[Caught General Exception]: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Dequeue and Underflow Demonstration ---" << std::endl;
    
    try {
        std::cout << "Queue size: " << q.size() << ", Capacity: " << q.max_capacity() << std::endl;
        
        // Dequeue several elements
        q.dequeue();
        q.dequeue();
        q.dequeue();

        // Continue dequeuing until empty
        while (!q.isEmpty()) {
            q.dequeue();
        }

        // Attempt Underflow (This will throw QueueUnderflowError)
        q.dequeue();
    }
    // Catch the specific custom exception
    catch (const QueueUnderflowError& e) {
        std::cerr << "\n[Caught Underflow Exception]: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "\n[Caught General Exception]: " << e.what() << std::endl;
    }
    
    return 0;
}