//
// Created by zh on 2020/7/29.
//

#include "ut_array_stack.h"
#include <stdlib.h> //malloc head
#include <string.h> //memset head
array_stack* create_stack(int stack_capacity){
    if(stack_capacity==0){
        return NULL;
    }

    array_stack* stack = (array_stack*)malloc(sizeof(array_stack));
    if(!stack) return NULL;
    memset(stack,0,sizeof(array_stack));
    stack->_top=-1;
    stack->_capacity=stack_capacity;

    stack->_array = (int*)malloc(stack->_capacity*sizeof(int));
    if(stack->_array==NULL) {
        free(stack);
        stack=NULL;
        return NULL;
    }
    return stack;


}
bool is_stack_empty(array_stack* stack){
    if(stack){
        return  (stack->_top==-1);
    }
    return true;

}
bool is_stack_full(array_stack* stack){
    if(stack){
        return (stack->_top==stack->_capacity-1);
    }
    return true ;

}
bool  top(array_stack* stack,int* dst){
    if (is_stack_empty(stack)){
        return false;

    }else{
        *dst= stack->_array[stack->_top];
    }
    return true;

}
bool push(array_stack* stack,int data){
    if(is_stack_full(stack)) return false;
    stack->_top++;
    stack->_array[stack->_top]=data;
    return true;
}


bool  pop(array_stack* stack,int* data){
    if(is_stack_empty(stack)) return false;
    *data = stack->_array[stack->_top];
    stack->_top --;
    return true;
}

void delete_stack(array_stack* stack){
    if(stack){
        if(stack->_array){
            free(stack->_array);
            stack->_array=NULL;
            stack->_top=-1;
        }

        free(stack);
    }
}