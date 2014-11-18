#include <tut/tut.hpp>

#include "List.h"

namespace tut
{

struct list_basic
{
  list_basic()
  {
  }
  
  virtual ~list_basic() { }

  ListNode* buildList(int A[], int n)
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

  void freeList(ListNode* head)
  {
    while( NULL!=head )
    {
      ListNode* p = head;
      head = head->next;

      delete p;
    }
  }

  bool sameList(ListNode* head, int A[], int n)
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

  List list_;

};

typedef test_group<list_basic> factory;
typedef factory::object object;
}

namespace
{

tut::factory tf("list basic operations");

}

namespace tut
{
/**
 * Check removeNthFromEnd
 */
template<>
template<>
void object::test<1>()
{
  ensure( NULL==list_.removeNthFromEnd(NULL, 10));

  int A[] = {2, 3, 4, 50};
  int n = sizeof(A)/sizeof(int);
  
  ListNode* head = buildList(A, n);

  // remove the 1st node from end
  ListNode* pHead = list_.removeNthFromEnd(head, 1);  // remove node3
  ensure( head==pHead );
  ensure( sameList(pHead, A, n-1) );

  pHead = list_.removeNthFromEnd(pHead, 3);  // remove head
  int B[] = {3, 4};
  ensure( sameList(pHead, B, 2) );

  pHead = list_.removeNthFromEnd(pHead, 2);  // remove node1
  int C[] = {4};
  ensure( sameList(pHead, C, 1) );
    
  pHead = list_.removeNthFromEnd(pHead, 1);  // remove node2
  ensure( NULL==pHead );
}


/**
 * Check deleteDuplicates
 */
template<>
template<>
void object::test<2>()
{
  ensure( NULL==list_.deleteDuplicates(NULL));

  int A[] = {2, 3, 3, 3};
  int n = 4;
  ListNode* head = buildList(A, 4);

  ListNode* pHead = list_.deleteDuplicates(head);
  ensure( head==pHead );
  int B[] = {2, 3};
  ensure( sameList(pHead, B, 2) );

  freeList(pHead);

}

/**
 * Check mergeTwoLists
 */
template<>
template<>
void object::test<3>()
{
  ensure( NULL==list_.mergeTwoLists(NULL, NULL));

  int A[] = {1, 2, 3, 4, 4, 5, 6, 7, 7};
  int n = sizeof(A)/sizeof(int);
  ListNode* l1 = buildList(A, n);

  int B[] = {2, 3, 5, 7};
  int m = sizeof(B)/sizeof(int);
  ListNode* l2 = buildList(B, m);

  ensure( l1==list_.mergeTwoLists(l1, NULL) );
  ensure( sameList(l1, A, n) );

  ensure( l2==list_.mergeTwoLists(NULL, l2) );
  ensure( sameList(l2, B, m) );

  ensure( l1==list_.mergeTwoLists(l1, l2) );
  int C[] = {1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7, 7};
  int l = sizeof(C)/sizeof(int);
  ensure( sameList(l1, C, l) );

  freeList(l1);
}



}

