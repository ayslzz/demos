// Given a sorted linked list, delete all duplicates such that each element appear only once.

// Example 1:

// Input: 1->1->2
// Output: 1->2
// Example 2:

// Input: 1->1->2->3->3
// Output: 1->2->3

struct ListNode
{
    struct ListNode *next;
    int val;
};

// 当需要涉及修改头指针的时候，一般使用二级指针指向头指针的地址，或者使用dummy node指向头节点

struct ListNode* deleteDuplicates_2(struct ListNode* head) {
    struct ListNode *cur;

    cur = head;
    while (cur) {
        if (cur->next && cur->next->val == cur->val) {
            struct ListNode *tmp;

            tmp = cur;
            while (tmp && tmp->val == cur->val)
                tmp = tmp->next;

            cur->next = tmp;
        }
        cur = cur->next;
    }

    return head;
}

struct ListNode* deleteDuplicates(struct ListNode *head) {
    struct ListNode *cur = head;

    while (cur && cur->next) {
        if (cur->val == cur->next->val) {
            struct ListNode *tmp;
            tmp = cur->next->next;
            free(cur->next);
            cur->next = tmp;
        }
        cur = cur->next;
    }

    return head;
}

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