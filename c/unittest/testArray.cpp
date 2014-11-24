#include <tut/tut.hpp>
#include "Array.h"


namespace tut
{

struct array_basic
{
    array_basic() { }
    virtual ~array_basic() { }

  Array array_;
};

typedef test_group<array_basic> factory;
typedef factory::object object;
}

namespace
{

tut::factory tf("array basic operations");

}

namespace tut
{
/**
 * Check searchInsert
 */
template<>
template<>
void object::test<1>()
{
  int A[] = {1, 3, 5, 6};
  int n = 4;
  int target = 5;
  ensure( 2==array_.searchInsert(A, n, target) );

  target = 2;
  ensure( 1==array_.searchInsert(A, n, target) );

  target = 7;
  ensure( 4==array_.searchInsert(A, n, target) );

  target = 0;
  ensure( 0==array_.searchInsert(A, n, target) );

  
}

/**
 * Check merge A[] & B[]
 */
template<>
template<>
void object::test<2>()
{
  int A[10] = {1, 3, 5, 6};
  int m = 4;
  int B[3] = {3, 5, 8};
  int n = 3;
  

  array_.merge(A, 4, B, 3);
  int resA[] = {1, 3, 3, 5, 5, 6, 8};
  for(int i=0; i<7; i++)
  {
    ensure( resA[i]==A[i] );
  }
 
}

/**
 * Check removeDuplicates
 */
template<>
template<>
void object::test<3>()
{
  ensure( 0==array_.removeDuplicates(NULL, 10) );
  
  int A[10] = {1, 3, 3, 4, 4, 5, 6, 6, 9, 9};
  int n = 10;

  ensure( 0==array_.removeDuplicates(A, 0) );
  
  int m = array_.removeDuplicates(A, n);
  ensure( m==6 );
  
  int resA[] = {1, 3, 4, 5, 6, 9};
  for(int i=0; i<m; i++)
  {
    ensure( resA[i]==A[i] );
  }
 
}

/**
 * Check removeElement
 */
template<>
template<>
void object::test<4>()
{
  ensure( 0==array_.removeElement(NULL, 10, 2) );
  
  int A[10] = {1, 3, 3, 4, 4, 5, 6, 6, 9, 9};
  int n = 10;

  ensure( 0==array_.removeElement(A, 0, 2) );
  
  int m = array_.removeElement(A, n, 5);
  ensure( m==9 );
  
  int resA[] = {1, 3, 3, 4, 4, 6, 6, 9, 9};
  for(int i=0; i<m; i++)
  {
    ensure( resA[i]==A[i] );
  }

  m = array_.removeElement(A, m, 1);
  ensure( m==8 );

  {
    int resA[] = {3, 3, 4, 4, 6, 6, 9, 9};
    for(int i=0; i<m; i++)
    {
      ensure( resA[i]==A[i] );
    }
  }

  m = array_.removeElement(A, m, 9);
  ensure( m==6 );

  {
    int resA[] = {3, 3, 4, 4, 6, 6 };
    for(int i=0; i<m; i++)
    {
      ensure( resA[i]==A[i] );
    }
  }

  m = array_.removeElement(A, m, 10);
  ensure( m==6 );

  {
    int resA[] = {3, 3, 4, 4, 6, 6 };
    for(int i=0; i<m; i++)
    {
      ensure( resA[i]==A[i] );
    }
  }
 
}

/**
 * Check plusOne
 */
template<>
template<>
void object::test<5>()
{
  std::vector<int> emptyDigits;
  std::vector<int> resDigits = array_.plusOne(emptyDigits);
  ensure( resDigits.empty() );

  std::vector<int> nDigits;
  nDigits.push_back(1);
  nDigits.push_back(4);
  nDigits.push_back(5);
  nDigits.push_back(6);
  nDigits.push_back(9);

  std::vector<int> expDigits = nDigits;
  expDigits[3] = 7;
  expDigits[4] = 0;
  
  resDigits = array_.plusOne(nDigits);

  for(unsigned i=0; i<resDigits.size(); i++)
  {
    ensure( resDigits[i]==expDigits[i] );
  }

  std::vector<int> sDigits;
  sDigits.push_back(9);
  sDigits.push_back(9);
  sDigits.push_back(9);

  expDigits.clear();
  expDigits.push_back(1);
  expDigits.push_back(0);
  expDigits.push_back(0);
  expDigits.push_back(0);
      
  resDigits = array_.plusOne(sDigits);

  for(unsigned i=0; i<resDigits.size(); i++)
  {
    ensure( resDigits[i]==expDigits[i] );
  }
}

/**
 * Check findMin for the rotated array
 */
template<>
template<>
void object::test<6>()
{
  std::vector<int> emptyVec;
  ensure ( 0==array_.findMin(emptyVec) );

  int A[] = {4, 5, 6, 7, 0, 1, 2};
  std::vector<int> num;
  num.resize(7);
  std::copy(A, A+7, num.begin());

  ensure( 0==array_.findMin(num) );

  int B[] = {3, 1, 2};
  num.resize(3);
  std::copy(B, B+3, num.begin());
  ensure( 1==array_.findMin(num) );
}



}

