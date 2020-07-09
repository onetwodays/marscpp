//
// Created by zh on 2020/6/22.
//

#ifndef MARSC___SORT_H
#define MARSC___SORT_H
#include <list>
#include <vector>
class sort{
public:
    //交换排序
    static void bubble(int* a,int length);
    static void quick( int* a, int left, int right);

    //选择排序
    static void select(int*a,int length);
    static void heap(int* a,int len);

    //插入排序
    static void insert(int* a,int len);
    static void insert(std::vector<int>& a);
    static void shell(int* a, int len);
    //归并排序
    static std::vector<int> two_merge(const std::vector<int>& a);

    //cout sort
    static void count(std::vector<int>& a);
    static void bucket(std::vector<int>& a,int bucketsize);
    //
    static void radix(std::vector<int>& a);
    static void radix_v2(std::vector<int>& a);

    static void print_vector(const std::vector<int>& v,const char*tip =""){
        for(int i=0 ;i<v.size();++i){
            std::cout<< v[i]<<" ";
        }
        std::cout <<tip<<"\n";
    }


};




#endif //MARSC___SORT_H
