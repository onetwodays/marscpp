//
// Created by zh on 2020/7/29.
//

#ifndef MARSC___UT_PTR_STACK_H
#define MARSC___UT_PTR_STACK_H

#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef  struct ptr_stack{
    int data;
    struct  ptr_stack* next;
} ptr_stack;

ptr_stack* create_stack();
void delete_stack(ptr_stack * stack);
bool is_stack_empty(ptr_stack * stack);

bool  top(ptr_stack * stack,int* dst);
bool  push(ptr_stack ** stack,int data);
bool  pop(ptr_stack ** stack,int* dst);



#ifdef __cplusplus
}
#endif




#endif //MARSC___UT_PTR_STACK_H
