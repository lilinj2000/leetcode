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

ListNode *List::deleteDuplicates(ListNode *head)
{
  if( !head )
    return head;
  
  ListNode *p = head;
  ListNode *q = head;

  while( q=q->next )
  {
    if( p->val==q->val )
    {
      p->next = q->next;
      delete q;
      
      q = p;
    }
    else
    {
      p = q;
    }
  }

  return head;
}

ListNode *List::mergeTwoLists(ListNode *l1, ListNode *l2)
{
  if( NULL==l1 )
    return l2;

  if( NULL==l2 )
    return l1;

  ListNode* p = l1;
  ListNode* q = l2;
  ListNode* cur = NULL;

  while( p && q )
  {
    if( p->val<q->val )
    {
      if( NULL!=cur )
        cur->next = p;
      
      cur = p;
      p = p->next;
    }
    else
    {
      if( NULL!=cur )
        cur->next = q;

      cur = q;
      q = q->next;
    }
  }

  cur->next = (NULL==p)?q:p;

  ListNode* head = (l1->val<l2->val)? l1 : l2;

  return head;
}
