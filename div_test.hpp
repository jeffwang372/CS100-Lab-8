#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "op.hpp"
#include "div.hpp"
#include "add.hpp"
#include "mockPow.hpp"
#include "mockSub.hpp"
#include "rand.hpp"

 TEST(DivTest, DivNonZero) {
 Op* op1 = new Op(16.0);
 Op* op2 = new Op(4.0);
 Div* test = new Div(op1, op2);

 EXPECT_EQ(test->evaluate(), 4.0);
 EXPECT_EQ(test->stringify(), "(16.000000/4.000000)" );
 }

 TEST(DivTest, DivZero) {
 Op* op1 = new Op(0);
 Op* op2 = new Op(7.0);
 Div* test = new Div(op1, op2);

 EXPECT_EQ(test->evaluate(), 0);
 EXPECT_EQ(test->stringify(), "(0.000000/7.000000)" );

 }

 TEST(DivTest, DivNegative) {
 Op* op1 = new Op(-10.0);
 Op* op2 = new Op(5.0);
 Div* test = new Div(op1, op2);

 EXPECT_EQ(test->evaluate(), -2);
 EXPECT_EQ(test->stringify(),"(-10.000000/5.000000)" );
}

 TEST(DivTest, DivZeroDenominator) {
 Op* op1 = new Op(17.0);
 Op* op2 = new Op(0.0);
 Div* test = new Div(op1, op2);

 EXPECT_THROW(Div(test,op2), runtime_error); 

}


 TEST(DivTest,DivMult ) {
 Op* op1 = new Op(10.0);
 Op* op2 = new Op(5.0);
 Op* op3 = new Op(2.0);
 Mult* mult1 = new Mult(op2,op3);
 Div* test = new Div(op1, mult1);

 EXPECT_EQ(test->evaluate(), 1);
 EXPECT_EQ(test->stringify(),"(10.000000/(5.000000*2.000000))" );
}

#
 TEST(DivTest,DivAdd ) {
 Op* op1 = new Op(10.0);
 Op* op2 = new Op(5.0);
 Op* op3 = new Op(5.0);
 Add* add1 = new Add(op2,op3);
 Div* test = new Div(op1, add1);

 EXPECT_EQ(test->evaluate(), 1);
 EXPECT_EQ(test->stringify(),"(10.000000/(5.000000+5.000000))" );
}

 TEST(DivTest,DivDiv ) {
 Op* op1 = new Op(10.0);
 Op* op2 = new Op(15.0);
 Op* op3 = new Op(3.0);
 Div* div1 = new Div(op2,op3);
 Div* test = new Div(op1, div1);

 EXPECT_EQ(test->evaluate(), 2.0);
 EXPECT_EQ(test->stringify(),"(10.000000/(15.000000/3.000000))" );
}

TEST(DivTest,DivSub ) {
 Op* op1 = new Op(25.0);
 PositiveMock* sub1 = new PositiveMock;//returns 5.0 from test sub
 Div* test = new Div(op1, sub1);

 EXPECT_EQ(test->evaluate(), 5.0);
 EXPECT_EQ(test->stringify(),"(25.000000/(10.000000-5.000000))" );
}

TEST(DivTest,DivPow ) {
 Op* op1 = new Op(24.0);
// Op* op2 = new Op(30.0);
 //Op* op3 = new Op(29.0);
 TwoSquaredMock* pow1 = new TwoSquaredMock;//returns 4.0 from test pow
 Div* test = new Div(op1, pow1);

 EXPECT_EQ(test->evaluate(), 6.0);
 EXPECT_EQ(test->stringify(),"(24.000000/(2.000000**2.000000))" );
}


TEST(DivTest,DivRand ) {
 Op* op1 = new Op(99.0);
 Rand* rand1 = new Rand();
 Div* test = new Div(rand1, op1);

 EXPECT_LE(test->evaluate(), 1.0);
}



#endif

