#include "List.h"

ListNode* List::removeNthFromEnd(ListNode *head, int n)
{
  ListNode *p = head;  // slow point
  ListNode *q = head;  // fast point

  ListNode *pPre = NULL;

  if( !head )
    return NULL;

  for(int i=0; i<n-1; i++)
    q = q->next;

  while(q->next)
  {
    pPre = p;
    p = p->next;
    q = q->next;
  }

  if( NULL==pPre )
  {
    head = p->next;
    delete p;
  }
  else
  {
    pPre->next = p->next;
    delete p;
  }

  return head;
}
