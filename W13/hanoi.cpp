#include <iostream>

using namespace std;

// T(n) = 2 * T(n-1) + 1; recurrence relation
void hanoi_tower(int n, char s, char a, char d, long int &count) // T(n)
{
	if (n == 1) // base case;
	{
		count++;
		//cout << "Move " << n << " disk from " << s << " to " << d << endl;
	}
	else
	{
		hanoi_tower(n - 1, s, d, a, count);
		count++;														   // T(n-1)
		//cout << "Move " << n << " disk from " << s << " to " << d << endl; // constant time
		hanoi_tower(n - 1, a, s, d, count);								   // T(n-1)
	}
}

int main()
{
	long int count = 0;
	int n = 3;
	char src = 'S';
	char dst = 'D';
	char aux = 'A';
	for (; n < 100; n++)
	{

		hanoi_tower(n, src, aux, dst, count);
		cout << "n = " << n << ", count = " << count << endl;
		count = 0;
	}

	return 0;
}
