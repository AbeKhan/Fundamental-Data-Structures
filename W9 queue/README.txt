Queue: FIFO, FCFS (First in First out) --> main()'s point of view --> the behavior of Queue
                                                                  --> service of Queue to the user of that class
                                    
Essentail operations: 
    1. push(), or enqueue() : add a new element ro the back(rear)
    2. pop(), or dequeue(): remove the first element(front) in the Queue

Implementation: (underlying data structure)
    1. A singly linked list
    2. A double linked list: deque is a Standard Template Library (STL)
    3. An array

Pros and Cons among the difference implementation
    1. SLL/DLL: 
    Pro :dynamic allocation for each element
                dynamically grows with push()
    Con: but calls the new operator whenever a new element is pushed. --> performace degrdation compared with an array
        Q: need to tranverse for push() or pop()?
        A: push() --> no need, because only rear pointer will be updated
           pop() --> no need, because only front pointer will be updated

           ==> must have front and rear pointerss
    2. array: 
         Pro: not madatory to use the heap to store data
           ==> create an array in the stack or heap
           ==> using the heap, only one call of the new operator in the contructor
        Con: limited by the capacity of the array
        Q: need to tranverse for push() or pop()?
        A: push() --> no need because only the rear index will be incremented
                  --> What id the rear passes the capacity?
           pop() --> no need because only the front index will be incremented
                 --> If a circular queue is not usedm the front index is always 0.
                     ==> implementation: shift elements at each pop()
                     ==> no traverse, but copies as many as the number of existing elements

    ==> Implicitly, we assume the underlying data structure is a circular queue
    Q: How is a circle queue implemented?
       ==> describe what member variables are needed and their roles
       ==> describe how push() is implemented
       ==> describe how pop() is implemented
       ==> discuss wht these implementation of push() and pop()

    
    
    
    
    
    
    
    
    
    
    
    
    With a circular queure, there are three varaibles, we have a front, rear, and a size varaibles. 
    The size variable is needed to be able to record however many elements are currently inside the array. Without this, 
