#ifndef BACKPACK_HPP
#define BACKPACK_HPP

#include <iostream>
#include <utility>
#include <vector>

#include "matrix.hpp"
#include "utils.hpp"

namespace lp {

void printResultFillBackpack(const std::pair<int, std::vector<int>>& result);
std::pair<int, std::vector<int>> fillBackpack(const std::vector<int>& weights,
                                              const std::vector<int>& prices,
                                              int capacity);

}  // namespace lp

#endif  // BACKPACK_HPP