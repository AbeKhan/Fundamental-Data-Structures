#include <iostream>
#include <string>

using namespace std;

int factorial(int n) // n! = 1 * 2 * ........ * (n-1)*n = (n-1)! * n
					 // factorial(n) n! = factorial(n-1) * n
					 // factorial(n) includes the identical problem but with a smaller n
// when a problem has the same problem inside, but with a smaller input
{

	cout << "factorial (" << n << ")" << endl;
	// base case: no need to call the recursion --> stopping condition
	if (n == 1)
		return 1;

	// recursive case: inductive case: call the function but with a smaller input
	else
		return factorial(n - 1) * n;
}

int main()
{
	for (int i = 1; i < 4; i++)
	{
		cout << factorial(i) << endl;
		cout << string(15, '-') << endl;
	}

	return 0;
}