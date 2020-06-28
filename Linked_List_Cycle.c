#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Definition for singly-linked list.
struct _ListNode {
    int val;
    struct _ListNode *next;
};

typedef struct _ListNode ListNode;

bool hasCycle( ListNode *head) {
    
    if (head == NULL) {
        return false;
    }
    ListNode *l1 ;
    l1 = head;
    ListNode *l2 ;
    l2=head->next;

    while (l1 != NULL && l2 != NULL && l2->next != NULL) {
        if (l1 == l2) {
            return true;
        }
        l1 = l1->next;
        l2 = l2->next->next;
    }
    return false;
}

int main()
{
    ListNode *head;
    head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *input1;
    input1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode *input2;
    input2 = (ListNode*)malloc(sizeof(ListNode));
    ListNode *input3;
    input3 = (ListNode*)malloc(sizeof(ListNode));
    
    head->val = 3;
    head->next = input1;

    input1->val = 2;
    input1->next = input2;

    input2->val = 0;
    input2->next = input3;
    
    input3->val = -4;
    input3->next = input1;
   
    bool ret = hasCycle( head);
    if(ret==true)
        printf("true\n");
    else
        printf("false\n");

    // ListNode *input4;
    // input4 = (ListNode*)malloc(sizeof(ListNode));
    // head->val = 3;
    // head->next = input1;

    return 0;
}
