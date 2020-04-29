/**************************************************
 * @file CustomMath.cpp
 * @authors Miroslav Ilavsky, <xilavs02@stud.fit.vutbr.cz>
 * @authors Rudolf Hyksa, <xhyksa00@stud.fit.vutbr.cz>
 * @brief lib containing implemented math functions
 * @date 19.4.2020
 **************************************************/

#include "pch.h"
#include "CustomMath.h"
#include <stdlib.h>

/**
 * @brief addition of two doubles
 * @param a addend1
 * @param b addend2
 * @return sum of [a] and [b]
 */
double CustomMath::addition(double a, double b) {
    return a + b;
}
/**
 * @brief subtraction of two doubles
 * @param a minued
 * @param b subtrahend
 * @return difference of [a] and [b]
 */
double CustomMath::substraction(double a, double b) {
    return a - b;
}
/**
 * @brief multiplication of two doubles
 * @param a factor1
 * @param b factor2
 * @return product of [a] and [b]
 */
double CustomMath::multiplication(double a, double b) {
    return a * b;
}
/**
 * @brief division of two doubles
 * @param dividend dividend
 * @param divisor divisor
 * @pre b != 0
 * @return quotient of [a] and [b]
 */
double CustomMath::division(double dividend, double divisor)
{
    if (divisor == 0.0) {
        throw "Math error: division by Zero!\n";
    }
    return (dividend / divisor);
}
/**
 * @brief function used to calculate the factorial of an integer
 * @param n to-be-used-as-input-for-factorial integer
 * @pre n >= 0 && must be an integer
 * @return factorial of [n]
 */
double CustomMath::factorial(double n) {
    double tmp = floor(n);
    if (n != tmp){
	throw "Math error: factorial - expected an integer!\n";
    }
    if (tmp < 0) {
        throw "Math error: factorial of a negative number!\n";
    }
    if (tmp == 1 || tmp == 0)
        return 1;
    else
        return tmp * factorial(tmp - 1);
}
/**
 * @brief custom power function
 * @param a basis
 * @param n exponent
 * @pre n must be an integer
 * @return [a] to the power of [n]
 */
double CustomMath::power(double a, double n) {
    double exp = floor(n);
    if (n != exp) {
        throw "Math error: power - expected integer as exponent!\n";
    }
    if (a == 0 && n < 0) {
        throw "Math error: power - division by zero!\n";
    }
    if (n == 0)
        return 1;
    else
        if (n == 1)
            return a;
        else if (n > 0)
            return a * power(a, n - 1);
        else {
            a = 1 / a;
            n *= -1;
            return power(a, n);
        }
}
/**
 * @brief custom general root function
 * @param a radinacd
 * @param n degree
 * @pre n must be an integer
 * @return [n]th root of [a]
 */
double CustomMath::root(double a, double n) {
    int degree = floor(n);
    if (degree != n) {
        throw "Math error: root - expected integer as degree!\n";
    }
    if ((a < 0) && !(degree % 2)) {
        throw "Math error: even root of a negative number!\n";
    }
    if (degree == 0) {
        throw "Math error: root - division by zero!\n";
    }
    if (a == 0 && degree == -1) {
        throw "Math error: root - division by zero!\n";
    }

    bool neg = 0;
    if (a < 0) {
        a *= -1;
        neg = 1;
    }

    double low = 0;
    double result = a / 2;
    double high = a;
    double prev_result = a;

    while (((prev_result - result) >= eps) || ((result - prev_result) >= eps)) {
        if (power(result, degree) < a)
            low = result;
        else
            high = result;
        prev_result = result;
        result = (low + high) / 2;
    }

    if (neg)
        result *= -1;

    return result;
}
/**
 * @brief custom sin function
 * @param cislo sin input in radians
 * @return sin of [cislo]
 */
double CustomMath::mySin(double cislo)
{
    cislo = toPi(cislo);
    int poradie = 1;
    int klad = 2;
    double hodnota = 0.0;
    double clen = 0;

    do {
        clen = 1;

        for (int i = 1; i <= poradie; i++) {
            clen *= cislo;
            clen /= (double)i;
        }

        if (!(klad % 2))
            hodnota += clen;
        else
            hodnota -= clen;

        klad++;
        poradie += 2;
    } while (clen > eps);

    return hodnota;
}
/**
 * @brief converts [a] to it's corresponding value in the interval <0, 2pi>
 * @param a angle in radians
 * @return converted value of [a]
 */
double CustomMath::toPi(double a) {
    if (a == 0)
        return 0;
    else
        if (a < 0)
            return toPi(a + 2 * M_PI);
        else
            if (a > 2 * M_PI)
                return toPi(a - 2 * M_PI);
    return a;
}
