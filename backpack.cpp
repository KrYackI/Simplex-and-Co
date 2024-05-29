#include "backpack.hpp"

namespace lp {

void printResultFillBackpack(const std::pair<int, std::vector<int>>& result) {
  std::cout << "Max Value: " << result.first << '\n';
  for (size_t i = 0; i < result.second.size(); ++i) {
    std::cout << "Item " << i + 1 << ": " << result.second[i] << '\n';
  }
}

std::pair<int, std::vector<int>> fillBackpack(const std::vector<int>& weights,
                                              const std::vector<int>& prices,
                                              int capacity) {
  if (weights.size() != prices.size() ||  weights.size() <= 1 || capacity < 1) {
    return {0, std::vector<int>()};
  }

  size_t numItems = weights.size();
  Matrix<int> matrix(numItems, capacity);

  // Initialize the first row
  for (int i = 0; i < capacity; ++i) {
    matrix(0, i) = prices[0] * ((i + 1) / weights[0]);
  }

  // Fill the matrix
  for (size_t i = 1; i < numItems; ++i) {
    for (int j = 0; j < capacity; ++j) {
      int remainingCapacity = j + 1 - weights[i];
      matrix(i, j) = std::max(matrix(i - 1, j),
                              remainingCapacity > 0 
                                ? matrix(i, remainingCapacity - 1) + prices[i]
                                : remainingCapacity == 0  ? prices[i] : 0);
    }
  }
  std::cout << "Prices = ";
  printVector(prices);
  std::cout << "Weights = ";
  printVector(weights);
  std::cout << " <= " << capacity << std::endl;
  printMatrix(matrix);

  // Backtrack to find the items to include in the backpack
  int maxVal = matrix(numItems - 1, capacity - 1);
  std::vector<int> selectedItems(numItems, 0);

  for (int i = numItems - 1, j = capacity - 1; i >= 0 && j >= 0;) {
    if (i > 0 && matrix(i - 1, j) != matrix(i, j)) {
      ++selectedItems[i];
      j -= weights[i];
    } else {
      if (i == 0) selectedItems[i] = (j + 1) / weights[i];
      --i;
    }
  }

  return {maxVal, selectedItems};
}

}  // namespace lp