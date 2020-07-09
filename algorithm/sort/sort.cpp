//
// Created by zh on 2020/6/22.
//
#include <cmath>
#include <iostream>


#include "sort.h"

static  void _swap(int* i,int* j){
    int temp = *i ;
    *i = *j;
    *j = temp;

}

/*
 * 算法描述
较相邻的元素。如果第一个比第二个大，就交换他们两个。

对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。

针对所有的元素重复以上的步骤，除了最后一个。

持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较
 是稳定算法,
 最好O(n) 最坏O(n2) avg O(n2) 空O(1) 排序方式就地排序
 */

void sort::bubble(int* a,int length){
    if (!length) return;
    for(int i = 0 ; i< length-1;++i){ //最后一个元素不用，所有是i<length-1
        bool flag = true ;
        for(int j=0;j<length-1-i;++j){
            if(a[j]>a[j+1]){
                _swap(&a[j],&a[j+1]);
                flag = false;
            }
        }
        if(flag){
            break;//退出外层循环，因为已经有序了
        }
    }
}
/*
 * 快速排序（Quick Sort）
快速排序的基本思想：通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序。

6.1 算法描述
快速排序使用分治法来把一个串（list）分为两个子串（sub-lists）。具体算法描述如下：

从数列中挑出一个元素，称为 “基准”（pivot）；
重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
 在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。
 不稳定，最好O(nlogn) 最坏O(n2) avg O(nlogn) 空O(1) 排序方式就地排序
 */

static int partition(int* a, int left, int right){
    int pivot = left; //设定基准值,是下标
    int index = pivot+1;
    for(int i = index; i <= right ; ++i){
        if(a[i] <a[pivot]){
            _swap(&a[i],&a[index]);
            ++index; //这里进1了
        }
    }
    _swap(&a[pivot],&a[index-1]); //index-1 代表的是基准值，放在left的位置
    return index-1;
}
void sort::quick(int *a, int left, int right) {
    if(left<right){
        int partition_index = partition(a,left,right);
        sort::quick(a,left,partition_index-1);
        sort::quick(a,partition_index+1,right);
    }
}

/*

 时间复杂度表现最稳定的排序算法之一，因为无论什么数据进去都是O(n2)的时间复杂度，
 所以用到它的时候，数据规模越小越好。唯一的好处可能就是不占用额外的内存空间了吧。
 理论上讲，选择排序可能也是平时排序一般人想到的最多的排序方法了。
 选择排序是给每个位置选择当前元素最小的，比如给第一个位置选择最小的，在剩余元素里面给第二个元素选择第二小的，
 依次类推，直到第n - 1个元素，第n个元素不用选择了，因为只剩下它一个最大的元素了。
 那么，在一趟选择，如果当前元素比一个元素小，而该小的元素又出现在一个和当前元素相等 的元素后面，那么交换后稳定性就被破坏了。
 比较拗口，举个例子，序列5 8 5 2 9，我们知道第一遍选择第1个元素5会和2交换，那么原序列中2个5的相对前后顺序就被破坏了，
 所以选择排序不是一个稳定的排序算法
 不稳定算法,
 最好O(n2) 最坏O(n2) avg O(n2) 空O(1) 排序方式就地排序

 */
void sort::select(int *a,int length) {
    for(int i = 0; i< length-1;++i ){ // 总共要经过 N-1 轮比较，因为最后一个元素就不用了
        int min_index = i; //最小的数
        for(int j=i+1;j<length;++j){
            if(a[min_index]>a[j]){ //寻找最小的数
                min_index = j; //将最小的数索引记录下来
            }
        }
        _swap(&a[i],&a[min_index]); //每次确定第i位置的最小值.
    }
}

