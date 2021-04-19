#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "solution.h"

bool IsCorrect(const std::string& file_name) {
  std::ifstream fin(file_name);
  Solution slv;
  slv.Solve(fin);
  size_t left = slv.GetAnswer().first;
  size_t right = slv.GetAnswer().second;

  std::ifstream current_in(file_name);
  size_t size = 0;
  current_in >> size;
  size_t number = 0;
  u_int64_t sum = 0;
  for (size_t i = 0; i < size; i++) {
    current_in >> number;
    if (left <= i && i <= right) {
      sum += number;
    }
  }
  if (sum % size == 0) {
    return true;
  }
  return false;
}

int main() {
  std::string file_name = "";
  size_t number_of_tests = 9;
  for (size_t i = 0; i < number_of_tests; i++) {
    file_name = "TESTS/test" + std::to_string(i) + ".txt";
    if (IsCorrect(file_name)) {
      std::cout << "Test " << i << " passed.\n";
    } else {
      std::cout << "Test " << i << " failed!\n";
    }
  }
}