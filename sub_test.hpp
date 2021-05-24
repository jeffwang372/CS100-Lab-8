#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "rand.hpp"
#include "mockMult.hpp"
#include "mockDiv.hpp"
#include "mockAdd.hpp"
#include "sub.hpp"
#include "pow.hpp"


 TEST(SubTest, SubNonZero) {
 Op* op1 = new Op(7.0);
 Op* op2 = new Op(5.0);
 Sub* test = new Sub(op1, op2);

 EXPECT_EQ(test->evaluate(), 2.0);
 EXPECT_EQ(test->stringify(), "(7.000000-5.000000)");
 }

TEST(SubTest, SubZero) {
 Op* op1 = new Op(7.0);
 Op* op2 = new Op(0.0);
 Sub* test = new Sub(op1, op2);

 EXPECT_EQ(test->evaluate(), 7.0);
 EXPECT_EQ(test->stringify(), "(7.000000-0.000000)");
 }

TEST(SubTest, SubNegative) {
 Op* op1 = new Op(7.0);
 Op* op2 = new Op(-5.0);
 Sub* test = new Sub(op1, op2);

 EXPECT_EQ(test->evaluate(),12.0);
 EXPECT_EQ(test->stringify(), "(7.000000--5.000000)");
 }

 TEST(SubTest, SubRand) {
 Op* op1 = new Op(100);
 Rand* op2 = new Rand();
 Sub* test = new Sub(op1, op2);

 EXPECT_LE(test->evaluate(), 100.0);
 }

 TEST(SubTest, SubMult) {
 Op* op1 = new Op(30);
 IntMultMock* op2 = new IntMultMock();
 Sub* test = new Sub(op1, op2);

 EXPECT_EQ(test->evaluate(), 15);
 EXPECT_EQ(test->stringify(), "(30.000000-(5.000000*3.000000))");
 }

TEST(SubTest, SubDiv) {
 Op* op1 = new Op(30);
 IntDivMock* op2 = new IntDivMock();
 Sub* test = new Sub(op1, op2);

 EXPECT_EQ(test->evaluate(), 28);
 EXPECT_EQ(test->stringify(), "(30.000000-(6.000000/3.000000))");
 }

 TEST(SubTest, SubAdd) {
 Op* op1 = new Op(30);
 IntAddMock* op2 = new IntAddMock();
 Sub* test = new Sub(op1, op2);

 EXPECT_EQ(test->evaluate(), 22);
 EXPECT_EQ(test->stringify(), "(30.000000-(5.000000+3.000000))");
 }

 TEST(SubTest, SubPow) {
 Op* op1 = new Op(30);
 Op* opPow1 = new Op(2);
 Op* opPow2 = new Op(2);
 Pow* op2 = new Pow(opPow1, opPow2);
 Sub* test = new Sub(op1, op2);

 EXPECT_EQ(test->evaluate(), 26);
 EXPECT_EQ(test->stringify(), "(30.000000-(2.000000**2.000000))");
 }

TEST(SubTest, SubSub) {
 Op* op1 = new Op(30);
 Op* opSub1 = new Op(4);
 Op* opSub2 = new Op(2);
 Sub* op2 = new Sub(opSub1, opSub2);
 Sub* test = new Sub(op1, op2);

 EXPECT_EQ(test->evaluate(), 28);
 EXPECT_EQ(test->stringify(), "(30.000000-(4.000000-2.000000))");
 }

#endif
