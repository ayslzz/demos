struct ListNode
{
    struct ListNode *next;
    int val;
};

struct ListNode* deleteDuplicates(struct ListNode *head) {
    struct ListNode *cur, *prev, *dummy;
    struct ListNode *new_head, *start, *end, *p_next;

    if (!head)
        return head;

    dummy = malloc(sizeof(*dummy));
    if (!dummy)
        return head;

    dummy->next = head;
    prev = dummy;
    cur = head;

    while (cur) {
        while (cur->next && cur->val == cur->next->val) {
            cur = cur->next;
        }
        if (prev->next == cur) {
            prev = prev->next;
            cur = cur->next;
        }
        else {
            start = prev->next;
            end = cur->next;
            prev->next = cur->next;
            cur = cur->next;
            while (start != end) {
                p_next = start->next;
                free(start);
                start = p_next;
            }
        }
    }

    new_head = dummy->next;
    free(dummy);

    return new_head;
}