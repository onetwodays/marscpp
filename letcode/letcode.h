//
// Created by zh on 2020/6/30.
//

#ifndef DATASTRUCTURE_EXE_LETCODE_H
#define DATASTRUCTURE_EXE_LETCODE_H
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


class letcode {
public:
    //求 1+2+3+...+n
    static int sum(int n);
    static int str2Int(const char* str);
    static void factorial(int n);
    static void* mymemmove(void* dst,void* src,std::size_t num);

    static char* myitoa(int num,char* src,int radix);
    static bool myatoi(const char* str,int &num);
    //
    static int mystrlen(const char* str);
    //给定N张扑克牌和一个随机函数，设计一个洗牌算法
    static void shuffle(int cards[],int n);
    //定一个整数数组arr和两个整数k和threshold，请你返回长度为k且平均值大于等于threshold的子数组数目
    static int numsOfsubarray(std::vector<int>& a,int k,int threshold);
    /*
     * 设计一个算法，判断玩家是否赢了井字游戏。输入是一个 N x N 的数组棋盘，
     * 由字符" "，"X"和"O"组成，其中字符" "代表一个空位。

以下是井字游戏的规则：

玩家轮流将字符放入空位（" "）中。
第一个玩家总是放字符"O"，且第二个玩家总是放字符"X"。
"X"和"O"只允许放置在空位中，不允许对已放有字符的位置进行填充。
当有N个相同（且非空）的字符填充任何行、列或对角线时，游戏结束，对应该字符的玩家获胜。
当所有位置非空时，也算为游戏结束。
如果游戏结束，玩家不允许再放置字符。
如果游戏存在获胜者，就返回该游戏的获胜者使用的字符（"X"或"O"）；
如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。
     */
    static  std::string tictactoe(std::vector<std::string>& board);
    /*
     * 给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。

如果符合下列情况之一，则数组 A 就是 锯齿数组：

每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
返回将数组 nums 转换为锯齿数组所需的最小操作次数。
     输入：nums = [1,2,3]
输出：2
解释：我们可以把 2 递减到 0，或把 3 递减到 1。

     */
    static int movesToMakeZigzag(std::vector<int>& nums);
    static char* strStr(const char* str1,const char* str2);
    //最长无重复子串的长度，是子串，不是子排列
    static  int lengthOfLongestSubstring(const std::string&s );


};
class A{
public:
    A(){
        A(0);//这里并不会给成员变量ｉ赋值为０
        //在无参的构造函数调用带参的构造函数属用户行为，
        // 而非编译器行为，它只会执行函数调用，而不会执行其后的初始化表达式
        Print();

    }
    A(int j):i(j){
        std::cout<<"call A(int i)"<<std::endl;
    }
    void Print(){
        std::cout<<"call print()"<<std::endl;
    }

public:
    int i;
};


class Food{
public:
    Food(){
        f();
        std::cout << "food调用默认构造函数"<<std::endl;

    }

    Food(const Food& other){
        std::cout << "food调用拷贝构造函数"<<std::endl;

    }

    Food& operator=(const Food& other){
        if(&other==this){
            return *this;
        }
        std::cout << "food调用赋值运算符"<<std::endl;
    }
    virtual  ~Food(){
        std::cout<<"food 析购函数"<<std::endl;
    }
    virtual void f(){
        std::cout << "虚函数food::f"<< std::endl;
    }

    virtual void g(){
        std::cout << "虚函数food::g"<< std::endl;
    }
    virtual void h(){
        std::cout << "虚函数food::h"<< std::endl;
    }

};

class Dog: public Food{
public:
    /*
    Dog(Food& food):m_food(food){ //调用拷贝构造函数

    }*/

    Dog(int j){
        i=j;
        //m_food = food; //先调用默认构造函数，后调用赋值运算符
        f();
        std::cout<<"Dog 构造函数"<<std::endl;
    }
    ~Dog(){
        std::cout<<"Dog 析购函数"<<std::endl;
    }

    virtual void f(){
        std::cout << "Dog::f"<< std::endl;
    }

    virtual void g(){
        std::cout << "Dog::g"<< std::endl;
    }
    virtual void h(){
        std::cout << "Dog::h"<< std::endl;
    }

private:
    //Food m_food;
    int i;
};


#endif //DATASTRUCTURE_EXE_LETCODE_H
