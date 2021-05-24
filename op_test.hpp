#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
//#include "mockOp.hpp"


TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}



TEST(OpTest, OpEvaluateSeven) {
    Op* test = new Op(7.5);
    EXPECT_EQ(test->evaluate(), 7.5);
}

TEST(OpTest, OpEvaluateFive) {
    Op* test = new Op(5.0);
    EXPECT_EQ(test->evaluate(), 5.0);
}


TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0.0);
    EXPECT_EQ(test->evaluate(), 0.0);
}


TEST(OpTest, OpEvaluateNegative) {
    Op* test = new Op(-3.0);
    EXPECT_EQ(test->evaluate(), -3.0);
}
/*
TEST(OpTest, OpEvaluateNonZero) {
    SevenOpMock* test = new SevenOpMock();
    EXPECT_EQ(test->evaluate(), 7.5);
}

TEST(OpTest, OpEvaluateFive) {
    FiveOpMock* test = new FiveOpMock();
    EXPECT_EQ(test->evaluate(), 5.0);
}


TEST(OpTest, OpEvaluateZero) {
    ZeroOpMock* test = new ZeroOpMock();
    EXPECT_EQ(test->evaluate(), 0.0);
}


TEST(OpTest, OpEvaluateNegative) {
    NegativeOpMock* test = new NegativeOpMock();
    EXPECT_EQ(test->evaluate(), -3.0);
}

*/






#endif //__OP_TEST_HPP__
