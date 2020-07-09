//
// Created by zh on 2020/7/9.
//
/*
 * 空队时指针（下标）front和rear在一起都指向队前方，当有元素进队，则rear后移；
 * 有元素出队，则front后移，
 * 最后，开始时分配给队的前端不再被利用
 * 为了充分利用队列，顺序队列总是做成一个逻辑上的循环队列。
 * 注意：空队时rear等于front，满队时必须空一个位置。
 * 1.判断满：循环队列的满不再是rear=front 而是改成(rear-front+maxn)%maxn。
 * 2.入队操作: data[rear] = x; rear = (rear+1)%maxn;
 * 总体思想就是不让rear和front的值超过maxn的大小。于是就在rear和front自增时候模maxn。
 */




#ifndef DATASTRUCTURE_EXE_CYCLEQUEUE_H
#define DATASTRUCTURE_EXE_CYCLEQUEUE_H
#include <utility>
template <typename T>
class cyclequeue {
private:
    unsigned int _cap;
    T* _data;
    unsigned int _front;
    unsigned int _rear;
    unsigned int _len;
public:
    cyclequeue(unsigned int cap):_cap(cap),_front(0),_rear(0){
        _data = new T(_cap);
    }
    ~cyclequeue(){
        delete [] _data;
        _data = nullptr;
    }
    inline bool empty(){ return _front == _rear ; }
    inline bool full(){return   _front == (_rear+1)%_cap;} // 空队时rear等于front，满队时必须空一个位置
    inline unsigned int length(){return _len;}

    bool push(const T& ele){
        if(full()){
            return false;
        }
        _data[_rear]=ele;
        _rear=(_rear+1)%_cap;
        _len++;
        return true;
    }
    std::pair<bool,T> pop(){
        if(empty()){
            return std::make_pair(false,T());
        }
        auto tmp = _data[_front];
        _front=(_front+1)%_cap;
        _len--;
        return std::make_pair(true,tmp);
    }


};


#endif //DATASTRUCTURE_EXE_CYCLEQUEUE_H
