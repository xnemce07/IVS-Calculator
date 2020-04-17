#include "CustomMath.h"
#include <stdlib.h>

#define eps 0.0000000001

/******************************************/

double Add(double a, double b) {
        return a + b;
}

double Sub(double a, double b) {
        return a - b;
}

double Mult(double a, double b) {
        return a * b;
}

double Div(double a, double b) {
        return a / b;
}

int Fact(int n) {
        if((n == 1) || (n == 0))
                return n;
        else
                return n * factorial(n - 1);
}

double Pow(double a, int n) {
        if(n == 0)
                return 1;
        else
                if(n == 1)
                        return a;
                else
                        return a * power(a, n - 1);
}

double Root(double a, int n) {
        if((a < 0) && !(n % 2))
                return NULL;
        bool neg = 0;
        if(a < 0) {
                a *= -1;
                neg = 1;
        }

        double low = 0;
        double result = a / 2;
        double high = a;

        while(((power(result, n) - a) !< eps) || ((a - power(result, n)) !< eps)) {
                if(power(result, n) < a) 
                        low = result;
                else
                        high = result;
                result = (low + high) / 2;
        }

	if(neg)
		result *= -1;

        return result;
}

double Sin(double cislo)
{
	cislo = toPi(cislo);
	int poradie = 1;
	int klad = 2;
	double hodnota = 0.0;
	double clen = 0;

	do {
		clen = 1;

		for(int i = 1; i <= poradie; i++) {
			clen *= cislo;
			clen /= (double)i;
        	}

		if (!(klad % 2))
			hodnota += clen;
		else
			hodnota -= clen;

		klad++;
		poradie += 2;
	} while(clen > eps);

	return hodnota;
}

double toPi(double a) {
	if(a == 0)
		return 0;
	else
		if(a < 0)
			return toPi(a + 2 * M_PI);
		else
			if(a > 2 * M_PI)
				return toPi(a - 2 * M_PI);
	return a;
}


