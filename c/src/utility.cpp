#include "utility.h"

utility* utility::instance()
{
  static utility utility_;
  
  return &utility_;
}

ListNode* utility::buildList(int A[], int n)
{
  ListNode* head = NULL;
  ListNode* cur = NULL;
  for(int i=0; i<n; i++)
  {
    ListNode* node = new ListNode(A[i]);

    if( NULL==head )
      head = node;

    if( NULL!=cur )
      cur->next = node;
      
    cur = node;
  }

  return head;
}

void utility::freeList(ListNode* head)
{
  while( NULL!=head )
  {
    ListNode* p = head;
    head = head->next;

    delete p;
  }
}

bool utility::sameList(ListNode* head, int A[], int n)
{
  for(int i=0; i<n; i++)
  {
    // std::cerr <<A[i] <<" - " <<head->val <<std::endl;
      
    if( head && head->val==A[i] )
    {
      head = head->next;
        
      continue;
    }

    return false;
  }

  return head?false:true;
}
