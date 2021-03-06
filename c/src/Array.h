#include <vector>

#ifndef ARRAY_H
#define ARRAY_H

class Array
{
public:

  int searchInsert(int A[], int n, int target);

  void merge(int A[], int m, int B[], int n);

  int removeDuplicates(int A[], int n);

  int removeElement(int A[], int n, int elem);

  std::vector<int> plusOne(std::vector<int> &digits);

  int findMin(std::vector<int> &num);

  int evalRPN(std::vector<std::string> &tokens);
};

#endif
