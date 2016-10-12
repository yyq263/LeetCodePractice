/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *tmpl1 = l1, *tmpl2 = l2;
    struct ListNode *retNode = NULL, **next, *last = NULL;
    int val1 = 0, val2 = 0, val3 = 0, C = 0;

    while(tmpl1 != NULL || tmpl2 != NULL)
    {
        if(tmpl1 == NULL)
            val1 = 0;
        else
        {
            val1 = tmpl1->val;
            tmpl1 = tmpl1->next;
        }

        if(tmpl2 == NULL)
            val2 = 0;
        else
        {
            val2 = tmpl2->val;
            tmpl2 = tmpl2->next;
        }

        if ((val3 = val1 + val2 + C) >= 10)
        {
            val3 = val3 % 10;
            C = 1;
        }
        else
        {
            C = 0;
        }

        last = (struct ListNode *)malloc(sizeof(struct ListNode));
        memset(last, 0, sizeof(struct ListNode));
        last->val = val3;
        last->next = NULL;

        if(retNode == NULL) // retNode: Head Node.
        {
            retNode = last;
            next = &(retNode->next);
        }
        else
        {
            *next = last;
            next = &(last->next);
        }
    }

    if (C == 1)
    {
        last = (struct ListNode *)malloc(sizeof(struct ListNode));
        memset(last, 0, sizeof(struct ListNode));
        last->val = C;
        last->next = NULL;
        *next = last;
    }

    return retNode;

}
