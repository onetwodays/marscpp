//
// Created by zh on 2020/6/16.
//
#include <stdio.h>

#include <string.h>

// 交换数组的俩元素
static void swap(int a[] , int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}


static  int partition(int a[], int l, int h) {
    int i = l, j = h + 1;
    while (true) {
        while (a[++i] < a[l] && i < h) ;
        while (a[--j] > a[l] && j > l) ;
        if (i >= j) {
            break;
        }
        swap(a, i, j);
    }
    swap(a, l, j);
    return j;
}

/*计算n的阶乘函数*/
void factorial(int n)
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

    /*可以在纸上画一下10000进制转成10进制的输出*/
    for (int i = digit_number - 2; i >= 0; i--)
        printf("%04d", num[i]);

    printf("\n");
}


char *Strstr(const char *s1, const char *s2)
{
    int n;
    if (*s2)
    {
        while (*s1)
        {
            for (n = 0; *(s1 + n) == *(s2 + n); n ++)
            {
                if (!*(s2 + n + 1)) //校验是否到了结尾
                    return (char *)s1;
            }
            s1++;
        }
        return NULL;
    }
    else
        return (char *)s1;
}

char *Mystr(const char* s1,const char* s2){
    if(!s2 || !s1){
        return (char*)(s1);
    }

    while(*s1){ //依次遍历s1
        for(int n=0;*(s1+n)==*(s2+n);n++){
            if(!*(s2+n+1)){
                return (char*)(s1);
            }
        }
        s1++;
    }
    return nullptr;

}

//快速排序
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if(i < j)
                s[i++] = s[j];

            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}