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

ListNode* List::addTwoNumbers(ListNode *l1, ListNode *l2)
{
  if( !l1 && !l2 )
    return NULL;

  ListNode* head = NULL;
  ListNode* cur = NULL;

  int carry = 0;
  while( l1 || l2 )
  {
    int val1 = l1?l1->val : 0;
    int val2 = l2?l2->val : 0;

    int sum = val1 + val2 + carry;

    if( !cur )
    {
      head = cur = new ListNode(sum%10);
    }
    else
    {
      cur->next = new ListNode(sum%10);
      cur = cur->next;
    }

    carry = sum/10;

    if( l1 )
      l1 = l1->next;

    if( l2 )
      l2 = l2->next;
  }

  if( carry )
    cur->next = new ListNode(carry);

  return head;
}

ListNode* List::sortList(ListNode *head)
{
  if( !head || !head->next )
    return head;

  ListNode* fast = head;
  ListNode* slow = head;

  while(fast->next && fast->next->next)
  {
    fast = fast->next->next;
    slow = slow->next;
  }

  fast = slow;
  slow = slow->next;
  fast->next = NULL;

  fast = sortList(head);
  slow = sortList(slow);

  return mergeTwoLists(fast, slow);
}

ListNode* List::insertionSortList(ListNode *head)
{
  if( !head || !head->next )
    return head;

  ListNode* p = head->next;
  head->next = NULL;

  while( p )
  {
    ListNode* q = p;
    p = p->next;

    ListNode* fast = head;
    ListNode* slow = NULL;

    while( fast )
    {
      if( fast->val>q->val )
        break;

      slow = fast;
      fast = fast->next;
    }

    if( !slow )
    {
      q->next = head;
      head = q;
    }
    else
    {
      slow->next = q;
      q->next = fast;
    }
  }

  return head;
}
