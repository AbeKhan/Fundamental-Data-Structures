#include <string>
#include <iostream>

using namespace std;

class A {
public:
     virtual void print() = 0;
private:
     int x;
};
class B : public A{
public:
      virtual void print();
private:
      int y;
};
class C : public B{
public:
      void print();
private:
      int z;
};
 

void A::print() {
      cout << "x = " << x << endl;
}
void B::print() {
     A::print();
     cout << "y = " << y << endl;
}
void C::print() {
     B::print();
     cout << "z = " << z << endl;
}
 

int main()
{
     B* p1 = new C;
     p1->print();
     A* p2 = new A;
     A* p3 = new C;
           p3->print();
           A* p4 = new B;
     return 0;
  }