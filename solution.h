#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 private:
  size_t size;
  std::vector<size_t> prefix_sum;
  std::pair<size_t, size_t> answer;

  void ReadData(std::istream& read);

 public:
  void Solve(std::istream& read);
  std::pair<size_t, size_t> GetAnswer();
};

void Solution::ReadData(std::istream& read) {
  read >> size;
  assert(size > 0);

  prefix_sum.resize(size, 0);
  read >> prefix_sum[0];
  prefix_sum[0] %= size;
  for (size_t i = 1; i < size; i++) {
    read >> prefix_sum[i];
    prefix_sum[i] = (prefix_sum[i] + prefix_sum[i - 1]) % size;
  }
}

void Solution::Solve(std::istream& read) {
  ReadData(read);

  // Если индекс ind лежит в remainder_index[r], то сумма первых ind
  //чисел исходного массива имеет остаток r по модулю size
  std::vector<std::vector<size_t>> remainder_index(size);
  for (size_t i = 0; i < size; i++) {
    remainder_index[prefix_sum[i]].push_back(i);
  }
  if (remainder_index[0].size() > 0) {  //есть префикс с суммой, кратной size
    answer.first = 0;
    answer.second = remainder_index[0][0];
  } else {
    //нужно найти две суммы с одинаковым остатком
    for (size_t i = 1; i < size; i++) {
      if (remainder_index[i].size() > 1) {
        answer.first = remainder_index[i][0] + 1;
        answer.second = remainder_index[i][1];
        break;
      }
    }
  }
}

std::pair<size_t, size_t> Solution::GetAnswer() { return answer; }