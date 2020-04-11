#pragma once

#define _USE_MATH_DEFINES

#include "pch.h"
#include "CustomMath.h" //change accordingly ^^
#include <math.h>
#include "gtest/gtest.h"

class MathTests :public::testing::Test {
protected:
	double eps = 1e-6;
	CustomMath unit;
};

TEST_F(MathTests, Add) {
	EXPECT_EQ(0, unit.Add(0, 0));
	EXPECT_EQ(0, unit.Add(7, -7));
	EXPECT_EQ(20, unit.Add(5, 15));
	EXPECT_EQ(-20, unit.Add(5, -25));
	EXPECT_EQ(500000000, unit.Add(1000000000, -500000000));
	EXPECT_DOUBLE_EQ(1.458746958, unit.Add(0.592849506, 0.865897452));
	EXPECT_DOUBLE_EQ(45.254876495, unit.Add(0, 45.254876495));

	EXPECT_NE(1, unit.Add(1, 1));
	EXPECT_NE(-5, unit.Add(5, -5));
	
}

TEST_F(MathTests, Sub) {
	EXPECT_EQ(0, unit.Sub(1, 1));
	EXPECT_EQ(0, unit.Sub(100000000, 100000000));
	EXPECT_EQ(200, unit.Sub(100, -100));
	EXPECT_EQ(100, unit.Sub(150, 50));
	EXPECT_EQ(-500000000, unit.Sub(500000000, 1000000000));
	EXPECT_DOUBLE_EQ(0.0, unit.Sub(154889764.104253, 154889764.104253));
	EXPECT_NEAR(456987.123654, unit.Sub(10000000.0001, 9543012.876446), eps);

	EXPECT_NE(-1, unit.Sub(2, -1));
	EXPECT_NE(5, unit.Sub(6, 2));
}

TEST_F(MathTests, Mult) {
	EXPECT_EQ(0, unit.Mult(0, 1));
	EXPECT_DOUBLE_EQ(1000000.0000000658, unit.Mult(500000.0000000329, 2.0));
	EXPECT_DOUBLE_EQ(13.6512, unit.Mult(1.58, 8.64));
	EXPECT_NEAR(23634720.774152, unit.Mult(4157.548, 5684.774), eps);
	//EXPECT_DOUBLE_EQ(30.0, unit.Mult());

}

TEST_F(MathTests, Div) {
	EXPECT_ANY_THROW(unit.Div(1, 0));
	EXPECT_ANY_THROW(unit.Div(-254875.00124576, 0));
	EXPECT_DOUBLE_EQ(0, unit.Div(0, -98));
	EXPECT_DOUBLE_EQ(1, unit.Div(-42, -42));
	EXPECT_DOUBLE_EQ(-1, unit.Div(128.256, -128.256));

}

TEST_F(MathTests, Pow) {
	EXPECT_EQ(1, unit.Pow(100, 0));
	EXPECT_EQ(9, unit.Pow(3, 2));
	EXPECT_EQ(125, unit.Pow(5, 3));
	EXPECT_EQ(-5370824, unit.Pow(-14, 5));
	EXPECT_NEAR(0.058527663, unit.Pow(1.5, -7), eps);

	EXPECT_ANY_THROW(unit.Pow(0, -1));
}

TEST_F(MathTests, Root) {
	EXPECT_EQ(100000, unit.Root(10000000000, 2));
	EXPECT_EQ(-1, unit.Root(-1, 3));
	EXPECT_EQ(3, unit.Root(9, 2));
	EXPECT_NEAR(4.47213595499, unit.Root(20, 2), eps);
	EXPECT_NEAR(1.52113139711, unit.Root(15.8, 6.58), eps);
	EXPECT_NEAR(1.11074452806, unit.Root(15467985.234, 157.614), eps);
	EXPECT_DOUBLE_EQ(5.0, unit.Root(125.0, 3.0));

	EXPECT_ANY_THROW(unit.Root(-1, 2));
	EXPECT_ANY_THROW(unit.Root(0, -1));
	EXPECT_ANY_THROW(unit.Root(123456789, 0));
}

TEST_F(MathTests, Fact) {
	EXPECT_EQ(1, unit.Fact(0));
	EXPECT_EQ(1, unit.Fact(1));
	EXPECT_EQ(2, unit.Fact(2));
	EXPECT_EQ(120, unit.Fact(5));
	EXPECT_EQ(362880, unit.Fact(9));
	EXPECT_EQ(8,71782912e10, unit.Fact(14));
	EXPECT_ANY_THROW(unit.Fact(-1));
	EXPECT_ANY_THROW(unit.Fact(1.114));
	EXPECT_ANY_THROW(unit.Fact(-8.13548));
	
	EXPECT_NE(0, unit.Fact(1));
}

TEST_F(MathTests, Sin) {
	EXPECT_EQ(1, unit.Sin(M_PI/2)); //0.5
	EXPECT_EQ(-1, unit.Sin((-M_PI/2))); //-0.5
	EXPECT_EQ(0, unit.Sin(0)); //0
	EXPECT_EQ(0, unit.Sin(M_PI)); //1
	EXPECT_EQ(0, unit.Sin(-M_PI)); //-1

	EXPECT_NEAR(0.70730678, unit.Sin(M_PI/4), eps); //0.25
	EXPECT_NEAR(0.09983341, unit.Sin(0.1*M_PI), eps);
}
