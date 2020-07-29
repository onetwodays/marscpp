//
// Created by zh on 2020/7/29.
//

#ifndef MARSC___UT_DYNARRAY_STACK_H
#define MARSC___UT_DYNARRAY_STACK_H

#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct dynarray_stack{
    int _top;
    int _capacity;
    int* _array;

} dynarray_stack ;

dynarray_stack* create_stack(int init_capacity);
dynarray_stack* create_double_stack(dynarray_stack* stack);
void delete_stack(dynarray_stack* stack);
bool is_stack_empty(dynarray_stack* stack);
bool is_stack_full(dynarray_stack* stack);
bool top(dynarray_stack* stack,int* dst);
bool push(dynarray_stack* stack,int data);
bool pop(dynarray_stack* stack,int* dst);



#ifdef __cplusplus
}
#endif


#endif //MARSC___UT_DYNARRAY_STACK_H
