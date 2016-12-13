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
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int length;
    int i;
    struct ListNode* tail;
    struct ListNode** next;
    struct ListNode* newHead;

    if (head == NULL)
        return NULL;
    
    length = 0;
    for(tail = head; tail != NULL; tail = tail->next)
    {
        next = &(tail->next);
        length++;
    }

    k = k % length;

    if (k == 0)
        return head;

    tail = head;
    for (i = 1; i < length - k - 1; i++)
    {
        tail = tail->next;
    }
    newHead = tail->next;
    tail->next = NULL;
    *next = head;
    
    return newHead;
}
