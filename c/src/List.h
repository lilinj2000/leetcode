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
};
