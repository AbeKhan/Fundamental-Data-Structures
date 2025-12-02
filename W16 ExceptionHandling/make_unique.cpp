#include <iostream>
#include <memory> //for make_unique<T>
#include <vector>

class Student {
public:
    Student(std::string name, int id)
        : name(name), id(id) {}
    
//private:
    std::string name;
    int id;
};

//A smart pointer in C++:an object that behaves like a pointer but automatically manages the lifetime of dynamically allocated memory
//The three main smart pointers: unique_ptr for sole owner, shared_ptr using reference count, weak_port: non-owning behabior
//All reside in the <memory> header and are a core part of modern C++ (C++11 and later)
// std::make_unique: allocates memory on the heap and returns a smart pointer that exclusively own that memory
//  --> exception safe, prevent memory leak


std::unique_ptr<int> create() {
    return std::make_unique<int>(99);
}


int main()
{
    //Create a unique pointer to an int
   
    auto p = std::make_unique<int>(42); 
   
    std::cout << "*p = " << *p << "\n";  // prints 42
    std::cout << "p.get() = " << p.get() << "\n"; //the address stored inside the unique pointer
    
    std::unique_ptr<int> q;
    //unique ptr cannot be copied, but moved
    //q = p;
    q = std::move(p); //p becomes empty
    std::cout << *q << std:: endl;


    auto arr = std::make_unique<int[]>(5);

    for (int i = 0; i < 5; i++)
        arr[i] = i;
    
    std::cout << "arr.get() = " << arr.get() << std::endl;


    //Create an object of a class in the heap
    auto s = std::make_unique<Student>("Alice", 1001);
    std::cout << s->name << std::endl;

    std::vector<std::unique_ptr<int>> vec;

    vec.push_back(std::make_unique<int>(10));
    vec.push_back(std::make_unique<int>(20));
    vec.push_back(std::make_unique<int>(30));
    std::cout << "vec size = " << vec.size() << std::endl;

    auto ptr = create();
    std::cout << "*ptr = " << *ptr << std::endl;

    return 0;
}
