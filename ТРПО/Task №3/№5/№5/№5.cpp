#include <iostream>
#include <time.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int a, i, j, q[10] = { 0 };

	for (i = 0; i < 10; i++)
	{
		a = rand() % 10 + 1;
		q[a-1]++;
		cout << a << endl;
	}

	cout << "Вероятности:\n";
	for (i = 1; i <= 10; i++)
		cout << i << "  ";
	cout << endl;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
			if (q[j] >= i+1) cout << "*  ";
				else cout << "   ";
		cout << endl;
	}
	return 0;
}