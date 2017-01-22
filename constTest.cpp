#include <iostream>

void constTest()
{
	const char *pcc = "hello";
	pcc = "world"; //pointer isn't const
	char *pc, *pb;
	std::cin >> pc;
	std::cin >> pc; //value isn't constsnt
	pc = pb; //pointer isn't constant
	char *const cpc = pc;
	std::cin >> cpc;
	std::cin >> cpc; //value isn't constsnt
	const char *const cpcc = "hello";
}
