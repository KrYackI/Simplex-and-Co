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
  auto simplex1 = lp::simplexMethodMax({3, 2}, {{1, 1, 4}, {1, 3, 6}});
  lp::printResultMaxSimplexMethod(simplex1);

  auto simplex2 = lp::simplexMethodMax(
      {4, 5, 3}, {{2, 3, 1, 20}, {1, 2, 3, 25}, {2, 1, 3, 15}});
  lp::printResultMaxSimplexMethod(simplex2);

  auto simplex3 = lp::simplexMethodMax(
      {6, 2, 2.5, 4},
      {{5, 1, 0, 2, 1000}, {1, 0, 2, 1, 150}, {4, 2, 2, 1, 600}});
  lp::printResultMaxSimplexMethod(simplex3);

  // Examples with the two-phase simplex method
  auto twoPhase1 = lp::TwoPhaseSM(
      {3, -4}, {{-2, 1, 10}, {1, 3, 12}, {3, -1, 7}},
      {lp::OpCompare::LESS_EQ, lp::OpCompare::MORE_EQ, lp::OpCompare::MORE_EQ});
  lp::printResultMaxSimplexMethod(twoPhase1);

  auto twoPhase2 = lp::TwoPhaseSM(
      {5, -3}, {{2, -1, 4}, {-1, 2, 1}, {2, 1, 5}},
      {lp::OpCompare::MORE_EQ, lp::OpCompare::LESS_EQ, lp::OpCompare::MORE_EQ});
  lp::printResultMaxSimplexMethod(twoPhase2);

  auto twoPhase3 = lp::TwoPhaseSM(
      {2, -3, -3, -4, -1},
      {{3, 4, -4, -3, 5, 2}, {3, -3, 1, -2, 3, 3}, {-2, -1, 2, -3, -1, 1}},
      {lp::OpCompare::LESS_EQ, lp::OpCompare::MORE_EQ, lp::OpCompare::LESS_EQ});
  lp::printResultMaxSimplexMethod(twoPhase3);

  // Examples with the backpack problem
  auto backpack1 = lp::fillBackpack({4, 5, 3, 7, 6}, {5, 7, 4, 9, 8}, 15);
  lp::printResultFillBackpack(backpack1);

  auto backpack2 = lp::fillBackpack({3, 4, 6}, {2, 3, 5}, 15);
  lp::printResultFillBackpack(backpack2);


  // Example with the gomory cut
    ifstream in;
    in.open("input.txt");
    Data d;
    d.readUserData(in);
    in.close();

    ofstream out;
    out.open("output.txt");
    gomori::gomoriAlgorithm(&d, out);
    out.close();
    
  return 0;
}