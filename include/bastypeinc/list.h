
#ifndef _LIST_H
#define _LIST_H

/* List Init */
static inline void listInit(list_h_t *list) {
    list->prev = list;
    list->next = list;
    return;
}

/* List Delete */
static inline void __listDel(list_h_t *prev, list_h_t *next) {
    next->prev = prev;
    prev->next = next;
    return;
}

static inline void __listDelEntry(list_h_t *entry) {
    __listDel(entry->prev, entry->next);
    return;
}

static inline void listDel(list_h_t *entry) {
    __listDel(entry->prev, entry->next);
    listInit(entry);
    return;
}

/* List Add */
static inline void __listAdd(list_h_t *list, list_h_t *prev, list_h_t *next) {
    next->prev = list;
    list->next = next;
    list->prev = prev;
    prev->next = list;
    return;
}

static inline void listAdd(list_h_t *list, list_h_t *head) {
    __listAdd(list, head, head->next);
    return;
}

static inline void listAddTail(list_h_t *list, list_h_t *head) {
    __listAdd(list, head->prev, head);
    return;
}

/* List Move */
static inline void listMove(list_h_t *list, list_h_t *head) {
    listDel(list);
    listAdd(list, head);
    return;
}

static inline void listMoveTail(list_h_t *list, list_h_t *head) {
    listDel(list);
    listAddTail(list, head);
    return;
}

/* List is Empty */

static inline bool_t listIsEmpty(list_h_t *head) {
    if (head == head->next) {
        return TRUE;
    }
    return FALSE;
}

static inline bool_t listIsEmptyCareful(list_h_t *head) {
    list_h_t *list = head->next;
    if (list == head && list == head->prev) {
        return TRUE;
    }
    return FALSE;
}

#define listForEach(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define listForEachHeadDell(pos, head) \
    for (pos = (head)->next; pos != (head); pos = (head)->next)

#define listEntry(ptr, type, member) \
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

#endif
