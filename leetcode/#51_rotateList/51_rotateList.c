// Given a linked list, rotate the list to the right by k places, where k is non-negative.

struct ListNode
{
    struct ListNode *next;
    int val;
};

// 这个题要注意k的范围，先求出链表长度len，然后 k %= len，求出合法k值
// 在遍历链表时，若伴随带有下标的循环，那么cur的初始值是头结点的话，指针的变化就和下标的变化一致了

// 第一次想到的方案，使用快慢指针
struct ListNode* rotateRight(struct ListNode *head, int k)
{
    int total_len = 0;
    struct ListNode *fast, *slow, *p;

    p = head;
    while (p) {
        p = p->next;
        total_len++;
    }

    fast = slow = head;
    k = k % total_len;
    while (k--) {
        fast = fast->next;
    }

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    fast->next = head;
    head = slow->next;
    slow->next = NULL;

    return head;
}

// leetcode上票数最高的方案，将单链表成环
struct ListNode* rotateRight_2(struct ListNode *head, int k)
{
    int i;
    int total_len = 1;
    struct ListNode *tail, *new_head;

    if (!head)
        return head;

    tail = head;
    // 找到尾节点，这时计算的链表长度比实际少1，所以total_len赋初值为1
    while (tail->next) {
        tail = tail->next;
        total_len++;
    }

    // 将单链表成环
    tail->next = head;
    k %= total_len;
    // 找到新链表的尾节点
    for (i = 0; i < total_len - k; i++) {
        tail = tail->next;
    }
    new_head = tail->next;
    tail->next = NULL;

    return new_head;
}