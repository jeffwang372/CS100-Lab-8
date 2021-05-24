#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "op.hpp"


 TEST(MultTest, MultNonZero) {
 Op* op1 = new Op(5.0);
 Op* op2 = new Op(7.0);
 Mult* test = new Mult(op1, op2);
 
 EXPECT_EQ(test->evaluate(), 35);
 EXPECT_EQ(test->stringify(), "(5.000000*7.000000)" );
 }

 TEST(MultTest, MultZero) {
 Op* op1 = new Op(0);
 Op* op2 = new Op(7.0);
 Mult* test = new Mult(op1, op2);

 EXPECT_EQ(test->evaluate(), 0);
 EXPECT_EQ(test->stringify(), "(0.000000*7.000000)" );
 
 }

 TEST(MultTest, MultNegative) {
 Op* op1 = new Op(-5.0);
 Op* op2 = new Op(7.0);
 Mult* test = new Mult(op1, op2);

 EXPECT_EQ(test->evaluate(), -35);
 EXPECT_EQ(test->stringify(),"(-5.000000*7.000000)" ); 
}

#endif
