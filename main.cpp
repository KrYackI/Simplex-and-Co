#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "lp.hpp"
#include "data.hpp"
#include "gomory_cut.hpp"

int main() {
  // Examples with the regular simplex method
  auto simplexResult1 = lp::simplexMethodMax({3, 2}, {{1, 1, 4}, {1, 3, 6}});
  lp::printResultMaxSimplexMethod(simplexResult1);

  auto simplexResult2 = lp::simplexMethodMax(
      {4, 5, 3}, {{2, 3, 1, 20}, {1, 2, 3, 25}, {2, 1, 3, 15}});
  lp::printResultMaxSimplexMethod(simplexResult2);

  auto simplexResult3 = lp::simplexMethodMax(
      {6, 2, 2.5, 4},
      {{5, 1, 0, 2, 1000}, {1, 0, 2, 1, 150}, {4, 2, 2, 1, 600}});
  lp::printResultMaxSimplexMethod(simplexResult3);

  // Examples with the two-phase simplex method
  auto twoPhaseResult1 = lp::simplexMethodMaxTwoPhase(
      {3, -4}, {{-2, 1, 10}, {1, 3, 12}, {3, -1, 7}},
      {lp::OpCompare::LESS_EQ, lp::OpCompare::MORE_EQ, lp::OpCompare::MORE_EQ});
  lp::printResultMaxSimplexMethod(twoPhaseResult1);

  auto twoPhaseResult2 = lp::simplexMethodMaxTwoPhase(
      {5, -3}, {{2, -1, 4}, {-1, 2, 1}, {2, 1, 5}},
      {lp::OpCompare::MORE_EQ, lp::OpCompare::LESS_EQ, lp::OpCompare::MORE_EQ});
  lp::printResultMaxSimplexMethod(twoPhaseResult2);

  auto twoPhaseResult3 = lp::simplexMethodMaxTwoPhase(
      {6, 2, 2.5, 4},
      {{5, 1, 0, 2, 1000}, {4, 2, 2, 1, 600}, {1, 0, 2, 1, 150}},
      {lp::OpCompare::LESS_EQ, lp::OpCompare::MORE_EQ, lp::OpCompare::LESS_EQ});
  lp::printResultMaxSimplexMethod(twoPhaseResult3);

  // Examples with the backpack problem
  auto backpackResult1 = lp::fillBackpack({4, 5, 3, 7, 6}, {5, 7, 4, 9, 8}, 16);
  lp::printResultFillBackpack(backpackResult1);

  auto backpackResult2 = lp::fillBackpack({3, 4, 6}, {2, 3, 5}, 17);
  lp::printResultFillBackpack(backpackResult2);

    ifstream in;
    in.open("input.txt");
    Data d;
    d.readUserData(in);
    in.close();

    ofstream out;
    out.open("output.txt");
    gomori::gomoriAlgorithm(&d, out);
    out.close();
    system("pause");
    
  return 0;
}