/*
 * 堆排序（Heap Sort）
 堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。
 堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：
 即子结点的键值或索引总是小于（或者大于）它的父节点。

7.1 算法描述
将初始待排序关键字序列(R1,R2….Rn)构建成大顶堆，此堆为初始的无序区；
将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1,R2,……Rn-1)和新的有序区(Rn),且满足R[1,2…n-1]<=R[n]；
由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1,R2,……Rn-1)调整为新堆，
 然后再次将R[1]与无序区最后一个元素交换，得到新的无序区(R1,R2….Rn-2)和新的有序区(Rn-1,Rn)。
 不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。
  不稳定，最好O(nlogn) 最坏O(nlogn) avg O(nlogn) 空O(1) 排序方式就地排序
 */

static void heapify(int* a, int i,int len){
    int largest = i ;
    int left = 2*i +1;
    int right = 2*i +2;
    if(left<len && a[left]>a[largest]){
        largest = left ;
    }
    if(right<len && a[right]>a[largest]){
        largest = right ;
    }
    if(largest != i ){
        _swap(&a[i],&a[largest]);
        heapify(a,largest,len);
    }
}

void sort::heap(int *a, int len) {
    //构造堆
    for ( int i = std::floor(len/2);i>=0; --i){
        heapify(a,i,len);
    }

    for( int i = len-1;i>0;--i){
        _swap(&a[0],&a[i]);
        len--;
        heapify(a,0,len);
    }
}

/*
 * 插入排序（Insertion Sort）
插入排序（Insertion-Sort）的算法描述是一种简单直观的排序算法。它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。

3.1 算法描述
一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：

从第一个元素开始，该元素可以认为已经被排序；
取出下一个元素，在已经排序的元素序列中从后向前扫描；
如果该元素（已排序）大于新元素，将该元素移到下一位置；
重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
将新元素插入到该位置后；
重复步骤2~5。
 插入排序在实现上，通常采用in-place排序（即只需用到O(1)的额外空间的排序），因而在从后向前扫描过程中，需要反复把已排序元素逐步向后挪位，为最新元素提供插入空间。
  是稳定算法,
 最好O(n) 最坏O(n2) avg O(n2) 空O(1) 排序方式就地排序
 */

void sort::insert(int *a, int len) {
    for(int i =1;i<len;++i){ //从下标为1的元素开始选择合适的位置插入，因为下标为0的只有一个元素，默认是有序的
        int pre_index =  i-1;
        int current = a[i];
        while (pre_index>=0 && a[pre_index]>current){ //一直退，不满足这个条件时，不用退了，找到位置
            a[pre_index+1] = a[pre_index];
            pre_index--;
        }
        a[pre_index+1] = current ; //这个元素的位置是pre_index+1
    }
}

void sort::insert(std::vector<int>& a){
    for(int i =1;i<a.size();++i){
        int index =  i;
        int current = a[i];
        while (index>=0 && a[index-1]>current){
            a[index] = a[index-1];
            index--;
        }
        a[index] = current ;
    }
}

/*
 * 1959年Shell发明，第一个突破O(n2)的排序算法，是简单插入排序的改进版。它与插入排序的不同之处在于，
 * 它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。

4.1 算法描述
先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，具体算法描述：

选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；
按增量序列个数k，对序列进行k 趟排序；
每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。
 仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度
 希尔排序的核心在于间隔序列的设定。既可以提前设定好间隔序列，也可以动态的定义间隔序列。
 动态定义间隔序列的算法是《算法（第4版）》的合著者Robert Sedgewick提出的。　
 一般是2分的间隔，先间隔，对于每个间隔，运用插入排序，直到间隔=0(gap最小值是1）
 10个元素 gap=[5,2,1]
 i=5,5<10,++i
 i=2,2<10,++i
 i=1,1<10,++i
  不稳定算法(希尔排序是按照不同步长对元素进行插入排序，当刚开始元素很无序的时候，步长最大，所以插入排序的元素个数很少，速度很快；当元素基本有序了，步长很小， 插入排序对于有序的序列效率很高。所以，希尔排序的时间复杂度会比O(n^2)好一些。由于多次插入排序，我们知道一次插入排序是稳定的，不会改变相同元素的相对顺序，但在不同的插入排序过程中，相同的元素可能在各自的插入排序中移动，最后其稳定性就会被打乱，所以shell排序是不稳定的。)
 最好O(nlog2n) 最坏O(log2 n) avg O(nlogn) 空O(1) 排序方式就地排序

 */

