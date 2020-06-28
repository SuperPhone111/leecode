#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct _ListNode {
    int val;
    struct _ListNode *next;
};

typedef struct _ListNode ListNode;

/* struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) { */
    
    // if (!headA || !headB) return NULL;
    // struct ListNode *ptr1 = headA, *ptr2 = headB;
    // while (ptr1 != ptr2) {
        // ptr1 = ptr1 ? ptr1->next : headB;
        // ptr2 = ptr2 ? ptr2->next : headA;
    // }
    // return ptr1;
/* } */


int main()
{
    ListNode *ptr1, *ptr2, *headB;
    headB = (ListNode*)malloc(sizeof(ListNode));
    ptr1 = (ListNode*)malloc(sizeof(ListNode));
    ptr2 = (ListNode*)malloc(sizeof(ListNode));
    ptr2->val=2;
    ptr2->next=NULL;
    // ptr1 = NULL;
    ptr1->val = 1;
    ptr1->next=ptr2;
    headB->val=99;
    headB->next=NULL;
    
    printf("headB=%p\n",headB);
    
    printf("ptr2=%p\n",ptr2);
    
    ptr1 = NULL;
    ptr1 = ptr1 ? ptr1->next : headB;
    
    printf("ptr1->val=%d\n",ptr1->val);
    if(ptr1 == headB)
        printf("true\n");
    if(ptr1 == ptr2)
        printf("true2\n");

    return 0;
}
