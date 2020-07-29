//
// Created by zh on 2020/6/22.
//
#include <gtest/gtest.h>
#include "letcode.h"
//不使用sizeof，如何求int占用的字节数
#define Mysizeof(Value) ((char*)(&Value+1)-(char*)(&Value))
//如何用宏求结构体的内存偏移地址
//在C，ANSI C 标准允许值为0的常量被强制转换成任何一种类型指针
#define OffSet(type,field) ((std::size_t)&((type*)(0)->field))
TEST(testLeetCode,sum_n){
    std::cout << letcode::sum(1024)<<"\n";
}

TEST(testLeetCode,str2int){
    std::cout << letcode::str2Int("1")<<"\n";
}
TEST(testLeetCode,factorial){
    letcode::factorial(10000);
}
TEST(testLeetCode,Mysizeof){
    int i;
    double a[4];
    double* q;
    std::cout<< "i:"<< Mysizeof(i)<<std::endl;
    std::cout<< "a:"<< Mysizeof(a)<<std::endl;
    std::cout<< "q:"<< Mysizeof(q)<<std::endl;

}
/*
TEST(testLeetCode,OffSet){
    typedef struct MY{
        char a;
        int b;
        float c;
        double d;
        char e;
    } MY;

    std::cout<< "a:"<< OffSet(MY,a)<<std::endl;
    std::cout<< "b:"<< OffSet(MY,b)<<std::endl;
    std::cout<< "c:"<< OffSet(MY,c)<<std::endl;
    std::cout<< "d:"<< OffSet(MY,d)<<std::endl;
    std::cout<< "e:"<< OffSet(MY,e)<<std::endl;


}*/

TEST(testLeetCode,PF){
    int x = 21342;
    int y = 21340;
    std::cout<< (x+y)/2<<std::endl;
    std::cout<<((x&y)+(x^y)>>1)<<std::endl;
}

TEST(testLeetCode,A){
    A a;
    std::cout<< a.i <<std::endl;

}

TEST(testLeetCode,mymemmove){
   char src[]="abc";
   char* dst=src+1;
   dst = (char*)(letcode::mymemmove(dst,src,4));
   std::cout <<dst<<std::endl;


}

TEST(testLeetCode,myitoa){
    char a[7];
    letcode::myitoa(-12345,a,10);
    std::cout<<a <<std::endl;
    int nReslut;
    letcode::myatoi("-12345",nReslut);
    std::cout<<nReslut <<std::endl;
    std::cout<< letcode::mystrlen(a)<<std::endl;

}

typedef void(*Fun)(void) ;

TEST(testLeetCode,Food){
    /*
    {
        Food f; //调用默认构造函数

        std::cout<<"------------"<<std::endl;


        Dog d(1);
        //Dog d1(f,1);
        std::cout<<"------------"<<std::endl;

        Food& f1 = d;
        f1.f();

        std::cout<<"------------"<<std::endl;
    }
     */

    Food* f = new Dog(1);
    delete f;






    //std::cout<< "f的虚函数表地址:"<<(int*)(&f)<<std::endl;
    //std::cout<< "f的虚函数表第一个虚函数地址:"<<(int*)*(int*)(&f)<<std::endl;
    //std::cout<< "f的虚函数表第2个虚函数地址:"<<(int*)*(int*)(&f)<<std::endl;
    //std::cout<< "f的虚函数表第3个虚函数地址:"<<(int*)*(int*)(&f)<<std::endl;
    //Fun pFun=(Fun)*((int*)*(int*)(&f)+0);
    //pFun();





}

TEST(testLeetCode,shu){
    int a[5]={5,3,2,1,4};
    for (auto &i:a){
        std::cout << i<<",";
    }
    std::cout<<std::endl;
    letcode::shuffle(a,5);

    for (auto &i:a){
        std::cout << i<<",";
    }
    std::cout<<std::endl;

}
TEST(testLetCode,numsofsubarray){
    std::vector<int > a{2,2,2,2,5,5,5,8};
    std::cout<<letcode::numsOfsubarray(a,3,4)<<std::endl;
}

TEST(testLetCode,tictactoe){
    std::vector<std::string > a{"O X"," XO","X O"};
    std::cout<<letcode::tictactoe(a)<<std::endl;

    std::vector<std::string > aa{"OOX","XXO","OXO"};
    std::cout<<letcode::tictactoe(aa)<<std::endl;

    std::vector<std::string > aaa{"OOX","XXO","OX "};
    std::cout<<letcode::tictactoe(aaa)<<std::endl;
}

TEST(testLetCode,movesToMakeZigzag){
    std::vector<int > a{9,6,1,6,2};
    std::cout<<letcode::movesToMakeZigzag(a)<<std::endl;
}