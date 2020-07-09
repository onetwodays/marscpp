//
// Created by zh on 2020/6/22.
//
#include <cmath>
#include <iostream>
#include <cstring>


#include "find.h"

int binary_find::binary_search(std::vector<int> &a, int target) {
    int left = 0 ;
    int right = a.size()-1;
    while(left<=right){
        int mid = left+ (right-left)/2;
        if(a[mid]<target){
            left = mid+1;

        } else if(a[mid]>target){
            right = mid -1;
        }else if(a[mid]==target){
            return mid; //直接返回
        }
    }
    return -1;


}

int binary_find::left_search(std::vector<int> &a, int target) {
    int left = 0;
    int right = a.size()-1;
    while (left<=right) {
        int mid = left + (right - left) / 2;
        if (a[mid] < target) {
            left = mid + 1;

        } else if (a[mid] > target) {
            right = mid - 1;
        } else {
            right = mid - 1;//别返回，锁定左侧边界
        }
    }
    if(left>=a.size()|| a[left]!=target){
        return -1 ;
    }
    return left ;

}

int binary_find::right_search(std::vector<int> &a, int target) {
    int left = 0;
    int right = a.size()-1;
    while (left<=right) {
        int mid = left + (right - left) / 2;
        if (a[mid] < target) {
            left = mid + 1;

        } else if (a[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;//别返回，锁定右侧边界
        }
    }
    if(right<0 || a[right]!=target){
        return -1 ;
    }
    return right ;

}


char* binary_find::strstr(const char* str1,const char* str2){
    if(!str1){ return nullptr;}
    if(!str2){return (char*)str1;}
    int str2_length = std::strlen(str2);
    while (str1){
        for(int n = 0;n<str2_length;n++){
            if(*(str1+n)==*(str2+n)){
                if(n==str2_length-1){
                    return (char*)(str1);
                }
            }
        }
        str1++;
    }
    return nullptr;
}