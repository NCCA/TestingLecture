// Problem
// Given a list of integers find the closest to zero.
// If there is a tie, choose the positive value.
// clang++ -std=c++17 -Wall -g -lgtest -lgtest_main
#include <gtest/gtest.h>
#include <vector>
#include <limits>
#include <optional>
#include <iostream>
#include <random>

/**************************************************************************************
* Example 1 this needs c++ 17 but should work in the labs
**************************************************************************************/

// std::optional allows us to return either whatever type it is  instantiated with <int>
// in this case, or a special value which is nullopt as in nothing so we use this to show
// an empty value otherwise the number nearest to zero
// Note we also pass in a const reference to a std::vector<int> as we don't want to change the values in the list.
std::optional <int> closestToZeroAlgorithm1(const std::vector<int> &_numbers)
{
  // first see if we have an empty list
  if(_numbers.size() == 0) 
  {
    return std::nullopt; // if empty list return nullopt (no value)
  }
  // if we have zero in our list return it as it's closest so search early for this
  else if( std::any_of(std::begin(_numbers),std::end(_numbers),[](int a){ return a==0;}))
  {
    return 0;
  }
  else
  {
  // this is a compund statement first we return the min_element based on the comparison function
  // in this case I'm using a lambda with x and y which I'm basically measuring the absolute distance of each from zero
  // finally this will give us an iterator so we de-reference to get the actual number
   return *std::min_element(std::begin(_numbers),std::end(_numbers),[](int x, int y)
    {   
        return std::abs(x - 0) < std::abs(y - 0);
    });
  }
}
TEST(closestToZeroAlgorithm1,testEmpty)
{
  // it's important to do a range of test. This one just passes and empty vector
  // we should have nullopt returned.
  std::vector<int> numbers;
  ASSERT_EQ(std::nullopt,closestToZeroAlgorithm1(numbers));
}

TEST(closestToZeroAlgorithm1,testwithZero)
{
  // now we set a range of numbers but we have the extents of an int (using std::numeric_limits<int>::min/max()) as well as a zero and some other numbers
  std::vector<int> numbers={std::numeric_limits<int>::max(),0,std::numeric_limits<int>::min(),2,3,-4,5};
  ASSERT_EQ(0,closestToZeroAlgorithm1(numbers));
}


TEST(closestToZeroAlgorithm1,testPositive)
{
  // now just positive
  std::vector<int> numbers={99,22,5,11,std::numeric_limits<int>::max()};
  ASSERT_EQ(5,closestToZeroAlgorithm1(numbers));
}

TEST(closestToZeroAlgorithm1,testRangeNegativeNearest)
{
  // now a range with negative nearest
  std::vector<int> numbers={-5,-12,11,200,99};
  ASSERT_EQ(-5,closestToZeroAlgorithm1(numbers));
}

TEST(closestToZeroAlgorithm1,testRangePositiveNearest)
{
  // range with positive nearest
  std::vector<int> numbers={-125,-132,11,200,99};
  ASSERT_EQ(11,closestToZeroAlgorithm1(numbers));
}

TEST(closestToZeroAlgorithm1,testBig)
{
  // lets create a big vector
  std::vector<int> numbers(1<<20);
  // fill with numbers ascending from 123
  std::iota(std::begin(numbers),std::end(numbers),123);
  std::random_device rd;
  std::mt19937 g(rd());
  // just for the hell of it let's shuffle them randomly
  std::shuffle(std::begin(numbers),std::end(numbers),g);
  // now test
  ASSERT_EQ(123,closestToZeroAlgorithm1(numbers));
}


/**************************************************************************************
* Example 1 this needs c++ 14 but should work in the labs
**************************************************************************************/

int closestToZeroAlgorithm2(const std::vector<int> &_numbers)
{
  if(_numbers.size() == 0) 
  {
    throw std::exception(); // if empty list throw an exception
  }
  // not if a zero not found std::end() is returned.
  else if( std::find(std::begin(_numbers),std::end(_numbers),int{0}) != std::end(_numbers))
  {
    return 0;
  }
  else
  {
  auto f=[](auto L,int&r){r=L[0];for(int x:L)r=x*x<=r*r?r+x?x:x>r?x:r:r;};
  int r=0;
  f(_numbers,r);
  return r;
  }  
  /*
  // first see if we have an empty list
  if(_numbers.size() == 0) 
  {
    throw std::exception(); // if empty list throw an exception
  }
  // so we can find a zero in our vector if present return 0 
  // not if a zero not found std::end() is returned.
  else if( std::find(std::begin(_numbers),std::end(_numbers),int{0}) != std::end(_numbers))
  {
    return 0;
  }
  else
  {
    auto minmax=std::minmax_element(std::begin(_numbers),std::end(_numbers));
    std::cout<<*minmax.first<<' '<<*minmax.second<<'\n';
    return  std::abs(*minmax.first-0)> std::abs(*minmax.second-0) ? *minmax.second : *minmax.first;
  // this is a compund statement first we return the min_element based on the comparison function
  // in this case I'm using a lambda with x and y which I'm basically measuring the absolute distance of each from zero
  // finally this will give us an iterator so we de-reference to get the actual number
  //  return *std::min_element(std::begin(_numbers),std::end(_numbers),[](int x, int y)
  //   {   
  //       return std::abs(x - 0) < std::abs(y - 0);
  //   });
  }*/
}
TEST(closestToZeroAlgorithm2,testEmpty)
{
  // it's important to do a range of test. This one just passes and empty vector
  // we should have nullopt returned.
  std::vector<int> numbers;
  ASSERT_THROW(closestToZeroAlgorithm2(numbers),std::exception);
}

TEST(closestToZeroAlgorithm2,testwithZero)
{
  // now we set a range of numbers but we have the extents of an int (using std::numeric_limits<int>::min/max()) as well as a zero and some other numbers
  std::vector<int> numbers={std::numeric_limits<int>::max(),0,std::numeric_limits<int>::min(),2,3,-4,5};
  ASSERT_EQ(0,closestToZeroAlgorithm2(numbers));
}


TEST(closestToZeroAlgorithm2,testPositive)
{
  // now just positive
  std::vector<int> numbers={99,22,5,11,std::numeric_limits<int>::max()};
  ASSERT_EQ(5,closestToZeroAlgorithm2(numbers));
}

TEST(closestToZeroAlgorithm2,testRangeNegativeNearest)
{
  // now a range with negative nearest
  std::vector<int> numbers={-5,-12,11,200,99};
  ASSERT_EQ(-5,closestToZeroAlgorithm2(numbers));
}

TEST(closestToZeroAlgorithm2,testRangePositiveNearest)
{
  // range with positive nearest
  std::vector<int> numbers={-125,-132,11,200,99};
  ASSERT_EQ(11,closestToZeroAlgorithm2(numbers));
}

TEST(closestToZeroAlgorithm2,testBig)
{
  // lets create a big vector
  std::vector<int> numbers(1<<2);
  // fill with numbers ascending from 123
  std::iota(std::begin(numbers),std::end(numbers),123);
  std::random_device rd;
  std::mt19937 g(rd());
  // just for the hell of it let's shuffle them randomly
  std::shuffle(std::begin(numbers),std::end(numbers),g);
  // now test
  ASSERT_EQ(123,closestToZeroAlgorithm2(numbers));
}
