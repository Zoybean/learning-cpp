#include <cstddef>
#include <iostream>
template <typename D>
class Unique
{
	protected:
	public:
		D *data;
		Unique(D *data) : data(data)
		{
			std::cout << "generic constructor called" << std::endl;
		}
		bool reset()
		{
			data = NULL;
			return true;
		}
};
template <typename D>
class UniquePtr : public Unique<D>
{
	public:
		UniquePtr(D *data)
		{
			Unique(data);
		}
		UniquePtr move()
		{
			UniquePtr ptr = new UniquePtr(data);
			reset();
			return ptr;
		}
		~UniquePtr()
		{
			std::cout << "destructor called" << std::endl;
			delete data;
		}
};
template <typename D>
class UniqueArray : public Unique<D>
{
	public:
		UniqueArray(D *data)
		{
			Unique(data);
		}
		UniqueArray move()
		{
			UniqueArray ptr = new UniqueArray(data);
			reset();
			return ptr;
		}
		~UniqueArray()
		{
			std::cout << "destructor[] called" << std::endl;
			delete [] data;
		}
};
int main()
{
	UniqueArray<int> *ptr = new UniqueArray<int>(new int[3]);
	UniquePtr<UniqueArray<int> > ptrptr = UniquePtr<UniqueArray<int> >(ptr);
}
