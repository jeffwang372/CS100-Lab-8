#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "op.hpp"
#include "add.hpp"


 TEST(AddTest, AddNonZero) {
 Op* op1 = new Op(5.0);
 Op* op2 = new Op(7.0);
 Add* test = new Add(op1, op2);

 EXPECT_EQ(test->evaluate(), 12);
 EXPECT_EQ(test->stringify(), "(5.000000+7.000000)" );
 }

 TEST(AddTest, AddZero) {
 Op* op1 = new Op(0);
 Op* op2 = new Op(7.0);
 Add* test = new Add(op1, op2);

 EXPECT_EQ(test->evaluate(), 7.0);
 EXPECT_EQ(test->stringify(), "(0.000000+7.000000)" );

 }

 TEST(AddTest, AddNegative) {
 Op* op1 = new Op(-5.0);
 Op* op2 = new Op(7.0);
 Add* test = new Add(op1, op2);

 EXPECT_EQ(test->evaluate(), 2);
 EXPECT_EQ(test->stringify(),"(-5.000000+7.000000)" );
}

 TEST(AddTest, AddAdd) {
 Op* op1 = new Op(-5.0);
 Op* op2 = new Op(7.0);
 Op* op3 = new Op(9.0);
 Op* op4 = new Op(10.0);
 Add* add1 = new Add(op1, op2);
 Add* add2 = new Add (op3,op4);
 Add* test = new Add (add1, add2);
 EXPECT_EQ(test->evaluate(), 21);
 EXPECT_EQ(test->stringify(),"((-5.000000+7.000000)+(9.000000+10.000000))" );
}

 TEST(AddTest, AddRand) {
 Op* op1 = new Op(-5.0);
 Op* op2 = new Op(7.0);
 Add* add1 = new Add(op1, op2);
 Rand* rand1 = new Rand();
 Add* test = new Add (add1, rand1);
 EXPECT_LE(test->evaluate(), 101);
}
 TEST(AddTest, AddDiv) {
 Op* op1 = new Op(-5.0);
 Op* op2 = new Op(7.0);
 Op* op3 = new Op(6.0);
 Op* op4 = new Op(3.0);
 Add* add1 = new Add(op1, op2);
 Div* div1 = new Div(op3, op4);
 Add* test = new Add (add1, div1);
 EXPECT_EQ(test->evaluate(), 4);
 EXPECT_EQ(test->stringify(), "((-5.000000+7.000000)+(6.000000/3.000000))");
}
 TEST(AddTest, AddSub) {
 Op* op1 = new Op(-5.0);
 Op* op2 = new Op(7.0);
 Add* add1 = new Add(op1, op2);
 ZeroMock* sub1 = new ZeroMock();
 Add* test = new Add (add1, sub1);
 EXPECT_EQ(test->evaluate(), 2);
 EXPECT_EQ(test->stringify(), "((-5.000000+7.000000)+(8.000000-8.000000))");
}
 TEST(AddTest, AddMult) {
 Op* op1 = new Op(-5.0);
 Op* op2 = new Op(7.0);
 Op* op3 = new Op(6.0);
 Op* op4 = new Op(3.0);
 Add* add1 = new Add(op1, op2);
 Mult* mult1 = new Mult(op3, op4);
 Add* test = new Add (add1, mult1);
 EXPECT_EQ(test->evaluate(), 20);
 EXPECT_EQ(test->stringify(), "((-5.000000+7.000000)+(6.000000*3.000000))");
}


 TEST(AddTest, AddPow) {
 Op* op1 = new Op(-5.0);
 Op* op2 = new Op(7.0);
 Add* add1 = new Add(op1, op2);
 ZeroRaisedMock* pow1 = new ZeroRaisedMock();
 Add* test = new Add (add1, pow1);
 EXPECT_EQ(test->evaluate(), 3);
 EXPECT_EQ(test->stringify(), "((-5.000000+7.000000)+(5.000000**0.000000))");
}


#endif

