#include "List.h"

#ifndef UTILITY_H
#define UTILITY_H

class utility
{
public:
  static utility* instance();

  /**
   * List utility
   */
  ListNode* buildList(int A[], int n);

  void freeList(ListNode* head);

  bool sameList(ListNode* head, int A[], int n);
  
protected:
  utility(){}
  
  utility(const utility&){}
  utility& operator=(const utility&){}

  
private:
};

#define util utility::instance()

#endif
