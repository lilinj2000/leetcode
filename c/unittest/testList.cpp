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

  ListNode* head;
  ListNode* node1;
  ListNode* node2;
  ListNode* node3;

  head = new ListNode(2);
  node1 = new ListNode(3);
  node2 = new ListNode(4);
  node3 = new ListNode(50);
    
  head->next = node1;
  node1->next = node2;
  node2->next = node3;


  // remove the 1st node from end
  ListNode* pHead = list_.removeNthFromEnd(head, 1);  // remove node3
  ensure( head==pHead );

  pHead = list_.removeNthFromEnd(pHead, 3);  // remove head
  ensure( node1==pHead );

  pHead = list_.removeNthFromEnd(pHead, 2);  // remove node1
  ensure( node2==pHead );

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

  ListNode* head;
  ListNode* node1;
  ListNode* node2;
  ListNode* node3;

  head = new ListNode(2);
  node1 = new ListNode(3);
  node2 = new ListNode(3);
  node3 = new ListNode(3);
    
  head->next = node1;
  node1->next = node2;
  node2->next = node3;


  ListNode* pHead = list_.deleteDuplicates(head);
  ensure( head==pHead );
  ensure( node1==pHead->next );
  ensure( NULL==node1->next );

}



}

