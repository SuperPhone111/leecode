#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct  __attribute__((aligned(16))) _sNode{
    int data;                                                                          
    struct _sNode *next;                                                              
} sNode;                                                                               

typedef struct {
    sNode *stack1;
    sNode *stack2;
} MyQueue;

/** Initialize your data structure here. */
void push(sNode** top_ref, int new_data)
{
    sNode *new_node = (sNode*)malloc(sizeof(sNode));
    if(new_node == NULL)
    {
        printf("stack overflow\n");
        getchar();
        exit(0);
    }
    new_node -> data = new_data; 
    new_node -> next = *top_ref;
    *top_ref = new_node; 
}

int pop(sNode** top_ref) 
{
    int res;
    sNode *top;
    
    if(*top_ref == NULL)
    {
        printf("Stack underflow\n");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

MyQueue* myQueueCreate() {
    MyQueue *obj = (MyQueue*)malloc(sizeof(MyQueue));
    sNode *stack1 = NULL;
    sNode *stack2 = NULL;
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    push(&obj->stack1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    
    int temp;
    
    if(obj->stack1 == NULL && obj->stack2 == NULL)
    {
        printf("Q is empty\n");
        getchar();                                                                     
        exit(0);
    }
    
    if(obj->stack2 == NULL)
    {
        while(obj->stack1 != NULL)
        {
            temp = pop(&obj->stack1); 
            push(&obj->stack2, temp);
        }
    }
    temp =  pop(&obj->stack2);
    
    return temp;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
   
    int temp;

    if(obj->stack2 != NULL)
    {
        while(obj->stack1 != NULL)
        {
            temp = pop(&obj->stack1); 
            push(&obj->stack2, temp);
        }
    }
    
    return obj->stack2->data;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    
    if(obj->stack1 == NULL && obj->stack2 == NULL)
    {
        printf("Q is empty\n");
        return false;
    }
    else
    {
        return true;
    }
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
int main()
{
    MyQueue *obj;
    obj = myQueueCreate(obj);   
    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    myQueuePush(obj, 3);

    printf("%d ",myQueuePop(obj));
    printf("%d ",myQueuePop(obj));
    printf("%d ",myQueuePop(obj));

    sNode *temp;
    temp = (sNode*)malloc(sizeof(sNode));
    printf("%ld\n",sizeof(temp->next));
    return 0;
}
/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
