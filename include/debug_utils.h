
#ifndef _DEBUG_UTILS_H_
#define _DEBUG_UTILS_H_

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

#include <cassert>


using std::cout;


template<typename T> 
void printVector(std::vector<T> _v) {
  for (size_t i=0; i < _v.size(); ++i) {
    std::cout << "_v[" << i << "] = " << _v[i] << "\n";
  }
}

template<typename T>
void printPairVector(std::vector<std::pair<T, T> > _v) {
  for (size_t i=0; i < _v.size(); ++i) {
    std::cout << "_v[" << i << "] = {" << _v[i].first << ", " << _v[i].second << "}\n";
  }
}

#endif