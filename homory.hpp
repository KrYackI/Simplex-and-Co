#include <limits>
#include "simplex.hpp"

bool isZ(double value, double eps = 0.001);

bool validateHomoryMax(
    const std::vector<double>& func,
    const std::vector<std::vector<double>>& limits);

std::pair<double, std::vector<double>> homoryMax(    
    const std::vector<double>& func,
    const std::vector<std::vector<double>>& limits);