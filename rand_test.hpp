#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"



 TEST(RandTest, RandGE0) {
 Rand* test = new Rand();
 EXPECT_GE(test->evaluate(), 0);
 }

 TEST(RandTest, RandLE99) {
 Rand* test = new Rand();
 EXPECT_LE(test->evaluate(), 99);
 }

#endif
