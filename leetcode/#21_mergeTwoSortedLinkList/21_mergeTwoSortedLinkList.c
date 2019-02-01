// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4


struct ListNode
{
    struct ListNode *next;
    int val;
};

struct ListNode* mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
}

struct ListNode* mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode **prev, *head = NULL;

    if (!l1)
        return l2;
    if (!l2)
        return l1;

    prev = &head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            *prev = l1;
            l1 = l1->next;
        }
        else {
            *prev = l2;
            l2 = l2->next;
        }
        prev = &((*prev)->next);
    }
    *prev = !l1 ? l2 : l1;

    return head;
}