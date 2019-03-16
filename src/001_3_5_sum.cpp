
/*
 *
 * Project Euler Problem #1
 * 
 * For input 1000, answer is 233168
 * 
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, 
 * we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>
#include <cstddef>

int constexpr TEST_ARG = 10;
int constexpr TEST_ANSWER = 23;
int constexpr PROBLEM_ARG = 1000;

int fibSum(int upTo) {
  int retVal{0};
  for (int i=0; i<upTo;++i) {
    if ( (i % 3 == 0) || (i % 5 == 0)) {
      retVal += i;
    }
  }
  return retVal;
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
    int argOne = std::atoi(argv[1]);
    std::cout << "answer for input " << argOne << " is " << fibSum(argOne) << "\n";
  } else {
    std::cout << "answer for test input " << TEST_ARG << " is " << fibSum(TEST_ARG) 
      << ",expecting " << TEST_ANSWER << "\n";
    std::cout << "answer for problem input " << PROBLEM_ARG << " is " << fibSum(PROBLEM_ARG) << "\n";
  }
}