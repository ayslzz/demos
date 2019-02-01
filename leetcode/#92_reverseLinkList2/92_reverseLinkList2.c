// Reverse a linked list from position m to n. Do it in one-pass.

// Note: 1 ≤ m ≤ n ≤ length of list.

// Example:

// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL

struct ListNode
{
    struct ListNode *next;
    int val;
};

struct ListNode* reverseBetween(struct ListNode *head, int m, int n) {
    int i;
    struct ListNode *prev, *cur, dummy;

    if (m >= n || n <= 0)
        return head;

    dummy.next = head;
    prev = &dummy;

    for (i = 1; i < m; i++) {
        prev = prev->next;
    }

    cur = prev->next;
    // cur就是要翻转的这段链表的最后一个节点，cur->next总是要前插到prev->next的节点，
    // 所以cur保持不动，cur->next的节点往前插入
    for (i = 0; i < n - m && cur->next; i++) {
        struct ListNode *move;
        move = cur->next;
        cur->next = move->next;
        move->next = prev->next;
        prev->next = move;
    }
    return dummy.next;
}
