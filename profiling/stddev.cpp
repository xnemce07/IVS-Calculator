#include <stdlib.h>
#include <iostream>
#include "CustomMath.h"

int main() {
	double tmp = 0;
	double sum = 0;
	double sqrsum = 0;
	int n = 0;

	CustomMath unit;

	while(!feof(stdin)) {
		std::cin >> tmp;
		std::cout << tmp << " ";
		sum += tmp;
		sqrsum += tmp * tmp;
		n++;
	}

	double avg = sum / n;

	double result = (((1 / (n - 1)) * (sqrsum - n * avg * avg)));

	std::cout << result << " " << n << " " << sqrsum << " " << avg << std::endl;

	return 0;
}
