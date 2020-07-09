
# ifndef _DICT_H_
# define _DICT_H_

# include <stdint.h>
# include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dict_entry {
    void *key; //能保存任何的数据类型，一般是结构体
    void *val; //能保存任何的数据类型，
    uint64_t id;//每个元素一个编号
    struct dict_entry *next;
} dict_entry;

typedef struct dict_types {
    //(*dup)代表这是一个函数指针，前面的void *代表函数返回值为指针（void *型）
    uint32_t (*hash_function)(const void *key);//必须实现
    void *(*key_dup)(const void *key);
    void *(*val_dup)(const void *val);
    int (*key_compare)(const void *key1, const void *key2);
    void (*key_destructor)(void *key);
    void (*val_destructor)(void *val);
} dict_types;

typedef struct dict_t {
    dict_entry **table; //指针数组
    dict_types type;    //不是指针类型
    uint32_t size;      //初始化的capacity 一开始就创建这么多元素(指针数组的长度）
    uint32_t mask;      //值固定是size-1
    uint32_t used;      //每dict_add 就++
    uint64_t id_start;  //字典元素的编号开始的值
    uint64_t id_clear;
} dict_t;

typedef struct dict_iterator {
    dict_t *dt;
    int64_t index;
    dict_entry *entry;
    dict_entry *next_entry;
} dict_iterator;

# define dict_size(dt) (dt)->used
# define dict_slot(dt) (dt)->size

uint32_t dict_generic_hash_function(const void *data, size_t len);

dict_t *dict_create(dict_types *type, uint32_t init_size);
dict_entry *dict_add(dict_t *dt, void *key, void *val);
dict_entry *dict_find(dict_t *dt, const void *key);
int dict_expand(dict_t *dt, uint32_t size);
int dict_replace(dict_t *dt, void *key, void *val);
int dict_delete(dict_t *dt, const void *key);
void dict_release(dict_t *dt);

void dict_clear(dict_t *dt);
void dict_mark_clear(dict_t *dt);

dict_iterator *dict_get_iterator(dict_t *dt);
dict_entry    *dict_next(dict_iterator *iter);
void dict_release_iterator(dict_iterator *iter);

#ifdef __cplusplus
}
#endif

# endif

