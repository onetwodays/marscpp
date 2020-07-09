/*
 * Description: 
 *     History: yang@haipo.me, 2017/03/20, create
 */

# include <stdlib.h>
# include <string.h>
# include "ut_skiplist.h"
# define SKIPLIST_MAX_LEVEL 16
# define SKIPLIST_P         0.25

//只是创建了一个节点,并没有加入跳表里面
static skiplist_node *skiplist_create_node(skiplist_t *list, int level, void *value)
{
    size_t size = sizeof(skiplist_node) + level * sizeof(skiplist_node *);//指针数组的大小是level.指针类型是skiplist_node*
    skiplist_node *node = malloc(size);
    if (node == NULL) {
        return NULL;
    }
    memset(node, 0, size);
    if (value && list->type.dup) {
        node->value = list->type.dup(value);
    } else {
        node->value = value;
    }
    return node;
}

//创建跳表结构
skiplist_t *skiplist_create(skiplist_type *type)
{
    if (type == NULL || type->compare == NULL) {
        return NULL;
    }
    skiplist_t *list = malloc(sizeof(skiplist_t));
    if (list == NULL) {
        return NULL;
    }
    memset(list, 0, sizeof(skiplist_t));
    list->level = 1; //默认层级是1
    memcpy(&list->type, type, sizeof(skiplist_type));
    list->header = skiplist_create_node(list, SKIPLIST_MAX_LEVEL, NULL); //实实在在的一个节点,只是元素实际值为空
    if (list->header == NULL) {
        free(list);
        return NULL;
    }
    return list;
}

//跳表的层级最大是SKIPLIST_MAX_LEVEL
/*
 * random()&0xFFFF形成的数，均匀分布在区间[0,0xFFFF]上，那么这个数小于(ZSKIPLIST_P * 0xFFFF)的概率是多少呢？
 * 自然就是ZSKIPLIST_P，也就是0.25了。

  因此，最终返回level为1的概率是1-0.25=0.75，
  返回level为2的概率为0.25*0.75，
  返回level为3的概率为0.25*0.25*0.75......
  因此，如果返回level为k的概率为x，则返回level为k+1的概率为0.25*x，
  换句话说，如果k层的结点数是x，那么k+1层就是0.25*x了。这就是所谓的幂次定律（powerlaw），越大的数出现的概率越小。
 */
static int skiplist_random_level(void)
{
    int level = 1;
    while ((random() & 0xFFFF) < (SKIPLIST_P * 0xFFFF)) {
        level += 1;
    }
    return level < SKIPLIST_MAX_LEVEL ? level : SKIPLIST_MAX_LEVEL;
}

skiplist_t *skiplist_insert(skiplist_t *list, void *value)
{
    skiplist_node *update[SKIPLIST_MAX_LEVEL];//update数组记录插入结点在每层上的前驱结点
    skiplist_node *node = list->header;
    //从最上面搜索 从表头结点的最高层开始查找，首先在该层中寻找插入结点的前驱结点
    for (int i = list->level - 1; i >= 0; i--) {
        //every level
        while (node->forward[i] && list->type.compare(node->forward[i]->value, value) <= 0) { //先横着走，走到最后
            node = node->forward[i];
        }
        update[i] = node; //在i层下行的节点，直到0层
    }
    if (node->value && list->type.compare(node->value, value) == 0) {
        return NULL;
    }

    int level = skiplist_random_level();
    if (level > list->level) {
        for (int i = list->level; i < level; ++i) {
            update[i] = list->header;
        }
        list->level = level;
    }

    node = skiplist_create_node(list, level, value);
    if (node == NULL) {
        return NULL;
    }
    for (int i = 0; i < level; ++i) {
        node->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = node;
    }
    list->len += 1;
    return list;
}

skiplist_node *skiplist_find(skiplist_t *list, void *value)
{
    skiplist_node *node = list->header;
    for (int i = list->level - 1; i >= 0; i--) {
        while (node->forward[i] && list->type.compare(node->forward[i]->value, value) <= 0) {
            node = node->forward[i];
        }
    }

    if (node->value && list->type.compare(node->value, value) == 0) {
        return node;
    }
    return NULL;
}

void skiplist_delete(skiplist_t *list, skiplist_node *x)
{
    skiplist_node *update[SKIPLIST_MAX_LEVEL];
    skiplist_node *node = list->header;

    for (int i = list->level - 1; i >= 0; i--) {
        while (node->forward[i] && list->type.compare(node->forward[i]->value, x->value) < 0) {
            node = node->forward[i];
        }
        update[i] = node;
    }

    for (int i = 0; i < list->level; ++i) {
        if (update[i]->forward[i] == x) {
            update[i]->forward[i] = x->forward[i];
        }
    }
    while (list->level > 1 && list->header->forward[list->level - 1] == NULL) {
        list->level -= 1;//实际层级，因为list->header是保存所有的
    }

    if (list->type.free) {
        list->type.free(x->value);
    }
    free(x);
    list->len -= 1;
}


void skiplist_release(skiplist_t *list)
{
    unsigned long len = list->len;
    skiplist_node *curr = list->header->forward[0];
    skiplist_node *next;
    while (len--) {
        next = curr->forward[0];
        if (list->type.free) {
            list->type.free(curr->value);
        }
        free(curr);
        curr = next;
    }
}


skiplist_iter *skiplist_get_iterator(skiplist_t *list)
{
    skiplist_iter *iter = malloc(sizeof(skiplist_iter));
    if (iter == NULL) {
        return NULL;
    }
    iter->next = list->header->forward[0];
    return iter;
}


skiplist_node *skiplist_next(skiplist_iter *iter)
{
    skiplist_node *curr = iter->next;
    if (curr) {
        iter->next = curr->forward[0];
    }
    return curr;
}


void skiplist_release_iterator(skiplist_iter *iter)
{
    free(iter);
}

