/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* struct ListNode* compareTwoLists(struct ListNode* p, struct ListNode* q) { */

/*     struct ListNode* tmp, *deletedNode, *cand1 = p, *cand2 = q, **next; */
/*     int isHead = 1; */
/*     struct ListNode* head = NULL; */

/*     //printf("tmp->val = %d\n", p->val); */
/*     while(cand1 != NULL && cand2 != NULL) */
/*     { */
/*         tmp = (struct ListNode*)malloc(sizeof(struct ListNode)); // create a new node */
/*         if(isHead) // if it is head, it is head. */
/*         { */
/*             head = tmp; */
/*             isHead = 0; */
/*         } */
/*         else // if it is not head, append it to the last node. */
/*         { */
/*             *next = tmp; */
/*         } */
/*         if (cand1->val < cand2->val) */
/*         { */
/*             tmp->val = cand1->val; */
/*             //printf("tmp->val = %d\n", tmp->val); */
/*             next = &(tmp->next); // remember 'next' pointer */
/*             deletedNode = cand1; */
/*             cand1 = cand1->next; */
/*         } */
/*         else */
/*         { */
/*             tmp->val = cand2->val; */
/*             //printf("tmp->val = %d\n", tmp->val); */
/*             next = &(tmp->next); */
/*             deletedNode = cand2; */
/*             cand2 = cand2->next; */
/*         } */

/*         free(deletedNode); */
/*         deletedNode = NULL; */
/*     } */

/*     if (cand1 != NULL) */
/*     { */
/*         if (head == NULL) // be careful to the empty list... */
/*         { */
/*             head = cand1; */
/*         } */
/*         else */
/*             *next = cand1; */
/*     } */
/*     else if (cand2 != NULL) */
/*     { */
/*         if (head == NULL) */
/*         { */
/*             head = cand2; */
/*         } */
/*         else */
/*             *next = cand2; */
/*     } */

/*     return head; */
/* } */

/* struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) { */
/*     int i; */
/*     struct ListNode* ans; */

/*     if (listsSize == 0) */
/*         return NULL; */

/*     if (listsSize == 1) */
/*         return *lists; */

/*     ans = lists[0]; */
/*     for (i = 1; i < listsSize; i++ ) */
/*     { */
/*         //printf("i=%d\n",i); */
/*         ans = compareTwoLists(ans, lists[i]); */
/*     } */

/*     return ans; */

/* } */

struct ListNode* mergeTwoLists(struct ListNode* p, struct ListNode* q)
{
    struct ListNode* tmp, *deletedNode, **next;
    int isHead = 1;
    struct ListNode* head = NULL;
    
    while (p != NULL && q != NULL)
    {
        tmp = (struct ListNode*)malloc(sizeof(struct ListNode)); // create a new node
        if(isHead) // if it is head, it is head.
        {
            head = tmp;
            isHead = 0;
        }
        else // if it is not head, append it to the last node.
        {
            *next = tmp;
        }
        if (p->val < q->val)
        {
            tmp->val = p->val;
            //printf("tmp->val = %d\n", tmp->val);
            next = &(tmp->next); // remember 'next' pointer
            deletedNode = p;
            p = p->next;
        }
        else
        {
            tmp->val = q->val;
            //printf("tmp->val = %d\n", tmp->val);
            next = &(tmp->next);
            deletedNode = q;
            q = q->next;
        }

        free(deletedNode);
        deletedNode = NULL;
    }
    
    if (p != NULL)
    {
        if (head == NULL) // be careful to the empty list...
        {
            head = p;
        }
        else
            *next = p;
    }
    else if (q != NULL)
    {
        if (head == NULL)
        {
            head = q;
        }
        else
            *next = q;
    }
    return head;
    
}

struct ListNode* helper(struct ListNode** lists, int beg, int end) { // divide and conquer for the array of lists.
    int m = 0;
    if (beg < end)
    {
        m = (beg + end) / 2;
        return mergeTwoLists(helper(lists, beg, m), helper(lists, m+1, end)); 
    }
    return &lists[beg];
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int i;
    struct ListNode* ans;

    if (listsSize == 0)
        return NULL;

    if (listsSize == 1)
        return *lists;

    ans = merge(lists, 0, listsSize - 1);
    return ans;
}
