/*
 * A palindromic number reads the same both ways. 
 * The largest palindrome made from the product of 
 * two 2-digit numbers is 9009 = 91 × 99.
 * 
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * 
 * A: 906609
 * 
 */

#include <vector>
#include <iostream>
#include <cmath>

constexpr int BASE_FOR_ALL = 10;

constexpr int TEST_ARG = 2;

constexpr int TEST_ANSWER = 9009;

constexpr int PROBLEM_ARG = 3;


int getReverse(int original) {
  int remainder;
  int reversedInteger{0};
  while( original != 0 ) {
    remainder = original % 10;
    reversedInteger = reversedInteger*10 + remainder;
    original /= 10;
  }
  return reversedInteger;
}

int ceilingDivision(int numerator, int denominator) {
  return (numerator + denominator - 1) / denominator;
}

bool isPalindrome(int x) {
  return getReverse(x) == x;
}

int pow(int base, int exponent) {
  int retval{1};
  for (int i=0; i<exponent; ++i) {
    retval *= base;
  }
  return retval;
}

int getMaxVal(int base, int exponent) {
  return pow(base, exponent) - 1;
}

bool hasDivisor(int i, int base, int exponent) {
  bool retVal = true;
  int maxVal = getMaxVal(10, exponent);
  int minVal = ceilingDivision(i, maxVal);
  if (minVal > maxVal)
    return false;
  for (int j=minVal; j <= maxVal; ++j) {
    if (i % j == 0) {
      return true;
    }
  }
  return false;
}

int largestPalindromicProduct(int base, int exponent) {
  int retVal = getMaxVal(base, exponent);
  int seed = getMaxVal(base, exponent);
  for (int i=seed * seed; i>0; --i) {
    if (isPalindrome(i)) {
      if (hasDivisor(i, base, exponent)) {
        retVal = i; 
        break;
      }
    }
  }
  return retVal;
}

int main(int argc, char *argv[]) {
  std::cout << "TEST: " << TEST_ARG << " -> " 
    << largestPalindromicProduct(BASE_FOR_ALL, TEST_ARG) << ", expecting " << TEST_ANSWER << "\n";

  std::cout << "PROBLEM: " << PROBLEM_ARG << " -> " 
    << largestPalindromicProduct(BASE_FOR_ALL, PROBLEM_ARG) << "\n";
}