void sort::shell(int *a, int len) {
    for(int gap = std::floor(len/2);gap>0;gap=std::floor(gap/2)){
        for (int i = gap; i<len;++i ){
            int j = i;
            int current = a[i];
            while (j-gap>=0 && current<a[j-gap]){
                a[j]=a[j-gap];
                j=j-gap;
            }
            a[j] = current;
        }
    }
}

/*
 * 归并排序（Merge Sort）
归并排序是建立在归并操作上的一种有效的排序算法。该
 算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
 将已有序的子序列合并，得到完全有序的序列；
 即先使每个子序列有序，再使子序列段间有序。
 若将两个有序表合并成一个有序表，称为2-路归并。

5.1 算法描述
把长度为n的输入序列分成两个长度为n/2的子序列；
对这两个子序列分别采用归并排序；
将两个排序好的子序列合并成一个最终的排序序列。
 归并排序是一种稳定的排序方法。和选择排序一样，归并排序的性能不受输入数据的影响，但表现比选择排序好的多，
 因为始终都是O(nlogn）的时间复杂度。代价是需要额外的内存空间。

 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
 设定两个指针，最初位置分别为两个已经排序序列的起始位置；
 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
 重复步骤 3 直到某一指针达到序列尾；
 将另一序列剩下的所有元素直接复制到合并序列尾。
 最好O(nlogn) 最坏O(nlog n) avg O(nlogn) 空O(n) 排序方式out-place;稳定
 */

static std::vector<int> _two_merge(const std::vector<int>& left,const std::vector<int>& right){
    sort::print_vector(left,"left");
    sort::print_vector(right,"right");
    std::vector<int> result(left.size()+right.size());//额外的空间保存结果元素
    int i_left = 0;
    int i_right = 0;
    int i_result = 0;
    while(i_left<left.size() && i_right<right.size()){
        if(left[i_left]<=right[i_right]){
            result[i_result]=left[i_left];
            i_left++;
        }else{
            result[i_result]=right[i_right];
            i_right++;
        }
        i_result++;
    }
    if(i_left==left.size()){
        for(int i = i_right;i<right.size();++i){
            result[i_result++] = right[i];
        }
    }

    if(i_right==right.size()){
        for(int i = i_left;i<left.size();++i){
            result[i_result++] = left[i];
        }
    }

    sort::print_vector(result,"递归after------------------");

    return result;
}
std::vector<int> sort::two_merge(const std::vector<int>& a){
    if(a.size()<2){
        return a;
    }
    int mid = std::floor(a.size()/2);
    std::vector<int> left(mid);
    std::vector<int> right(a.size()-mid);
    for(int i=0;i<mid;++i){
        left[i]=a[i];
    }
    for(int i=0;i<a.size()-mid;++i){
        right[i]=a[i+mid];
    }

    return _two_merge(sort::two_merge(left),sort::two_merge(right));
}



/*
 * 计数排序不是基于比较的排序算法，其核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。
 * 作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。

8.1 算法描述
找出待排序的数组中最大和最小的元素；
统计数组中每个值为i的元素出现的次数，存入数组C的第i项；
对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）；
反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1。
 计数排序是一个稳定的排序算法。当输入的元素是 n 个 0到 k 之间的整数时，时间复杂度是O(n+k)，空间复杂度也是O(n+k)，
 其排序速度快于任何比较排序算法。当k不是很大并且序列比较集中时，计数排序是一个很有效的排序算法。

 花O(n)的时间扫描一下整个序列 A，获取最小值 min 和最大值 max

开辟一块新的空间创建新的数组 B，长度为 ( max - min + 1)

数组 B 中 index 的元素记录的值是 A 中某元素出现的次数

最后输出目标整数序列，具体的逻辑是遍历数组 B，输出相应元素以及对应的个数
 最好O(n+K) 最坏O(n+k) avg O(n+k) 空O(k) 排序方式out-place;稳定
 */
