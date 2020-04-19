#include "pch.h"
#include "CustomMath.h"
#include <stdlib.h>

/******************************************/

double CustomMath::addition(double a, double b) {
    return a + b;
}

double CustomMath::substraction(double a, double b) {
    return a - b;
}

double CustomMath::multiplication(double a, double b) {
    return a * b;
}

double CustomMath::division(double dividend, double divisor)
{
    if (divisor == 0.0) {
        throw "Math error: division by Zero!\n";
    }
    return (dividend / divisor);
}

double CustomMath::factorial(double n) {
    if (n < 0) {
        throw "Math error: factorial of negative/decimal number!\n";
    }
    if (n == 1 || n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

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