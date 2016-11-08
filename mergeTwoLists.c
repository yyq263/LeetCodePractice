#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    struct ListNode* head = NULL;
    struct ListNode** last = &head;
    struct ListNode* tmp = NULL;
    
    // Find minimun of two lists in each loop
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val < l2->val)
        {
            tmp = (struct ListNode*)malloc(sizeof(struct ListNode)); 
            tmp->val = l1->val;
            *last = tmp;
            last = &((*last)->next);
            l1 = l1->next;
        }
        else 
        {
            tmp = (struct ListNode*)malloc(sizeof(struct ListNode)); 
            tmp->val = l2->val;
            *last = tmp;
            last = &((*last)->next);
            l2 = l2->next;
        }
    }
    
    if (l1 != NULL)
    {
        *last = l1;
    } else if (l2 != NULL)
    {
        *last = l2;
    }
    return head;

}


