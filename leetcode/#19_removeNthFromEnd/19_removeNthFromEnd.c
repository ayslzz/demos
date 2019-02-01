struct ListNode
{
    struct ListNode *next;
    int val;
};

struct ListNode *removeNthfromEnd(struct ListNode *head, int n)
{
    struct ListNode *fast, **slow;

    // 这里low没有直接指向第一个节点，而是head指针的地址
    fast = head;
    slow = &head;
    
    // 循环n次，让fast领先n个节点
    while (n--) {
        fast = fast->next;
    }

    // 如果不执行此循环，那么此时low就是head的地址，
    // 通过*low直接修改head的值，为head->next
    // 如果执行了此循环，那么此时low就是被删元素的前驱节点的next指针的地址
    // 那么*low就是被删除元素，修改*low就戳修改前驱节点的next的值，为被删节点的next节点
    while (fast) {
        fast = fast->next;
        slow = &((*slow)->next);
    }

    *slow = (*slow)->next;

    return head;
}

struct ListNode *removeNthfromEnd(struct ListNode *head, int n)
{
    int i;
    struct ListNode *fast, **slow;

    if (n <= 0)
        return head;

    // 这里low没有直接指向第一个节点，而是head指针的地址
    fast = head;
    slow = &head;
    
    // 循环n次，让fast领先n个节点
    // 如果循环不够n次，fast为NULL，表示指定的n值比链表长度还长
    for (i = 0; i < n && fast; i++) {
        fast = fast->next;
    }

    if (n > 0)
        return head;

    // 如果不执行此循环，那么此时low就是head的地址，
    // 通过*low直接修改head的值，为head->next
    // 如果执行了此循环，那么此时low就是被删元素的前驱节点的next指针的地址
    // 那么*low就是被删除元素，修改*low就戳修改前驱节点的next的值，为被删节点的next节点
    while (fast) {
        fast = fast->next;
        slow = &((*slow)->next);
    }

    *slow = (*slow)->next;

    return head;
}