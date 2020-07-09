//
// Created by zh on 2020/6/22.
//
#include <gtest/gtest.h>
#include "find.h"
#include <iostream>
#include <map>
#include <vector>


TEST(testFind,binary_find){
    std::vector<int> a{1,2,3,4,5};
    int index = binary_find::binary_search(a,3);
    if(index!=-1){
        std::cout<<"a[" << index<<"]="<<a[index] <<"\n";
    } else{
        std::cout << index <<"\n";
    }

    index = binary_find::left_search(a,7);
    if(index!=-1){
        std::cout<<"a[" << index<<"]="<<a[index] <<"\n";
    } else{
        std::cout << index <<"\n";
    }
    index = binary_find::right_search(a,6);
    if(index!=-1){
        std::cout<<"a[" << index<<"]="<<a[index] <<"\n";
    } else{
        std::cout << index <<"\n";
    }

}


TEST(testFind,binary_strstr){
    const char* s1 = "helloworld helloworld";
    const char* s2 = "world";
    char* p = binary_find::strstr(s1,s2);
    if (p){
        std::cout << p<<std::endl;
        //p=binary_find::strstr(p,s2);
    }

}