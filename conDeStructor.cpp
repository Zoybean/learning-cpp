#include <iostream>

class Foo
{
private:
	int n;
	char* name;
public:
	Foo(int n = 0, char* name = "nup"): n(n), name(name)
	{
		std::cout
			<< "n: " << n << std::endl
			<< "name: " << name << std::endl;
	}
	~Foo()
	{
		std::cout << "Foo destructor called" << std::endl;
	}
};
