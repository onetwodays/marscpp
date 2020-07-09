/*
 * Description: 
 *     History: yang@haipo.me, 2017/03/20, create
 */

# ifndef _UT_SKIPLIST_H_
# define _UT_SKIPLIST_H_
#ifdef __cplusplus
extern "C" {
#endif

//https://blog.csdn.net/daniel_ustc/article/details/20218489
/*
(1) 由很多层结构组成
(2) 每一层都是一个有序的链表
(3) 最底层(Level 1)的链表包含所有元素
(4) 如果一个元素出现在 Level i 的链表中，则它在 Level i 之下的链表也都会出现。
(5) 每个节点包含两个指针，一个指向同一链表中的下一个元素，一个指向下面一层的元素
跳跃表（skiplist）是一种有序数据结构， 它通过在每个节点中维持多个指向其他节点的指针， 从而达到快速访问节点的目的

跳跃表支持平均 O(log N) 最坏 O(N) 复杂度的节点查找， 还可以通过顺序性操作来批量处理节点。

在大部分情况下， 跳跃表的效率可以和平衡树相媲美， 并且因为跳跃表的实现比平衡树要来得更为简单，
 所以有不少程序都使用跳跃表来代替平衡树
 */
typedef struct skiplist_node {
    void *value;
    struct skiplist_node *forward[];//指针数组
} skiplist_node;

typedef struct skiplist_iter {
    skiplist_node *next;
} skiplist_iter;

//跳表内部方法
typedef struct skiplist_type {
    void *(*dup)(void *value);
    void (*free)(void *value);
    int (*compare)(const void *value1, const void *value2);//必须提供，排序用到
} skiplist_type;

typedef struct skiplist_t {
    int level;//跳表的层数
    skiplist_type type;
    skiplist_node *header;
    unsigned long len;//跳表的元素个数
} skiplist_t;

# define skiplist_len(l)        ((l)->len)
# define skiplist_node_value(n) ((n)->value)

skiplist_t *skiplist_create(skiplist_type *type);
skiplist_t *skiplist_insert(skiplist_t *list, void *value);
skiplist_node *skiplist_find(skiplist_t *list, void *value);
void skiplist_delete(skiplist_t *list, skiplist_node *node);
void skiplist_release(skiplist_t *list);

skiplist_iter *skiplist_get_iterator(skiplist_t *list);
skiplist_node *skiplist_next(skiplist_iter *iter);
void skiplist_release_iterator(skiplist_iter *iter);

#ifdef __cplusplus
}
#endif

# endif

