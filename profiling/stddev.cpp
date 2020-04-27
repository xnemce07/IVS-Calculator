/**********************************************************
 * @file stddev.cpp
 * @author Miroslav Ilavsky, <xilavs02@stud.fit.vutbr.cz>
 * @brief standard deviation
 * @date 25.4.2020
 **********************************************************/

#include <stdlib.h>
#include <iostream>
#include "../src/CustomMath.h"

int main() {
	double tmp = 0;
	double sum = 0;
	double sqrsum = 0;
	int n = 0;

	CustomMath u;

	while(!feof(stdin)) {
		std::cin >> tmp;
		sum = u.addition(sum, tmp);
		sqrsum = u.addition(sqrsum, u.power(tmp, 2));
		n = u.addition(n, 1);
	}

	double avg = u.division(sum, n);

	double result = u.substraction(n, 1);
	result = u.division(1, result);
	double result2 = u.power(avg, 2);
	result2 = u.multiplication(n, result2);
	result2 = u.substraction(sqrsum, result2);
	result = u.multiplication(result, result2);
	result = u.root(result, 2);

	std::cout << result << std::endl;

	return 0;
}
