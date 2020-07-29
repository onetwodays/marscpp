//
// Created by zh on 2020/7/14.
//
//智能指针是一种资源管理类，通过对原始指针进行封装，在资源管理对象进行析构时对指针指向的内存进行释放；
// 通常使用引用计数方式进行管理，一个基本实现如下：

#ifndef LETCODE_EXE_SMART_POINTER_H
#define LETCODE_EXE_SMART_POINTER_H
class Object;
class SmartPointer;

class Counter
{
    friend class SmartPointer;
public:
    Counter()
    {
        ptr = nullptr;
        cnt = 0;
    }
    Counter(Object* p)
    {
        ptr = p;
        cnt = 1;
    }
    ~Counter()
    {
        delete ptr;
    }
private:
    Object* ptr;
    int cnt;
};

class SmartPointer
{
public:
    SmartPointer(Object* p)
    {
        ptr_counter = new Counter(p);
    }
    SmartPointer(const SmartPointer &sp)
    {
        ptr_counter = sp.ptr_counter;
        ++ptr_counter->cnt;
    }
    SmartPointer& operator=(const SmartPointer &sp) //复制运算符
    {
        ++sp.ptr_counter->cnt;
        --ptr_counter->cnt;
        if (ptr_counter->cnt == 0)
        {
            delete ptr_counter;
        }
        ptr_counter = sp.ptr_counter;
    }
    ~SmartPointer()
    {
        --ptr_counter->cnt;
        if (ptr_counter->cnt == 0)
        {
            delete ptr_counter;
        }
    }
private:
    Counter* ptr_counter;

};


class smart_pointer {

};

/*
 *


     在C++中，类的对象建立分为两种，一种是静态建立，如A a；另一种是动态建立，如A* ptr=new A；这两种方式是有区别的。

        静态建立一个类对象，是由编译器为对象在栈空间中分配内存，是通过直接移动栈顶指针，挪出适当的空间，然后在这片内存空间上调用构造函数形成一个栈对象。使用这种方法，直接调用类的构造函数。

        动态建立类对象，是使用new运算符将对象建立在堆空间中。这个过程分为两步，第一步是执行operator new()函数，在堆空间中搜索合适的内存并进行分配；第二步是调用构造函数构造对象，初始化这片内存空间。这种方法，间接调用类的构造函数。
 */

//只能在堆上创建对象
class  A
{
protected :
    A(){}
    ~A(){}
public :
    static  A* create()
    {
        return   new  A();
    }
    void  destory()
    {
        delete   this ;
    }
};



//只能在栈上创建对象
class  AA
{
private :
    void* operator new (unsigned  long t){}      // 注意函数的第一个参数和返回值都是固定的
    void  operator  delete ( void * ptr){}  // 重载了new就需要重载delete
public :
    AA(){}
    ~AA(){}
};

#endif //LETCODE_EXE_SMART_POINTER_H
