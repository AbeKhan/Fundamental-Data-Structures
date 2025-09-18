#include <iostream>
#include <string>

using namespace std;

class A {
public:
   explicit A(int x) { std::cout << "A(" << x << ")\n"; }
};

void f(A obj) {
    std::cout << "f(A)\n";
    //inside of the function, the parameter implicitly calls the contructor of A because a local object is created due to the pass-by-value
}

int main() {
    f(5);   // OK: 5 is implicitly converted into A(5)

    string s ="abcdef"; //string =  const char*
                        //string(const char*)
}