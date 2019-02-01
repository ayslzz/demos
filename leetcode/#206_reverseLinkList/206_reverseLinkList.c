// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
// Follow up:

// A linked list can be reversed either iteratively or recursively. Could you implement both?

struct ListNode
{
    struct ListNode *next;
    int val;
};

struct ListNode* _reverseList(struct ListNode *head)
{
    struct ListNode *cur, *next;

    cur = NULL;
    while (head) {
        next = head->next;
        head->next = cur;
        cur = head;
        head = next;
    }

    return cur;
}

// non tail-recursive
struct ListNode *recursion(struct ListNode *head)
{
    struct ListNode *new_head;
    
    if (!head || !(head->next))
        return head;
    new_head = recursion(head->next);
    // 由于递归中，如果只剩下一个节点，则不会修改next指针，所以需要修改逆置后的链表的倒数第二个节点的next指针
    // 并且head->next还是指向这个倒数第二个节点，所以通过head->next->next修改指向head，
    // 然后把head->next指向NULL，因为这时head是最后一个节点
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

struct ListNode *reverse_recursion(struct ListNode **head)
{
    *head = recursion(*head);
    return *head;
}

struct ListNode *tail_recursion(struct ListNode *head, struct ListNode *reversed)
{
    struct ListNode *cur;

    if (!head)
        return reversed;
    
    cur = head;
    head = head->next;
    cur->next = reversed;
    return tail_recursion(head, cur);
}

struct ListNode *reverse_tail_recursion(struct ListNode **head)
{
    *head = tail_recursion(*head, NULL);
    return *head;
}