#include <sstream>
#include <iostream>

int main( int argc, char **argv )
{
	const char *svalue = "42.0";
	int ivalue;
	std::istringstream istream;
	std::ostringstream ostream;

	istream.str(svalue); //push to stream?
	istream >> ivalue; //pop from stream?
	std::cout << svalue << " = " << ivalue << std::endl;

	ostream.clear();
	ostream << ivalue;
	std::cout << ivalue << " = " << ostream.str() << std::endl;

	return 0;
}
