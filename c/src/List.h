#include <cstddef>

struct ListNode
{
  int val;
  ListNode *next;

 ListNode(int x): val(x), next(NULL) {}
};
  
class List
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n);

  ListNode *deleteDuplicates(ListNode *head);

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

  ListNode* addTwoNumbers(ListNode *l1, ListNode *l2);

  ListNode* sortList(ListNode *head);

  ListNode* insertionSortList(ListNode *head);
};
