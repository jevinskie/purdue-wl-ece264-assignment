#ifndef LINKLIST_H
#define LINKLIST_H

/* This module implements double linked list with a dummy node.
   The dummy node is identified by its p_previous as NULL. */

typedef struct tagListNode
{
  struct tagListNode * p_prev;  /* Pointer to previous node, NULL for dummy */
  struct tagListNode * p_next;  /* Pointer to next node, NULL for tail */
  void * p_data;  /* Pointer to data block */
} *LinkList, ListNode;


ListNode * ListNode_Construct(void * data);
void ListNode_Destruct(ListNode * node, void (*destructor)(void *));
LinkList LinkList_Construct();
ListNode * LinkList_Append(LinkList list, void * data);
ListNode * LinkList_Insert(LinkList list, int position, void * data);
void * LinkList_Remove(LinkList list, int position);
ListNode * LinkList_GetNode(LinkList list, int index);
void * LinkList_SetData(LinkList list, int index, void * data);
ListNode * LinkList_GetLastNode(LinkList list);
void LinkList_Destruct(LinkList list, void (*destructor)(void *));
void LinkList_Reverse(LinkList list);

#endif
