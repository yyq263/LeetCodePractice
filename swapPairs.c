#include<stdlib.h>
#include<string.h>
#include<stdio.h>



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    int i;
    struct ListNode* tmp;
    struct ListNode* pre, *c, *d, *tmp2, *tmp3;

    if (head == NULL || head->next == NULL)
        return head;

    //a-->b-->c-->d-->e
    tmp = head->next; // a & b
    head->next = head->next->next;
    tmp->next = head; // tmp becomes top

    pre = tmp->next; // b
    while(pre->next != NULL && pre->next->next != NULL)
    {
        c = pre->next;
        d = pre->next->next;
        tmp2 = c; //store c and e
        tmp3 = d->next;
        pre->next = d; // delete c: a-->b-->d-->e
        d->next = tmp2; // link c to d: a-->b-->d-->c
        d->next->next = tmp3; //link e to c: a-->b-->d-->c-->e
        pre = d->next; //pre = c
    }
    return tmp;

}

