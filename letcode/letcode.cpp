//
// Created by zh on 2020/6/30.
//
#include <stdio.h>
#include "letcode.h"
//使用递归求和1+2+3+....+n
int letcode::sum(int n) {
    int sum_= n;
    bool flag=(n>0) && (sum_+=letcode::sum(n-1))>0;
    return sum_;
}

int letcode::str2Int(const char *str) {
    if (*str=='\0'||!str)
        return 0;

    int ret = 0;

    bool isNegative = *str =='-';
    while (str++){
        if(*str==0 && (*str=='+' || *str=='-')){
            continue;
        }
        if(*str<'0' || *str>'9'){
            return 0;
        }
        ret = ret*10 + (*str-'0'); //?
    }
    //判断数据溢出
    if((isNegative && ret < (int)0x80000000)||(!isNegative&&ret>0x7fffffff )){
        return 0;
    }

    return isNegative?-ret:ret;




}

/*计算n的阶乘函数*/
void letcode::factorial(int n)
{
    /*这里初始化为1*/
    static int num[10000 + 1];
    num[0] = 1;

    /*当前数字的位数*/
    int digit_number = 1;

    /*从2开始进行乘法运算*/
    for (int i = 2; i <= n; i++)
    {
        /*是否进位*/
        int carry = 0;

        /*示例：
            2583
          x   35
          将35与3、8、5、2依次进行乘法，每次乘之后计算进位
        */
        for (int j = 0; j < digit_number; j++)
        {
            /*采用10000进制，每次乘的时候加上进位*/
            num[j] = num[j] * i + carry;
            /*取得进位*/
            carry = num[j] / 10000;
            /*计算j位的数值*/
            num[j] %= 10000;
        }

        /*最高位的进位，如果进位了，则当前数字的位数digit_number+1*/
        if (carry > 0)
            num[digit_number++] = carry;
    }

    /*输出：高位原样输出，低位的高位补0*/
    printf("%d", num[digit_number - 1]);
    printf("---------------\n");

    /*可以在纸上画一下10000进制转成10进制的输出*/
    for (int i = digit_number - 2; i >= 0; i--)
        printf("%04d\n", num[i]);

    printf("\n");
}