void sort::count(std::vector<int> &a) {
    int max = a[0];
    for(int i=1;i<a.size();++i){
        if(a[i]>max) {
            max = a[i];
        }
    }
    std::vector<int > bucket(max+1,0);
    for(int i = 0;i<a.size();i++){
        bucket[a[i]]++;
    }
    int sortIndex = 0;
    for(int j=0;j<bucket.size();++j){
        while (bucket[j]>0){
            a[sortIndex++] = j ;
            bucket[j]--;
        }
    }
}
/*
 * 桶排序（Bucket Sort）
桶排序是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。
 桶排序 (Bucket sort)的工作的原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，
 每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排）。

9.1 算法描述
设置一个定量的数组当作空桶；
遍历输入数据，并且把数据一个一个放到对应的桶里去；
对每个不是空的桶进行排序；
从不是空的桶里把排好序的数据拼接起来。
 桶排序最好情况下使用线性时间O(n)，
 桶排序的时间复杂度，取决与对各个桶之间数据进行排序的时间复杂度，因为其它部分的时间复杂度都为O(n)。
 很显然，桶划分的越小，各个桶之间的数据越少，排序所用的时间也会越少。但相应的空间消耗就会增大。

最好O(n+K) 最坏O(n2) avg O(n+k) 空O(n+k) 排序方式out-place;稳定
 */

void sort::bucket(std::vector<int> &a,int bucketsize) {
    if(a.empty()) return;
    int i =0;
    int min_value = a[0];
    int max_value = a[0];
    for(i = 1 ; i< a.size();++i){
        if(a[i]<min_value){
            min_value = a[i];
        }else if( a[i]>max_value){
            max_value = a[i];
        }
    }

    int DEFAULT_BUCKET_SIZE = 5;
    bucketsize = bucketsize || DEFAULT_BUCKET_SIZE ;
    int bucket_count = std::floor((max_value-min_value)/bucketsize)+1; //每个桶固定5个元素；
    std::vector<std::vector<int>> buckets(bucket_count);
    //利用映射函数将数据分配到各个桶中
    for(auto & item : a){
        buckets[std::floor(item-min_value)/bucketsize].push_back(item);
    }
    a.clear();
    for(auto & item:buckets){
        sort::insert(item); // 对每个桶进行排序，这里使用了插入排序
        for(auto& i : item){
            a.push_back(i);
        }
    }
}

/*
 * 基数排序（Radix Sort）
基数排序是按照低位先排序，然后收集；
 再按照高位排序，然后再收集；依次类推，直到最高位。有
 时候有些属性是有优先级顺序的，先按低优先级排序，再按高优先级排序。
 最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前。

10.1 算法描述
取得数组中的最大数，并取得位数；
arr为原始数组，从最低位开始取每个位组成radix数组；
对radix进行计数排序（利用计数排序适用于小范围数的特点）

 基数排序基于分别排序，分别收集，所以是稳定的。但基数排序的性能比桶排序要略差，每一次关键字的桶分配都需要O(n)的时间复杂度，而且分配之后得到新的关键字序列又需要O(n)的时间复杂度。假如待排数据可以分为d个关键字，则基数排序的时间复杂度将是O(d*2n) ，当然d要远远小于n，因此基本上还是线性级别的。

基数排序的空间复杂度为O(n+k)，其中k为桶的数量。一般来说n>>k，因此额外空间需要大概n个左右

将所有待比较数值（正整数）统一为同样的数位长度，数位较短的数前面补零

从最低位开始，依次进行一次排序

从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列

 数排序存在问题对于包含负数的数据无法进行排序
 将所有的数加一个正数，使得所有的数变为正数进行基数排序；
排序完之后在减点加的正数值输出。
注意：这里的正数是指大于最小值的绝对值的数，下面程序中缺少找最小值的过程自己有需要的自己加

 时间复杂度
        该算法所花的时间基本是在把元素分配到桶里和把元素从桶里串起来；把元素分配到桶里：循环 length 次；
       把元素从桶里串起来：这个计算有点麻烦，看似两个循环，其实第二循环是根据桶里面的元素而定的，可以表示为：k×buckerCount；其中 k 表示某个桶中的元素个数，buckerCount  则表示存放元素的桶个数；
       有几种特殊情况：
       第一、所有的元素都存放在一个桶内：k = length，buckerCount = 1；
       第二、所有的元素平均分配到每个桶中：k = length/ bukerCount，buckerCount = 10；（这里已经固定了10个桶）
       所以平均情况下收集部分所花的时间为：length （也就是元素长度 n）

       综上所述：
       时间复杂度为：posCount * (length  + length) ；其中 posCount 为数组中最大元素的最高位数；简化下得：O( k*n ) ；其中k为常数，n为元素个数；


 最好O(n*K) 最坏O(n*K) avg O(n*k) 空O(n+k) 排序方式out-place;稳定

 */

