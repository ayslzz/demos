// Given a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers from the original list.

// Example 1:

// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
// Example 2:

// Input: 1->1->1->2->3
// Output: 2->3

struct ListNode
{
    struct ListNode *next;
    int val;
};

// 当需要涉及修改头指针的时候，一般使用二级指针指向头指针的地址，或者使用dummy node指向头节点

struct ListNode* deleteDuplicates(struct ListNode *head) {
    struct ListNode **cur;

    if (!head || !head->next)
        return head;

    cur = &head;
    while (*cur) {
        // 有相邻节点值相同，固定当前指针
        if ((*cur)->next && (*cur)->next->val == (*cur)->val) {
            struct ListNode *tmp_next, *tmp;
            tmp = *cur;
            // 通过临时指针，接着遍历，直到找到和当前固定指针所指节点值不同的节点
            while (tmp && (*cur)->val == tmp->val) {
                tmp = tmp->next;
            }
            // 如果需要释放内存，则遍历，如果不需要，直接 *cur = tmp
            while (*cur != tmp) {
                tmp_next = (*cur)->next;
                free(*cur);
                *cur = tmp_next;
            }
        } 
        else {
            // 这里cur变成了当前指针的next域的地址，
            // 因为除了修改头指针，其他情况，我们都只需要修改当前节点的next域
            cur = &((*cur)->next);
        }
    }
    return head;
}

// 第一次的代码
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