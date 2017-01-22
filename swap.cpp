#include <iostream>
template <typename T>
void swap (T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
	return;
}
int main()
{
	int zero = 0;
	int one = 1;
	swap(zero,one);
	std::cout << "zero: " << zero << "; one: " << one << std::endl;
	char a = 'a';
	char b = 'b';
	swap(a,b);
	std::cout << "a: " << a << "; b: " << b << std::endl;
	return 0;
}
