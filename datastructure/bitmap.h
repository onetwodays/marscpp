//
// Created by zh on 2020/7/9.
//

#ifndef DATASTRUCTURE_EXE_BITMAP_H
#define DATASTRUCTURE_EXE_BITMAP_H
//当数据量很大而每个数据的状态又很少的情况时候，可以用位图来设计存储数据的容器。
/*
 * 定义一个数组： unsigned char bit[8 * 1024];这样做，能存 8K*8=64K 个 unsigned short 数据。
 * bit 存放的字节位置和位位置（字节 0~8191 ，位 0~7 ）
比如写 1234 ，字节序： 1234/8 = 154; 位序： 1234 &0b111 = 2 ，
 那么 1234 放在 bit 的下标 154 字节处，把该字节的 2 号位（ 0~7）置为 1

字节位置： int nBytePos =1234/8 = 154;

位位置： int nBitPos = 1234 & 7 = 2;
 */
#include <vector>

class bitmap {
private:
    std::vector<int> _bit_table;

public:
    bitmap(std::size_t range){
        //右移5位相当于除以32，加1是因为小于32的数字如果与32相除则得到0
        _bit_table.resize((range>>5)+1);
    }
    void set_bit(std::size_t x){
        auto index = x >> 5; //组序号
        auto num = x%32;//具体序号
        _bit_table[index]|=(1<<num);
    }
    void remove_bit(std::size_t x){
        auto index = x >> 5;
        auto num = x%32;
        _bit_table[index] &= ~(1 << num);
    }
    bool test_bit(std::size_t x){
        auto index = x >> 5;
        auto num = x%32;
        return _bit_table[index] & (1 << num);
    }


};

//你寻找出40亿个数据中出现过两次的数据，此时我们就需要使用两位来标记同一个数据了
class NBitMap
{
public:
    NBitMap(size_t range)
    {
        _bitTable.resize((range >> 4) + 1);
    }

    void SetBit(size_t x)
    {
        size_t index = x >> 4;
        size_t num = x % 16;
        num *= 2;

        bool first = _bitTable[index] & (1 << num);
        bool second = _bitTable[index] & (1 << (num + 1));

        if (!(first && second))
        {
            _bitTable[index] += (1 << num);
        }
    }

    bool TestBit(size_t x)
    {
        size_t index = x >> 4;
        size_t num = x % 16;
        num *= 2;

        return (_bitTable[index] >> num) & 0x03;
    }

private:
    std::vector<int> _bitTable;
};



#endif //DATASTRUCTURE_EXE_BITMAP_H
