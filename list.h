#ifndef LIST_H
#define LIST_H

#include "common.h"

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct List
{
    Node *front;
    Node *rear;
    char name[20];
    U8 size;
} List;

static inline void init_list(List *l, char *name)
{
    l->front = NULL;
    l->rear = NULL;
    l->size = 0;
    strncpy(l->name, name, sizeof(l->name));
}

static inline void push_list(List *l, U32 data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (l->rear == NULL)
    {
        l->front = l->rear = newNode;
    }
    else
    {
        l->rear->next = newNode;
        l->rear = newNode;
    }
    l->size++;
}

static inline U32 pop_list(List *l)
{
    if (l->front == NULL)
    {
        return NOTHING;
    }

    Node *temp = l->front;
    U32 value = temp->data;

    l->front = l->front->next;
    if (l->front == NULL)
    {
        l->rear = NULL;
    }

    free(temp);
    l->size--;
    return value;
}

static inline U8 isEmpty(List *l)
{
    return l->size == 0;
}

static inline void remove_list(List *l, U32 data)
{
    if (isEmpty(l))
        return;

    Node *current = l->front;
    Node *prev = NULL;

    while (current != NULL)
    {
        if (current->data == data)
        {
            // 要刪除的是 front
            if (prev == NULL)
            {
                l->front = current->next;
                if (l->front == NULL)
                {
                    l->rear = NULL; // 也把 rear 設為 NULL（空清單）
                }
            }
            else
            {
                prev->next = current->next;

                // 如果刪的是尾巴
                if (current == l->rear)
                {
                    l->rear = prev;
                }
            }

            free(current);
            l->size--;
            return; // 找到就刪除並離開（只刪第一個匹配）
        }

        prev = current;
        current = current->next;
    }
}

static inline void free_list(List *l)
{
    while (!isEmpty(l))
    {
        pop_list(l);
    }
}

static inline U8 search_list(List *l, U32 data)
{
    Node *current = l->front;
    while (current != NULL)
    {
        if (current->data == data)
        {
            return TRUE;
        }
        current = current->next;
    }
    return FALSE;
}

#endif