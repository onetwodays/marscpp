//
// Created by zh on 2020/7/29.
//
#include "ut_dynarray_stack.h"
#include <stdlib.h>
#include <string.h>
dynarray_stack* create_stack(int init_capacity){
    dynarray_stack* stack = (dynarray_stack*) malloc(sizeof(dynarray_stack));
    if(stack==NULL){
        return NULL;
    }
    memset((stack,0,sizeof(dynarray_stack)));

    stack->_top=-1;
    stack->_capacity=init_capacity;

    if(init_capacity!=0){
        stack->_array = (int*)malloc(init_capacity*sizeof(int));
        if(stack->_array==NULL){
            free(stack);
            return NULL;
        }
        memset(stack->_array,0,init_capacity*sizeof(int));

    }

}
dynarray_stack* create_double_stack(dynarray_stack* stack){
    //extern void *realloc(void *mem_address, unsigned int newsize);
    //先判断当前的指针是否有足够的连续空间，如果有，扩大mem_address指向的地址，并且将mem_address返回，
    // 如果空间不够，先按照newsize指定的大小分配空间，将原有数据从头到尾拷贝到新分配的内存区域，
    // 而后释放原来mem_address所指内存区域（注意：原来指针是自动释放，不需要使用free），
    // 同时返回新分配的内存区域的首地址。即重新分配存储器块的地址
    stack->_capacity*=2;
    stack->_array=realloc(stack->_array,stack->_capacity*sizeof(int));
    if(stack->_array==NULL){
        delete_stack(stack);
    }
    return stack;

}

void delete_stack(dynarray_stack* stack){
    if(stack){
        if(is_stack_empty(stack)==false){
            free(stack->_array);
            stack->_array=NULL;
        }
        stack->_top=-1;
        free(stack);
    }
}
bool is_stack_empty(dynarray_stack* stack){
    if(stack){
        return stack->_top==-1;
    }
    return true;

}
bool is_stack_full(dynarray_stack* stack){
    if(stack){
        return stack->_top==(stack->_capacity-1);
    }
    return true;

}
bool top(dynarray_stack* stack,int* dst){
    if(is_stack_empty(stack)) return false;
    *dst=stack->_array[stack->_top];
    return true;
}


bool push(dynarray_stack* stack,int data){
    if(is_stack_full(stack)){
        stack=create_double_stack(stack);
    }
    stack->_top++;
    stack->_array[stack->_top]=data;
    return true;

}
bool pop(dynarray_stack* stack,int* dst){
    if(is_stack_empty(stack)) return false;
    *dst = stack->_array[stack->_top];
    stack->_top--;
    return true;

}