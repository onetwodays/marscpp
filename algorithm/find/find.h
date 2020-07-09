//
// Created by zh on 2020/6/22.
//

#ifndef MARSC___FIND_H
#define MARSC___FIND_H

#include <vector>
#include "sort.h"
class binary_find{
public:
    static int binary_search(std::vector<int>&a , int target);
    static int left_search(std::vector<int>&a ,   int target);
    static int right_search(std::vector<int>&a ,  int target);
    //查找第一次出现的位置
    static char* strstr(const char* s1,const char* s2);



};




#endif //MARSC___find_H
