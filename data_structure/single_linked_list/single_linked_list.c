#include <stdio.h>
#include <stdlib.h>

struct list_node
{
    struct list_node *next;
    int data;
};

struct list_node* new_node(int data)
{
    struct list_node *node;

    node = malloc(sizeof(*node));
    if (node) {
        node->next = NULL;
        node->data = data;
    }
    return node;
}

struct list_node* add(struct list_node **head, int data)
{
    struct list_node *node, **p;

    node = new_node(data);
    if (!node)
        return *head;

    p = head;
    node->next = *p;
    *p = node;

    return *head;
}

struct list_node* append(struct list_node **head, int data)
{
    struct list_node *node, **p;

    node = new_node(data);
    if (!node)
        return *head;
    
    p = head;
    while (*p) {
        p = &((*p)->next);
    }
    *p = node;

    return *head;
}

struct list_node* list_remove(struct list_node **head, int index)
{
    int i;
    struct list_node **p, *node;

    assert(head);

    p = head;
    for (i = 0; i < index && *p; i++) {
        p = &((*p)->next);
    }

    if (i < index || index < 0)
        return *head;

    node = *p;
    *p = (*p)->next;
    free(node);

    return *head;
}

void traverse(struct list_node *head)
{
    struct list_node *cur = head;

    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    printf("\n");
}

void destroy(struct list_node *head)
{
    struct list_node *cur = head;
    struct list_node *p_next;

    while (cur) {
        p_next = cur->next;
        free(cur);
        cur = p_next;
    }
}

int main()
{
    int arr[] = {1,3,5,7,9};
    int i;
    struct list_node *alist;

    alist = NULL;
    for (i = 0; i < sizeof(arr)/sizeof(*arr); i++) {
        add(&alist, arr[i]);
    }
    traverse(alist);
    destroy(alist);

    return 0;
}