//
// Created by zh on 2020/7/29.
//

#include "ut_ptr_stack.h"
#include <stdlib.h>
ptr_stack* create_stack(){
    return NULL;
}
void delete_stack(ptr_stack * stack){
    while (stack){
        ptr_stack * next = stack->next;
        free(stack);
        stack=next;
    }
}
bool is_stack_empty(ptr_stack * stack){
    return stack==NULL;
}

bool  top(ptr_stack * stack,int* dst){
    if(stack){
        *dst = stack->data;
        return true
    }
    return false;

}
bool  push(ptr_stack ** stack,int data){
    //头插法
    ptr_stack * node = (ptr_stack*)malloc(sizeof(ptr_stack));
    node->data=data;
    node->next = *stack;
    *stack=node;
    return true;

}
bool  pop(ptr_stack ** stack,int* dst){
    if(is_stack_empty(*stack)){return false;}
    *dst=(*stack)->data;
    ptr_stack* next=(*stack)->next;
    free(*stack);
    *stack=next;

    return true;


}