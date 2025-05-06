#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
/* General q_insert marco */
#define q_insert(head, s, fn)                       \
    ({                                              \
        if (!head || !s)                            \
            return false;                           \
        size_t len = strlen(s);                     \
        element_t *ele = malloc(sizeof(element_t)); \
        char *str = malloc(len + 1);                \
        if (!ele || !str) {                         \
            free(ele);                              \
            free(str);                              \
            return false;                           \
        }                                           \
        strncpy(str, s, len);                       \
        str[len] = '\0';                            \
        ele->value = str;                           \
        INIT_LIST_HEAD(&ele->list);                 \
        fn(&ele->list, head);                       \
        return true;                                \
    })
/* General q_remove marco */
#define q_remove(head, sp, bufsize, direction)                         \
    ({                                                                 \
        if (!head || list_empty(head))                                 \
            return NULL;                                               \
        element_t *ele = list_entry(head->direction, element_t, list); \
        list_del_init(&ele->list);                                     \
        if (sp) {                                                      \
            strncpy(sp, ele->value, bufsize - 1);                      \
            sp[bufsize - 1] = '\0';                                    \
        }                                                              \
        return ele;                                                    \
    })

/* Create an empty queue */
struct list_head *q_new()
{
    struct list_head *head = malloc(sizeof(struct list_head));
    if (!head)
        return NULL;
    INIT_LIST_HEAD(head);
    return head;
}

/* Free all storage used by queue */
void q_free(struct list_head *head)
{
    if (!head)
        return;

    element_t *entry, *safe;
    list_for_each_entry_safe(entry, safe, head, list) {
        q_release_element(entry);
    }
    free(head);
}

/* Insert an element at head of queue */
bool q_insert_head(struct list_head *head, char *s)
{
    q_insert(head, s, list_add);
}

/* Insert an element at tail of queue */
bool q_insert_tail(struct list_head *head, char *s)
{
    q_insert(head, s, list_add_tail);
}

/* Remove an element from head of queue */
element_t *q_remove_head(struct list_head *head, char *sp, size_t bufsize)
{
    q_remove(head, sp, bufsize, next);
}

/* Remove an element from tail of queue */
element_t *q_remove_tail(struct list_head *head, char *sp, size_t bufsize)
{
    q_remove(head, sp, bufsize, prev);
}

/* Return number of elements in queue */
int q_size(struct list_head *head)
{
    if (!head)
        return 0;
    int cnt = 0;
    struct list_head *dummy;
    list_for_each(dummy, head)
        cnt++;
    return cnt;
}

/* Delete the middle node in queue */
bool q_delete_mid(struct list_head *head)
{
    // https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
    return true;
}

/* Delete all nodes that have duplicate string */
bool q_delete_dup(struct list_head *head)
{
    // https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
    return true;
}

/* Swap every two adjacent nodes */
void q_swap(struct list_head *head)
{
    // https://leetcode.com/problems/swap-nodes-in-pairs/
}

/* Reverse elements in queue */
void q_reverse(struct list_head *head) {}

/* Reverse the nodes of the list k at a time */
void q_reverseK(struct list_head *head, int k)
{
    // https://leetcode.com/problems/reverse-nodes-in-k-group/
}

/* Sort elements of queue in ascending/descending order */
void q_sort(struct list_head *head, bool descend) {}

/* Remove every node which has a node with a strictly less value anywhere to
 * the right side of it */
int q_ascend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Remove every node which has a node with a strictly greater value anywhere to
 * the right side of it */
int q_descend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Merge all the queues into one sorted queue, which is in ascending/descending
 * order */
int q_merge(struct list_head *head, bool descend)
{
    // https://leetcode.com/problems/merge-k-sorted-lists/
    return 0;
}
