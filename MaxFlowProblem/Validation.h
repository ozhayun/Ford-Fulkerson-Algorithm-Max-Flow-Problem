#ifndef _VALIDATION_H_
#define _VALIDATION_H_
#include <stdlib.h>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Validation {
public:
	bool isStartInputValid(int n, int m, int s, int t);
	bool isNaturalNumber(int n);
	bool isBetweenZeroAndN(int num, int n);
	bool isValidEdge(int i, int j, int c, int n);

};

#endif
