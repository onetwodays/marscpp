//
// Created by zh on 2020/6/30.
//
#include <climits>
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

void* letcode::mymemmove(void* dst,void* src,std::size_t num){
    if(dst==NULL || src==NULL) return NULL;
    char* pdst = (char*)(dst);
    const char* psrc = (char*)(src);
    //dst与src有没有重叠，若果有重叠，src要从后向前复制
    if(pdst>psrc && pdst < psrc+num){
        for(std::size_t i=num-1;i>=0;++i){
            pdst[i]=psrc[i];
        }
    //没有重叠时，对src从前往后复制
    }else{
        for(std::size_t i=0;i<=num-1;++i){
            pdst[i]=psrc[i];
        }
    }
    return dst;
}

char* letcode::myitoa(int num, char *src, int radix) {
    char* ptr=src;
    int sign = num ;

    if(sign<0){
        num = -num ;
    }

    while (num){
        *ptr++ = num%radix+'0';
        num/=radix;
        if(num<radix){
            *ptr++ = num+'0';
            break;
        }
    }
    if(sign<0){
        *ptr++ = '-';
    }
    *ptr='\0';
    int j = ptr-src-1;
    for(int i=0;i<j;i++){

        src[i] = src[i]^src[j];
        src[j] = src[i]^src[j];
        src[i] = src[i]^src[j];

    }

    return src;

}

bool letcode::myatoi(const char *str,int& num) {
    if(str==NULL){
        return -1;
    }
    while (*str==' '){
        str++;
    }
    int nSign = (*str=='-')?-1:1;//确定符号位
    if(*str=='+' || *str=='-'){
        str++;
    }

    int nResult = 0;
    while (*str>='0' && *str<='9'){
        nResult = nResult*10+(*str-'0');
        str++;
    }
    while (*str==' ' ){
        str++;
    }
    if(*str!='\0'){
        return false;
    }
    num = nResult*nSign;
    return num ;

}

int letcode::mystrlen(const char *str) {

    if(str== nullptr) return 0;
    if(*str=='\0') return 0;
    return 1+mystrlen(++str);



}

void letcode::shuffle(int *cards, int n) {
    if (cards==NULL) return;
    srand(time(0));

    for(int i=0;i<n-1;++i){
        int index = i+ rand()%(n-i) ;//保证每次第i位的值不会涉及到第i位以前，产生i到n-1间的随机数
        int t = cards[i];
        cards[i]=cards[index];
        cards[index]=t;
    }
}

/*
 * 关键思路
关注题目中给出的几个变量: arr、k、threshold，关键词: 子数组、数目
子数组指的是连续数组，看评论好多同学都以为是不连续数组
子数组的长度为k，且平均值>=threshold，那么子数组的和必定>= k * threshold
我们要求的结果就是数目这个变量，这里至少可以想到代码中肯定要定义这么个变量，比如: nums

解题方法是滑动窗口的思路(这里也是先入为主，不是我自己分析出来的)
滑动窗口：这个词搜索了一下是出现在TCP协议中，用于网络传输报文的流量控制。
 */

static void print_vector(std::vector<int>& a,int begin,int end){

    std::cout <<"[";
    for(int i=begin;i<=end;++i){
        std::cout<<a[i]<<",";
    }

    std::cout <<"]"<<std::endl;
}

int letcode::numsOfsubarray(std::vector<int> &a, int k, int threshold) {
    // 判断边界条件, 数组的长度 < 给定的子数组的长度, 必然不符合
    if(a.size()<k) return 0;
    int num=0; //最后返回值，即符合条件的子数组个数
    int sum =0; //子数组的和
    int target = k* threshold;//子数组的目标和，大于等于这个值就满足条件
    // 初始子数组的和
    for(int i=0;i<k;++i){
        sum+=a[i];

    }
    // 如果初始子数组就满足条件，nums加1
    if(sum>=target) {
        num++;
        print_vector(a,0,k-1);

    }

    // 这两步是整个算法的关键
    // 新子数组和计算，即老子数组的和减去老子数组的第一个index的值，再加上当前index的值
    // 可以理解为长度为k的窗口往后移动一位
    for (int i=k;i<a.size();++i){
        sum-=a[i-k];// i = 3, k = 3, 就是减去arr[0]
        sum+=a[i];  // 再加上arr[3]
        if(sum>=target) {
            num++;
            print_vector(a,i-k+1,i);
        }

    }

    return num;

}

/*
 * 因为是N x N的方格棋盘，在一次遍历中可以对行、对列、对主副对角线进行求和。
"X"和或"O"获胜的条件是：求和=N个"X"或"O"。
没有获胜选手的情况：判断棋盘是否填满，来判断平局或待定。
 */
std::string letcode::tictactoe(std::vector<std::string>& board){

    int row_size= board.size();
    int column_size=board.size();
    int N=board.size();
    int sum_X=int('X')*N;
    int sum_o=int('0')*N;
    int sum_row = 0;
    int sum_col = 0;
    int sum_left = 0;
    int sum_right = 0;
    int is_full = 1;
    for(int i=0;i<row_size;++i){

        sum_row = 0;
        sum_col = 0;
        sum_left+=board[i][i];
        sum_right+=board[i][column_size-1-i];
        for(int j=0;j<column_size;++j){
            sum_row+=board[i][j];
            sum_col+=board[j][i];
            if(board[i][j]==' ') is_full = 0;
        }
        if( (sum_row==sum_X)||(sum_col==sum_X)){
            return std::string("X");
        }
        if( (sum_row==sum_o)||(sum_col==sum_o)){
            return std::string("o");
        }
    }

    if( (sum_left==sum_X)||(sum_right==sum_X)){
        return std::string("X");
    }
    if( (sum_left==sum_o)||(sum_right==sum_o)){
        return std::string("o");
    }
    if(is_full){
        return "Draw";

    }else{
        return "Pending";
    }



}

int letcode::movesToMakeZigzag(std::vector<int> &nums) {
    if (nums.size() < 2) return 0;
    int s1 = 0;
    int s2 = 0;
    int N = nums.size();
    for (int i = 0; i < N; ++i) {
        int l = (i > 0) ? nums[i - 1] : INT_MAX;
        int r = (i < N - 1) ? nums[i + 1] : INT_MAX;
        if (i & 1) {
            s1 += std::max(0, nums[i] - std::min(l, r) + 1); //奇数
        } else {
            s2 += std::max(0, nums[i] - std::min(l, r) + 1);
        }
    }
    return std::min(s1, s2);

}