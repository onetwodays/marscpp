//
// Created by zh on 2020/7/29.
//

#ifndef MARSC___UT_ARRAY_STACK_H
#define MARSC___UT_ARRAY_STACK_H
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct array_stack{
    int _top;
    int _capacity;
    int* _array;

} array_stack ;

array_stack* create_stack(int stack_capacity);
void delete_stack(array_stack* stack);
bool is_stack_empty(array_stack* stack);
bool is_stack_full(array_stack* stack);
bool  top(array_stack* stack,int* dst);
bool  push(array_stack* stack,int data);
bool  pop(array_stack* stack,int* dst);



#ifdef __cplusplus
}
#endif

#endif //MARSC___UT_ARRAY_STACK_H
