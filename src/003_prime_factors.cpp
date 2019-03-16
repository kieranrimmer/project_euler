/*
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * 
 * What is the largest prime factor of the number 600851475143 ?
 * 
 * A: 6857
 */

constexpr long TEST_ARG = 10;
constexpr long TEST_ANSWER = 5;
constexpr long PROBLEM_ARG = 600851475143;

#include <iostream>

long lpf(long factorand) {
  if (factorand < 2)
    return factorand;
  long prime{2};
  while (factorand >= prime * prime) {
    if (factorand % prime == 0) {
      // std::cout << prime << " is a factor\n";
      factorand = factorand / prime;
    } else {
      ++prime;
    }
  }
  return factorand;
}

int main(int argc, char * argv[]) {
  std::cout << "TEST: " << TEST_ARG << " -> " << lpf(TEST_ARG) << ", expecting " << TEST_ANSWER << "\n";
  std::cout << "PROBLEM: " << PROBLEM_ARG << " -> " << lpf(PROBLEM_ARG) << "\n";
}