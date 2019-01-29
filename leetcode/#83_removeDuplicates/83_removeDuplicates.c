struct ListNode
{
    struct ListNode *next;
    int val;
};

struct ListNode* deleteDuplicates(struct ListNode *head) {
    struct ListNode *slow, *fast, *p_next;

    if (!head || !head->next)
        return head;

    slow = head;
    fast = head->next;

    while (fast) {
        p_next = fast->next;
        if (slow->val == fast->val) {
            slow->next = p_next;
            free(fast);
        }
        else {
            slow = slow->next;
        }
        fast = p_next;
    }

    return head;
}