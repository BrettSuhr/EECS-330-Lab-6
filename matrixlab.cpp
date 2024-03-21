#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>

std::vector<std::vector<int>> readMatrix(std::ifstream& file, int size) {
    std::vector<std::vector<int>> matrix(size, std::vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
        }
    }
    return matrix;
}

void printMatrix(const std::vector<std::vector<int>>& matrix, const std::string& label) {
    std::cout << label << std::endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << std::setw(5) << val << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int size = matrix1.size();
    std::vector<std::vector<int>> result(size, std::vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int size = matrix1.size();
    std::vector<std::vector<int>> result(size, std::vector<int>(size, 0));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

std::vector<std::vector<int>> subtractMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int size = matrix1.size();
    std::vector<std::vector<int>> result(size, std::vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

void updateMatrixElement(std::vector<std::vector<int>>& matrix, int row, int col, int newValue) {
    int size = matrix.size();
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = newValue;
    } else {
        std::cerr << "Invalid row or column index." << std::endl;
    }
}

int findMaxValue(const std::vector<std::vector<int>>& matrix) {
    int maxVal = std::numeric_limits<int>::min();
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val > maxVal) {
                maxVal = val;
            }
        }
    }
    return maxVal;
}

std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix) {
    int size = matrix.size();
    std::vector<std::vector<int>> transposed(size, std::vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main() {
    std::ifstream file("matrix_input.txt");
    if (!file) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }

    int size;
    file >> size;

    auto matrix1 = readMatrix(file, size);
    printMatrix(matrix1, "Matrix 1:");

    auto matrix2 = readMatrix(file, size);
    printMatrix(matrix2, "Matrix 2:");

    auto resultMatrix = addMatrices(matrix1, matrix2);
    printMatrix(resultMatrix, "Matrix 1 + Matrix 2:");

    auto resultMatrixMultiply = multiplyMatrices(matrix1, matrix2);
    printMatrix(resultMatrixMultiply, "Matrix 1 * Matrix 2:");

    auto resultMatrixSubtract = subtractMatrices(matrix2, matrix1);
    printMatrix(resultMatrixSubtract, "Matrix 2 - Matrix 1:");

    updateMatrixElement(matrix1, 1, 2, 100);
    printMatrix(matrix1, "Updated Matrix 1:");

    int maxVal = findMaxValue(matrix1);
    std::cout << "Maximum value in Matrix 1: " << maxVal << std::endl;

    auto transposedMatrix = transposeMatrix(matrix1);
    printMatrix(transposedMatrix, "Transposed Matrix 1:");


    file.close();
    return 0;
}

