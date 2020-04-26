#include <gtest/gtest.h>
#include "../pch.h"
#include "../CustomMath.h"
#include "../CustomMath.cpp"

#define accuracy 1e-9

class MathTests :public::testing::Test {
protected:
	CustomMath unit;
};

TEST_F(MathTests, Add) {
	EXPECT_EQ(0, unit.addition(0, 0));
	EXPECT_EQ(0, unit.addition(7, -7));
	EXPECT_EQ(20, unit.addition(5, 15));
	EXPECT_EQ(-20, unit.addition(5, -25));
	EXPECT_EQ(500000000, unit.addition(1000000000, -500000000));
	EXPECT_DOUBLE_EQ(1.458746958, unit.addition(0.592849506, 0.865897452));
	EXPECT_DOUBLE_EQ(45.254876495, unit.addition(0, 45.254876495));

	EXPECT_NE(1, unit.addition(1, 1));
	EXPECT_NE(-5, unit.addition(5, -5));

}

TEST_F(MathTests, Sub) {
	EXPECT_EQ(0, unit.substraction(1, 1));
	EXPECT_EQ(0, unit.substraction(100000000, 100000000));
	EXPECT_EQ(200, unit.substraction(100, -100));
	EXPECT_EQ(100, unit.substraction(150, 50));
	EXPECT_EQ(-500000000, unit.substraction(500000000, 1000000000));
	EXPECT_DOUBLE_EQ(0.0, unit.substraction(154889764.104253, 154889764.104253));
	EXPECT_NEAR(456987.123654, unit.substraction(10000000.0001, 9543012.876446), accuracy);

	EXPECT_NE(-1, unit.substraction(2, -1));
	EXPECT_NE(5, unit.substraction(6, 2));
}

TEST_F(MathTests, Mult) {
	EXPECT_EQ(0, unit.multiplication(0, 1));
	EXPECT_DOUBLE_EQ(1000000.0000000658, unit.multiplication(500000.0000000329, 2.0));
	EXPECT_DOUBLE_EQ(13.6512, unit.multiplication(1.58, 8.64));
	EXPECT_NEAR(23634720.774152, unit.multiplication(4157.548, 5684.774), accuracy);

}

TEST_F(MathTests, Div) {
	EXPECT_ANY_THROW(unit.division(1, 0));
	EXPECT_ANY_THROW(unit.division(-254875.00124576, 0));
	EXPECT_DOUBLE_EQ(0, unit.division(0, -98));
	EXPECT_DOUBLE_EQ(1, unit.division(-42, -42));
	EXPECT_DOUBLE_EQ(-1, unit.division(128.256, -128.256));

}


TEST_F(MathTests, Fact) {
	EXPECT_EQ(1, unit.factorial(0));
	EXPECT_EQ(1, unit.factorial(1));
	EXPECT_EQ(2, unit.factorial(2));
	EXPECT_EQ(120, unit.factorial(5));
	EXPECT_EQ(362880, unit.factorial(9));
	EXPECT_ANY_THROW(unit.factorial(-1));
	EXPECT_ANY_THROW(unit.factorial(1.114));
	EXPECT_ANY_THROW(unit.factorial(-8.13548));

	EXPECT_NE(0, unit.factorial(1));
}

TEST_F(MathTests, Pow) {
	EXPECT_NEAR(1, unit.power(100, 0), accuracy);
	EXPECT_NEAR(4, unit.power(-2, 2), accuracy);
	EXPECT_NEAR(9, unit.power(3, 2), accuracy);
	EXPECT_NEAR(125, unit.power(5, 3), accuracy);
	EXPECT_NEAR(-537824, unit.power(-14, 5), accuracy);
	EXPECT_NEAR(0.058527663, unit.power(1.5, -7), accuracy);

	EXPECT_ANY_THROW(unit.power(0, -1));
	EXPECT_ANY_THROW(unit.power(1, 0.5));
}

TEST_F(MathTests, Root) {
	EXPECT_NEAR(100000, unit.root(10000000000, 2), accuracy);
	EXPECT_NEAR(-1, unit.root(-1, 3), accuracy);
	EXPECT_NEAR(3, unit.root(9, 2), accuracy);
	EXPECT_NEAR(4.47213595499, unit.root(20, 2), accuracy);
	EXPECT_NEAR(1.58407660928, unit.root(15.8, 6), accuracy);
	EXPECT_NEAR(1.11120086716, unit.root(15467985.234, 157), accuracy);

	EXPECT_ANY_THROW(unit.root(125, 3.45));
	EXPECT_ANY_THROW(unit.root(-1, 2));
	EXPECT_ANY_THROW(unit.root(0, -1));
	EXPECT_ANY_THROW(unit.root(123456789, 0));
}

TEST_F(MathTests, Sin) {
	EXPECT_NEAR(1, (unit.mySin(M_PI / 2)), accuracy); //0.5
	EXPECT_NEAR(-1, (unit.mySin(-M_PI / 2)), accuracy); //-0.5
	EXPECT_NEAR(0, unit.mySin(0), accuracy); //0
	EXPECT_NEAR(0, unit.mySin(M_PI), accuracy); //1
	EXPECT_NEAR(0, unit.mySin(-M_PI), accuracy); //-1

	EXPECT_NEAR(0.70710678118, unit.mySin(M_PI / 4), accuracy); //0.25
	EXPECT_NEAR(0.30901699437, unit.mySin(0.1 * M_PI), accuracy);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
