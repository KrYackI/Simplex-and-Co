#ifndef PRINT_FUNCTIONS_HPP
#define PRINT_FUNCTIONS_HPP

#include <iostream>
#include "matrix.hpp"

template <typename T>
void printMatrix(const Matrix<T>& matrix) {
  size_t rows = matrix.getRows();
  size_t cols = matrix.getCols();

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cout << matrix(i, j) << '\t';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

template <typename T>
void printVector(const std::vector<T>& vec) {
  for (const auto& val : vec) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
}

#endif  // PRINT_FUNCTIONS_HPP