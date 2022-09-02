#include "Validation.h"


bool Validation::isStartInputValid(int n, int m, int s, int t) {
	return isNaturalNumber(n) && isNaturalNumber(m) && isBetweenZeroAndN(s, n) && isBetweenZeroAndN(t, n);
}


bool Validation::isNaturalNumber(int n) {
	return n > 0;
}


bool Validation::isBetweenZeroAndN(int num, int n) {
	return num > 0 && n >= num;
}

bool Validation::isValidEdge(int i, int j, int c, int n) {
	return c >= 0 && isBetweenZeroAndN(i, n) && isBetweenZeroAndN(j, n);
}

