#include <iostream>

using namespace std;

int score = 100;

int win()
{
	cout << "You win" << endl;
	return rand() % 100; // points earned
}

int lose()
{
	cout << "You lose" << endl;
	return rand() % 100; // points lost
}

int eventHandler(int (*fp)()) // callback : passing a function pointer to another function
{
	return fp();
}
int main()
{
	srand(time(0));
	// int* x[2] --> x[0] and x[1] ==> int *
	int (*fp[2])() = {lose, win};
	int idx = rand() % 2;
	cout << "idx = " << idx << endl;
	int points = fp[idx](); //
	score = (idx == 0) ? score - points : score + points;
	cout << "score = " << score << endl;
	

	idx = rand() % 2;
	cout << "idx = " << idx << endl;
	points = eventHandler(fp[idx]);
	score = (idx == 0) ? score - points : score + points;
	cout << "score = " << score << endl;

	cout << "addr of lose() = " << fp[0] << endl;
	cout << "addr of win() = " << fp[1] << endl;
	cout << "addr of lose() = " << &fp[0] << endl;
	cout << "addr of win() = " << &fp[1] << endl;
	cout << "addr of lose() = " << (void*)fp[0] << endl;
	cout << "addr of win() = " << (void*)fp[1] << endl;

	return 0;
}