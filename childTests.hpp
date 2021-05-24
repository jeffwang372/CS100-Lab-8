#ifndef __CHILDTESTS_HPP__
#define __CHILDTESTS_HPP__


#include "gtest/gtest.h"
#include "mult.hpp"
#include "op.hpp"
#include "div.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "rand.hpp"

TEST(AddChildTest, NumChild1) {
 Op* op1 = new Op(-5.0);
 Op* op2 = new Op(7.0);
 Add* add1 = new Add(op1, op2);
 Rand* rand1 = new Rand();
 Add* test = new Add (add1, rand1);
 EXPECT_EQ(test->number_of_children(), 2);
}

TEST(AddChildTest, getChild) {
 Op* op1 = new Op(-5.0);
 Op* op2 = new Op(7.0);
 Add* add1 = new Add(op1, op2);
 Rand* rand1 = new Rand();
 Add* test = new Add (add1, rand1);
 EXPECT_EQ((add1->get_child(0))->evaluate(), -5);
}



TEST(SubChildTest, NumChildSub) {
 Op* op1 = new Op(7.0);
 Op* op2 = new Op(0.0);
 Sub* test = new Sub(op1, op2);

 EXPECT_EQ(test->number_of_children(), 2);
 }

TEST(SubChildTest, getChildSub) {
 Op* op1 = new Op(7.0);
 Op* op2 = new Op(0.0);
 Sub* test = new Sub(op1, op2);

 EXPECT_EQ(test->get_child(1)->evaluate(), 0.0);
 }

TEST(childMultTest, numChildMult) {
 Op* op1 = new Op(5.0);
 Op* op2 = new Op(7.0);
 Mult* test = new Mult(op1, op2);
 
 EXPECT_EQ(test->number_of_children(), 2);
 }

TEST(childMultTest, getchildMult) {
 Op* op1 = new Op(7.0);
 Op* op2 = new Op(0.0);
 Mult* test = new Mult(op1, op2);

 EXPECT_EQ(test->get_child(1)->evaluate(), 0.0);
 }




TEST(childDivTest, numChildDiv) {
 Op* op1 = new Op(16.0);
 Op* op2 = new Op(4.0);
 Div* test = new Div(op1, op2);

 EXPECT_EQ(test->number_of_children(), 2.0);
 }



TEST(childDivTest, getChildDiv) {
 Op* op1 = new Op(16.0);
 Op* op2 = new Op(4.0);
 Div* test = new Div(op1, op2);

 EXPECT_EQ(test->get_child(0)->evaluate(), 16.0);
 }


 TEST(childPowTest, getChildPow) {
 Op* op1 = new Op(7.0);
 Op* op2 = new Op(2.0);
 Pow* test = new Pow(op1, op2);

 EXPECT_EQ(test->get_child(0)->evaluate(), 7.0);
 }



 TEST(childPowTest, numChildPow) {
 Op* op1 = new Op(7.0);
 Op* op2 = new Op(2.0);
 Pow* test = new Pow(op1, op2);

 EXPECT_EQ(test->number_of_children(), 2);
 }



 TEST(childRandTest, getChildRand) {
 Rand* test = new Rand();
 EXPECT_EQ(test->get_child(0), nullptr);
 }


TEST(childRandTest, numChildRand) {
 Rand* test = new Rand();
 EXPECT_EQ(test->number_of_children(), 0);
 }


TEST(childOpTest, OpgetChild) {
    Op* test = new Op(8);
    EXPECT_EQ(test->get_child(0), nullptr);
}


TEST(childOpTest, numChildOp) {
    Op* test = new Op(8);
    EXPECT_EQ(test->number_of_children(), 0);
}





















#endif
