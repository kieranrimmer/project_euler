
/*
 * A permutation is an ordered arrangement of objects. 
 * For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. 
 * If all of the permutations are listed numerically or alphabetically, 
 * we call it lexicographic order. 
 * The lexicographic permutations of 0, 1 and 2 are:
 *
 * 012   021   102   120   201   210
 *
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 * 
 */

#include <iostream>
#include <vector>
#include <map>

static std::map<int, char> charContainer(
  {
    {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, 
    {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}
  }
);



int factorial(int n) {
  int retVal{1};
  while (n > 1) {
    retVal *= n;
    --n;
  }
  return retVal;
}

int findStringPivotPosition(const std::map<int, char> &charContainer, int ordinal) {
  int x = 0;
  int pos = 0;
  while (x < ordinal) {
    ++pos;
    x = factorial(pos);
  }
  return pos;
}

int findOrdinalRemainder(int ordinal) {
  return 0;
}

void findAndPrintLexicographicalOrdinal(std::map<int, char> charContainer, int ordinal) {
  std::vector<char> retVal;
  int posOriginal = findStringPivotPosition(charContainer, ordinal);
  int pos = posOriginal;
  int quotient = (ordinal -1) / factorial(pos -1);
  int remainder = (ordinal -1) % factorial(pos -1);

  std::vector<char> suffixVector;

  int containerSize = charContainer.size();

  auto cc = charContainer.find(containerSize - pos + quotient);
  --pos;
  //auto cc = charContainer.find(2);
  auto toAppend = cc->second;
  charContainer.erase(cc);
  // charContainer.erase(charContainer.find(quotient));

  suffixVector.push_back(toAppend);

  while (remainder != 0) {
    --pos;
    quotient = (remainder -1) / factorial(pos - 1);
    remainder = (remainder -1) % factorial(pos -1);
    //
    auto csize = charContainer.size();
    cc = charContainer.find(charContainer.size() - pos + quotient);
    //auto cc = charContainer.find(2);
    toAppend = cc->second;
    charContainer.erase(cc);
    // charContainer.erase(charContainer.find(quotient));
    suffixVector.push_back(toAppend);
  }

  auto finalIt = charContainer.size() -  pos ? charContainer.find(charContainer.size() - pos) : charContainer.end();
  while (finalIt != charContainer.end()) {
    suffixVector.push_back(finalIt->second);
    ++finalIt;
  }

  std::cout << "Here we go " << ordinal << ":\n\t";

  auto it = charContainer.begin();
  auto val = it->first;
  while (it != charContainer.end() && it->first < containerSize - posOriginal) {
    std::cout << it->second;
    ++it;
  }

  for (int i=0; i < suffixVector.size(); ++i) {
    std::cout << suffixVector[i];
  }

  std::cout << "\n\n";
  
}

int main(int argc, char * argv[]) {
  std::cout << charContainer.size() << "\n";
  // findAndPrintLexicographicalOrdinal(std::map<int, char>(charContainer), 0);
  // findAndPrintLexicographicalOrdinal(std::map<int, char>(charContainer), 5);
  // std::cout << "\n\n\n";
  // findAndPrintLexicographicalOrdinal(std::map<int, char>(charContainer), 6);
  // findAndPrintLexicographicalOrdinal(std::map<int, char>(charContainer), 7);
  // findAndPrintLexicographicalOrdinal(std::map<int, char>(charContainer), 25);
  // findAndPrintLexicographicalOrdinal(std::map<int, char>(charContainer), 121);
  // findAndPrintLexicographicalOrdinal(std::map<int, char>(charContainer), 721);
  // findAndPrintLexicographicalOrdinal(std::map<int, char>(charContainer), 5041);
  // findAndPrintLexicographicalOrdinal(std::map<int, char>(charContainer), 40321);
  findAndPrintLexicographicalOrdinal(std::map<int, char>(charContainer), 322881);
  // std::cout << charContainer.size() << "\n";
  // findAndPrintLexicographicalOrdinal(charContainer, 1'000'000);
}



