
#ifndef _LIST_H
#define _LIST_H

typedef struct s_LIST_H {
    struct s_LIST_H *prev, *next;
} list_t;

/* List Init */
static inline void listInit(list_t *list) {
    list->prev = list;
    list->next = list;
    return;
}

/* List Delete */
static inline void __listDel(list_t *prev, list_t *next) {
    next->prev = prev;
    prev->next = next;
    return;
}

static inline void __listDelEntry(list_t *entry) {
    __listDel(entry->prev, entry->next);
    return;
}

static inline void listDel(list_t *entry) {
    __listDel(entry->prev, entry->next);
    listInit(entry);
    return;
}

/* List Add */
static inline void __listAdd(list_t *list, list_t *prev, list_t *next) {
    next->prev = list;
    list->next = next;
    list->prev = prev;
    prev->next = list;
    return;
}

static inline void listAdd(list_t *list, list_t *head) {
    __listAdd(list, head, head->next);
    return;
}

static inline void listAddTail(list_t *list, list_t *head) {
    __listAdd(list, head->prev, head);
    return;
}

/* List Move */
static inline void listMove(list_t *list, list_t *head) {
    listDel(list);
    listAdd(list, head);
    return;
}

static inline void listMoveTail(list_t *list, list_t *head) {
    listDel(list);
    listAddTail(list, head);
    return;
}

/* List is Empty */

static inline bool listIsEmpty(list_t *head) {
    if (head == head->next) {
        return true;
    }
    return false;
}

static inline bool listIsEmptyCareful(list_t *head) {
    list_t *list = head->next;
    if (list == head && next == head->prev) {
        return true;
    }
    return false;
}

#define listForEach(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define listForEachHeadDell(pos, head) \
    for (pos = (head)->next; pos != (head); pos = (head)->next)

#define listEntry(ptr, type, member) \
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

#endif
