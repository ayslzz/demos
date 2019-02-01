// Given a linked list and a value x, partition it such that
// all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// Example:

// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5

struct ListNode
{
    struct ListNode *next;
    int val;
};

// 建立两个链表，一个链表存储小于x的节点，另一个链表存储大于等于x的节点，然后将两个链表join

struct ListNode* partition(struct ListNode *head, int x) 
{
    struct ListNode left, right, *l, *r;

    l = &left;
    r = &right;
    while (head) {
        if (head->val < x) {
            l->next = head;
            l = l->next;
        }
        else {
            r->next = head;
            r = r->next;
        }
        head = head->next;
    }
    // join
    r->next = NULL;
    left.next = right.next;
    return left.next;
}