#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

template <typename T>
class Matrix {
 private:
  std::vector<T> mData;
  size_t mRows;
  size_t mCols;

 public:
  using type = T;

  Matrix() = default;
  Matrix(size_t rows, size_t cols, T val = T());
  Matrix(const Matrix&) = default;
  Matrix(Matrix&&) = default;
  ~Matrix() = default;

  Matrix& operator=(const Matrix&) = default;
  Matrix& operator=(Matrix&&) = default;

  [[nodiscard]] T& operator()(size_t row, size_t col);
  [[nodiscard]] const T& operator()(size_t row, size_t col) const;

  [[nodiscard]] bool empty() const noexcept { return mData.empty(); }
  [[nodiscard]] size_t getRows() const noexcept { return mRows; }
  [[nodiscard]] size_t getCols() const noexcept { return mCols; }

  void reset(size_t rows = 0, size_t cols = 0, T val = T());
  void fill(T val);
};

template <typename T>
inline Matrix<T>::Matrix(size_t rows, size_t cols, T val)
    : mData(rows * cols, val), mRows(rows), mCols(cols) {}

template <typename T>
inline T& Matrix<T>::operator()(size_t row, size_t col) {
  return mData[row * mCols + col];
}

template <typename T>
inline const T& Matrix<T>::operator()(size_t row, size_t col) const {
  return mData[row * mCols + col];
}

template <typename T>
inline void Matrix<T>::reset(size_t rows, size_t cols, T val) {
  mRows = rows;
  mCols = cols;
  mData.assign(rows * cols, val);
}

template <typename T>
inline void Matrix<T>::fill(T val) {
  std::fill(mData.begin(), mData.end(), val);
}

#endif  // MATRIX_HPP