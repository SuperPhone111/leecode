#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
   int *stack;
   int top;
   int size;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {

    MyStack *obj = malloc(sizeof(MyStack));    
    obj->stack = calloc(100,sizeof(int));
    obj->top = 0;
    obj->size = 0;

    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->size++;
    obj->stack[obj->top];
    obj->top = (obj->top + 1) % 100;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    obj->size--;
    obj->top = (obj->top - 1) % 100;
    return obj->stack[obj->top]; 
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->stack[(obj->top - 1) % 100];  
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->size==0)return true;
    else return false;
}

void myStackFree(MyStack* obj) {
   free(obj); 
}

int main()
{


    return 0;
}
