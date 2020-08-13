//
// Created by zh on 2020/6/22.
//
#include <gtest/gtest.h>
#include "sort.h"
#include <iostream>
#include <map>
#include <vector>






static void print(int a[],int length,const char*tip =""){
    for(int i=0 ;i<length;++i){
        std::cout<< a[i]<<" ";
    }
    std::cout <<tip<<"\n";
}

static void print_vector(const std::vector<int>& v,const char*tip =""){
    for(int i=0 ;i<v.size();++i){
        std::cout<< v[i]<<" ";
    }
    std::cout <<tip<<"\n";
}


TEST(testSort,bubble){
    int a[5]={55,44,33,22,11};
    print(a,5);
    sort::bubble(a,5);
    print(a,5,"bubble");

    int b[6]={55,44,33,22,11,11};
    print(b,6);
    sort::bubble(b,6);
    print(b,6,"bubble");
}

TEST(testSort,quick){
    int a[6]={55,44,33,22,11,33};
    print(a,6);
    sort::quick(a,0,5);
    print(a,6,"quick");

    int b[5]={55,44,33,22,11};
    print(b,5);
    sort::quick(b,0,4);
    print(b,5,"quick");
}


TEST(testSort,select){
    int a[6]={55,44,33,22,11,33};
    print(a,6);
    sort::select(a,6);
    print(a,6,"select");

    int b[5]={55,44,33,22,11};
    print(b,5);
    sort::select(b,5);
    print(b,5,"select");
}

TEST(testSort,heap){
    int a[6]={55,44,33,22,11,33};
    print(a,6);
    sort::heap(a,6);
    print(a,6,"heap");

    int b[5]={55,44,33,22,11};
    print(b,5);
    sort::heap(b,5);
    print(b,5,"heap");
}


TEST(testSort,insert){
    int a[6]={55,44,33,22,11,33};
    print(a,6);
    sort::insert(a,6);
    print(a,6,"insert");

    int b[5]={55,44,33,22,11};
    print(b,5);
    sort::insert(b,5);
    print(b,5,"insert");
}


TEST(testSort,shell){
    int a[6]={55,44,33,22,11,33};
    print(a,6);
    sort::shell(a,6);
    print(a,6,"shell");

    int b[5]={55,44,33,22,11};
    print(b,5);
    sort::shell(b,5);
    print(b,5,"shell");
}

TEST(testSort,two_merge){
    std::vector<int> a={55,44,33,22,11,33};
    print_vector(a,"归并排序前");
    auto result = sort::two_merge(a);
    print_vector(result,"归并排序后");

    std::vector<int> a1={55,44,33,22,11};
    print_vector(a1,"归并排序前");
    result = sort::two_merge(a1);
    print_vector(result,"归并排序后");


}


TEST(testSort,bucket){
    std::vector<int> a={55,44,33,22,11,33};
    print_vector(a,"桶排序前");
    sort::bucket(a,2);
    print_vector(a,"桶排序后");

    std::vector<int> a1={55,44,33,22,11};
    print_vector(a1,"桶排序前");
    sort::bucket(a1,3);
    print_vector(a1,"桶排序后");
}


//基数排序不能出现负数
TEST(testSort,count){
    std::vector<int> a={55,44,33,22,11,33};
    print_vector(a,"计数排序前");
    sort::count(a);
    print_vector(a,"计数排序后");

    std::vector<int> a1={55,44,33,22,11};
    print_vector(a1,"计数排序前");
    sort::count(a1);
    print_vector(a1,"计数排序后");
}


TEST(testSort,radix){
    std::vector<int> a={0,55,44,33,22,11,33};
    print_vector(a,"基数排序前");
    sort::radix(a);
    print_vector(a,"基数排序后");

    std::vector<int> a1={55,44,33,22,11};
    print_vector(a1,"基数排序前");
    sort::radix(a1);
    print_vector(a1,"基数排序后");
}

TEST(testSort,radix_v2){
    std::vector<int> a={0,-55,44,33,22,11,33};
    print_vector(a,"基数v2排序前");
    sort::radix_v2(a);
    print_vector(a,"基数v2排序后");

    std::vector<int> a1={0,55,-44,33,22,11};
    print_vector(a1,"基数v2排序前");
    sort::radix_v2(a1);
    print_vector(a1,"基数v2排序后");
}


//当map.erase(it)语句执行之后，it就变成了一个野指针，对野指针++是错误的
TEST(testMap,erase){
    std::map<int,std::string> _map{
            {1,"1"},
            {2,"2"},
            {3,"2"},
            {4,"4"},
            {5,"2"}
    };
    auto it = _map.begin();
    while (it!=_map.end()){
        if(it->second=="2"){
            _map.erase(it++);
        }else{
            ++it;
        }
    }

    for(auto &item: _map){
        std::cout <<item.first<<" "<< item.second<<"\n";
    }
}




TEST(testVector,erase){
    std::vector<int> _map{1,2,2,3,4,5,2};
    auto it = _map.begin();
    /*
     * 这段代码有2个错误，1.无法删除2个连续的2 ，因为it已经是指向下一个2个，然后再++，就会跳过这个2；
     * 2._map_end()++ 发生错误
    for(;it!=_map.end();it++){
        if(*it==2){
            it = _map.erase(it);
        }
    }*/
    while (it!=_map.end()){
        if(*it==2){
            it=_map.erase(it);
        }else{
            ++it;
        }
    }

    for(auto &item: _map){
        std::cout <<item<<" ";
    }
}