#include <tut/tut.hpp>

#include "List.h"
#include "utility.h"

namespace tut
{

struct list_basic
{
  list_basic()
  {
  }
  
  virtual ~list_basic() { }


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
  
  ListNode* head = util->buildList(A, n);

  // remove the 1st node from end
  ListNode* pHead = list_.removeNthFromEnd(head, 1);  // remove node3
  ensure( head==pHead );
  ensure( util->sameList(pHead, A, n-1) );

  pHead = list_.removeNthFromEnd(pHead, 3);  // remove head
  int B[] = {3, 4};
  ensure( util->sameList(pHead, B, 2) );

  pHead = list_.removeNthFromEnd(pHead, 2);  // remove node1
  int C[] = {4};
  ensure( util->sameList(pHead, C, 1) );
    
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
  ListNode* head = util->buildList(A, 4);

  ListNode* pHead = list_.deleteDuplicates(head);
  ensure( head==pHead );
  int B[] = {2, 3};
  ensure( util->sameList(pHead, B, 2) );

  util->freeList(pHead);

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
  ListNode* l1 = util->buildList(A, n);

  int B[] = {2, 3, 5, 7};
  int m = sizeof(B)/sizeof(int);
  ListNode* l2 = util->buildList(B, m);

  ensure( l1==list_.mergeTwoLists(l1, NULL) );
  ensure( util->sameList(l1, A, n) );

  ensure( l2==list_.mergeTwoLists(NULL, l2) );
  ensure( util->sameList(l2, B, m) );

  ensure( l1==list_.mergeTwoLists(l1, l2) );
  int C[] = {1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7, 7};
  int l = sizeof(C)/sizeof(int);
  ensure( util->sameList(l1, C, l) );

  util->freeList(l1);
}

/**
 * Check addTwoNumbers
 */
template<>
template<>
void object::test<4>()
{
  ensure( NULL==list_.addTwoNumbers(NULL, NULL));

  int A[] = {2, 4, 3};
  int n = sizeof(A)/sizeof(int);
  ListNode* l1 = util->buildList(A, n);

  int B[] = {5, 6, 4};
  int m = sizeof(B)/sizeof(int);
  ListNode* l2 = util->buildList(B, m);

  int res[] = {7, 0, 8};
  ListNode* result = list_.addTwoNumbers(l1, l2);
  ensure( util->sameList(result, res, 3) );

  int C[] = {4, 4, 5, 9, 9, 9};
  ListNode* l3 = util->buildList(C, 6);
  ListNode* result2 = list_.addTwoNumbers(l2, l3);

  int res2[] = {9, 0, 0, 0, 0, 0, 1};
  ensure( util->sameList(result2, res2, 7) );

  util->freeList(l1);
  util->freeList(l2);
  util->freeList(l3);
  util->freeList(result);
  util->freeList(result2);
}

/**
 * Check sort list (merge)
 */
template<>
template<>
void object::test<5>()
{
  ensure( NULL==list_.sortList(NULL));

  int A[] = {2, 3, 6, 8, 4, 5, 9, 10, 7, 6};
  int n = sizeof(A)/sizeof(int);
  ListNode* head = util->buildList(A, n);

  int B[] = {2, 3, 4, 5, 6, 6, 7, 8, 9, 10};

  ListNode* l1 = list_.sortList(head);
  ensure( util->sameList(l1, B, n) );
  util->freeList(l1);
}

/**
 * Check insertion list
 */
template<>
template<>
void object::test<6>()
{
  ensure( NULL==list_.insertionSortList(NULL));

  int A[] = {2, 3, 6, 8, 4, 5, 9, 10, 7, 6};
  int n = sizeof(A)/sizeof(int);
  ListNode* head = util->buildList(A, n);

  int B[] = {2, 3, 4, 5, 6, 6, 7, 8, 9, 10};

  ListNode* l1 = list_.insertionSortList(head);
  ensure( util->sameList(l1, B, n) );
  util->freeList(l1);


  int C[] = { 2, 1 };
  ListNode* l2 = util->buildList(C, 2);
  ListNode* res_l2 = list_.insertionSortList(l2);
  int D[] = { 1, 2 };
  ensure( util->sameList(res_l2, D, 2) );
  util->freeList(res_l2);
  
}


}

