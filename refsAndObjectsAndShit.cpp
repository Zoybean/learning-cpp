#include <iostream>

void values()
{
	int *a = new int;
	delete a;

	int *b = new int[5];
	b[0] = 1;
	std::cout << b[0] << std::endl;
	delete [] b;

	int x;
	int& foo = x;

	foo = 42;
	std::cout << x << std::endl;
}
