//
// Copyright (c) 2024 Kuznetsov Artyom
//
#ifndef SIMPLEX_HPP
#define SIMPLEX_HPP

#include <cmath>
#include <limits>

#include "matrix.hpp"
#include "utils.hpp"

enum class test;

namespace lp {

void printResultMaxSimplexMethod(
    const std::pair<double, std::vector<double>>& ans);

bool isEqual(double valueOne, double valueTwo, double eps = 0.01);

void transformationRows(Matrix<double>& matr, size_t indRowBase,
                        size_t indColBase);

std::pair<double, std::vector<double>> makeResult(const Matrix<double>& matr,
                                                  const std::vector<int>& basis,
                size_t sizeFunc);

bool validateSimplexMethodMax(const std::vector<double>& func,
                              const std::vector<std::vector<double>>& limits);

Matrix<double> createMatrixSimplexMethodMax(
    const std::vector<double>& func,
    const std::vector<std::vector<double>>& limits, size_t rows, size_t cols,
    size_t sizeFunc, size_t countLim);

std::vector<int> createBasisSimplexMethodMax(size_t sizeFunc, size_t countLim);

void calculateSimplexMethodMax(Matrix<double>& matr, std::vector<int>& basis,
                               size_t countLim);

std::pair<double, std::vector<double>> simplexMethodMax(const std::vector<double>& func,
                      const std::vector<std::vector<double>>& limits);

// simplex two phase

enum class OpCompare { LESS_EQ, MORE_EQ };

Matrix<double> createMatrixTwoPhaseSM(
    const std::vector<double>& func,
    const std::vector<std::vector<double>>& limits,
    const std::vector<OpCompare>& op, size_t rows, size_t cols, size_t sizeFunc,
    size_t countLim, size_t countMoreEq, std::vector<int>& basis);

void firstPhaze(Matrix<double>& matr, std::vector<int>& basis,
                const std::vector<double>& func, size_t countMoreEq);

void checkBasis(Matrix<double>& matr, const std::vector<int>& basis);

std::pair<double, std::vector<double>> TwoPhaseSM(
    const std::vector<double>& func,
    const std::vector<std::vector<double>>& limits,
    const std::vector<OpCompare>& op);

}  // namespace lp

#endif  // SIMPLEX_HPP