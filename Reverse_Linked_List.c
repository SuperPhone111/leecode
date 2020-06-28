#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *newhead=NULL;
    struct ListNode *tmpnode=NULL;
    
    while(head)
    {
        tmpnode = head->next;
        head->next = newhead;
        newhead = head;
        head = tmpnode;
    }
   return newhead;
}

int main()
{


    return 0;
}
