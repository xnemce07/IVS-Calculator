/**************************************************
 * @file CustomMath.h
 * @authors Miroslav Ilavsky <xilavs02@stud.fit.vutbr.cz>
 * @authors Rudolf Hyksa <xhyksa00@stud.fit.vutbr.cz>
 * @brief lib containing implemented math functions
 * @date 19.4.2020
 **************************************************/

#define _USE_MATH_DEFINES
#include <math.h>

#ifndef CUSTOMMATH_H_
#define CUSTOMMATH_H_

#define eps 0.0000000001

/**
 * @brief class used for mathematical operations
 */
class CustomMath
{
public:
    double addition(double a, double b);

    double substraction(double a, double b);

    double multiplication(double a, double b);

    double division(double a, double b);

    double factorial(double n);

    double power(double a, double n);

    double root(double a, double n);

    double mySin(double cislo);

    double toPi(double a);
};

#endif//!CUSTOMMATH_H_
/******************************************/
