#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "rand.hpp"
//#include "mockMult.hpp"
//#include "mockDiv.hpp"
//#include "mockAdd.hpp"
#include "sub.hpp"
#include "pow.hpp"


 TEST(PowTest, PowNonZero) {
 Op* op1 = new Op(7.0);
 Op* op2 = new Op(2.0);
 Pow* test = new Pow(op1, op2);

 EXPECT_EQ(test->evaluate(), 49.0);
 EXPECT_EQ(test->stringify(), "(7.000000**2.000000)");
 }

TEST(PowTest, PowZero) {
 Op* op1 = new Op(7.0);
 Op* op2 = new Op(0.0);
 Pow* test = new Pow(op1, op2);

 EXPECT_EQ(test->evaluate(), 1.0);
 EXPECT_EQ(test->stringify(), "(7.000000**0.000000)");
 }

TEST(PowTest, PowNegative) {
 Op* op1 = new Op(4.0);
 Op* op2 = new Op(-1.0);
 Pow* test = new Pow(op1, op2);

 EXPECT_EQ(test->evaluate(), 0.25);
 EXPECT_EQ(test->stringify(), "(4.000000**-1.000000)");
 }

TEST(PowTest, PowNegative2) {
 Op* op1 = new Op(-1.0);
 Op* op2 = new Op(4.0);
 Pow* test = new Pow(op1, op2);

 EXPECT_EQ(test->evaluate(), 1.0);
 EXPECT_EQ(test->stringify(), "(-1.000000**4.000000)");
 }

 TEST(PowTest, PowRand) {
 Op* op1 = new Op(2);
 Rand* op2 = new Rand();
 Pow* test = new Pow(op2, op1);

 EXPECT_LE(test->evaluate(), 9801.0);
 }

 TEST(PowTest, PowMult) {
 Op* op1 = new Op(2);
 IntMultMock* op2 = new IntMultMock();
 Pow* test = new Pow(op2, op1);

 EXPECT_EQ(test->evaluate(), 225);
 EXPECT_EQ(test->stringify(), "((5.000000*3.000000)**2.000000)");
 }

TEST(PowTest, PowDiv) {
 Op* op1 = new Op(2);
 IntDivMock* op2 = new IntDivMock();
 Pow* test = new Pow(op1, op2);

 EXPECT_EQ(test->evaluate(), 4);
 EXPECT_EQ(test->stringify(), "(2.000000**(6.000000/3.000000))");
 }

 TEST(PowTest, PowAdd) {
 Op* op1 = new Op(2);
 IntAddMock* op2 = new IntAddMock();
 Pow* test = new Pow(op2, op1);

 EXPECT_EQ(test->evaluate(), 64);
 EXPECT_EQ(test->stringify(), "((5.000000+3.000000)**2.000000)");
 }

TEST(PowTest, PowSub) {
 Op* op1 = new Op(2);
 Op* opSub1 = new Op(4);
 Op* opSub2 = new Op(2);
 Sub* op2 = new Sub(opSub1, opSub2);
 Pow* test = new Pow(op2, op1);

 EXPECT_EQ(test->evaluate(), 4);
 EXPECT_EQ(test->stringify(), "((4.000000-2.000000)**2.000000)");
 }

TEST(PowTest, PowPow) {
 Op* op1 = new Op(2);
 Op* opPow1 = new Op(2);
 Op* opPow2 = new Op(2);
 Pow* op2 = new Pow(opPow1, opPow2);
 Pow* test = new Pow(op1, op2);

 EXPECT_EQ(test->evaluate(), 16);
 EXPECT_EQ(test->stringify(), "(2.000000**(2.000000**2.000000))");
 }

#endif

