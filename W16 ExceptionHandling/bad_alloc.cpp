#include <iostream>
#include <new> // for 'new' operator
using namespace std;

int main() {

  double *p;

  try {

    for (int i = 0; i < 1000000; i++) {
      p = new double [1024*1024]; // 8(double type) * 1M
      cout << "\r" << i*8 << "MB allocated";
    }

  } catch (bad_alloc& e) { // 'bad_alloc' exception in 'new" header

    cout << "\nException: " << e.what() << endl;

  }

  return 0;
}