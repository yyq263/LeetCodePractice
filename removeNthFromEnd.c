/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int i;
    int listSize = 0;
    struct ListNode* last;
    struct ListNode* predecessor;

    for (last = head; last != NULL; last = last->next)
    {
        listSize++;
    }
    
    if (listSize == 1)
        return NULL;

    if (n == listSize)
        return head->next;

    predecessor = head;
    for (i = 1; i < listSize - n; i++ ) {
        predecessor = predecessor->next;
    }

    predecessor->next = predecessor->next->next;
    
    return head;
}
