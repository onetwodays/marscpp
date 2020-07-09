//
// Created by zh on 2020/6/22.
//
#include <gtest/gtest.h>
#include "letcode.h"
TEST(testLeetCode,sum_n){
    std::cout << letcode::sum(1024)<<"\n";
}

TEST(testLeetCode,str2int){
    std::cout << letcode::str2Int("1")<<"\n";
}
TEST(testLeetCode,factorial){
    letcode::factorial(10000);
}
