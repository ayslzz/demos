// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

// Note: Do not modify the linked list.

struct ListNode
{
    struct ListNode *next;
    int val;
};

// 假设环入口距离链表头的长度为L，快慢指针相遇的位置为cross，且该位置距离环入口的长度为S。
// 考虑快慢指针移动的距离，慢指针走了L+S，快指针走了L+S+nR(这是假设相遇之前快指针已经绕环n圈)。
// 由于快指针的速度是慢指针的两倍，相同时间下快指针走过的路程就是慢指针的两倍，所以有2(L+S)=L+S+nR，化简得L+S=nR
// 当n=1
// n=1时，即快指针在相遇之前多走了一圈，即L+S=R，也就是L=R−S，
// 观察图片，L表示从链表头到环入口的距离，而R−S表示从cross继续移动到环入口的距离，
// 既然二者是相等的，那么如果采用两个指针，一个从表头出发，一个从cross出发，那么它们将同时到达环入口。即二者相等时便是环入口节点

// 当n>1
// n>1时，上式为L=nR−S，L仍然表示从链表头到达环入口的距离，
// 而nR−S可以看成从cross出发移动nR步后再倒退S步，从cross移动nR步后回到cross位置，倒退S步后是环入口，
// 所以也是同时到达环入口。即二者相等时便是环入口节点

// 所以寻找环入口的方法就是采用两个指针，一个从表头出发，一个从相遇点出发，一次都只移动一步，当二者相等时便是环入口的位置

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow, *fast;

    slow = fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

// 计算环的长度，通过找到的环的位置，让指针再走一圈
int cycleLen(struct ListNode* head)
{
    struct ListNode *cycleIn = detectCycle(head);
    int len = 1;
    struct ListNode *walker = cycleIn;

    while(walker->next != cycleIn) {
        len++;
        walker = walker->next;
    }
    return len;
}

// 计算环的长度，快慢指针相遇后，再各自走一圈，再次相遇后就是环的长度
int cycleLen(struct ListNode* head)
{
    struct ListNode* walker = head;
    struct ListNode* runner = head;
    while(runner && runner->next) {
        walker = walker->next;
        runner = runner->next;
        if(walker == runner)
            break;
    }
    int len = 0;
    while(runner && runner->next) {
        len++;
        walker = walker->next;
        runner = runner->next;
        if(walker == runner)
            break;
    }
    return len;
}