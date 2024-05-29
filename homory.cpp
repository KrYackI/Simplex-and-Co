#include "homory.hpp"

bool isZ(double value, double eps){
    return std::fabs(value - round(value)) <= eps;
}

bool validateHomoryMax(
    const std::vector<double>& func,
    const std::vector<std::vector<double>>& limits){
  size_t sizeFunc = func.size();

  if (func.empty() || limits.empty()) return false;

  for (const auto& val : func){
        if (!isZ(val)) return false;
  }

  for (const auto& row : limits){
    if (row.size() - 1 != sizeFunc) return false;
    for (const auto& val : row){
        if (!isZ(val)) return false;
    }
  }

  return true;
}

bool validateHomoryRes(
    const std::pair<double, std::vector<double>> res){
  for (const auto& val : res.second){
        if (!isZ(val)) return false;
  }

  return true;
}

void addCut(Matrix<double>& matrix, const std::vector<int> basis){
    int maxidx = -1;
    double maxfract=0.0;
    for(int i = 0; i < basis.size(); ++i){
        double val = matrix(i, matrix.getCols() - 1);
        if (std::fabs(val - round(val)) > maxfract){
            maxfract = std::fabs(val - round(val));
            maxidx = basis[i];
        }
    }
    
}

std::pair<double, std::vector<double>> homoryMax(    
    const std::vector<double>& func,
    const std::vector<std::vector<double>>& limits){
    if (!validateHomoryMax(func, limits))
        return std::pair(0.0, std::vector<double>());
    size_t countLim = limits.size();
    size_t sizeFunc = func.size();
    size_t rows = countLim + 1;
    size_t cols = sizeFunc + countLim + 1;

    auto matr = lp::createMatrixSimplexMethodMax(func, limits, rows, cols, sizeFunc,
                                            countLim);
    auto basis = lp::createBasisSimplexMethodMax(sizeFunc, countLim);
    lp::calculateSimplexMethodMax(matr, basis, countLim);

    auto res = lp::makeResult(matr, basis, sizeFunc);
    while(!validateHomoryRes(res)){

    }

    return res;
}