void sort::radix(std::vector<int> &a) {
    if(a.empty()) return;

    //找到最大值
    int max = a[0];
    for(int i=1;i<a.size();++i){
        if(a[i]>max) {
            max = a[i];
        }
    }

    if(max == 0) return;
    int lenght = 0;
    for (long temp = max; temp != 0; temp /= 10) {
        lenght++;
    }

    int mod = 10 ;
    int dev = 1 ;
    std::vector<std::vector<int>> buckets(20); //负数问题？


    for(int i=0; i<lenght;i++,dev*=10,mod*=10){
        //要考虑负数，这里[0-9]表示负数 [10-19]正数
        for(auto& item: a){
            int bucket = (item%mod)/dev;
            if (buckets.size()<bucket+1){
                buckets.resize(bucket+1);
            }
            buckets[bucket].push_back(item);
        }

        //sort each bucket
        int pos =0 ;
        for(int bucket = 0 ; bucket< buckets.size();++bucket){
            for(auto &item :buckets[bucket] ){
                a[pos++] = item;
            }
            if(!buckets[bucket].empty()){
                buckets[bucket].clear();
            }
        }
    }
}
/*
 * 通常我们的输入都是十进制数，桶排序都是设置为10个桶，从后向前每次对每一个位进行排序，
 * 这样虽然是O(n)，但是除法操作会占用大量的时间。
 * 我的改进思路是将桶设置为16个，即2^4个桶，32位的int型整数看做16进制是8位，最高位是符号位，
 * 这样可以用移位操作代替除法操作，大大提高了效率。桶排序的空间复杂度是O(n) ，
 * 即需要开辟新数组存储所有的数据，桶的数量不影响空间复杂度。代码如下：
 */

void sort::radix_v2(std::vector<int> &nums) {
    using namespace std;
    vector<vector<int>> bucket(16, vector<int>());
    //第一轮，将数组按照最低四位2进制数存入所有的桶中
    for (auto i : nums){
        bucket[i & 15].push_back(i);
    }
    //循环七轮，进行桶排序
    for (int i = 1; i < 8; i++){
        vector<vector<int>> bucket2(16, vector<int>());
        //计算移位和掩码
        int shift = i * 4;
        int mask = 0xf<< shift;
        for (auto v : bucket)
            //注意 C++ unsigned的右移是逻辑右移，前面不补0
            for (unsigned num : v)
                bucket2[(num&mask) >> shift].push_back(num);
        //每轮之后交换原桶和临时桶
        swap(bucket, bucket2);
    }
    //排序之后，交换正负数的位置
    int pos = 0;
    for (int i = 0; i < 8; i++) swap(bucket[i], bucket[i + 8]);
    for (auto v : bucket){
        for (auto i : v)
            nums[pos++] = i;
    }

}
//唯一需要说明的就是，排序之后，由于负数的符号位是1，正数的符号位是0，所以0-7个桶存放的是正数，8-15个桶存放的是负数；除此之外，正数是从小到大排列的，负数由于是补码存放，其绝对值为取反之后再加1，所以负数是按照绝对值从大到小排列的，即负数也是从小到大排列的。所以只需要把0-7桶放到8-15桶的后面，即可完成排序。
