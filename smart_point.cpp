#include <cstddef>
#include <iostream>
template <typename D>
class Unique
{
	protected:
		D *data;
	public:
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
class UniquePtr// : public Unique<D>
{
	protected:
		D *data;
	public: //Should be able to declare in a super class
		UniquePtr(D *data) : data(data)
		{
			std::cout << "generic constructor called" << std::endl;
		}
		bool reset()
		{
			data = NULL;
			return true;
		}
	public:
		/*UniquePtr(D *data)
		{
			Unique<D>(data);
		}*/
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
class UniqueArray// : public Unique<D>
{
	protected:
		D *data;
	public:
		UniqueArray(D *data) : data(data)
		{
			std::cout << "generic constructor called" << std::endl;
		}
		bool reset()
		{
			data = NULL;
			return true;
		}
	public:
		/*UniqueArray(D *data)
		{
			Unique<D>(data);
		}*/
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
